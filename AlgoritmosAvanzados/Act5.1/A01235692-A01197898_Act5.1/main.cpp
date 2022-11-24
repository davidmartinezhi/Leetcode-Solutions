/*
Act5.1
Using the backtracking algorithm, build a C++ program to determine the path of the knight's 
piece from the chess game (Knight's tour)

INPUT:
The program receives an integer n which representes a board with size ,
followed by two numbers in the next line. Those two numbers represent the initial position  
(X,Y) of the Knight in the board in an empty board.
Move the piece according to the rules of the chess, knight must visit each cell exactly once.

OUTPUT:
The board showing the order in which each cell is visited.

David Gerardo Martinez Hidrogo - A01235692 
Humberto Ricardo Rodriguez Ruan - A01197898

Created: Nov 24, 2022 01:50pm    Last Modification: 
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){

    //Declare variables
    int n;
    int x, y;

    //Get input
    cin >> n;
    cin >> x >> y;

    //create board
    vector<vector<int> > board(n, vector<int>(n, -1));

    //call knights tour algorithm

    
    return 0;
}

