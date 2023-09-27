#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        /*
        info
            input:
                * non-negative integers array "height" representing elevation map
                * width of each bar is 1

            output:
                * compute how much water it can trap after raining

            constraints:
                * what range of sizes can the array have? [1,20k]
                * what range of values can each height[i] have? [0,100k]

        example
            height = [0,1,0,2,1,0,1,3,2,1,2,1]
                     [0,0,1,0,1,2,1,0,0,1,0,0]
                     [f,t,t,t,t,t,t,f,t,t,t,f]
            -> 6

            height = [0,1,0,2,1,0,1,3,2,1,2,1]
                     [0,0,3,0,0,1,2,0,1,1,0,1]

            height = [4,2,0,3,2,5]
                     [0,2,4,1,2,0]
                     [t,t,t,t,t,f]

        brute force
            have a waterTrapped array and have a visited array
            for each height
                if height has not been visited
                    search for water retention recursively

            traverse waterTrapped array

            recursive call 
                check if we are on out of bounds, return false
                check if number is greater or equal than currMaxHeight, if yes return true

                mark index as visited

                recursive call
                if(recursive call is false) set waterTrapped[i] as 0 and visited as false
                else waterTrapped[i] is maxHeight = maxHeight - height[i]

        complexity:
            runtime: O(n^2)
            extra space: O(n)

        optimize
            best conceivable runtime: O(n)

            using two pointer technique with both pointers at the extremes

            have max on left and right side to represent the maxHeight where we start trapping water
            move pointers
                if pointer is less than max of its side, its trapping water.
                else we are just setting the new wall.


        test
            * limits can't hold water
            * limits can contain water
            * cannot trap any water
        */

        //Declare variables
        int n = height.size();
        int left = 0;
        int right = n-1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        while(left < right){
            
            if(height[left] < height[right]){ //if height at left side is smaller

                //if height is equal or greater than max, set as new max
                if(height[left] >= leftMax) leftMax = height[left]; 
                //if we are not at a new max, we are trapping water
                else water += leftMax - height[left]; 
                left++; //move pointer
            }
            else{ //if height at right side is equal or smaller

                //if height is equal or greater than max, set as new max, we are not trapping water there
                if(height[right] >= rightMax) rightMax = height[right]; 
                //if we are not at a new max, we are trapping water
                else water += rightMax - height[right];
                right--; //move pointer
            }
        }

        return water;
    }
};