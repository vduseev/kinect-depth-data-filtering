#include "filters.h"
#include "ctmf.h"
#include "gradientfilter.h"
#include "drsfilter.h"
#include "fmm.h"

Filters::Filters(int width, int height, int history_capacity)
{	
	tmpData	= new unsigned char [width * height];
	DRSFilterInitialize(history_capacity, width * height);
}

void Filters::Apply(
	unsigned char* src, unsigned char* dst,
	int width, int height,
	bool filtrate_flickering, bool filtrate_zero, bool use_median, bool use_fmm,
	int median_radius,
	int flickering_history_depth,
	int flickering_delta)
{
	if (filtrate_flickering) {
		DRSFilter(src, tmpData, flickering_delta, flickering_history_depth);
	}
	else {
		justcpyarr(src, tmpData, width, height);
	}

	if (filtrate_zero) {
		GradientFilter(tmpData, width, height);
	}	

	if (use_fmm) {
		unsigned char* mask = new unsigned char[width * height];
		for (int i = 0; i < width * height; i++)
		{
			if (tmpData[i] == 0) {
				mask[i] = 0;
			}
			else {
				mask[i] = 255;
			}
		}
		FFMrun(mask, tmpData, width, height);
		delete mask;
	}

	// медиан фильтр
	if (use_median) {
		ctmf(tmpData, dst, width, height, width, width, median_radius, 1, 512 * 1024);				
	}
	else {
		justcpyarr(tmpData, dst, width, height);
	}	
}

Filters::~Filters()
{
	delete tmpData;
	DRSFilterDestruct();
}

void Filters::justcpyarr(unsigned char *src, unsigned char *dst, int width, int height)
{
	for (int i = 0; i < width * height; i++) {
		dst[i] = src[i];
	}
}