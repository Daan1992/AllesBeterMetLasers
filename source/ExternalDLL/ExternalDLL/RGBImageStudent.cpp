#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	imgVector.resize(0);
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	imgVector.resize(other.getWidth() * other.getHeight());
	for (unsigned i = 0; i < imgVector.size(); i++) {
		imgVector.at(i) = other.getPixel(i);
	}
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	imgVector.resize(width * height);
}

RGBImageStudent::~RGBImageStudent() {
	imgVector.~vector();
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	imgVector.resize(width * height);
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	imgVector.resize(other.getWidth() * other.getHeight());
	for (unsigned i = 0; i < imgVector.size(); i++) {
		imgVector.at(i) = other.getPixel(i);
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	imgVector.at(y * width + x) = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	imgVector.at(i) = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	if (x <= width && y <= height) {
		return imgVector.at(y * width + x);
	}
	return 0;
}

RGB RGBImageStudent::getPixel(int i) const {
	if ((unsigned int)i < imgVector.size()){
		return imgVector.at(i);
	}
	return 0;
}