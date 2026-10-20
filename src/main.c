//-----------------------------------------------------------------------------
//      __   ___  ___         ___  __
//     |  \ |__  |__  | |\ | |__  /__`
//     |__/ |___ |    | | \| |___ .__/
//
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

// struct f/ 2D point location (might need 3D struct in future depending on laser mounting)
typedef struct {
    double x;
    double y;
} point2D;

// output structure for pitch and roll angles
// might not need radians but ya never know
typedef struct {
    double pitch_deg;
    double roll_deg;
    double pitch_rad;
    double roll_rad;
} spatulaTilt;

//-----------------------------------------------------------------------------
//     ___      __   ___  __   ___  ___  __
//      |  \ / |__) |__  |  \ |__  |__  /__`
//      |   |  |    |___ |__/ |___ |    .__/
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//                __          __        ___  __
//     \  /  /\  |__) |  /\  |__) |    |__  /__`
//      \/  /~~\ |  \ | /~~\ |__) |___ |___ .__/
//
//-----------------------------------------------------------------------------

// Measured distances from sensors to spatula surface
static double d1;
static double d2;
static double d3;

static double s1_xy[2];
static double s2_xy[2];
static double s3_xy[2];

//-----------------------------------------------------------------------------
//      __   __   __  ___  __  ___      __   ___  __
//     |__) |__) /  \  |  /  \  |  \ / |__) |__  /__`
//     |    |  \ \__/  |  \__/  |   |  |    |___ .__/
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//      __        __          __
//     |__) |  | |__) |    | /  `
//     |    \__/ |__) |___ | \__,
//
//-----------------------------------------------------------------------------

//=============================================================================
int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
        
    }
}

//-----------------------------------------------------------------------------
//      __   __              ___  ___
//     |__) |__) | \  /  /\   |  |__
//     |    |  \ |  \/  /~~\  |  |___
//
//-----------------------------------------------------------------------------

spatulaTilt calculate_spatula_tilt(double d1, double d2, double d3, point2D s1_xy, point2D s2_xy, point2D s3_xy) {
    
    // initialize what we';; be returning
    spatulaTilt result = {0.0, 0.0, 0.0, 0.0};

    // Calculate the differences in distances
    double delta_d12 = d1 - d2;
    double delta_d13 = d1 - d3;

    // get  differences in sensor positions
    double delta_x12 = s2_xy.x - s1_xy.x;
    double delta_y12 = s2_xy.y - s1_xy.y;
    double delta_x13 = s3_xy.x - s1_xy.x;
    double delta_y13 = s3_xy.y - s1_xy.y;

    // cross products
    double Nx = delta_y12 * delta_d13 - delta_y13 * delta_d12;
    double Ny = delta_x13 * delta_d12 - delta_x12 * delta_d13;
    double Nz = delta_x12 * delta_y13 - delta_x13 * delta_y12;

    // enforce upward pointing nomral vector
    if (Nz < 0.0) {
        Nx = -Nx;
        Ny = -Ny;
        Nz = -Nz;
    }
   
    // normalize
    double norm_N = sqrt(Nx * Nx + Ny * Ny + Nz * Nz);
    nx = Nx / norm_N;
    ny = Ny / norm_N;
    nz = Nz / norm_N;

    // get phi (roll) and theta (pitch)
    result.roll_rad = asin(nx);
    result.pitch_rad = acos(nz / cos(result.roll_rad));

    // degree conversion
    result.roll_deg = result.roll_rad * (180.0 / M_PI);
    result.pitch_deg = result.pitch_rad * (180.0 / M_PI);

    // return struct
    return result;
}

//-----------------------------------------------------------------------------
//        __   __   __
//     | /__` |__) /__`
//     | .__/ |  \ .__/
//          
//-----------------------------------------------------------------------------

