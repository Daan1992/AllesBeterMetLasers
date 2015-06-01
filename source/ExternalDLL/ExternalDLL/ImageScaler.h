/*
Author: Daan Leijen
*/

#pragma once
#include "IntensityImageStudent.h"
#include <math.h>

class ImageScaler
{
public:
	ImageScaler();
	~ImageScaler();
	IntensityImageStudent * scaleImage(const IntensityImage &image, double scale);
};

