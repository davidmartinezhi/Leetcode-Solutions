#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
        
        info
            input: m = rows, n = columns grid
            
            robot starts and grid[0][0]
            robot can only move right and down
            
            output: all possible ways to get to bottom right corner
            
            constraints: m and n are both between 1 and 100
            
        example
           Input: m = 3, n = 7
           Output: 28
           
           Input: m = 3, n = 2
           Output: 3 
           
        brute force
            backtracking
                complexity
                    time: O(n!)
                    space: O(m+n)
                    
        optimize
            I think this is the optimal approach
            
        walkthrough
            declare variables
            do backtrack
            
            
            if passed limits return
            if reached goal, count++ and return
            
            for both possible moves
                mark visited cell
                do backtrack
                unmark cell
            
        test
                
        */
        
        //create grid
        //extra space: O(n*m)
        vector<vector<int>> grid(m, vector<int>(n, 1));       
        
        //traverse to fill the gaps
        //time O(n*m)
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                //takes values from left and right and that is the value on each cell
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        
        return grid[m-1][n-1];  //value ends up on the bottom right corner
    }
};

/*
Notes:
    time: rapido con backtracking pero no optimo.

    complexity
        time O(n*m)
        extra space O(n*m)


*/