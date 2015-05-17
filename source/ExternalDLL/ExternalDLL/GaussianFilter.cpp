#define _USE_MATH_DEFINES
#include <math.h>
#include "GaussianFilter.h"

GaussianFilter::GaussianFilter(int radius = 1, double sigma = 1.0):
radius{ radius }, sigma{sigma}
{
	gaussKernel.resize((2 * radius + 1) * (2 * radius + 1));

	//Genereer het gaussianmask
	for (int y = radius; y >= -radius; y++){
		for (int x = -radius; x <= radius; x++){
			gaussKernel[-y * (2 * radius + 1) + x] = (1 / (2 * M_PI * pow(sigma, 2.0)))*exp(-1 * (pow(x, 2.0) * pow(y, 2.0) / (2 * pow(sigma, 2.0))));
			sum += gaussKernel[-y * (2 * radius + 1) + x];
		}
	}

	//Normaliseer het gaussianmask]
	for (int i = 0; i < gaussKernel.size; i++){
		gaussKernel[i] /= sum;
	}
}

GaussianFilter::~GaussianFilter()
{
}

IntensityImageStudent GaussianFilter::applyFilter(const IntensityImageStudent image)
{
	IntensityImageStudent filteredImage = IntensityImageStudent(image.getWidth() - (2 * radius + 1), image.getHeight() - (2 * radius + 1));
	
	for (int y = 0; y < filteredImage.getHeight(); y++){
		for (int x = 0; x < filteredImage.getWidth(); x++){
			double filteredIntensity = 0.0;
			for (int i = 0; i < gaussKernel.size; i++){
				filteredIntensity += gaussKernel[i] * image.getPixel(x + (i % (2 * radius + 1)), y + i / (2 * radius + 1));
			}
			filteredImage.setPixel(x, y, static_cast<Intensity>(filteredIntensity));
		}
	}

	return filteredImage;
}