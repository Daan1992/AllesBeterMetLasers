#pragma once
#include "IntensityImageStudent.h"
#include <vector>

//! Class representing a laplacian filter
/*!
\author Daan Leijen
*/
class GaussianFilter
{
public:
	//! Constructor for the Gaussian Filter
	/*!
		\param radius The radius of the mask. 1 generates a 3x3 mask, 2 a 5x5 mask and so forth.
		\param sigma The sigma value for the calculation of the gaussian kernel. Advice for sigma is 0.8 + 0.3 * (radius - 1)
	*/
	GaussianFilter(int radius = 1, double sigma = 0.8);

	//! Standard Deconstructor
	~GaussianFilter();

	//! Method that handles applying the filter.
	/*!
		\param image The image the filter should be applied to
		\return The filtered IntensityImage
	*/
	IntensityImageStudent applyFilter(const IntensityImage &image);
private:
	std::vector<double> gaussKernel;
	int radius;
	double sigma;
	double sum = 0.0;
};

