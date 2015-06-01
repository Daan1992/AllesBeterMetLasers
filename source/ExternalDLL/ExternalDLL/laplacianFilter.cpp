/*
Author: Daan Leijen
*/

#include "laplacianFilter.h"
#include <iostream>

laplacianFilter::laplacianFilter()
{
	filterKernel.resize(9);
	for (unsigned int i = 0; i < filterKernel.size(); i++){
		if (i % 2) {
			filterKernel[i] = 1;
		}
		else if (i == 4) {
			filterKernel[i] = -8;
		}
		else {
			filterKernel[i] = 1;
		}
	}
}


laplacianFilter::~laplacianFilter()
{
}


IntensityImageStudent laplacianFilter::filterImage(const IntensityImage &image)
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
	std::cout << "\nLaplacian:" << "\nWidth: " << filteredImage.getWidth() << "Height: " << filteredImage.getHeight() << "\n";
	return filteredImage;
}