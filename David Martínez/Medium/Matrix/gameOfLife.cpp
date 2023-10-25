#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        /*
        info
            input:
                * board of game of life

                1. live cell with < 2 live neighbors. DIES
                2. live cell with > 3 live neighbors. DIES
                3. live cell with 2-3 live neighbors. LIVES
                4. dead cell with 3 live neighbors. LIVES

            output:
                nest state of board

            constraints:
                * what range of sizes can i get for rows and cols of board [1, 25]
                * only values will be 0 and 1? yes

        example
            board = 
                [
                [0,1,0],
                [0,0,1],
                [1,1,1],
                [0,0,0]
                ]

                [
                [0,1,0],
                [0,0,1],
                [1,1,1],
                [0,0,0]
                ]

            ->  [
                [0,0,0],
                [1,0,1],
                [0,1,1],
                [0,1,0]
                ]

        brute force
            have a copy of board for next generation which will be modified based on information 
            on current board.

            complexity:
                runtime: O(n*m)
                extra space: O(n*m)

        optimize
            best conceivable runtime: O(n*m)

            can memory be improved? 

        test
            * board with single cell
            * board with 2x2 cell
        */

        //get size of board
        int rows = board.size();
        int cols = board[0].size();

        //declare variables
        vector<vector<int>> nextGeneration = board; //next generation board

        //traverse board
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){

                //live neighbours
                int liveNeighbours = getLiveNeighbours(board, rows, cols, row, col);

                //cell is alive
                if(board[row][col] == 1){
                    //check how many live neigbours it has
                    if(liveNeighbours < 2) nextGeneration[row][col] = 0; //less than 2 neighbours
                    else if(liveNeighbours > 3) nextGeneration[row][col] = 0; //more than 3 neighbours
                    else nextGeneration[row][col] = 1; //2-3 neighbours
                }
                //cell is dead
                else{
                    //exactly 3 alive neighbours
                    if(liveNeighbours == 3) nextGeneration[row][col] = 1; 
                    else nextGeneration[row][col] = 0;
                    
                }
            }
        }

        //Set board as its next generation
        board = nextGeneration;

    }

    int getLiveNeighbours(vector<vector<int>> & board, int & rows, int & cols, int row, int col){

        //declare variable
        int neighbours = 0;

/*
                [
                [0,1,0],
                [0,0,1],
                [1,1,1],
                [0,0,0]
                ]

*/

        //check neighbours
        if(row-1 >= 0) neighbours += board[row-1][col]; //up
        if(row+1 < rows) neighbours += board[row+1][col]; //down
        if(col-1 >= 0) neighbours += board[row][col-1]; //left
        if(col+1 < cols) neighbours += board[row][col+1]; //right
        if(row-1 >= 0 && col-1 >= 0) neighbours += board[row-1][col-1]; //top-left
        if(row-1 >= 0 && col+1 < cols) neighbours += board[row-1][col+1]; //top-right
        if(row+1 < rows && col-1 >= 0) neighbours += board[row+1][col-1]; //bottom-left
        if(row+1 < rows && col+1 < cols) neighbours += board[row+1][col+1]; //bottom-right



        return neighbours;
    }
};
/*
time: 38 minutes
complexity:
    runtime: O(n*m)
    extra space: O(n*m)

I came up with a brute force approach with optimal runtime very quickly
and I believe the solution was displayed since the 20 minutes mark
but i took time on the auxiliary function of getting all the neighbours of a cell

Still it was a very fun problem and I'll try on improving the memory usage
by modifying the board instead of creating a new one.
*/
