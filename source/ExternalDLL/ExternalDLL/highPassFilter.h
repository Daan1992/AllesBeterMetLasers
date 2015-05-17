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
	IntensityImageStudent filterImage(const IntensityImageStudent image);
private:
	std::vector<char> filterKernel;
};

