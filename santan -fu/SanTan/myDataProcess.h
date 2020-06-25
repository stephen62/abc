#pragma once
#include "ImageAlgorithm.h"
#include "RegistrationAlgorithm.h"
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

class myDataProcess
{
public:
	myDataProcess();
	~myDataProcess();

	void createXRayReader(const char* filename);
	void setVtkImitateDRR(const char* filename);
	void clearXRayReader();
	void setDRRFile(const char* filename);
	void setImageAlgorithm(ImageAlgorithm* ia);
	void setRegistrationAlgorithm(RegistrationAlgorithm* ra);
	ImageAlgorithm* getImageAlgorithm();
	RegistrationAlgorithm* getRegistrationAlgorithm();
	vtkSmartPointer<vtkBMPReader> getXRayReader();
	vtkSmartPointer<vtkBMPReader> getCTReader();
	vtkSmartPointer<vtkVolume> getDRRVolume();
	std::string getXRayPath();
	std::string getDRRPath();

	void processItkDrr(int count, double rx, double ry, double rz,
		double tx, double ty, double tz,
		double sid, int dx, int dy, double sx, double sy, double threshold);

private:
	vtkSmartPointer<vtkBMPReader> XRayReader;
	vtkSmartPointer<vtkBMPReader> CTReader;
	vtkSmartPointer<vtkVolume> DRRvolume;
	std::string XRayFile;
	std::string DRRFile;
	ImageAlgorithm* algorithm;							//ITK DRR生成类
	RegistrationAlgorithm* registration;				//图像配准算法
};

