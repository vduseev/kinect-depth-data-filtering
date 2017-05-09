#include "drsfilter.h"
#include "drsfilterdata.h"
#include <math.h>

void DRSFilterInitialize(int history_capacity, int layer_size)
{
	capacity	= history_capacity;
	size		= layer_size;
	history		= new unsigned char[history_capacity * layer_size];
	average		= new unsigned char[layer_size];
}

/* FFilter - Flickering Filter
 * Filter reduces or even eliminates flickering of elements of source data array.				*
 * Flickering filter must be applied to dynamic source array, not static.						*
 * The more history filter keeps, the longer it takes destination array to be affected by		*
 * changes in source array.																		*
 *																								*
 * This filter holds the history of source data in a few layers. It counts average value		*
 * in history for each element. If next value from source is close enough to the average		*
 * then this element can be written in destination array. Otherwise the element from			*
 * destination array stays with old value.														*
 *																								*
 * data_delta			- determines possible difference between new and average values.		*
 * history_scan_depth	- determines many layers of history should filter keep.					*
 *																								*
 * Filter must be initialized with determined size of sorce and destination arrays.				*
 * Obviously, source array should have the same size as destination array.						*
*/
void DRSFilter(unsigned char* src, unsigned char* dst, int data_delta, unsigned int history_scan_depth)
{	
	if (history_scan_depth > capacity) {
		history_scan_depth = capacity;
	}

	for (int i = 0; i < size; i++) {
		unsigned char b = src[i];

		// * 1. –асчЄт среднего значени€ данных с сенсора в этой точке за последние N фреймов	* //
		// * 2. ѕоиск ненулевого значени€ пиксел€ в истории										* //
		bool is_color_pixel = false;
		unsigned int avrg = 0;
		for (int k = 0; k < history_scan_depth; k++) 
		{
			avrg += history[k * size + i];
			if (history[k * size + i] > 0) {
				is_color_pixel = true; // нашли в истории, что этот пиксель был цветным
				//break;
			}
		}
		average[i] = avrg / history_scan_depth;

		// * ћожно записать новое значение только если либо			* //
		// * а) пиксель цветной, либо								* //
		// * б) этот пикесель нулевой на прот€жении всей истории	* //
		//if (b > 0 || b == 0 && !is_color_pixel) {
			// * «аписать значение только если оно совпадает со средним значением за историю	* //
			// * ƒанное условие означает, что в истории должно накопитьс€ новое значение,		* //
			// * чтобы оно могло озаказть вли€ние на конечную картинку							* //
			if (abs(b - average[i]) < data_delta) { 
				dst[i] = b;
			}
		//}

		// —охран€ем историю
		history[layer * size + i] = b;	
	}	

	layer++;
	if (layer == history_scan_depth) {
		layer = 0;
	}
}

void DRSFilterDestruct()
{
	delete	history;
	delete	average;
}
