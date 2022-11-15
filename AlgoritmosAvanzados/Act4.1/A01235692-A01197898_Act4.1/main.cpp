/*
Act4.1
Using the computational geometry programming technique, 
build a C++ program that implements the algorithm for determining whether two line segments intersect.

INPUT: 
The program receives a set of points located on a Cartesian plane.
with format:
    x1, y1, x2, y2, x3, y3, x4, y4
    x5, y5, x6, y6, x7, y7, x8, y8


OUTPUT:    
True if instersection is present, else false

David Gerardo Martinez Hidrogo - A01235692 
Humberto Ricardo Rodriguez Ruan - A01197898

Created: Nov 15, 2022 3:00pm    Last Modification: Nov 15, 2022 4:09pm
*/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


/*
Calculates relative orientation with cross product relative to each segment
Input: 3 pair of coordinates (x0,y0) (x1,y1) (x2,y2)
Output: return orientation value

Complexity: 
    Time:O(1)
    Extra space: O(1)
*/
double getDirection(pair<int,int> & p0, pair<int,int> & p1, pair<int,int> & p2){

    //get point coordinates values
    double x0, x1, x2, y0, y1, y2;

    //first point
    x0 = p0.first;
    y0 = p0.second;

    //first point
    x1 = p1.first;
    y1 = p1.second;

    //first point
    x2 = p2.first;
    y2 = p2.second;

    return (x1 - x0)*(y2-y0)-(x2-x0)*(y1-y0);
}


/*
Determines if a point is in a segment
Input: 3 pair of coordinates (x0,y0) (x1,y1) (x2,y2)
Output: return if point is in segment (true/false)

Complexity: 
    Time:O(1)
    Extra space: O(1)
*/
bool inSegment(pair<int,int> & p0, pair<int,int> & p1, pair<int,int> & p2){

    //get point coordinates values
    double x0, x1, x2, y0, y1, y2;

    //first point
    x0 = p0.first;
    y0 = p0.second;

    //first point
    x1 = p1.first;
    y1 = p1.second;

    //first point
    x2 = p2.first;
    y2 = p2.second;

    if((min(x0,x1) <= x2 && x2 <= max(x0, x1)) && (min(y0,y1) <= y2 && y2 <= max(y0, y1))) return true;

    return false;
}

/*
Returns if two segments intersect
Input: vector with 4 pair of points (x0,y0) (x1,y1) (x2,y2) (x3,y3)
Output: true/false if segments intersect

Complexity
    Time: O(1)
    Space complexity: O(1)
*/
bool intersection(vector<pair<int,int> > & coordinates){

    //get directions
    double d1 = getDirection(coordinates[2], coordinates[3], coordinates[0]);
    double d2 = getDirection(coordinates[2], coordinates[3], coordinates[1]);
    double d3 = getDirection(coordinates[0], coordinates[1], coordinates[2]);
    double d4 = getDirection(coordinates[0], coordinates[1], coordinates[3]);

    if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) return true;
    else if(d1 == 0 && inSegment(coordinates[2], coordinates[3], coordinates[0])) return true;
    else if(d2 == 0 && inSegment(coordinates[2], coordinates[3], coordinates[1])) return true;
    else if(d3 == 0 && inSegment(coordinates[0], coordinates[1], coordinates[2])) return true;
    else if(d4 == 0 && inSegment(coordinates[0], coordinates[1], coordinates[3])) return true;
    else return false;
}

/*
Return if set of points located on a Cartesian plane intersect

INPUT: 
The program receives a set of points located on a Cartesian plane.
with format:
    x1, y1, x2, y2, x3, y3, x4, y4
    x5, y5, x6, y6, x7, y7, x8, y8

OUTPUT:    
True if instersection is present, else false

COMPLEXITY:
    Time: O(lines*chars in line)
    Extra Space: O(1), No dynammic variable is created
*/
int main()
{
    //declare variables
    int x1, x2, x3, x4, y1, y2, y3, y4;
    string coordinatesString;

    //get cordinates line by line
    while(getline(cin, coordinatesString)){ 

        //receive line as string
        istringstream iss(coordinatesString);

        //converto to numbers and add coordinates. O(n)
        int count = 0;
        int number = 0;
        int sign = 1;

        for(int i = 0; i < coordinatesString.size(); i++){
            
            if(coordinatesString[i] == ','){

                //set value of number
                number = number * sign;

                //point 1
                if(count == 0) x1 = number;
                else if(count == 1) y1 = number;

                //point 2
                else if(count == 2) x2 = number;
                else if(count == 3) y2 = number;

                //point 3
                else if(count == 4) x3 = number;
                else if(count == 5) y3 = number;

                //point 4
                else if(count == 6) x4 = number;
                else if(count == 7) y4 = number;
                

                count++;
                number = 0;
                sign = 1;
                
            }
            else if(coordinatesString[i] == '-'){
                sign = -1;
            }
            else{
                number = (number * 10) + (coordinatesString[i] - '0');
            }
        }

        y4 = number;


        //create pair of coordinates in input
        vector<pair<int,int> > coordinates;

        coordinates.push_back(make_pair(x1, y1));
        coordinates.push_back(make_pair(x2, y2));
        coordinates.push_back(make_pair(x3, y3));
        coordinates.push_back(make_pair(x4, y4));

        //Call function to know if segments intersect
        if(intersection(coordinates)) cout << "True" << endl;
        else cout << "False" << endl;
    }

    return 0;
}
