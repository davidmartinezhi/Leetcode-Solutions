#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        /*
        info
            input:
                * integer array "ratings" representing rating of children standing in line
                * each children must have at least one candy
                * children with higher rating get more candies than their neighbors

            output:
                * minimum number of candies you need to have to distribute the candies

            constraints:
                * what range of sizes can the array have? [1,20k]
                * what range of values can ratings have? [0, 20k]

        example
            ratings = [1,0,2]
            candies = [2,1,2]
            -> 5

            ratings = [1,2,2]
            candies = [1,2,1]
            ->4

            ratings = [1,1,1]
            candies = [1,1,1]
            -> 3

            ratings = [2,2,2,2]
            candies = [1,1,1,1]
            ->4        

            ratings = [1,2,2,2]
                    = [1,2,1,1]
            candies = [1,2,1,1]
            ->5 

            ratings = [1,2,2,2,3,3,3,4]   
                    = [1,2,1,1,2,3]
            -> 10

        brute force
            sort array
            once we find a new number we increment 1 from the previous, 
            if number is the same as previous number, set it as 1

            complexity
                runitme: O(n log n)
                extra space: O(1)

        optimize
            best conceivable runtime: O(n)

            bottleneck: sorting

            can it be improved?

            well ioutput depends on order of input

            maybe if we dont sort, can the same logic work?

            ratings = [1,0,-1]
                    = []
                      [3,2,1]

                      check middle value
                      add 1 candy
                      if left is greater add candy until it surpasses middle
                      if right is less than left, add 1 to middle and left
 

        test
            * numbers are not in order
            * numbers are in order


        */

        //declare variables
        int n = ratings.size();
        vector<int> candies(n,1);
        int totalCandies = 0;

        /*
        ratings = [1,0,2]
                  [0,0,0]
        */

        //traverse array: left to right
        for(int i = 1; i < n; i++){
            //check if current value is greater than previous
            if(ratings[i-1] < ratings[i]){
                candies[i] = candies[i-1] + 1;
            }
        }

        //traverse array: right to left
        for(int i = n-2; i >= 0; i--){
            //check if current value is greater than previous one
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1]+1);
            }

        }

        //count candies
        for(int c : candies){
            totalCandies += c;
        }

        return totalCandies;
    }
};