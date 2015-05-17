/*
Author: Daan Leijen
*/

#pragma once
#include "IntensityImageStudent.h"
#include <vector>

class laplacianFilter
{
public:
	laplacianFilter();
	~laplacianFilter();
	IntensityImageStudent filterImage(const IntensityImageStudent image);
private:
	std::vector<double> filterKernel;
};

