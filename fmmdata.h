#include "fmm.h"

float				inf_;
unsigned char*		flag_; // flag map
float*				dist_; // distance map
int*				index_; // index of point in the narrow band
std::vector<DXY>	narrowBand_; // narrow band heap
int					size_; // narrow band size

//Point3*				frame1;
//unsigned char*		mask0; 
//unsigned char*		mask1;
//float*				flowX;
//float*				flowY;
//float					eps;
//int					rad;

int&			indexOf(const DXY &dxy, int width, int height) { return index_[dxy.y * width + dxy.x]; }
inline float	sqr(float x) { return x * x; }
inline float	intensity(const Point3 &bgr) { return 0.3f*bgr.x + 0.59f*bgr.y + 0.11f*bgr.z; }