/*
Author: Daan Leijen
*/

#pragma once
#include "IntensityImageStudent.h"

class dynamicThresholdFilter
{
public:
	dynamicThresholdFilter();
	~dynamicThresholdFilter();
	IntensityImageStudent filterImage(const IntensityImage &image);
};

