#pragma once
#include "IntensityImageStudent.h"

//! Class representing a dynamic threshold filter
/*!
\author Daan Leijen
*/
class dynamicThresholdFilter
{
public:
	dynamicThresholdFilter();
	~dynamicThresholdFilter();
	IntensityImageStudent filterImage(const IntensityImage &image);
};

