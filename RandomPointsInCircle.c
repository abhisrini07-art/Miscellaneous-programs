#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x, y, r;
    int n;
    unsigned int seed;
    float x1 = 0, y1 = 0, xd = 0, yd = 0;

    printf("Give values for the centre x, y, the radius, the number of random points, and a seed: ");
    scanf("%f, %f, %f, %d, %u", &x, &y, &r, &n, &seed);   // Input from user

    srand(seed);  // seed only once

    for (int i = 0; i < n; i++)
    {
        xd = ((float)rand() / RAND_MAX) * r * (rand() % 2 ? 1 : -1);                       // random x offset within radius
        yd = ((float)rand() / RAND_MAX) * sqrtf(r * r - xd * xd) * (rand() % 2 ? 1 : -1);

        x1 = x + xd;  // Offset added to the centre
        y1 = y + yd;

        printf("(%f, %f)\n", x1, y1);  // The random point displayed
    }

    return 0;
}
