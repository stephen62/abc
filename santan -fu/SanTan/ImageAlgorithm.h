#pragma once
#include <vtkDataObject.h>
class ImageAlgorithm {
public:
	virtual void imageProcess(int count, ...) = 0;
	virtual void setInputName(const char* input) = 0;
	virtual vtkDataObject* getOutput() = 0;
};