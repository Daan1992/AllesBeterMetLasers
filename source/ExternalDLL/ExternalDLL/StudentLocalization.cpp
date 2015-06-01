#define MINIMALDIFFERENCE 10

#include "StudentLocalization.h"
#include "IntensityImageStudent.h"
#include "ImageIO.h"

bool StudentLocalization::stepFindHead(const IntensityImage &image, FeatureMap &features) const {
	//This is where I'd put my localization. IF I HAD ONE

	int * yHistogram = new int[image.getHeight()];
	for (int i = 0; i < image.getHeight(); i++){
		yHistogram[i] = 0;
	}
	int highestVal = 0;

	for (int y = 0; y < image.getHeight(); y++){
		for (int x = 0; x < image.getWidth(); x++){
			if (image.getPixel(x,y) == 0){
				yHistogram[y] = yHistogram[y] + 1;
			}
		}
	}

	for (int i = 0; i < image.getHeight(); i++){
		if (highestVal < yHistogram[i]){
			highestVal = yHistogram[i];
		}

	}

	int topYIndex = 0;
	int i = 1;
	while (yHistogram[i] - yHistogram[i - 1] < MINIMALDIFFERENCE){
		topYIndex++;
		i++;
	}
	

	// Just making an image with the histogram layered on top of it for comparison reasons
	IntensityImageStudent *iImageLayer = new IntensityImageStudent(image);
	for (int i = 0; i < iImageLayer->getHeight(); i++){
		for (int j = 0; j < yHistogram[i]; j++){
			iImageLayer->setPixel(j, i, 0);
		}
	}

	for (int k = 0; k < iImageLayer->getWidth(); k++){
		iImageLayer->setPixel(k, topYIndex, 0);
	}

	ImageIO::saveIntensityImage(*iImageLayer, ImageIO::getDebugFileName("yHistogramLayered.png"));
	delete iImageLayer;
	
	// Building the histogram into an image
	IntensityImageStudent *iImage = new IntensityImageStudent(highestVal, image.getHeight());
	for (int i = 0; i < iImage->getHeight(); i++){
		for (int j = 0; j < yHistogram[i]; j++){
			iImage->setPixel(j, i, 255);
		}
	}
	ImageIO::saveIntensityImage(*iImage, ImageIO::getDebugFileName("yHistogram.png"));
	delete iImage;

	// To-do: Three histograms, one Vertical, Multiple Horizontal, set features to top, left head side and right head side

	// cleanup and stuff

	delete[] yHistogram;
	return false;
}

bool StudentLocalization::stepFindNoseMouthAndChin(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindChinContours(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseEndsAndEyes(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindExactEyes(const IntensityImage &image, FeatureMap &features) const {
	return false;
}