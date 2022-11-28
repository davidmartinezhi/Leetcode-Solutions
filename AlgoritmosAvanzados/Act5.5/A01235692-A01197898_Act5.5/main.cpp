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
#include <unordered_map>
#include <sstream>
using namespace std;


int main(){

    //Declare variables
    int n; //board dimentions
    vector<vector<int> > maze; //maze
    int input;
    
    //Get input
    cin >> n;

    for(int i = 0; i < n; i++){
        maze.push_back(vector<int>(0));
        for(int j = 0; j < n; j++){
            cin >> input;
            cout << input << " ";
            maze[i].push_back(input);
        }
        cout << endl;
    }

    return 0;
}
