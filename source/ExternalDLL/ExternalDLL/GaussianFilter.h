/*
Author: Daan Leijen
*/

#pragma once
#include "IntensityImageStudent.h"
#include <vector>

class GaussianFilter
{
public:
	//Advice for sigma is 0.8 + 0.3 * (radius - 1)
	GaussianFilter(int radius = 1, double sigma = 0.8);
	~GaussianFilter();
	IntensityImageStudent applyFilter(const IntensityImage &image);
private:
	std::vector<double> gaussKernel;
	int radius;
	double sigma;
	double sum = 0.0;
};

