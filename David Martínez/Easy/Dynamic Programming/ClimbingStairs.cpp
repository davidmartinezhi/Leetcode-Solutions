#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        /*
        info
            input: integer "n"
                it takes n steps to reach the top
                
                each time I climb i can either climb 1 or 2 steps.
            
            output: all disting ways we could reach the top
            
            constrains
                n is in range 1 - 45
                
        example
            
            n = 1
            -> 1
            
            n = 2
            -> 2
            
            n = 3
            -> 3
            
            n = 4
            -> (1+1+1+1) (2+1+1) (1+1+2) (1+2+1) (2+2)
            
            n = 5
            -> (1+1+1+1+1) (2+2+1) (2+1+2) (1+2+2) (2+1+1+1) (1+2+1+1) (1+1+2+1) (1+1+1+2)
            
            Found pattern:
                n = 1 2 3 4 5
                r = 1 2 3 5 8
                
                each result is the sum of both previous results
                
        brute force
            recursive call until auxN is equal to n
            
            each call, return the sum of the two previous values returned
        
            runtime: O(n)
            space: O(n)
            
        optimize
            use array of size 2
            save new value and the previous next value traverse it to the other index
            
            repeat n times
            
            runtime: O(n)
            space: O(1)
            
        test
            n = 1
            n = 2
            n = 3
            n = 5
        
        */
        
        //array
        int steps[2] = {0, 1};
        
        //loop of updates in the array
        for(int i = 0; i < n; i++){
            int newStep = steps[0] + steps[1];
            
            steps[0] = steps[1];
            steps[1] = newStep;
        }
        
        return steps[1];
    }
};