#include "MainApplication.h"
#include <QtWidgets/QApplication>
#include "vtkoutputwindow.h"
#include "itkDrr.h"
#include "drrRegistration.h"
#include "myDataProcess.h"

int main(int argc, char *argv[])
{
	vtkOutputWindow::SetGlobalWarningDisplay(0);
    QApplication a(argc, argv);
    MainApplication w;
	// ��Ҫָ��ͼ�����㷨
	// ������drrΪ��
	myDataProcess* dataProcess = new myDataProcess();
	dataProcess->setImageAlgorithm(new itkDrr());
	dataProcess->setRegistrationAlgorithm(new drrRegistration());
	w.setDataProcess(dataProcess);
    w.show();
    return a.exec();
}
