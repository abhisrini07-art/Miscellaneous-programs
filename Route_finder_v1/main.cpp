#include <iostream>
#include <cstdlib>
#include <ctime>
#include "nearest_neighbour.h"

using namespace std;

int main()
{
    int points[11][2];

    // Starting point (0,0)
    points[0][0] = 0;
    points[0][1] = 0;

    // Seed random number generator
    srand(time(NULL));

    // Generate 10 random points
    for (int i = 0; i < 10; i++)
    {
        points[i + 1][0] = rand() % 20 + 1;  // X coordinate
        points[i + 1][1] = rand() % 20 + 1;  // Y coordinate
    }

    // Print the points
    for (int i = 1; i < 11; i++)
    {
        cout << "Point " << i << ": ("
             << points[i][0] << ", "
             << points[i][1] << ")" << endl;
    }

    // Asking user to choose desired points
    int user_choice[5];

    cout << "Choose your desired points by entering their index." << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Point " << i + 1 << ": ";
        cin >> user_choice[i];
        cout << endl;
    }

    // Printing user choices
    cout << "This is the index of every point you chose: " << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << user_choice[i] << ", ";
    }

    cout << endl;

    // Indication of input stage's completion
    cout << "***PROCESSING***" << endl;

    /*
        route_arr:
        Column 0 = X coordinate
        Column 1 = Y coordinate
        Column 2 = 0 = not visited
                     1 = visited
    */

    float route_arr[6][3] = {};

    // Starting point
    route_arr[0][0] = 0;
    route_arr[0][1] = 0;
    route_arr[0][2] = 1;

    // Transfer selected points into route_arr
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            route_arr[j + 1][i] = points[user_choice[j]][i];
        }
    }

    // TEST CODE
    /*
    for (int i = 1; i < 6; i++)
    {
        cout << "(" << route_arr[i][0]
             << "," << route_arr[i][1] << ")" << endl;
    }
    */

    // Send array to nearest-neighbour function
    nearest_neighbour(route_arr);

    // Print final route
    cout << endl;
    cout << "The most optimal route is: " << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << "(" << route_arr[i][0] << ","
             << route_arr[i][1] << ")" << endl;
    }

    // Calculate total distance
    float total_dist = 0;

    for (int i = 1; i < 6; i++)
    {
        total_dist = total_dist + route_arr[i][2];
    }

    cout << "Total distance travelled is: "
         << total_dist << endl;

    return 0;
}
