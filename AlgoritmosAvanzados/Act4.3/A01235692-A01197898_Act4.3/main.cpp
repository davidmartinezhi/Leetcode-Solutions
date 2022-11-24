/*
Act4.3
Implementation of algorithm to determine the closest pair of points in a set of points.


INPUT: 
The program must read a number n, that describes the number of points in a set located on a Cartesian plane, 
followed by n points (one per line). 
Each line represent a point and it is described by three elements: a name, the x, and y coordinate.


OUTPUT:    
The output of the program will be the shortest distance (up to 4 decimals with the last digit rounded, 
not truncated, for example: 1.1661903789690602, then we have with 4 decimals: 1.1662) between 
two points and the corresponding points.

David Gerardo Martinez Hidrogo - A01235692 
Humberto Ricardo Rodriguez Ruan - A01197898

Created: Nov 22, 2022 11:34am    Last Modification: Nov 24, 2022 01:15am
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <limits.h>
#include <float.h>
using namespace std;

class Point{

    public:
        string id;
        double x;
        double y;
        Point(): id(""), x(0), y(0) {}
        Point(string ID, double X, double Y): id(ID), x(X), y(Y) {}
};

/*
Round number to 4 decimal points
Input: number of tye double
Output: number of type double rounded to 4 decimals

Complexity
    time: O(1)
    extra space: O(1)
*/
void roundNumber(double & value){
    value = round(value / 0.0001) * 0.0001;
}

/*
Get euclidian distance between two points
Input: Two points
Output: distance between both points

Complexity
    Time: O(1)
    Extra space: O(1)
*/
double distanceBetweenPoints(Point & p1, Point & p2, Point & P1, Point & P2, double & globalMin){

    double d = abs(sqrt((pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2))));

    if(d < globalMin){
        P1 = p1;
        P2 = p2;

        globalMin = d;
    }

    return d;
}

/*
Get distance between two points on x axis
Input: Two points
Output: distance on x axis between both points

Complexity
    Time: O(1)
    Extra space: O(1)
*/
double distanceBetweenPointsX(Point & p1, Point & p2){
    return abs(p1.x - p2.x);
}

/*
Comparation of points in thesort function of the standard library
Input: two points
Output: boolean value for p1 being smaller than p2 on x axis

Complexity
    Time: O(1)
    Extra Space: O(1)
*/
bool comparePointsX(Point & p1, Point & p2){
   return (p1.x  < p2.x);
}

/*
Comparation of points in thesort function of the standard library
Input: two points
Output: boolean value for p1 being smaller than p2 on x axis

Complexity
    Time: O(1)
    Extra Space: O(1)
*/
bool comparePointsY(Point & p1, Point & p2){
   return (p1.y  < p2.y);
}

/*
Divide and conquer
Input: coordinates vector, reference to global points and reference to global min distance
Output: min distance

Complexity
    Time: O(n log n)
    Extra space: O(n) with the strip
*/
double mergeSearch(vector<Point> points, Point & p1, Point & p2, double & globalMin){

    int n = points.size();

    //Base case
    if(n <= 3){
        double d = DBL_MAX;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(distanceBetweenPoints(points[i], points[j], p1, p2, globalMin) < d){
                    d = distanceBetweenPoints(points[i], points[j], p1, p2, globalMin);
                } 
            } 
        } 
        return d; 
    } 

    //divide
    int mid = n/2;
    Point midPoint = points[mid];

    vector<Point> leftSide;
    vector<Point> rightSide;

    for(int i = 0; i < mid; i++){
        leftSide.push_back(points[i]);
    }
 
    for(int i = mid; i < n; i++){
        rightSide.push_back(points[i]);
    }
 
    //O(n log n)
    double dl = mergeSearch(leftSide, p1, p2, globalMin);
    double dr = mergeSearch(rightSide, p1, p2, globalMin);
 
    double d = min(dl, dr);
 
    //combine points x coordinate are in the range x-d and x+d
    vector<Point> strip;
    for(int i = 0; i < n; i++){ //O(n)
        if(abs(points[i].x - midPoint.x) < d){
            strip.push_back(points[i]);
        }
    }
 
    sort(strip.begin(), strip.end(), comparePointsY); //O(n log n)
 
    //get min in the strip
    for(int i = 0; i < strip.size(); i++){ // O(n)

        //this runs only 6 times always
        for(int j = i+1; j < 7 && (strip[j].y - strip[i].y) < d; j++){
            if(distanceBetweenPoints(strip[i],strip[j], p1, p2, globalMin) < d){
                d = distanceBetweenPoints(strip[i], strip[j], p1, p2, globalMin);
            }                
        }
    }
 
    return d;
}

/*
Convert number id to integer to know order orf points
Input: string id
Output: integer number of id

Complexity
    Time: O(n)
    space: O(n)
*/
int stringToInt(string & id){

    //Get string number
    string auxId = id.substr(1, id.size()-1);
    int num = 0;

    //Transform to integer
    for(int i = 0; i < auxId.size(); i++){
        //get number
        num = (num * 10) + (auxId[i] - '0');
    }

    return num;

}

/*
Determine and print the smallest convex polygon (convex hull)
Input: vector of coordinates and integer n that represents it's size
Output: None

Complexity
    Time: O(n log n)
    Extra space: O(n)
*/
double geometricalSearch(vector<Point> & points, int &  n, Point & p1, Point & p2){

    double globalMin = DBL_MAX - 1;

    //sort points based on x axis in increasing order
    sort(points.begin(), points.end(), comparePointsX);

    //get shortest distance and points
    double minDistance = mergeSearch(points, p1, p2, globalMin);

    //round shortest distance
    roundNumber(globalMin);

    return globalMin;
}

int main(){

    //Declare variables
    int n; //number of points we'll receive
    string id; //coordinates id
    int x, y; //coordinates axis
    vector<Point> points; //coordinates list

    //get input
    cin >> n; //number of points

    //receive points
    while(cin >> id){
        cin >> x >> y;
        Point aux = Point(Point(id, x, y));
        points.push_back(aux);

    }

    //global variables
    Point p1;
    Point p2;
    double minDistance = geometricalSearch(points, n, p1, p2);

    //get id order
    int first = stringToInt(p1.id);
    int second = stringToInt(p2.id);

    if( second < first ){
        Point aux = p1;
        p1 = p2;
        p2 = aux;
    }
    
    cout << minDistance << " " << p1.id << " " << p2.id << endl;

    return 0;
}
