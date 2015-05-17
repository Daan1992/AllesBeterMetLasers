/*
Author: Daan Leijen
*/

#pragma once
#include "IntensityImageStudent.h"
#include <vector>

class GaussianFilter
{
public:
	GaussianFilter(int radius = 1, double sigma = 1.0);
	~GaussianFilter();
	IntensityImageStudent applyFilter(const IntensityImageStudent image);
private:
	std::vector<double> gaussKernel;
	int radius;
	double sigma;
	double sum = 0.0;
};

