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
private:
	IntensityImageStudent * scaleX(const IntensityImage &image, double scale);
	IntensityImageStudent * scaleY(const IntensityImage &image, double scale);
};

