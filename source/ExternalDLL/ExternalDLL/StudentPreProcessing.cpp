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
	GaussianFilter gFilter = GaussianFilter(2);
	laplacianFilter lFilter = laplacianFilter();
	return &lFilter.filterImage(gFilter.applyFilter(image));
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	dynamicThresholdFilter dTFilter = dynamicThresholdFilter();
	return &dTFilter.filterImage(image);
}