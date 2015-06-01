#define MINIMALDIFFERENCE 11

#include "StudentLocalization.h"
#include "IntensityImageStudent.h"
#include "ImageIO.h"

bool StudentLocalization::stepFindHead(const IntensityImage &image, FeatureMap &features) const {
	//Making the yHistogram
	int * yHistogram = new int[image.getHeight()];
	for (int i = 0; i < image.getHeight(); i++){
		yHistogram[i] = 0;
	}
	int highestYVal = 0;
	for (int y = 0; y < image.getHeight(); y++){
		for (int x = 0; x < image.getWidth(); x++){
			if (image.getPixel(x,y) == 0){
				yHistogram[y] = yHistogram[y] + 1;
			}
		}
	}
	for (int i = 0; i < image.getHeight(); i++){
		if (highestYVal < yHistogram[i]){
			highestYVal = yHistogram[i];
		}

	}

	//making the xHistogram
	int * xHistogram = new int[image.getWidth()];
	for (int i = 0; i < image.getWidth(); i++){
		xHistogram[i] = 0;
	}
	int highestXVal = 0;
	for (int x = 0; x < image.getWidth(); x++){
		for (int y = 0; y < image.getHeight(); y++){
			if (image.getPixel(x, y) == 0){
				xHistogram[x] = xHistogram[x] + 1;
			}
		}
	}
	for (int i = 0; i < image.getWidth(); i++){
		if (highestXVal < xHistogram[i]){
			highestXVal = xHistogram[i];
		}

	}

	//determining top of head
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
			if (iImageLayer->getPixel(j, i) != 0){
				iImageLayer->setPixel(j, i, 127);
			}
			
		}
	}
	for (int i = 0; i < iImageLayer->getWidth(); i++){
		for (int j = 0; j < xHistogram[i]; j++){
			if (iImageLayer->getPixel(i, j) != 0){
				iImageLayer->setPixel(i, j, 127);
			}
		}
	}

	for (int k = 0; k < iImageLayer->getWidth(); k++){
		iImageLayer->setPixel(k, topYIndex, 0);
	}

	ImageIO::saveIntensityImage(*iImageLayer, ImageIO::getDebugFileName("HistogramLayered.png"));
	delete iImageLayer;
	
	// Building the yHistogram into an image
	IntensityImageStudent *yImage = new IntensityImageStudent(highestYVal, image.getHeight());
	for (int i = 0; i < yImage->getHeight(); i++){
		for (int j = 0; j < yHistogram[i]; j++){
			yImage->setPixel(j, i, 255);
		}
	}
	ImageIO::saveIntensityImage(*yImage, ImageIO::getDebugFileName("yHistogram.png"));
	delete yImage;

	IntensityImageStudent *xImage = new IntensityImageStudent(image.getWidth(), highestXVal);
	for (int i = 0; i < xImage->getWidth(); i++){
		for (int j = 0; j < xHistogram[i]; j++){
			xImage->setPixel(i, j, 255);
		}
	}
	ImageIO::saveIntensityImage(*xImage, ImageIO::getDebugFileName("xHistogram.png"));
	delete xImage;

	// To-do: Three histograms, one Vertical, Multiple Horizontal, set features to top, left head side and right head side

	// cleanup and stuff

	delete[] yHistogram;
	delete[] xHistogram;
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