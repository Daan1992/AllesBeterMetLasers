#include "laplacianFilter.h"


laplacianFilter::laplacianFilter()
{
	filterKernel.resize(9);
	for (unsigned int i = 0; i < filterKernel.size(); i++){
		if (i % 2) {
			filterKernel[i] = 0.5;
		}
		else {
			filterKernel[i] = 8;
		}
	}
}


laplacianFilter::~laplacianFilter()
{
}
