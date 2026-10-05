#include <iostream>
#include <cstdlib>
#include "nearest_neighbour.h"
#include "dist_calc.h"

using namespace std;

void nearest_neighbour(float route_arr[][3])
{
    cout << "Nearest Neighbour function has been called." << endl;

    //**********************************************************************
    // dist       = distance between two points
    // nrst_dist  = distance to nearest unvisited point
    // crnt_index = index of current point
    // trgt_index = index of closest unvisited point
    //**********************************************************************

    float dist = 0;
    float nrst_dist = 999999;

    int crnt_index = 0;
    int trgt_index = 0;

    // Stores the new route
    float process_arr[6][3] = {};

    // Starting point
    process_arr[0][0] = route_arr[0][0];
    process_arr[0][1] = route_arr[0][1];
    process_arr[0][2] = 0;

    // Find nearest neighbour repeatedly
    for (int i = 1; i < 6; i++)
    {
        // Reset nearest distance for this iteration
        nrst_dist = 999999;
        trgt_index = 0;

        // Check every point
        for (int j = 1; j < 6; j++)
        {
            // Only consider points that haven't been visited
            if (route_arr[j][2] == 0)
            {
                dist = dist_calc(
                    route_arr[crnt_index][0],
                    route_arr[crnt_index][1],
                    route_arr[j][0],
                    route_arr[j][1]
                );

                // Is this the closest point so far?
                if (dist < nrst_dist)
                {
                    nrst_dist = dist;
                    trgt_index = j;
                }
            }
        }

        // Mark selected point as visited
        route_arr[trgt_index][2] = 1;

        // Copy selected point into new route
        process_arr[i][0] = route_arr[trgt_index][0];
        process_arr[i][1] = route_arr[trgt_index][1];
        process_arr[i][2] = nrst_dist;

        // Move to selected point
        crnt_index = trgt_index;
    }

    // Copy the completed route back into route_arr
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            route_arr[i][j] = process_arr[i][j];
        }
    }
}
