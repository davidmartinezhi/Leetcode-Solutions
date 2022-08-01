#include <iostream>
#include <vector>

using namespace std;


/*
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around
 and drive west).
You are given the integer capacity and an array trips where trips[i] = [numPassengers_i, from_i, to_i] 
indicates that the ith trip has numPassengers_i passengers 
and the locations to pick them up and drop them off are from_i and to_i respectively. 
The locations are given as the number of kilometers due east from the car's initial location.
Return true if it is possible to pick up and drop off all passengers for all the given trips, 
or false otherwise.


Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false

brute force
    locate overlapse of trips and count the number of passengers
    considering the trips are in ascending order from starting points
    complexity: O(n) time and O(1) extra space



optimize
    this answer is optimal

*/

class Solution{

    public:
        bool tripBool(int & capacity, vector<vector<int>> & trips){

            //declare variables
            vector<int> mergeInterval;
            int currPassengers;
            int i = 0;

            //traverse
            while(i < trips.size()-1){
                mergeInterval = trips[i];
                currPassengers = trips[i][0];

                while(i < trips.size() - 1 && mergeInterval[2] > trips[i+1][1]){

                    currPassengers += trips[i+1][0];
                    if(currPassengers > capacity) return false;

                    i++;
                }
                i++;
            }

            return true;
        }
};

