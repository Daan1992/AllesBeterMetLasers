/*
Author: Daan Leijen
*/

#pragma once
#include "IntensityImageStudent.h"
#include <vector>

class highPassFilter
{
public:
	highPassFilter();
	~highPassFilter();
	IntensityImageStudent filterImage(const IntensityImage &image);
private:
	std::vector<char> filterKernel;
};
