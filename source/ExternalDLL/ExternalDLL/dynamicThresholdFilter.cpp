/*
Author: Daan Leijen
*/

#include "dynamicThresholdFilter.h"
#include <iostream>
dynamicThresholdFilter::dynamicThresholdFilter()
{
}

dynamicThresholdFilter::~dynamicThresholdFilter()
{
}

IntensityImageStudent dynamicThresholdFilter::filterImage(const IntensityImage &image)
{
	IntensityImageStudent filteredImage = IntensityImageStudent(image.getWidth(), image.getHeight()); 
	
	double average = 0.0;
	for (int i = 0; i < image.getWidth()*image.getHeight(); i++){
		average += image.getPixel(i);
	}
	average /= image.getWidth()*image.getHeight();

	for (int i = 0; i < image.getWidth()*image.getHeight(); i++){
		filteredImage.setPixel(i, static_cast<Intensity>(255 * (image.getPixel(i) < average*1.05)));
	}
	return filteredImage;
}