/*
Act4.2
Using the computational geometry programming technique, build a C++ program that 
implements the algorithm for determining the smallest convex polygon (convex hull) 
on a set of points by applying Graham's Scan algorithm.

The output of the program will be an array of points (vertices) in counterclockwise order that define the convex polygon. 
The array should be output to standard output.

INPUT: 
The program must read a number n, that describes the number of points in a set located
on a Cartesian plane, followed by n points (one per line). Each line represent a point and 
it is described by three elements: an id, the x and y coordinate.


OUTPUT:    
The output of the program will a list of points in counterclockwise order defining the convex polygon. 
The list must be formed only by the ids of the points. 
The order must be the one described in the stack of Graham's Scan algorithm, from botton to top.

David Gerardo Martinez Hidrogo - A01235692 
Humberto Ricardo Rodriguez Ruan - A01197898

Created: Nov 16, 2022 8:37pm    Last Modification: Nov 15, 2022 4:09pm
*/

#include <iostream>
using namespace std;

class Point{
    public:
        int x;
        int y;
        Point(): x(0), y(0) {};
        Point(int X, int Y): x(X), y(Y) {};
};

int main()
{
    
    return 0;
}
