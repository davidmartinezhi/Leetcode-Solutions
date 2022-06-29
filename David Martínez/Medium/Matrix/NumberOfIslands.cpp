#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        /*
        info:
            input: matrix m*n, with "1" and "0" 1 represents land and 0 represents water
            output: return number of islands
            
            islands are surrounded by water and connected horizaontally and vertically
            
            constraints:
                 length betwwen 1 and 300
            
        example:
             Input: grid = [
                  ["1","1","1","1","0"],
                  ["1","1","0","1","0"],
                  ["1","1","0","0","0"],
                  ["0","0","0","0","0"]
                ]
                -> 1
                
            Input: grid = [
              ["1","1","0","0","0"],
              ["1","1","0","0","0"],
              ["0","0","1","0","0"],
              ["0","0","0","1","1"]
            ]
                -> 3
                
        brute force
            DFS for every one
        
        optimize
            Array of pairs
            which uses Disjoint Set
            
            
        */
        
        //brute force
        
        //declare variables
        int counter = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        //traverse
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == '1'){
                    checkAdj(grid, row, col, rows, cols);
                    counter++;
                }
            }
        }
        
        return counter;
    }
    
    //check horizontal and vertical adj
    void checkAdj(vector<vector<char>>& grid, int row, int  col, int & rows, int & cols){
        
        //base case
        if(row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != '1') return;
        
        //mark current cell as visited
        grid[row][col] = '2';
        
        //recursive call to adjacent directions
        checkAdj(grid, row + 1, col, rows, cols); //down
        checkAdj(grid, row, col + 1, rows, cols); //right
        checkAdj(grid, row - 1, col, rows, cols); //top
        checkAdj(grid, row, col - 1, rows, cols); //left
        
    }
};