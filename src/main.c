#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// 2d point struct
typedef struct {
    double x;
    double y; // check on necessary decimal precision 
} point2D;

// what we'll return
typedef struct {
    double pitch_deg; // pitch in degrees
    double roll_deg;
    double pitch_rad; // pithc in radians
    double roll_rad; 
} tilt_angles;