#pragma once
#include "IntensityImageStudent.h"
#include <vector>

//! Class representing a laplacian filter
/*!
\author Daan Leijen
*/
class laplacianFilter
{
public:
	//! Standard Constructor
	laplacianFilter();

	//! Satndard Deconstructor
	~laplacianFilter();

	//! Method that handles applying the filter.
	/*!
		\param image The image the filter should be applied to
		\return The filtered IntensityImage
	*/
	IntensityImageStudent filterImage(const IntensityImage &image);
private:
	std::vector<double> filterKernel;
};

