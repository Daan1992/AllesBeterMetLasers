/*
Author: Daan Leijen
*/

#define _USE_MATH_DEFINES
#include <math.h>
#include "GaussianFilter.h"
#include <iostream>

GaussianFilter::GaussianFilter(int radius, double sigma):
radius{ radius }, sigma{sigma}
{
	gaussKernel.resize((2 * radius + 1) * (2 * radius + 1));

	//Genereer het gaussianmask
	for (int y = radius; y >= -radius; y--){
		for (int x = -radius; x <= radius; x++){
			gaussKernel[(-y + radius) * (2 * radius + 1) + (x + radius)] = (1 / (2 * M_PI * pow(sigma, 2.0)))*exp(-1 * (((pow(x, 2.0) * pow(y, 2.0)) / (2 * pow(sigma, 2.0)))));
		}
	}

	for each (double val in gaussKernel){
		sum += val;
	}
	std::cout << "\nSum before normalization: " << sum;

	//Normaliseer het gaussianmask
	for (unsigned int i = 0; i < gaussKernel.size(); i++){
		gaussKernel[i] /= sum;
	}

	sum = 0.0;
	for each (double val in gaussKernel){
		sum += val;
	}
	std::cout << "\nSum after normalization: " << sum;
}

GaussianFilter::~GaussianFilter()
{
}

IntensityImageStudent GaussianFilter::applyFilter(const IntensityImage &image)
{
	IntensityImageStudent filteredImage = IntensityImageStudent(image.getWidth() - 2 * radius, image.getHeight() - 2 * radius);
	
	for (int y = 0; y < filteredImage.getHeight(); y++){
		for (int x = 0; x < filteredImage.getWidth(); x++){
			double filteredIntensity = 0.0;
			for (unsigned int i = 0; i < gaussKernel.size(); i++){
				filteredIntensity += gaussKernel[i] * image.getPixel(x + (i % (2 * radius + 1)), y + i / (2 * radius + 1));
			}
			filteredImage.setPixel(x, y, static_cast<Intensity>(filteredIntensity));
		}
	}
	return filteredImage;
}