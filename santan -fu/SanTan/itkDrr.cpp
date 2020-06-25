#include "itkDrr.h"



itkDrr::itkDrr()
{
	isRead = false;
}


itkDrr::~itkDrr()
{
}

void itkDrr::setInputName(const char* input) {
	// ���µ���CT���к���Ҫ��reader����������
	reader = nullptr;
	isRead = false;

	//�����������ͣ�ͼ�����ͣ���ά�з�����������ָ��
	typedef signed short PixelType;
	const unsigned int Dimension = 3;
	typedef itk::Image< PixelType, Dimension > ImageType;
	typedef itk::ImageSeriesReader< ImageType > ReaderType;

	//��������д DICOM ͼ �� �� itk::GDCMImageIO����
	//itk::GDCMSeriesFileNames�������ɲ����������������ݵ���Ƭ���ļ�����������
	typedef itk::GDCMImageIO ImageIOType;
	typedef itk::GDCMSeriesFileNames NamesGeneratorType;
	ImageIOType::Pointer gdcmIO = ImageIOType::New();
	NamesGeneratorType::Pointer namesGenerator = NamesGeneratorType::New();

	if (!isRead) {
		bool result = reader.IsNull();
		//���ö�ȡ·��
		//���ļ������������ɱ������ļ����ͱ�д���ļ���
		namesGenerator->SetInputDirectory(input);
		const ReaderType::FileNamesContainer& filenames = namesGenerator->GetInputFileNames();

		//����DICOMͼ��IO����ͱ������ļ������б�
		ReaderType::Pointer reader = ReaderType::New();
		reader->SetImageIO(gdcmIO);
		reader->SetFileNames(filenames);
		try
		{
			reader->Update();
		}
		catch (const itk::ExceptionObject & err)
		{
			std::string strerr = err.GetDescription();
			return;
		}

		image = reader->GetOutput();
		isRead = true;
	}
}

vtkDataObject * itkDrr::getOutput()
{
	return ivfilter->GetOutput();
}

void itkDrr::imageProcess(int count, ...)
{

	bool ok;
	va_list arg_ptr;
	va_start(arg_ptr, count);
	//va_arg(arg_ptr, int);
	// ��任
	float rx = va_arg(arg_ptr, double);
	float ry = va_arg(arg_ptr, double);
	float rz = va_arg(arg_ptr, double);
	// ����任����
	float tx = va_arg(arg_ptr, double);
	float ty = va_arg(arg_ptr, double);
	float tz = va_arg(arg_ptr, double);
	//����������ת����
	float cx = 0;
	float cy = 0;
	float cz = 0;
	//float sid = 400.;
	float sid = va_arg(arg_ptr, double); // Դ���
	int dx = va_arg(arg_ptr, int);//int dx = 501; //������
	int dy = va_arg(arg_ptr, int);//int dy = 501;

	
	float sx = va_arg(arg_ptr, double);//���ؼ��
	float sy = va_arg(arg_ptr, double);


	//2dͶӰλ�� �����޸�
	float o2Dx = 0;
	float o2Dy = 0;
	//��ֵ
	double threshold = va_arg(arg_ptr, double);//double threshold = 0;
	va_end(arg_ptr);
	// Software Guide : BeginLatex
	//
	// Although we generate a 2D projection of the 3D volume for the
	// purposes of the interpolator both images must be three dimensional.
	//
	// Software Guide : EndLatex

	// Software Guide : BeginCodeSnippet
	constexpr unsigned int Dimension = 3;
	using InputPixelType = short;
	using OutputPixelType = unsigned char;

	using InputImageType = itk::Image<InputPixelType, Dimension>;
	using OutputImageType = itk::Image<OutputPixelType, Dimension>;

	// Software Guide : EndCodeSnippet

	// Software Guide : BeginLatex
	//
	// For the purposes of this example we assume the input volume has
	// been loaded into an \code{itk::Image image}.
	//
	// Software Guide : EndLatex

	if (!isRead)
	{
		// ��Ҫ���ļ�
		return;
	}

	// Software Guide : BeginLatex
	//
	// Creation of a \code{ResampleImageFilter} enables coordinates for
	// each of the pixels in the DRR image to be generated. These
	// coordinates are used by the \code{RayCastInterpolateImageFunction}
	// to determine the equation of each corresponding ray which is cast
	// through the input volume.
	//
	// Software Guide : EndLatex

	// Software Guide : BeginCodeSnippet
	using FilterType = itk::ResampleImageFilter<InputImageType, InputImageType>;

	FilterType::Pointer filter = FilterType::New();

	filter->SetInput(image);
	filter->SetDefaultPixelValue(0);
	// Software Guide : EndCodeSnippet

	// Software Guide : BeginLatex
	//
	// An Euler transformation is defined to position the input volume.
	// The \code{ResampleImageFilter} uses this transform to position the
	// output DRR image for the desired view.
	//
	// Software Guide : EndLatex

	// Software Guide : BeginCodeSnippet
	using TransformType = itk::CenteredEuler3DTransform<double>;

	TransformType::Pointer transform = TransformType::New();

	transform->SetComputeZYX(true);

	TransformType::OutputVectorType translation;

	translation[0] = tx;
	translation[1] = ty;
	translation[2] = tz;

	// constant for converting degrees into radians
	const double dtr = (std::atan(1.0) * 4.0) / 180.0;

	
	transform->SetTranslation(translation);
	transform->SetRotation(dtr * rx, dtr * ry, dtr * rz);

	InputImageType::PointType   imOrigin = image->GetOrigin();
	InputImageType::SpacingType imRes = image->GetSpacing();

	using InputImageRegionType = InputImageType::RegionType;
	using InputImageSizeType = InputImageRegionType::SizeType;

	InputImageRegionType imRegion = image->GetBufferedRegion();
	InputImageSizeType   imSize = imRegion.GetSize();

	imOrigin[0] += imRes[0] * static_cast<double>(imSize[0]) / 2.0;
	imOrigin[1] += imRes[1] * static_cast<double>(imSize[1]) / 2.0;
	imOrigin[2] += imRes[2] * static_cast<double>(imSize[2]) / 2.0;

	TransformType::InputPointType center;
	center[0] = cx + imOrigin[0];
	center[1] = cy + imOrigin[1];
	center[2] = cz + imOrigin[2];

	transform->SetCenter(center);

	// Software Guide : EndCodeSnippet

	// Software Guide : BeginLatex
	//
	// The \code{RayCastInterpolateImageFunction} is instantiated and passed the
	// transform object. The \code{RayCastInterpolateImageFunction} uses this
	// transform to reposition the x-ray source such that the DRR image
	// and x-ray source move as one around the input volume. This coupling
	// mimics the rigid geometry of the x-ray gantry.
	//
	// Software Guide : EndLatex

	// Software Guide : BeginCodeSnippet
	using InterpolatorType =
		itk::RayCastInterpolateImageFunction<InputImageType, double>;
	InterpolatorType::Pointer interpolator = InterpolatorType::New();
	interpolator->SetTransform(transform);
	// Software Guide : EndCodeSnippet

	// Software Guide : BeginLatex
	//
	// We can then specify a threshold above which the volume's
	// intensities will be integrated.
	//
	// Software Guide : EndLatex

	// Software Guide : BeginCodeSnippet
	interpolator->SetThreshold(threshold);
	// Software Guide : EndCodeSnippet

	// Software Guide : BeginLatex
	//
	// The ray-cast interpolator needs to know the initial position of the
	// ray source or focal point. In this example we place the input
	// volume at the origin and halfway between the ray source and the
	// screen. The distance between the ray source and the screen
	// is the "source to image distance" \code{sid} and is specified by
	// the user.
	//
	// Software Guide : EndLatex

	// Software Guide : BeginCodeSnippet
	InterpolatorType::InputPointType focalpoint;

	focalpoint[0] = imOrigin[0];
	focalpoint[1] = imOrigin[1];
	focalpoint[2] = imOrigin[2] - sid / 2.;

	interpolator->SetFocalPoint(focalpoint);
	// Software Guide : EndCodeSnippet

	// Software Guide : BeginLatex
	//
	// Having initialised the interpolator we pass the object to the
	// resample filter.
	//
	// Software Guide : EndLatex

	// Software Guide : BeginCodeSnippet
	interpolator->Print(std::cout);

	filter->SetInterpolator(interpolator);
	filter->SetTransform(transform);
	// Software Guide : EndCodeSnippet

	// Software Guide : BeginLatex
	//
	// The size and resolution of the output DRR image is specified via the
	// resample filter.
	//
	// Software Guide : EndLatex

	// Software Guide : BeginCodeSnippet

	// setup the scene
	InputImageType::SizeType size;

	size[0] = dx; // number of pixels along X of the 2D DRR image
	size[1] = dy; // number of pixels along Y of the 2D DRR image
	size[2] = 1;  // only one slice

	filter->SetSize(size);

	InputImageType::SpacingType spacing;

	spacing[0] = sx;  // pixel spacing along X of the 2D DRR image [mm]
	spacing[1] = sy;  // pixel spacing along Y of the 2D DRR image [mm]
	spacing[2] = 1.0; // slice thickness of the 2D DRR image [mm]

	filter->SetOutputSpacing(spacing);

	// Software Guide : EndCodeSnippet

	// Software Guide : BeginLatex
	//
	// In addition the position of the DRR is specified. The default
	// position of the input volume, prior to its transformation is
	// half-way between the ray source and screen and unless specified
	// otherwise the normal from the "screen" to the ray source passes
	// directly through the centre of the DRR.
	//
	// Software Guide : EndLatex

	// Software Guide : BeginCodeSnippet

	double origin[Dimension];

	origin[0] = imOrigin[0] + o2Dx - sx * ((double)dx - 1.) / 2.;
	origin[1] = imOrigin[1] + o2Dy - sy * ((double)dy - 1.) / 2.;
	origin[2] = imOrigin[2] + sid / 2.;

	filter->SetOutputOrigin(origin);
	// Software Guide : EndCodeSnippet

	// create writer

		// Software Guide : BeginLatex
		//
		// The output of the resample filter can then be passed to a writer to
		// save the DRR image to a file.
		//
		// Software Guide : EndLatex

		// Software Guide : BeginCodeSnippet
	itk::GiplImageIOFactory::RegisterOneFactory();
	using RescaleFilterType =
		itk::RescaleIntensityImageFilter<InputImageType, OutputImageType>;
	RescaleFilterType::Pointer rescaler = RescaleFilterType::New();
	rescaler->SetOutputMinimum(0);
	rescaler->SetOutputMaximum(255);
	rescaler->SetInput(filter->GetOutput());

	///////////////
	ivfilter = itk::ImageToVTKImageFilter<OutputImageType>::New();
	ivfilter->SetInput(rescaler->GetOutput());
	ivfilter->Update();
	///////////////
	// Software Guide : EndCodeSnippet

	return;
}
