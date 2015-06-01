#pragma once
#include "IntensityImageStudent.h"
#include <vector>

//! Class representing a high-pass filter
/*!
\author Daan Leijen
*/
class highPassFilter
{
public:
	//! Standard Constructor
	highPassFilter();

	//! Standard Deconstructor
	~highPassFilter();

	//! Method that handles applying the filter.
	/*!
		\param image The image the filter should be applied to
		\return The filtered IntensityImage 
	*/
	IntensityImageStudent filterImage(const IntensityImage &image);
private:
	std::vector<char> filterKernel;
};

