#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        /*
        INFO
            input:
                - m*n "heights" representing rectangular idland that borders pacific and atlantic ocean
                - pacific ocean border is on top left and atlanting on right bottom
                - rain can flow to neighbour cells in all directions (n,s,w,e).
                - if neighbour cell height is less than or equal to current cell,
                - water can flow from any cell adjacent to an ocean into the ocean

            output
                - return 2d list of grid coordinates "result"
                - result[i] = [r, c] denotes rain water can flow from cell (r, i) to both oceans

            constraints
                - what range of values coul n and m have? [1, 200]
                - what values could i expect in heights? [0, 100,000]
                - do oceans can always have water flowing from ocean to ocean? i'll assume yes
                - answer needs to be in any specific order?

        EXAMPLE
            heights = [
                [1,2,2,3,5],
                [3,2,3,4,4],
                [2,4,5,3,1],
                [6,7,1,4,5],
                [5,1,1,2,4]]

        BRUTE FORCE

        DFS
            from any cell got to adjacent cells if we reach topLeft and bottomRight return true
            if we get true on both, add it to answer

            complexity:
                runtime: O((n*m)^2)

        optimize
            best conceivable runtime: O(n*m)


                
        test
            all cells connect oceans
            only one cell connects the oceans
        */

        //declare variables
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> flowToBothOceans;

        //traverse matrix
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                bool pacific = false;
                bool atlantic = false;
                reachesBothOceans(heights, rows, cols, pacific, atlantic, row, col, heights[row][col]);
                if(pacific && atlantic){
                    flowToBothOceans.push_back({row, col});
                }
            }
        }

        return flowToBothOceans;
    }

    void reachesBothOceans(vector<vector<int>> & heights, int & rows, int & cols, bool &pacific, bool &atlantic, int row, int col, int prev){

        //base case: check if we reached pacific ocean
        if(row < 0 || col < 0){
            pacific = true;
            return;
        }

        //base case: check if we reached atlantic ocean
        if(row == rows || col == cols){
            atlantic = true;
            return;
        }

        //base case: check if we have reached both oceans
        if(pacific && atlantic) return;

        int curr = heights[row][col];

        //base case: check if curr its greater or equal to last value
        if(curr > prev) return;

        //change value in matrix
        heights[row][col] = INT_MAX;

        //check pacific ocean
        reachesBothOceans(heights, rows, cols, pacific, atlantic, row-1, col, curr); //top
        reachesBothOceans(heights, rows, cols, pacific, atlantic, row+1, col, curr); //bottom
        reachesBothOceans(heights, rows, cols, pacific, atlantic, row, col-1, curr); //left
        reachesBothOceans(heights, rows, cols, pacific, atlantic, row, col+1, curr); //right

        heights[row][col] = curr;


    }
};