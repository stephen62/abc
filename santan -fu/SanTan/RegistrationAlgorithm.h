#pragma once
#include <vtkDataObject.h>
class RegistrationAlgorithm {
public:
	// �������ƶ�
	virtual double getSimilarity() = 0;
};