#include "ImageScaler.h"
#include <iostream>

ImageScaler::ImageScaler()
{
}

ImageScaler::~ImageScaler()
{
}

IntensityImageStudent * ImageScaler::scaleImage(const IntensityImage &image, double scale)
{
	IntensityImageStudent *targetImage = new IntensityImageStudent(static_cast<int>(ceil(image.getWidth() * scale)), static_cast<int>(ceil(image.getHeight() * scale)));
	
	for (int x = 0; x < targetImage->getWidth(); x++){
		for (int y = 0; y < targetImage->getHeight(); y++){
			double x_source = x / scale; double y_source = y / scale;
			double pixelvalue = image.getPixel(static_cast<int>(floor(x_source)), static_cast<int>(floor(y_source))) * (x_source - floor(x_source)) * (y_source - floor(y_source));
			pixelvalue += image.getPixel(static_cast<int>(floor(x_source)), static_cast<int>(ceil(y_source))) * (x_source - floor(x_source)) * (ceil(y_source) - y_source);
			pixelvalue += image.getPixel(static_cast<int>(ceil(x_source)), static_cast<int>(floor(y_source))) * (ceil(x_source) - x_source) * (y_source - floor(y_source));
			pixelvalue += image.getPixel(static_cast<int>(ceil(x_source)), static_cast<int>(ceil(y_source))) * (ceil(x_source) - x_source) * (ceil(y_source) - y_source);

			std::cout << "\nSetting pixel (" << x << "," << y << ") to value: " << pixelvalue;
			targetImage->setPixel(x, y, static_cast<Intensity>(pixelvalue));
		}
	}

	return targetImage;
}

