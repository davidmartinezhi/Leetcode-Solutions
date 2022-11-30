/*
Act5.7

Build a program that implements the Hill-Climbing algorithm. In the activity of N-Queen was analyzed a way to solve the scenario based on backtracking. 
In this new activity, the solution to the N Queen problem will be implemented using Hill-Climbing.

The problem N Queen is to place N queens of the game of chess on an NxN board so that no queen can attack each other.

INPUT:
Receive a value N, which can be 4 or 8 and applying the Hill-Climbing algorithm must calculate 
the positions where it is possible to place a queen and that none is eaten.

OUTPUT: 
Matrix (of zeros and ones) indicating with a 1 where a queen can be placed

COMPLEXITY: 
O(n^n)


David Gerardo Martinez Hidrogo - A01235692 
Humberto Ricardo Rodriguez Ruan - A01197898

Created: 22/11/22
*/

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

/*
 Function fillBoard that generates the board 
 Input: Vector, integer number, integer number
*/
void fillBoard(vector<vector<int> > &board, int value, int n) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            board[i][j] = value;
        }
    }
}

/*
 Generates a boord based on a given state
 Input: vector with integer vector numbers which is the board, vector with integers numbers which are the states, integer number that is the number of rows and columns in the matrix
*/
void generateBoard(vector<vector<int> > &board, vector<int> &state, int n) {
    // Llamamos funcion auxiliar llenar
    fillBoard(board, 0, n);
    for (int i = 0; i < n; i++) {
        board[state[i]][i] = 1;
    }
}

/*
Random positions
Input: vector with integer vector numbers, vector with integers numbers, integer number

*/
void randomPositions(vector<vector<int> > &board, vector<int> &state, int n) {
    //Configuration for the random function
    srand(time(0));
    
    //Iterate on each column
    for (int i = 0; i < n; i++) {
        //We get some random cell
        state[i] = rand() % n;
        
        // Position the queen in that position
        board[state[i]][i] = 1;
    }
}

/*
 
Prints the generated board
Input: vector with integer vector

Complexity
    O(n^2)

 */
void printBoard(vector<vector<int> > &board, int n) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

/*
Copy the contents of the second state to the first state
Input: vector with integers thats the first state, vector with integers with the second state, integer number which is the number of rows and columns in the matrix
*/
void copyState(vector<int> &state1, vector<int> &state2, int n) {
    for (int i = 0; i < n; i++) {
        state1[i] = state2[i];
    }
}


/*
 
Compare two arrangements that represent the states

Input:  vector with integers thats the first state, vector with integers with the second state, integer number which is the number of rows and columns in the matrix
Output: Boolean

*/
bool compareStates(vector<int> &state1, vector<int> &state2, int n) {
    
    for (int i = 0; i < n; i++) {
        if (state1[i] != state2[i]) {
            return false;
        }
    }
    return true;
}

/*

Calculate which is the queen with the lowest quantity of collisions
Input: vector with integer vector which is the board, vector with integers represents the states, integer number which is the number of rows and columns in the matrix

*/
int calculateOptimalValue(vector<vector<int> > &board, vector<int> &state, int n) {
    // Number of queens that collide is initially 0
    int collisions = 0;
    // Variables of row and column to move on the board
    int row, col;
    // Look at all the possibilities.
    for (int i = 0; i < n; i++) {
        row = state[i];
        col = i - 1;
        while (col >= 0 && board[row][col] != 1) {
            col--;
        }
        if (col >= 0 && board[row][col] == 1) {
            collisions++;
        }
        row = state[i];
        col = i + 1;
        while (col < n && board[row][col] != 1) {
            col++;
        }
        if (col < n && board[row][col] == 1) {
            collisions++;
        }
        row = state[i] - 1;
        col = i - 1;
        while (col >= 0 && row >= 0 && board[row][col] != 1) {
            col--;
            row--;
        }
        if (col >= 0 && row >= 0 && board[row][col] == 1) {
            collisions++;
        }
        row = state[i] + 1;
        col = i + 1;
        while (col < n && row < n && board[row][col] != 1) {
            col++;
            row++;
        }
        if (col < n && row < n && board[row][col] == 1) {
            collisions++;
        }
        row = state[i] + 1;
        col = i - 1;
        while (col >= 0 && row < n && board[row][col] != 1) {
            col--;
            row++;
        }
        if (col >= 0 && row < n && board[row][col] == 1) {
            collisions++;
        }
        row = state[i] - 1;
        col = i + 1;
        while (col < n && row >= 0 && board[row][col] != 1) {
            col++;
            row--;
        }
        if (col < n && row >= 0 && board[row][col] == 1) {
            collisions++;
        }
    }
    
    // Return even
    return (int)(collisions / 2);
}

/*

Gets the neighbor of the current state having the value with fewer collisions
Input: vector with integer vector which is the board, vector with integers represents the states, integer number which is the number of rows and columns in the matrix
Complexity:
    O(n^2)
*/
void getNeighbour(vector<vector<int> > &board, vector<int> &state, int n) {
    // Declare and initialize the board
    vector<vector<int> > optimalBoard(n, vector<int>(n));
    vector<int> optimalState(n);
    copyState(optimalState, state, n);
    generateBoard(optimalBoard, optimalState, n);
    
    // Calculate the value with less collisions
    int optimalValue = calculateOptimalValue(optimalBoard, optimalState, n);
    // Create an array and a temporal matrix to save the neighbors
    vector<vector<int> > tempNeighborBoard(n, vector<int>(n));
    vector<int> tempNeighborState(n);
    copyState(tempNeighborState, state, n);
    generateBoard(tempNeighborBoard, tempNeighborState, n);
    
    // Iterate over each possible neighbor on the board
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            // Check if we can skip the current state
            if (j != state[i]) {
                // Initialize the temporary neighbor state with the actual neighbor
                tempNeighborState[i] = j;
                tempNeighborBoard[tempNeighborState[i]][i] = 1;
                tempNeighborBoard[state[i]][i] = 0;
                
                // Calculate the neighbor collisions
                int temp = calculateOptimalValue(tempNeighborBoard, tempNeighborState, n);
                
                // Compare the collisions of the temporal and the optimal neighbor
                if (temp <= optimalValue) {
                    optimalValue = temp;
                    copyState(optimalState, tempNeighborState, n);
                    generateBoard(optimalBoard, optimalState, n);
                }
                
              
                tempNeighborBoard[tempNeighborState[i]][i] = 0;
                tempNeighborState[i] = state[i];
                tempNeighborBoard[state[i]][i] = 1;
            }
        }
    }
    
    copyState(state, optimalState, n);
    fillBoard(board, 0, n);
    generateBoard(board, state, n);
}

/*
Updates the board depending on the neighbors or fewer collisions
Input:  vector with integer vector which is the board, vector with integers represents the states, integer number which is the number of rows and columns in the matrix
Complexity
    O(n^n)
*/
void hillClimbing(vector<vector<int> > &board, vector<int> &state, int n) {
    
    // Declare and initialize the neighbor board and state with the current board and state as the starting point.
    vector<vector<int> > neighborBoard(n, vector<int>(n));
    vector<int> neighborState(n);
   
    copyState(neighborState, state, n);
    generateBoard(neighborBoard, neighborState, n);
    
    // While loop until the problem is resolved
    do {
       //Copy the neighbor board and state to the current board and current state
        copyState(state, neighborState, n);
        generateBoard(board, state, n);
        
        // Get the optimal neighbor
        getNeighbour(neighborBoard, neighborState, n);
    
        if (compareStates(state, neighborState, n)) {
            printBoard(board, n);
            break;
        } else if (calculateOptimalValue(board, state, n) == calculateOptimalValue(neighborBoard, neighborState, n)) {
            neighborState[rand() % n] = rand() % n;
            generateBoard(neighborBoard, neighborState, n);
        }
        
    } while (true);
}

/*
Print state list
Input: vector with integers
Complexity
    O(n) 
*/
void printState(vector<int> state, int n) {
    
    for (int i = 0; i < n; i++) {
        cout << state[i] << " ";
    }

    cout << endl;
}

int main() {
    // Integer represents the number of rows and columns
    int n;
    
    // Ask for n value
    cin >> n;
    
    vector<vector<int> > board(n, vector<int>(n));
    vector<int> state(n);
    
    // Random board with initial state
    randomPositions(board, state, n);
    
    // Call hillCliming 
    hillClimbing(board, state, n);
    
    return 0;
}
