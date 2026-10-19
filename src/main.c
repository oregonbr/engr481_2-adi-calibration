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

// THE FOLLOWING WAS WHAT VSCODE AUTOMATICALLY GENERATED AFTER I STARTED WRITING
// "spatulaTilt".... IT PROBABLY IS NOT RIGHT!

spatulaTilt calculate_spatula_tilt(double d1, double d2, double d3, point2D s1_xy, point2D s2_xy, point2D s3_xy) {
    
    spatulaTilt result = {0.0, 0.0, 0.0, 0.0};

    // Calculate the differences in distances
    double delta_d12 = d1 - d2;
    double delta_d13 = d1 - d3;

    // Calculate the differences in sensor positions
    double delta_x12 = s2_xy.x - s1_xy.x;
    double delta_y12 = s2_xy.y - s1_xy.y;
    double delta_x13 = s3_xy.x - s1_xy.x;
    double delta_y13 = s3_xy.y - s1_xy.y;

    // !!need to enforce upward-pointing normal vector (+z)!!

    // Calculate pitch and roll angles in radians
    // CHECK THIS!!!
    result.pitch_rad = atan2(delta_d12, sqrt(delta_x12 * delta_x12 + delta_y12 * delta_y12));
    result.roll_rad = atan2(delta_d13, sqrt(delta_x13 * delta_x13 + delta_y13 * delta_y13));

    // Convert to degrees
    // CHECK THIS!!!
    tilt.pitch_deg = tilt.pitch_rad * (180.0 / M_PI);
    tilt.roll_deg = tilt.roll_rad * (180.0 / M_PI);

    return tilt;
}

//-----------------------------------------------------------------------------
//        __   __   __
//     | /__` |__) /__`
//     | .__/ |  \ .__/
//          
//-----------------------------------------------------------------------------

