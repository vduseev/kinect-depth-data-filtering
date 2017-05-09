#ifndef _FMM_H
#define _FMM_H

#include <stdlib.h>
#include <cmath>
#include <queue>
#include <algorithm>

enum { INSIDE = 0, BAND = 1, KNOWN = 255 };

struct DXY
{
    float dist;
    int x, y;

    DXY() : dist(0), x(0), y(0) {}
    DXY(float _dist, int _x, int _y) : dist(_dist), x(_x), y(_y) {}
    bool operator <(const DXY &dxy) const { return dist < dxy.dist; }
};

struct Point3
{
	unsigned char x, y, z;
};

float FMMsolve(int x1, int y1, int x2, int y2, int width, int height);

void FFMrun(unsigned char* mask, unsigned char* frame, int width, int height);
void FMMheapUp(int idx, int width, int height);
void FMMheapDown(int idx, int width, int height);
void FMMheapAdd(const DXY &dxy, int width, int height);
void FMMheapRemoveMin(int width, int height);
float* distanceMap();

#endif