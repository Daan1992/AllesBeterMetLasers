#define DENOMINATOR 2

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
	//determining the highest Y value
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
	//determining the highest X value
	for (int i = 0; i < image.getWidth(); i++){
		if (highestXVal < xHistogram[i]){
			highestXVal = xHistogram[i];
		}

	}

	//determine top of head
	int topYIndex = 0;
	for (int iTop = 1; iTop < image.getHeight(); iTop++){
		if (yHistogram[iTop] >= highestYVal / DENOMINATOR && topYIndex == 0){
			topYIndex = iTop;
		}
	}
	/*while (iTop != image.getHeight() && yHistogram[iTop] - yHistogram[iTop - 1] < highestYVal / 10 ){
		if (yHistogram[iTop] > highestYVal / 4){
			topYIndex = iTop;
		}
		iTop++;
	}
	*/
	
	//determine left of head
	int leftXIndex = 0;
	for (int iLeft = 1; iLeft < image.getWidth(); iLeft++){
		if (xHistogram[iLeft] >= highestXVal / DENOMINATOR && leftXIndex == 0){
			leftXIndex = iLeft;
		}
	}

	/*while (iLeft != image.getWidth() && xHistogram[iLeft] - xHistogram[iLeft - 1] < highestXVal / 10 ){
		if (xHistogram[iLeft] > highestXVal / 4){
			leftXIndex = iTop;
		}
		iLeft++;
	}
	*/

	//determine right of head
	int rightXIndex = image.getWidth() - 1;
	for (int iRight = image.getWidth() - 2; iRight > 0; iRight--){
		if (xHistogram[iRight] >= highestXVal / DENOMINATOR && rightXIndex == image.getWidth() - 1){
			rightXIndex = iRight;
		}
	}

	/*while (iRight != 0 && xHistogram[iRight] - xHistogram[iRight + 1] < highestXVal / 10 ){
		if (xHistogram[iRight] > highestXVal / 4){
			rightXIndex = iTop;
		}
		iRight--;
	}
	*/

	//determine middle of head
	int middleXIndex = leftXIndex + (rightXIndex - leftXIndex) / 2;

	// Image for testing reasons, to visually confirm the values set by the localization
	IntensityImageStudent *iImageLayer = new IntensityImageStudent(image);
	//create the yHistogram on the y axis
	for (int i = 0; i < iImageLayer->getHeight(); i++){
		for (int j = 0; j < yHistogram[i]; j++){
			if (iImageLayer->getPixel(j, i) != 0){
				iImageLayer->setPixel(j, i, 127);
			}
		}
	}
	//create the xHistogram on the x axis
	for (int i = 0; i < iImageLayer->getWidth(); i++){
		for (int j = 0; j < xHistogram[i]; j++){
			if (iImageLayer->getPixel(i, j) != 0){
				iImageLayer->setPixel(i, j, 127);
			}
		}
	}
	//draw a line on top of the head
	for (int k = 0; k < iImageLayer->getWidth(); k++){
		iImageLayer->setPixel(k, topYIndex, 0);
	}

	//draw a line on the left side of the head
	for (int k = 0; k < iImageLayer->getHeight(); k++){
		iImageLayer->setPixel(leftXIndex, k, 0);
	}
	
	//draw a line on the right side of the head
	for (int k = 0; k < iImageLayer->getHeight(); k++){
		iImageLayer->setPixel(rightXIndex, k, 0);
	}

	//draw a line in the middle of the head
	for (int k = 0; k < iImageLayer->getHeight(); k++){
		iImageLayer->setPixel(middleXIndex, k, 0);
	}
	
	//set top of head to white pixel
	iImageLayer->setPixel(middleXIndex, topYIndex, 255);

	//save the test image
	ImageIO::saveIntensityImage(*iImageLayer, ImageIO::getDebugFileName("HistogramLayered.png"));
	
	
	// Building the yHistogram into an image
	IntensityImageStudent *yImage = new IntensityImageStudent(highestYVal, image.getHeight());
	for (int i = 0; i < yImage->getHeight(); i++){
		for (int j = 0; j < yHistogram[i]; j++){
			yImage->setPixel(j, i, 255);
		}
	}
	ImageIO::saveIntensityImage(*yImage, ImageIO::getDebugFileName("yHistogram.png"));
	

	// Building the xHistogram into an image
	IntensityImageStudent *xImage = new IntensityImageStudent(image.getWidth(), highestXVal);
	for (int i = 0; i < xImage->getWidth(); i++){
		for (int j = 0; j < xHistogram[i]; j++){
			xImage->setPixel(i, j, 255);
		}
	}
	ImageIO::saveIntensityImage(*xImage, ImageIO::getDebugFileName("xHistogram.png"));
	
	//features

	Feature headTop = Feature(Feature::FEATURE_HEAD_TOP, Point2D<double>(topYIndex, middleXIndex));
	features.putFeature(headTop);



	// cleanup and stuff
	delete iImageLayer;
	delete yImage;
	delete xImage;
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