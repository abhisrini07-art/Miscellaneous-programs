#include <iostream>
#include <cstdlib>
#include <cmath>
#include "dist_calc.h"

using namespace std;

float dist_calc(int x1, int y1, int x2, int y2)
{
    int x_d = 0;
    int y_d = 0;
    float dist = 0;

    // Getting difference between coordinate values
    x_d = x1 - x2;
    y_d = y1 - y2;

    // Pythagoras: a² + b² = c²
    dist = sqrt(x_d * x_d + y_d * y_d);

    return dist;
}
