#include "MainApplication.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>
#include <QtGlobal>
#include <QPaintEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsOpacityEffect>
#include "QtUtil.h"

// 适配ITK
#include <winsock2.h> 
#pragma comment(lib, "WS2_32")
#pragma comment(lib, "Rpcrt4.lib")

MainApplication::MainApplication(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	//部分控件初始值设置
	ui.m_ddr_box->setChecked(true);
	ui.m_xray_box->setChecked(true);
	m_pImageViewer = vtkSmartPointer<vtkImageViewer2>::New();
	m_pRenderer = vtkSmartPointer<vtkRenderer>::New();
	imageBlend = vtkSmartPointer<vtkImageBlend>::New();
	imageBlend->SetBlendModeToCompound();
	ui.qvtkWidget->GetRenderWindow()->AddRenderer(m_pRenderer);
	ui.qvtkWidget_2->setVisible(false);
	
	isCT = false;
	isDRR = false;
	isXray = false;
	DRR_visible = true;
	XRay_visible = true;
	current_mode = 0;
	lock3d = false;
	layer = 0;
	cur_DRR = -1;
	cur_Xray = -1;
	m_pImageViewer->SetInputData(imageBlend->GetOutput());
	m_pImageViewer->UpdateDisplayExtent();
	m_pImageViewer->SetRenderWindow(ui.qvtkWidget->GetRenderWindow());
	m_pImageViewer->SetRenderer(m_pRenderer);
	m_pImageViewer->SetupInteractor(ui.qvtkWidget->GetRenderWindow()->GetInteractor());
	m_pImageViewer->SetSliceOrientationToXY();//默认就是这个方向
	m_pImageViewer->GetImageActor()->InterpolateOff();
	//m_pRenderer->ResetCamera();
	//m_pRenderer->DrawOn();
	vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::New();
	m_pImageViewer->SetupInteractor(iren);
	m_pImageViewer->GetRenderer()->InteractiveOff();
	//矩形框
	area_visible = false;
	borderWidget = vtkBorderWidget::New();
	borderWidget->SetInteractor(iren);
	static_cast<vtkBorderRepresentation*>(borderWidget->GetRepresentation())->
		GetBorderProperty()->SetColor(0, 1, 0);
	borderWidget->CreateDefaultRepresentation();
	borderWidget->SelectableOff();
	borderWidget->Off();

	m_pRenderer->ResetCamera();
	m_pRenderer->DrawOn();
	ui.qvtkWidget->GetRenderWindow()->Render();

	//以下是信号关联
	
	connect(ui.actionJHK, SIGNAL(triggered()), this, SLOT(openCT_clicked()));	//打开CT
	connect(ui.actiondd, SIGNAL(triggered()), this, SLOT(openXRay_clicked()));//打开X-ray

	//connect(ui.m_ct_btn, SIGNAL(clicked()), this, SLOT(openCT_clicked()));	//打开CT
	//connect(ui.m_xray_btn, SIGNAL(clicked()), this, SLOT(openXRay_clicked()));//打开X-ray

	connect(ui.m_ddr_box, SIGNAL(clicked(bool)), this, SLOT(viewDRR()));//显示drr
	connect(ui.m_xray_box, SIGNAL(clicked(bool)), this, SLOT(viewXRay()));//显示x-ray
	connect(ui.opacity_text, SIGNAL(editingFinished()), this, SLOT(changeOpacity()));//ddr图透明占比

	//参数调整
	connect(ui.xp_label, SIGNAL(returnPressed()), this, SLOT(outOfFocusConfirm_TRS()));
	connect(ui.yp_label, SIGNAL(returnPressed()), this, SLOT(outOfFocusConfirm_TRS()));
	connect(ui.zp_label, SIGNAL(returnPressed()), this, SLOT(outOfFocusConfirm_TRS()));
	connect(ui.xr_label, SIGNAL(returnPressed()), this, SLOT(outOfFocusConfirm_TRS()));
	connect(ui.yr_label, SIGNAL(returnPressed()), this, SLOT(outOfFocusConfirm_TRS()));
	connect(ui.zr_label, SIGNAL(returnPressed()), this, SLOT(outOfFocusConfirm_TRS()));
	connect(ui.xt_label, SIGNAL(returnPressed()), this, SLOT(outOfFocusConfirm_TRS()));
	connect(ui.yt_label, SIGNAL(returnPressed()), this, SLOT(outOfFocusConfirm_TRS()));
	connect(ui.zt_label, SIGNAL(returnPressed()), this, SLOT(outOfFocusConfirm_TRS()));
	connect(ui.dx_label, SIGNAL(returnPressed()), this, SLOT(outOfFocusConfirm_TRS()));
	connect(ui.dy_label, SIGNAL(returnPressed()), this, SLOT(outOfFocusConfirm_TRS()));
	connect(ui.sx_label, SIGNAL(returnPressed()), this, SLOT(outOfFocusConfirm_TRS()));
	connect(ui.sy_label, SIGNAL(returnPressed()), this, SLOT(outOfFocusConfirm_TRS()));
	connect(ui.sid_label, SIGNAL(returnPressed()), this, SLOT(outOfFocusConfirm_TRS()));
	connect(ui.threshold_label, SIGNAL(returnPressed()), this, SLOT(outOfFocusConfirm_TRS()));
	ui.init_btn->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
	connect(ui.init_btn, SIGNAL(clicked()), this, SLOT(restorPara()));		//恢复参数
	ui.m_change_btn->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
	connect(ui.m_change_btn, SIGNAL(clicked()), this, SLOT(changeToOther())); //修改展示模式
	ui.m_compare_btn->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
	connect(ui.m_compare_btn, SIGNAL(clicked()), this, SLOT(compareArea())); //比较区域
	ui.m_output_btn->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
																			
																			 
 //测试代码

}

void MainApplication::openCT_clicked() {

	// 读取序列图像
	// 进入ITKDRR处理
	QFileDialog *fileDialog = new QFileDialog(this);
	fileDialog->setWindowTitle(QStringLiteral("选择CT图像序列"));
	fileDialog->setDirectory("");
	fileDialog->setFileMode(QFileDialog::Directory);
	fileDialog->setViewMode(QFileDialog::Detail);
	QString filedic;
	if (fileDialog->exec()) {
		filedic = fileDialog->selectedFiles()[0];
	}
	if (filedic.isEmpty()) return;
	else {
		// 清除上一个CT序列
		clearLayer();
		// 使用ITKDRR类读入图像序列
		QWaiting *qwait = new QWaiting(this);
		qwait->show();
		QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
		QFuture<void> future = QtConcurrent::run(this, &MainApplication::cur_open_ct, filedic.toStdString());
		QFuture<void> vtk3d = QtConcurrent::run(this, &MainApplication::vtkImitateDRR, filedic.toStdString());
		while (!future.isFinished()) {
			QApplication::processEvents();
		}
		ui.qvtkWidget->setVisible(true);
		ui.qvtkWidget_2->setVisible(false);
		viewImage(0);
		qwait->close();
		QApplication::restoreOverrideCursor();
	}
}

void MainApplication::setDataProcess(myDataProcess * process)
{
	dataProcess = process;
}

void MainApplication::cur_open_ct(std::string filename) {
	dataProcess->getImageAlgorithm()->setInputName(filename.data());
}

void MainApplication::openXRay_clicked() {
	QFileDialog *fileDialog = new QFileDialog(this);
	fileDialog->setWindowTitle(QStringLiteral("选择X-Ray图像"));
	fileDialog->setDirectory("");
	fileDialog->setNameFilter(tr("Images (*.bmp)"));
	fileDialog->setFileMode(QFileDialog::ExistingFiles);
	fileDialog->setViewMode(QFileDialog::Detail);
	QString filename;
	if (fileDialog->exec()) {
		filename = fileDialog->selectedFiles()[0];
	}
	if (filename.isEmpty()) return;
	else {
		dataProcess->createXRayReader(filename.toStdString().data());
		if (cur_Xray == -1) {
			imageBlend->AddInputData(dataProcess->getXRayReader()->GetOutput());
			imageBlend->SetOpacity(getLayer(), 1.0 - getOpacity());
			cur_Xray = getLayer();
			layer++;
		}
		else {
			imageBlend->ReplaceNthInputConnection(cur_Xray, dataProcess->getXRayReader()->GetOutputPort());
			imageBlend->SetOpacity(cur_Xray, 1.0 - getOpacity());
		}
		imageBlend->Update();
		m_pImageViewer->SetInputData(imageBlend->GetOutput());
		m_pImageViewer->UpdateDisplayExtent();
		m_pImageViewer->SetRenderWindow(ui.qvtkWidget->GetRenderWindow());
		m_pImageViewer->SetRenderer(m_pRenderer);
		m_pRenderer->ResetCamera();
		m_pRenderer->DrawOn();
		ui.qvtkWidget->GetRenderWindow()->Render();

		viewImage(2);

	}
}

void MainApplication::viewDRR() {
	if (DRR_visible) {
		DRR_visible = false;
	}
	else
		DRR_visible = true;
	if (isXray || isDRR) {
		chooseReader();
	}
}

void MainApplication::viewXRay() {
	if (XRay_visible)
		XRay_visible = false;
	else
		XRay_visible = true;
	if (isXray || isDRR) {
		chooseReader();
	}
}

void MainApplication::chooseReader() {
	if (XRay_visible && DRR_visible && isXray && isDRR) { //显示混合图像
		m_pImageViewer->SetInputData(imageBlend->GetOutput());
	}
	else if (DRR_visible && isDRR) {	//只显示DRR
		m_pImageViewer->SetInputData(dataProcess->getCTReader()->GetOutput());
	}
	else if (XRay_visible && isXray) {	//只显示XRay
		m_pImageViewer->SetInputData(dataProcess->getXRayReader()->GetOutput());
	}
	else {				//都不显示
		m_pImageViewer->SetInputData(vtkImageData::New());
	}
	m_pImageViewer->UpdateDisplayExtent();
	m_pImageViewer->SetRenderWindow(ui.qvtkWidget->GetRenderWindow());
	m_pImageViewer->SetRenderer(m_pRenderer);
	m_pRenderer->ResetCamera();
	m_pRenderer->DrawOn();
	ui.qvtkWidget->GetRenderWindow()->Render();
}

void MainApplication::changeOpacity()
{
	if (isDRR) {
		imageBlend->SetOpacity(cur_DRR, getOpacity());
		imageBlend->Update();
		ui.qvtkWidget->GetRenderWindow()->Render();
	}
	if (isXray) {
		imageBlend->SetOpacity(cur_Xray, 1.0-getOpacity());
		imageBlend->Update();
		ui.qvtkWidget->GetRenderWindow()->Render();
	}
}

void MainApplication::vtkImitateDRR(std::string input)
{
	
	dataProcess->setVtkImitateDRR(input.data());
	lock3d = true;
	vtkRenderer *aRenderer = vtkRenderer::New();
	ui.qvtkWidget_2->GetRenderWindow()->AddRenderer(aRenderer);
	aRenderer->AddActor(dataProcess->getDRRVolume());
	

}

void MainApplication::restorPara() {
	ui.xp_label->setText("0");
	ui.yp_label->setText("0");
	ui.zp_label->setText("0");
	ui.xr_label->setText("90");
	ui.yr_label->setText("0");
	ui.zr_label->setText("0");
	ui.xt_label->setText("0");
	ui.yt_label->setText("0");
	ui.zt_label->setText("0");
	ui.sid_label->setText("400");
	ui.dy_label->setText("1024");
	ui.dx_label->setText("1024");
	ui.threshold_label->setText("0");
	ui.sx_label->setText("0.3125");
	ui.sy_label->setText("0.3125");
	ui.lineEdit_00->setText("1");
	ui.lineEdit_01->setText("0");
	ui.lineEdit_02->setText("0");
	ui.lineEdit_03->setText("0");
	ui.lineEdit_10->setText("0");
	ui.lineEdit_11->setText("0");
	ui.lineEdit_12->setText("-1");
	ui.lineEdit_13->setText("0");
	ui.lineEdit_20->setText("0");
	ui.lineEdit_21->setText("1");
	ui.lineEdit_22->setText("0");
	ui.lineEdit_23->setText("0");
	ui.lineEdit_30->setText("0");
	ui.lineEdit_31->setText("0");
	ui.lineEdit_32->setText("0");
	ui.lineEdit_33->setText("1");
}

void MainApplication::changeToOther()
{
	if (current_mode == 0) //当前显示ITK DRR
	{
		current_mode = 1;
		ui.qvtkWidget_2->setVisible(true);
		ui.qvtkWidget->setVisible(false);
	}
	else if (current_mode == 1) {
		current_mode = 0;
		ui.qvtkWidget->setVisible(true);
		ui.qvtkWidget_2->setVisible(false);
	}
}

void MainApplication::adjustPara()
{
	if (!isCT) {
		return;
	}
	double xp = ui.xp_label->text().toDouble();
	double yp = ui.yp_label->text().toDouble();
	double zp = ui.zp_label->text().toDouble();
	double xr = ui.xr_label->text().toDouble();
	double yr = ui.yr_label->text().toDouble();
	double zr = ui.zr_label->text().toDouble();
	double sid = ui.sid_label->text().toDouble();
	int dx = ui.dx_label->text().toInt();
	int dy = ui.dy_label->text().toInt();
	double sx = ui.sx_label->text().toDouble();
	double sy = ui.sy_label->text().toDouble();
	double threshold = ui.threshold_label->text().toDouble();
	// 异步处理DRR图像
	dataProcess->processItkDrr(15, xr, yr, zr, xp, yp, zp, sid, dx, dy, sx, sy, threshold);
	/*QWaiting *qwait = new QWaiting(this);
	qwait->show();
	QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
	
	QFuture<void> future = QtConcurrent::run(std::bind(&(myDataProcess::processItkDrr), 15, xr, yr, zr, xp, yp, zp, sid, dx, dy, sx, sy, threshold));
	while (!future.isFinished()) {
		QApplication::processEvents();
	}
	qwait->close();
	QApplication::restoreOverrideCursor();*/
	// 如果已存储入imageBlend， 只需要刷新改区域
	if (cur_DRR == -1) {
		imageBlend->AddInputData(dataProcess->getCTReader()->GetOutput());
		imageBlend->SetOpacity(getLayer(), getOpacity());
		cur_DRR = getLayer();
		imageBlend->Update();
		layer++;
	}
	else {
		imageBlend->ReplaceNthInputConnection(cur_DRR, dataProcess->getCTReader()->GetOutputPort());
		imageBlend->SetOpacity(cur_DRR, getOpacity());
		imageBlend->Update();
	}
	chooseReader();
}

int MainApplication::getLayer() {
	if (layer == 0 || layer == 1)
		return layer;
	else
		return 0;
}

void MainApplication::clearLayer() {
	layer = 0;
	imageBlend = vtkSmartPointer<vtkImageBlend>::New();
	dataProcess->clearXRayReader();
	isCT = false;
	isDRR = false;
	isXray = false;
	lock3d = false;
}

double MainApplication::getOpacity()
{
	double opcaity = ui.opacity_text->text().toDouble();
	if (0 <= opcaity && opcaity <= 100) {
		return opcaity / 100.0;
	}
	return 0;
}

void MainApplication::viewImage(int flag) {
	//此方法中的所有步骤都采用多线程来避免UI卡顿
	if (flag == 0) {	//调用ITKDRR中的DRR算法
		// 导入CT图像之后使用DRR算法生成DRR图像
		//
		isCT = true;
		cur_DRR = -1;
		cur_Xray = -1;
		isDRR = true;
		adjustPara();
	}
	else if (flag == 1) { // 展示DRR图像
		return;
	}
	else if (flag == 2) { // 展示XRay图像
		isXray = true;
	}
	//相似度配准
	if (isCT && isDRR & isXray) {
		runRegistration();
	}
}

void MainApplication::runRegistration() {
	ui.m_scale_label->setText(QString("calculating..."));
	double rate = dataProcess->getRegistrationAlgorithm()->getSimilarity();
	if (rate > 1 || rate < 0) {
		//相似度需要在0-1之间
		ui.m_scale_label->setText(QString("invalid number"));
		return;
	}
	int tmp = rate*10000;
	rate = (double)tmp / 100;
	std::string str = std::to_string(rate) + "%";
	ui.m_scale_label->setText(QString::fromStdString(str));
}

void MainApplication::outOfFocusConfirm_TRS() {
	//是否还有数据正在编辑
	/*if (ui.xp_label->hasFocus() || ui.yp_label->hasFocus() || ui.zp_label->hasFocus() ||
		ui.xr_label->hasFocus() || ui.yr_label->hasFocus() || ui.zr_label->hasFocus() ||
		ui.xt_label->hasFocus() || ui.yt_label->hasFocus() || ui.zt_label->hasFocus() ||
		ui.dx_label->hasFocus() || ui.dy_label->hasFocus() || ui.sx_label->hasFocus() ||
		ui.sy_label->hasFocus() || ui.sid_label->hasFocus() || ui.threshold_label->hasFocus())
		return;*/
	//调整对应矩阵值
	using TransformType = itk::CenteredEuler3DTransform<double>;
	TransformType::Pointer transform = TransformType::New();
	itk::Matrix<double, 3, 3> tmp_matrix;
	transform->SetComputeZYX(true);
	double xr = ui.xr_label->text().toDouble();
	double yr = ui.yr_label->text().toDouble();
	double zr = ui.zr_label->text().toDouble();
	double xp = ui.xp_label->text().toDouble();
	double yp = ui.yp_label->text().toDouble();
	double zp = ui.zp_label->text().toDouble();
	const double dtr = (std::atan(1.0) * 4.0) / 180.0;
	transform->SetRotation(dtr * xr, dtr * yr, dtr * zr);
	tmp_matrix = transform->GetMatrix();
	ui.lineEdit_00->setText(QString::number(adjustValue(tmp_matrix[0][0]), 'g', 13));
	ui.lineEdit_01->setText(QString::number(adjustValue(tmp_matrix[0][1]), 'g', 13));
	ui.lineEdit_02->setText(QString::number(adjustValue(tmp_matrix[0][2]), 'g', 13));
	ui.lineEdit_10->setText(QString::number(adjustValue(tmp_matrix[1][0]), 'g', 13));
	ui.lineEdit_11->setText(QString::number(adjustValue(tmp_matrix[1][1]), 'g', 13));
	ui.lineEdit_12->setText(QString::number(adjustValue(tmp_matrix[1][2]), 'g', 13));
	ui.lineEdit_20->setText(QString::number(adjustValue(tmp_matrix[2][0]), 'g', 13));
	ui.lineEdit_21->setText(QString::number(adjustValue(tmp_matrix[2][1]), 'g', 13));
	ui.lineEdit_22->setText(QString::number(adjustValue(tmp_matrix[2][2]), 'g', 13));
	//像素平移
	ui.lineEdit_03->setText(QString::number(adjustValue(xp)));
	ui.lineEdit_13->setText(QString::number(adjustValue(yp)));
	ui.lineEdit_23->setText(QString::number(adjustValue(zp)));
	adjustPara();
}


double MainApplication::adjustValue(double v) {
	if (v < 0.0001 && v>0)
		return 0.0;
	else if (v > -0.0001 && v < 0)
		return 0.0;
	else
		return v;
}

void MainApplication::compareArea() {
	if (area_visible) {
		borderWidget->Off();
		area_visible = false;
		m_pRenderer->ResetCamera();
		m_pRenderer->DrawOn();
		ui.qvtkWidget->GetRenderWindow()->Render();
	}
	else {
		borderWidget->On();
		area_visible = true;
		m_pRenderer->ResetCamera();
		m_pRenderer->DrawOn();
		ui.qvtkWidget->GetRenderWindow()->Render();
	}
	
}

void MainApplication::outputArea() {

}