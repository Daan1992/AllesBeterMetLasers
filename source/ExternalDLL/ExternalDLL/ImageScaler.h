#pragma once
#include "IntensityImageStudent.h"
#include <math.h>

//! The class responsible for image scaling.
/*
Implements bilinear interpolation to achieve scaling.

Author: Daan Leijen
*/
class ImageScaler
{
public:
	//!Standard Constructor
	ImageScaler();

	//!Standard Deconstructor
	~ImageScaler();

	//! Method that implements the actual scaling
	/*!
		\param image The original image to be scaled.
		\param scale The scale desired for the new image
		\return The IntensityImageStudent constructed from the original image scaled to size.
	*/
	IntensityImageStudent * scaleImage(const IntensityImage &image, double scale);
};

