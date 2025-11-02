#include <stdio.h>
#include <math.h>

void main()
{
    float xo = 0, yo = 0, xa = 0, ya = 0, xe = 0, ye = 0;  // A few variables defined
    printf("Enter x and y to convert and the reference point's x and y: ");
    scanf("%f %f %f %f", &xa, &ya, &xo, &yo);
    xe = xa-xo;   // Equivalent x and y coords with (0,0) as reference
    ye = ya-yo;
    float theta = atan2(ye, xe), r = sqrtf(xe*xe + ye*ye);   // Theta and radius defined
    printf("\nThe rectangular coordinate form is: (%.3f,%.3f)\nThis was with respect to: (%.3f,%.3f)\nThe polar coordinate form is: (%.3f,%.3f)", xa, ya, xo, yo, theta, r);
}
