#pragma once
#include "RegistrationAlgorithm.h"
class drrRegistration :
	public RegistrationAlgorithm
{
public:
	drrRegistration();
	~drrRegistration();
	double getSimilarity();
};

