#ifndef _DRSFILTER_H
#define _DRSFFILTER_H

/*
 * Рисуешь пиксель, когда он появился 10 раз.
 */

void DRSFilterInitialize(int history_capacity, int size);
void DRSFilter(unsigned char* src, unsigned char* dst, int data_delta, unsigned int history_scan_depth);
void DRSFilterDestruct();

#endif