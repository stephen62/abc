#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainApplication.h"
#include "ImageAlgorithm.h"
#include "RegistrationAlgorithm.h"
#include "QWaiting.h"
#include <QThread>
#include <QtConcurrent>
#include <QFuture>
#include "myDataProcess.h"
/*itk File*/
#include "itkCenteredEuler3DTransform.h"
/*vtk File*/
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkImageViewer2.h>
#include <QVTKWidget.h>
#include <vtkDICOMImageReader.h>
#include <vtkJPEGReader.h>
#include <vtkPNGReader.h>
#include <vtkImageActor.h>
#include <vtkEventQtSlotConnect.h>
#include "vtkCommand.h"
#include <vtkOutputWindow.h>
#include "vtkSmartPointer.h"
#include "vtkImageBlend.h"
#include "vtkBMPReader.h"
#include "vtkImageCast.h"
#include "vtkBMPWriter.h"
#include "vtkFixedPointVolumeRayCastMapper.h"
#include "vtkColorTransferFunction.h"
#include "vtkPiecewiseFunction.h"
#include "vtkVolumeProperty.h"
#include "vtkBorderWidget.h"
#include "vtkBorderRepresentation.h"
#include "vtkProperty2D.h"
//Ϊ���ܹ�ʹ��vtk��Ӵ���
#include "vtkAutoInit.h"
VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

class MainApplication : public QMainWindow
{
    Q_OBJECT

public:
    MainApplication(QWidget *parent = Q_NULLPTR);
	void setDataProcess(myDataProcess* process);

public slots:
	void openCT_clicked();
	void cur_open_ct(std::string filename);
	void openXRay_clicked();
	void viewDRR();
	void viewXRay();
	void viewImage(int flag);
	void chooseReader();
	void changeOpacity();
	void vtkImitateDRR(std::string input);
	void adjustPara();
	void restorPara();
	void changeToOther();
	void runRegistration();
	void outOfFocusConfirm_TRS();
	void compareArea();
	void outputArea();

private:
    Ui::MainApplication ui;
	vtkSmartPointer<vtkImageViewer2> m_pImageViewer;
	vtkSmartPointer<vtkRenderer> m_pRenderer;
	vtkSmartPointer<vtkImageBlend> imageBlend;
	vtkSmartPointer<vtkBorderWidget> borderWidget;
	bool isDRR;											//�Ƿ��Ѿ�����DRR
	bool isXray;										//�Ƿ���Xrayͼ��
	bool isCT;											//�Ƿ���CTͼ��
	bool DRR_visible;									//�Ƿ���ʾDRR
	bool XRay_visible;									//�Ƿ���ʾXRay
	bool area_visible;									//�Ƿ�������ʾ
	int layer;											//ͼ����
	int cur_Xray;										//Xray����ͼ��
	int cur_DRR;										//DRR����ͼ��
	myDataProcess* dataProcess;							//vtk������
	bool lock3d;										//3dͼ������
	int current_mode;									//��ǰģʽ
	

private:
	int getLayer();
	void clearLayer();
	double getOpacity();
	double adjustValue(double v);
};