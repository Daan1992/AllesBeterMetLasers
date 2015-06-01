#include "StudentPreProcessing.h"
#include "IntensityImageStudent.h"
#include "GaussianFilter.h"
#include "laplacianFilter.h"
#include "dynamicThresholdFilter.h"
#include "highPassFilter.h"
#include "ImageScaler.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent *iImage = new IntensityImageStudent(image);
	return iImage;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	ImageScaler scaler = ImageScaler();
	IntensityImageStudent *iImage = new IntensityImageStudent(*scaler.scaleImage(image, 1));
	return iImage;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	GaussianFilter gFilter = GaussianFilter(3, 1.4);
	laplacianFilter lFilter = laplacianFilter();
	IntensityImageStudent iImage = IntensityImageStudent(gFilter.applyFilter(image)); 
	IntensityImageStudent *iImage2 = new IntensityImageStudent(lFilter.filterImage(iImage));
	return iImage2;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	dynamicThresholdFilter dTFilter = dynamicThresholdFilter();
	IntensityImageStudent *iImage = new IntensityImageStudent(dTFilter.filterImage(image));
	return iImage;
}