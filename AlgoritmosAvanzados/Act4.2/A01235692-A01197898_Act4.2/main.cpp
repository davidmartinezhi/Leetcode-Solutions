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

Created: Nov 16, 2022 8:37pm    Last Modification: Nov 22, 2022 11:22am
*/

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

class Point{

    public:
        string id;
        int x;
        int y;
        Point(): id(""), x(0), y(0) {};
        Point(string ID, int X, int Y): id(ID), x(X), y(Y) {};
};


//global variable
Point p0;

Point nextToTop(stack<Point> &pointStack)
{
    Point p = pointStack.top();
    pointStack.pop();
    Point res = pointStack.top();
    pointStack.push(p);
    return res;
}

/*
Swap point positions
Input: point 1 and point 2
Output: none

Complexity
    time: O(1)
    extra space: O(1)
*/
void swap(Point & p1, Point & p2){
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

/*
Find square of distance between 2 points
Input: Two points
Ouput: Square distance between 2 points

Complexity:
    Time: O(1)
    Extra space: O(1)
*/
int squareDistance(Point & p1, Point & p2){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

/*
Find orientation
Input: Ordered triplet of points
Output: values based on orientation.
    0 --> colinear
    1 --> clockwise
    2 --> counter-clockwise

Complexity
    Time: O(1)
    Extra Space: O(1)
*/
int direction(Point p1, Point & p2, Point & p3) {

    //get direction value
   int val = (p2.y-p1.y)*(p3.x-p2.x)-(p2.x-p1.x)*(p3.y-p2.y);

    //colinear
    if(val == 0){
        return 0;
    }
    //Counter-clockwise direction
    else if(val < 0){
        return 2;
    }
    //clockwise direction
    else{
        return 1;
    }
}

/*
Function for camparation of points

Input: two points
Output: number representing point value

Complexity
    Time: O(1)
    Extra Space: O(1)
*/
int comparePoints(Point & p1, Point & p2){
 
   // Find direction
   int dir = direction(p0, p1, p2);


   //if colinear, check orientations for clockwise os counter clockwise
   if (dir == 0)
     return (squareDistance(p0, p2) >= squareDistance(p0, p1));
 
    //clockwise vs counter-clockwise
   return (dir == 2);
}
/*
class myComparator
{
public:
    int operator() (Point * & p1, Point * & p2){
        
        // Find direction
        int dir = direction(p0, *p1, *p2);


        //if colinear, check orientations for clockwise os counter clockwise
        if (dir == 0)
            return (squareDistance(p0, *p2) >= squareDistance(p0, *p1))? -1 : 1;
        
            //clockwise vs counter-clockwise
        return (dir == 2)? -1: 1;
    }
};
*/

/*
Set Bottom-most and left-most coordinate as first value of points
Input: Points coordinates, and size of the array
Ouput: None

Complexity
    Time: O(n)
    Extra space: O(1)
*/
void setBottomLeftMostPoint(vector<Point> & coordinates, int & n){

    //set first coordinate as smaller coordinate (bottom-left most)
    int bottomY = coordinates[0].y; //minimum y
    int idxBottom = 0; //idx of minimum y

    //traverse coordinates
    for(int i = 1; i < n; i++){

        //get y value
        int y = coordinates[i].y;

        //set data of bottom-most and left-most coordinate
        if((y < bottomY) || (bottomY == y && coordinates[i].x < coordinates[idxBottom].x)){
            bottomY = coordinates[i].y;
            idxBottom = i;
        }
    }

    //set bottom-most point at first index
    swap(coordinates[0], coordinates[idxBottom]);
    
    //set p0 coordinate
    p0 = coordinates[0];
}

/*
Remove all duplicate angle points except the one that is farthest
Input: coordinates vector and size of vector
Output: None

Complexity
    Time: O(n)
    Extra space: O(1)
*/
void removeDuplicateAngles(vector<Point> & coordinates, int n){

    int m = 1;

    for(int i = 1; i < n; i++){

        //remove while angle of i and i+1 is the same with respect to p0
        while(i < n-1 && direction(p0, coordinates[i], coordinates[i+1]) == 0){
            i++;
        }

        //update modified array
        coordinates[m] = coordinates[i];
        m++;

    }

    //remove duplicate values and update size of array
    while(n-m > 0){
        coordinates.pop_back();
        n--;
    }

}

/*
Determine and print the smallest convex polygon (convex hull)
Input: vector of coordinates and integer n that represents it's size
Output: None

Complexity
    Time: O(n log n)
    Extra space: O(n)
*/
vector<Point> convexHull(vector<Point> coordinates, int n){

    vector<Point> convexHullPoints;

    //Sets bottom-most and left-most point
    setBottomLeftMostPoint(coordinates, n);

    //Sort points with respect of bottom-most and left-most coordinate
    //Sort based on biggest polar angle (counterclockwise direction)
    sort(coordinates.begin()+1, coordinates.end(), comparePoints);

    //Remove all duplicate angle points except the one that is farthest
    removeDuplicateAngles(coordinates, n);

    //Check that convex hull can be made, that 3 points exist
    if(n < 3) return convexHullPoints;

    //Create stack and add first 3 points
    stack<Point> pointStack;

    pointStack.push(coordinates[0]);
    pointStack.push(coordinates[1]);
    pointStack.push(coordinates[2]);

    //Process remaining points
    for(int i = 3; i < n; i++){
      while (pointStack.size()>1 && direction(nextToTop(pointStack), pointStack.top(), coordinates[i]) != 2){
        pointStack.pop();
      }
      pointStack.push(coordinates[i]);
    }

    //print points
    //stack<Point> result;

    while(!pointStack.empty()){
        //result.push(pointStack.top());
        convexHullPoints.push_back(pointStack.top());
        pointStack.pop(); 
        
    }
    /*
    while(!result.empty()){
        Point p = result.top();
        result.pop();
        cout << p.id << " ";
    }
    cout << endl;
    */
    return convexHullPoints;
}

int main()
{

    //Declare variables
    int n; //number of points we'll receive
    string id; //coordinates id
    int x, y; //coordinates axis
    vector<Point> coordinates; //coordinates list
    vector<Point> answer;

    //get input
    cin >> n; //number of points

    //receive points
    while(cin >> id){
        cin >> x >> y;
        Point aux = Point(Point(id, x, y));
        coordinates.push_back(aux);

        //cout << "id: " << id << " x: " << x << " y: " << y << endl;
    }

    //get convex hull
    answer = convexHull(coordinates, n);

    for(int i = answer.size() - 1 ; i >= 0; i--){
        cout << answer[i].id << " ";
    }
    cout << endl;

    return 0;
}
