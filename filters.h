#ifndef _FILTERS_H
#define _FILTERS_H

class Filters
{
public:
	Filters(int width, int height, int history_capacity);
	~Filters();	

	void Apply(
		unsigned char* src, unsigned char* dst, 
		int width, int height,
		bool filtrate_flickering, bool filtrate_zero, bool use_median, bool use_fmm,
		int median_radius = 7,
		int flickering_history_depth = 10,
		int flickering_delta = 1);

private:
	unsigned char* tmpData;
	void justcpyarr(unsigned char *src, unsigned char *dst, int width, int height);
};

#endif