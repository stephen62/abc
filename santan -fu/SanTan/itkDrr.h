#pragma once
#include <cstdarg>
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkResampleImageFilter.h"
#include "itkCenteredEuler3DTransform.h"
#include "itkNearestNeighborInterpolateImageFunction.h"
#include "itkImageRegionIteratorWithIndex.h"
#include "itkRescaleIntensityImageFilter.h"
#include "itkImageSeriesReader.h"
#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"
#include "itkRayCastInterpolateImageFunction.h"
#include "itkBMPImageIOFactory.h"
#include "itkGiplImageIOFactory.h"
#include "itkImageToVTKImageFilter.h"
#include "ImageAlgorithm.h"
class itkDrr : public ImageAlgorithm
{
public:
	itkDrr();
	~itkDrr();
	void imageProcess(int count, ...);
	void setInputName(const char* input);
	vtkDataObject* getOutput();
	itk::ImageToVTKImageFilter<itk::Image<unsigned char, 3>>::Pointer ivfilter;

private:
	bool isRead;
	itk::ImageSeriesReader< itk::Image< signed short, 3 > >::Pointer reader;
	itk::Image<short, 3>::Pointer image;
	char* input_name;


};

