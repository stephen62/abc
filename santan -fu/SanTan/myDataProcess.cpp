#include "myDataProcess.h"



myDataProcess::myDataProcess()
{
	DRRFile = "./tmp.bmp";
}


myDataProcess::~myDataProcess()
{
}

void myDataProcess::setDRRFile(const char* filename) {
	DRRFile = filename;
}

void myDataProcess::setImageAlgorithm(ImageAlgorithm * ia)
{
	algorithm = ia;
}

void myDataProcess::setRegistrationAlgorithm(RegistrationAlgorithm * ra)
{
	registration = ra;
}

ImageAlgorithm * myDataProcess::getImageAlgorithm()
{
	return algorithm;
}

RegistrationAlgorithm * myDataProcess::getRegistrationAlgorithm()
{
	return registration;
}

void myDataProcess::createXRayReader(const char * filename)
{
	XRayReader = vtkSmartPointer<vtkBMPReader>::New();
	XRayReader->SetFileName(filename);
	XRayReader->Update();
	XRayFile = filename;
}

void myDataProcess::clearXRayReader()
{
	XRayReader = vtkSmartPointer<vtkBMPReader>::New();
}

vtkSmartPointer<vtkBMPReader> myDataProcess::getXRayReader()
{
	return XRayReader;
}

vtkSmartPointer<vtkBMPReader> myDataProcess::getCTReader()
{
	return CTReader;
}

vtkSmartPointer<vtkVolume> myDataProcess::getDRRVolume()
{
	return DRRvolume;
}

std::string myDataProcess::getXRayPath()
{
	return XRayFile;
}

std::string myDataProcess::getDRRPath()
{
	return DRRFile;
}

void myDataProcess::setVtkImitateDRR(const char * filename)
{
	vtkDICOMImageReader* v16 = vtkDICOMImageReader::New();
	v16->SetDirectoryName(filename);
	v16->Update();

	vtkSmartPointer<vtkFixedPointVolumeRayCastMapper> volumeMapper = vtkSmartPointer<vtkFixedPointVolumeRayCastMapper>::New();
	volumeMapper->SetInputConnection(v16->GetOutputPort());
	volumeMapper->SetBlendModeToComposite();
	vtkSmartPointer<vtkPiecewiseFunction> volumeScalarOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
	//volumeScalarOpacity->AddSegment(100, 0.73, 200, 0.9);
	volumeScalarOpacity->AddPoint(10, 0.0);
	volumeScalarOpacity->AddPoint(50, 0.1);
	volumeScalarOpacity->AddPoint(200, 0.6);
	volumeScalarOpacity->AddPoint(1000, 0.6);
	volumeScalarOpacity->AddPoint(2000, 0.8);
	volumeScalarOpacity->AddPoint(3000, 1);
	vtkSmartPointer<vtkPiecewiseFunction> volumeGradientOpacity =
		vtkSmartPointer<vtkPiecewiseFunction>::New();
	volumeGradientOpacity->AddPoint(0, 0.0);
	volumeGradientOpacity->AddPoint(150, 0.1);
	volumeGradientOpacity->AddPoint(1500, .7);
	volumeGradientOpacity->AddPoint(2000, 1);
	vtkSmartPointer<vtkVolumeProperty> volumeProperty =
		vtkSmartPointer<vtkVolumeProperty>::New();
	volumeProperty->SetScalarOpacity(volumeScalarOpacity);
	volumeProperty->SetGradientOpacity(volumeGradientOpacity);
	volumeProperty->SetInterpolationTypeToLinear();
	//volumeProperty->ShadeOn();
	volumeProperty->SetAmbient(0.4);
	volumeProperty->SetDiffuse(0.6);
	volumeProperty->SetSpecular(0.2);
	DRRvolume = vtkSmartPointer<vtkVolume>::New();
	DRRvolume->SetMapper(volumeMapper);
	DRRvolume->SetProperty(volumeProperty);
}

void myDataProcess::processItkDrr(int count, double rx, double ry, double rz,
	double tx, double ty, double tz,
	double sid, int dx, int dy, double sx, double sy, double threshold)
{
	algorithm->imageProcess(15, rx, ry, rz, tx, ty, tz, sid, dx, dy, sx, sy, threshold);
	vtkImageCast * imgCast = vtkImageCast::New();
	imgCast->SetInputData(algorithm->getOutput());
	imgCast->SetOutputScalarTypeToUnsignedChar();
	vtkBMPWriter* writer = vtkBMPWriter::New();
	writer->SetInputConnection(imgCast->GetOutputPort());
	writer->SetFileName(DRRFile.data());
	writer->Write();
	writer->Update();
	CTReader = vtkSmartPointer<vtkBMPReader>::New();
	CTReader->SetFileName(DRRFile.data());
	CTReader->Update();
}
