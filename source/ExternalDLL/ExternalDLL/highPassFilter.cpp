/*
Author: Daan Leijen
*/

#include "highPassFilter.h"

highPassFilter::highPassFilter()
{
	filterKernel.resize(9);
	for (unsigned int i = 0; i < filterKernel.size(); i++){
		if (i != 4) { //All except center of matrix
			filterKernel[i] = -1;
		}
		else {
			filterKernel[i] = 8;
		}
	}
}


highPassFilter::~highPassFilter()
{
}

IntensityImageStudent highPassFilter::filterImage(const IntensityImageStudent image)
{
	IntensityImageStudent filteredImage = IntensityImageStudent(image.getWidth() - 2, image.getHeight() - 2);

	for (int y = 0; y < filteredImage.getHeight(); y++){
		for (int x = 0; x < filteredImage.getWidth(); x++){
			double filteredIntensity = 0.0;
			for (unsigned int i = 0; i < filterKernel.size(); i++){
				filteredIntensity += filterKernel[i] * (image.getPixel(x + i % 3, y + i / 3) - 128);
			}
			filteredImage.setPixel(x, y, static_cast<Intensity>(filteredIntensity + 128));
		}
	}

	return filteredImage;
}