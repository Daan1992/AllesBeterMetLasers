#include "StudentPreProcessing.h"
#include "IntensityImageStudent.h"
#include "GaussianFilter.h"
#include "laplacianFilter.h"
#include "dynamicThresholdFilter.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent *iImage = new IntensityImageStudent(image);
	return iImage;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	GaussianFilter gFilter = GaussianFilter(1);
	laplacianFilter lFilter = laplacianFilter();
	IntensityImageStudent *iImage =  &gFilter.applyFilter(image);
	//Returned image has a filled vector, pointer suddenly has empty vector.
	IntensityImageStudent *iImage2 = &lFilter.filterImage(*iImage);
	return iImage2;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	dynamicThresholdFilter dTFilter = dynamicThresholdFilter();
	return &dTFilter.filterImage(image);
}