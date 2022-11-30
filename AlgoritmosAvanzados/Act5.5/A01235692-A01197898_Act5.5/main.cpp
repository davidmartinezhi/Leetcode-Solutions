/*
Act5.5
Using the A* algorithm , build a C++ program that solves the maze
A maze is given as an n*n  binary array of blocks where the origin point 
is the upper left block, i.e., position (0,0) and the destination point is 
the lower right block, i.e., position (n-1, n-1).

A Bot (virtual agent) will leave the source position and has to reach the 
destination position. The Bot can move in four directions: 
 'U' (up), 'D' (down), 'L' (left), 'R' (right).

 The value of 0 (zero) in a block or cell in the matrix represents that it 
 is locked and cannot be crossed. A value of 1 in a block or cell in the matrix 
 represents that it can be used.

INPUT:
integer n, for matrix dimentions followed by matrix values

OUTPUT:
List of all possible paths that allow to reach (n-1, n-1) position
starting from (0, 0) with the minimum distance. each path should be a string formed
by the directions taken in order to reach (n-1, n-1) position starting from (0, 0)

CONSTRAINTS:
n is the dimentions of the board and is a natural number
followed by n*n filled with (0|1).

David Gerardo Martinez Hidrogo - A01235692 
Humberto Ricardo Rodriguez Ruan - A01197898

Created: Nov 28, 2022 2:03pm    Last Modification: 
*/

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <limits.h>
#include <float.h>
using namespace std;

// Creating a shortcut for int, int pair type
typedef pair<int, int> Pair;
 
// Creating a shortcut for pair<int, pair<int, int>> type
typedef pair<double, pair<int, int> > pPair;

// A structure to hold the necessary parameters
struct Cell {
    // Row and Column index of its parent
    // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
    int parent_i, parent_j;
    // f = g + h
    double f, g, h;
};


bool validMove(vector<vector<int> > maze, int row, int col){
    int n = maze[0].size(); //get board dimentions

    //return false if it's out of range
    if(row < 0 || n <= row || col < 0 || n <= col) return false;

    return true;
}

bool isDest(int row, int col, Pair dest){
    
    if(row == dest.first && col == dest.second) return true;

    return false;
}

/*
Get euclidian distance between two points
Input: Two points
Output: distance between both points

Complexity
    Time: O(1)
    Extra space: O(1)
*/
double calculateHCost(int i, int j, Pair & dest){

    return abs(sqrt((pow(i - dest.first, 2) + pow(j - dest.second, 2))));

}

void tracePath(vector<vector<Cell> > cellInfo, Pair dest){

    //get destination coordinates
    int row = dest.first;
    int col = dest.second;

    stack<Pair> path;

    while(!(cellInfo[row][col].parent_i == row && cellInfo[row][col].parent_j == col)){
        path.push(make_pair(row, col));
        int temp_row = cellInfo[row][col].parent_i;
        int temp_col = cellInfo[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }

    path.push(make_pair(row, col));

    while(!path.empty()){
        pair<int, int> p = path.top();
        path.pop();

        cout << "(" << p.first << "," << p.second << ") " << endl;
    }

    return;
}


void aStarSearch(vector<vector<int> > maze, Pair src, Pair dest){

    int n = maze[0].size(); // board dimentions

    //declare and initialize boards
    vector<vector<bool> > closed(n, vector<bool>(n, false)); // no cell included
    vector<vector<Cell> > cellInfo(n, vector<Cell>(n)); // cell info

    int i, j;

    //fill cell info
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cellInfo[i][j].f = DBL_MAX;
            cellInfo[i][j].g = DBL_MAX;
            cellInfo[i][j].h = DBL_MAX;
            cellInfo[i][j].parent_i = -1;
            cellInfo[i][j].parent_j = -1;
        }
    }

    //initialize parameters of first cell
    i = 0;
    j = 0;
    cellInfo[i][j].f = 0.0;
    cellInfo[i][j].g = 0.0;
    cellInfo[i][j].h = 0.0;
    cellInfo[i][j].parent_i = i;
    cellInfo[i][j].parent_j = j; 

    //create open list with info as <f, <i,j>> f = g+h
    set<pPair> open;

    //put first cell on starting list
    open.insert(make_pair(0.0, make_pair(i, j)));

    //destiny reached flag
    bool foundDest = false;

    while(!open.empty()){

        //get value with smalles f cost and remove from open
        pPair p = *open.begin();
        open.erase(open.begin());

        //get coordinates
        int i = p.second.first;
        int j = p.second.second;

        //add to closed list
        closed[i][j] = true;

        //declare values for succesors
        double g_new, h_new, f_new;

        //up
        if(validMove(maze, i-1, j) == true){

            //if destination is the same as successor
            if(isDest(i-1, j, dest) == true){

                //set parent of setination cell
                cellInfo[i-1][j].parent_i = i;
                cellInfo[i-1][j].parent_j = j;
                tracePath(cellInfo, dest);
                foundDest = true;
                //return;

            }

            //if successor is not on closed list && is not blockage
            else if(closed[i-1][j] == false && maze[i-1][j] == 1){
                g_new = cellInfo[i][j].g + 1.0;
                h_new = calculateHCost(i - 1, j, dest);
                f_new = g_new + h_new;

                //if it not on open or the new f cost is lesser
                if(cellInfo[i-1][j].f == DBL_MAX || cellInfo[i-1][j].f > f_new){

                    //add pair to open
                    open.insert(make_pair(f_new, make_pair(i-1, j)));

                    //update details of this cell
                    cellInfo[i-1][j].f = f_new;
                    cellInfo[i-1][j].g = g_new;
                    cellInfo[i-1][j].h = h_new;
                    cellInfo[i-1][j].parent_i = i;
                    cellInfo[i-1][j].parent_j = j;
                }
            }

        }

        //down
        if(validMove(maze, i+1, j) == true){

            //if destination is the same as successor
            if(isDest(i+1, j, dest) == true){

                //set parent of setination cell
                cellInfo[i+1][j].parent_i = i;
                cellInfo[i+1][j].parent_j = j;
                tracePath(cellInfo, dest);
                foundDest = true;
                //return;

            }

            //if successor is not on closed list && is not blockage
            else if(closed[i+1][j] == false && maze[i+1][j] == 1){
                g_new = cellInfo[i][j].g + 1.0;
                h_new = calculateHCost(i + 1, j, dest);
                f_new = g_new + h_new;

                //if it not on open or the new f cost is lesser
                if(cellInfo[i+1][j].f == DBL_MAX || cellInfo[i+1][j].f > f_new){

                    //add pair to open
                    open.insert(make_pair(f_new, make_pair(i+1, j)));

                    //update details of this cell
                    cellInfo[i+1][j].f = f_new;
                    cellInfo[i+1][j].g = g_new;
                    cellInfo[i+1][j].h = h_new;
                    cellInfo[i+1][j].parent_i = i;
                    cellInfo[i+1][j].parent_j = j;
                }
            }

        }

        //right
        if(validMove(maze, i, j+1) == true){

            //if destination is the same as successor
            if(isDest(i, j+1, dest) == true){

                //set parent of setination cell
                cellInfo[i][j+1].parent_i = i;
                cellInfo[i][j+1].parent_j = j;
                tracePath(cellInfo, dest);
                foundDest = true;
                //return;

            }

            //if successor is not on closed list && is not blockage
            else if(closed[i][j+1] == false && maze[i][j+1] == 1){
                g_new = cellInfo[i][j].g + 1.0;
                h_new = calculateHCost(i, j+1, dest);
                f_new = g_new + h_new;

                //if it not on open or the new f cost is lesser
                if(cellInfo[i][j+1].f == DBL_MAX || cellInfo[i][j+1].f > f_new){

                    //add pair to open
                    open.insert(make_pair(f_new, make_pair(i, j+1)));

                    //update details of this cell
                    cellInfo[i][j+1].f = f_new;
                    cellInfo[i][j+1].g = g_new;
                    cellInfo[i][j+1].h = h_new;
                    cellInfo[i][j+1].parent_i = i;
                    cellInfo[i][j+1].parent_j = j;
                }
            }

        }

        //left
        if(validMove(maze, i, j-1) == true){

            //if destination is the same as successor
            if(isDest(i, j-1, dest) == true){

                //set parent of setination cell
                cellInfo[i][j-1].parent_i = i;
                cellInfo[i][j-1].parent_j = j;
                tracePath(cellInfo, dest);
                foundDest = true;
                //return;

            }

            //if successor is not on closed list && is not blockage
            else if(closed[i][j-1] == false && maze[i][j-1] == 1){
                g_new = cellInfo[i][j].g + 1.0;
                h_new = calculateHCost(i, j-1, dest);
                f_new = g_new + h_new;

                //if it not on open or the new f cost is lesser
                if(cellInfo[i][j-1].f == DBL_MAX || cellInfo[i][j-1].f > f_new){

                    //add pair to open
                    open.insert(make_pair(f_new, make_pair(i, j-1)));

                    //update details of this cell
                    cellInfo[i][j-1].f = f_new;
                    cellInfo[i][j-1].g = g_new;
                    cellInfo[i][j-1].h = h_new;
                    cellInfo[i][j-1].parent_i = i;
                    cellInfo[i][j-1].parent_j = j;
                }
            }
        }
    }

    return;
}

int main(){

    //Declare variables
    int n; //board dimentions
    vector<vector<int> > maze; //maze
    int input;
    
    //Get input
    cin >> n;   //board dimentions

    for(int i = 0; i < n; i++){

        //add row
        maze.push_back(vector<int>(0));

        for(int j = 0; j < n; j++){

            //get input and add to row
            cin >> input;
            maze[i].push_back(input);

        }
    }

    Pair src = make_pair(0,0);
    Pair dest = make_pair(n-1, n-1);


    //call A star method
    aStarSearch(maze, src, dest);

    return 0;
}
