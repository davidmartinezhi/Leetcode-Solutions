#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        /*
        info
            input: array with coordinates
                   each cell represents point x and y
            
            output: true if point make a stright line, false if not
            
            constraints:
                - coordinates size is between 2 and 1,000
                - all coordinates have x and y
                - each point can have value between -10,000 and 10,000
                - there are no duplicate points
                - are all points in order?
                
        example
           [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
           -> true
           
           [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
           -> false
            
            [2,3], [1,2]
            
            2-1 = 1, 3-2 = 1 [1,1]
            
            [3,4], [2,3]
            
            3-2 = 1, 4-3 = 1 [1,1]
            
            [1,1] [2,2]
            
            2-1 = 1 2-1 = 1 [1,1] 
            
            [2,2] [3,4]
            
            3-2 = 1, 4-2 = 2 [1,2]
            
          brute force
            get difference in distances between points and compare to previous diff
            if they are the same it's a stright line
            
            complexity:
                time: O(n)
                extra spcae: O(1)
                
        optimize
            best case running time: O(n)
            
        walkthourgh
        create array for previous and current points difference
        get difference for first point, in previous array
        
        traverse coordinates until previous to last coordinate
            get differences for current point
            compare with differences from last point
            
            
        test
            one coordinate
            straight line exists
            straight line doesn't exist
        
        */
        
        /*
            [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
            
            [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
            prevC
            currC
        
        
        */
        /*
        //check if there is only one coordinate
        if(coordinates.size() == 1) return true;
        
        //declare varibles
        double currC[2];
        double prevC[2];
        double prev;
        double curr;
        
        //set difference between first 2 coordinates
        prevC[0] = coordinates[1][0] - coordinates[0][0]; //x
        prevC[1] = coordinates[1][1] - coordinates[0][1]; //y
        
        //set slope without 0 division
        if(prevC[0]  == 0){
            prev = 0;
        } else{
            prev = prevC[1]/prevC[0];
        }
        
        
        //traverse the rest of the list
        for(int i = 2; i < coordinates.size(); i++){
            
            //get current point coordinates
            //x
            currC[0] = coordinates[i][0] - coordinates[1][0];
            //y
            currC[1] = coordinates[i][1] - coordinates[1][1]; 
                        
            if(currC[0]  == 0){
                curr = 0;
            } else{
                curr = currC[1]/currC[0];
            }
            
            //check if points are different
            if(curr != prev) return false;           
        }
        
        return true;
        
        */
        //solution Ian
        
        //just 2 coordinates
        if(coordinates.size() == 2) return true;
        
        //get coordinates of first point
        double y0 = coordinates[0][1];
        double x0 = coordinates[0][0];
        
        //get difference between first and second point (slope)
        double dy_0 = coordinates[1][1] - y0;
        double dx_0 = coordinates[1][0] - x0;
        
        //traverse the rest of coordinates
        for(int i = 2; i < coordinates.size(); i++){
            
            //get slope of next and previous slope
            double dx_i = coordinates[i][0] - coordinates[i-1][0];
            double dy_i = coordinates[i][1] - coordinates[i-1][1];
            
            //check if they are the same slope
            //they should give the same result
            if((dx_i*dy_0)!=(dy_i*dx_0)) return false;
        }
        
        return true;
        
    }
};