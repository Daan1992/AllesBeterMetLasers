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
	for (int y = 0; y < targetImage->getHeight(); y++){
		for (int x = 0; x < targetImage->getWidth(); x++){
			double x_source = x / scale; double y_source = y / scale;

			int leftX = static_cast<int>(floor(x_source)); int rightX = leftX + 1;
			double weightX = x_source - leftX;

			int topY = static_cast<int>(floor(y_source)); int bottomY = topY + 1;
			double weightY = y_source - topY;

			double topLeft = image.getPixel(leftX, topY) * (1 - weightX) * (1 - weightY);
			double bottomLeft = image.getPixel(leftX, bottomY) * (1 - weightX) * weightY;
			double topRight = image.getPixel(rightX, topY) * weightX * (1 - weightY);
			double bottomRight = image.getPixel(rightX, bottomY) * weightX * weightY;

			int pixelvalue = static_cast<int>(topLeft + bottomLeft + topRight + bottomRight);
			
			targetImage->setPixel(x, y, static_cast<Intensity>(pixelvalue));
		}
	}

	return targetImage;
}

