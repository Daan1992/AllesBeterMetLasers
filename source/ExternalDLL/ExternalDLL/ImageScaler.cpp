#include "ImageScaler.h"


ImageScaler::ImageScaler()
{
}

ImageScaler::~ImageScaler()
{
}

IntensityImageStudent * ImageScaler::scaleImage(const IntensityImage &image, double scale)
{
	//IntensityImageStudent *imageXScaled = new IntensityImageStudent(*scaleX(image, scale));
	IntensityImageStudent *imageScaled = new IntensityImageStudent(*scaleY(image, scale));
	//delete imageXScaled;
	return /imageScaled;
}

IntensityImageStudent * ImageScaler::scaleX(const IntensityImage &image, double scale)
{
	IntensityImageStudent *scaledImage = new IntensityImageStudent(static_cast<int>(ceil(image.getWidth() * scale)) + 1, image.getHeight());
	for (int y = 0; y < image.getHeight(); y++){
		for (int x = 0; x < image.getWidth(); x++){
			double newX = x * scale;
			scaledImage->setPixel(static_cast<int>(floor(newX)), 
				y, 
				scaledImage->getPixel(static_cast<int>(floor(newX)), y) 
				+ static_cast<Intensity>(image.getPixel(x, y) * (1 - (newX - floor(newX)))));
			scaledImage->setPixel(static_cast<int>(ceil(newX)),
				y,
				scaledImage->getPixel(static_cast<int>(ceil(newX)), y)
				+ static_cast<Intensity>(image.getPixel(x, y) * (newX - floor(newX))));
		}
	}
	return scaledImage;
}

IntensityImageStudent * ImageScaler::scaleY(const IntensityImage &image, double scale)
{
	IntensityImageStudent *scaledImage = new IntensityImageStudent(image.getWidth(), static_cast<int>(ceil(image.getHeight() * scale)) + 1);
	for (int x = 0; x < image.getWidth(); x++){
		for (int y = 0; y < image.getHeight(); y++){
			double newY = y * scale;
			scaledImage->setPixel(x,
				static_cast<int>(floor(newY)),
				scaledImage->getPixel(x, static_cast<int>(floor(newY)))
				+ static_cast<Intensity>(image.getPixel(x, y) * (1 - (newY - floor(newY)))));
			scaledImage->setPixel(x,
				static_cast<int>(ceil(newY)),
				scaledImage->getPixel(x, static_cast<int>(ceil(newY)))
				+ static_cast<Intensity>(image.getPixel(x, y) * (newY - floor(newY))));
		}
	}
	return scaledImage;
}
