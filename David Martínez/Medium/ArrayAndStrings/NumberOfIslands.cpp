#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    void discoverIslands(vector<vector<char>> & grid, int & rows, int & cols, int row, int col){
        
        //base case, chack that we are in a valid position
        if(row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != '1') return;
        
        //mark position
        grid[row][col] = '2';
        
        //traverse
        discoverIslands(grid, rows, cols, row-1, col); //up
        discoverIslands(grid, rows, cols, row+1, col); //down
        discoverIslands(grid, rows, cols, row, col-1); //left
        discoverIslands(grid, rows, cols, row, col+1); //right
    

    }
    
    int numIslands(vector<vector<char>>& grid) {
        /*
        info
            input: m * n binary grid, represents a map of land(1) and water(0)
            output: number of islands
            constraints: 
                - m, grid rows
                - n grid columns
                - m and n have values in range 1 and 300
                - there are only 0s and 1s in the grid
                - island connections are horizontally or vertically, not diagonal
                
        example
            grid = [
              ["1","1","1","1","0"],
              ["1","1","0","1","0"],
              ["1","1","0","0","0"],
              ["0","0","0","0","0"]
            ]
            -> 1
            
            
            grid = [
              ["1","1","0","0","0"],
              ["1","1","0","0","0"],
              ["0","0","1","0","0"],
              ["0","0","0","1","1"]
            ]
            
            -> 3
            
        brute force
            grid = [
              ["2","2","2","2","0"],
              ["2","2","0","2","0"],
              ["2","2","0","0","0"],
              ["0","0","0","0","0"]
            ]
            -> 0 -> 1
            
            grid = [
              ["2","2","0","0","0"],
              ["2","2","0","0","0"],
              ["0","0","2","0","0"],
              ["0","0","0","2","2"]
            ]
            
            -> 1 -> 2 -> 3
            
            complexity:
                runtime: O(n*m)
                extra space: O(1)
                
        optimize
            best conceivable runtime: O(m*n), traverse the complete grid at least once
            the approach seems optimal
            
            //update
            It must be recursive search
            
        test:
            - no islands
            - all the grid is land
            - multiple islands in grid
            
        
        */
        
        /*
             grid = [
              ["1","1","0","0","0"],
              ["1","1","0","0","0"],
              ["0","0","1","0","0"],
              ["0","0","0","1","1"]
            ]
            
            row = 1
            col = 0
            numOfIslands = 0
        
        
        */
        
        //declare variables
        int rows = grid.size();
        int cols = grid[0].size();
        int numOfIslands = 0;
        
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                
                //if we find an unexplored island
                if(grid[row][col] == '1'){
                    numOfIslands++; //update number of islands
                    discoverIslands(grid, rows, cols, row, col); //discover island
                }
            }
        }
        
        
        return numOfIslands;
    }
};


/*
Complexity
    runtime: O(n*m), we traverse all positions in the grid
    extra space: O(n*m * memory on each recursive call) recursive calls m*n

Trate de hacerlo iterativo pero no salio como solución. Lo que hace más sentido es hacer dfs en
cada nueva isla descubierta, de esta manera se puede hacer una busqueda profunda
de hasta donde se extiende cada isla.

Buen pensamiento sobre el problema y buen manejo del tiempo, pero los test cases me fallaron para hacer
una solución optima desde el principio. Esa key de hacer dfs por cada isla debío de
ser mi indicador sobre el tipo de solución que es.
*/
