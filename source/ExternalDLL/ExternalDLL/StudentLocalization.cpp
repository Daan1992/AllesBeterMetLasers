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


	IntensityImageStudent *iImage = new IntensityImageStudent(highestVal, image.getHeight());
	/*
	for (int i = 0; i < iImage->getHeight(); i++){
		for (int j = 0; j < iImage->getWidth(); j++){
			iImage->setPixel(j, i, 255);
		}
	}
	*/
	for (int i = 0; i < iImage->getHeight(); i++){
		for (int j = 0; j < yHistogram[i]; j++){
			//iImage->setPixel(j, i, 0);
			iImage->setPixel(j, i, 255);
		}
	}

	ImageIO::saveIntensityImage(*iImage, ImageIO::getDebugFileName("histogramizzle.png"));
		

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