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

/*
Print a matrix with nxn dimensions
Input: matrix and integer n representing their boards
Ouput: none
complexity:
    time: O(n^2), traversing every row and column
    extra space: O(1)
*/
void printMatrix(vector<vector<int> > & matrix, int & n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

/*
Veifies if the move is valid
I'ts valid if it's in bounds nad the cell has a -1
Input: x coordinate, y coordinate and int matrix representing boards
Ouput: bool
complexity:
    time: O(1)
    extra space: O(1)
 */
bool isValid(int x, int y, vector<vector<int> > &ans, int n) {
    if (x >= 0 && x < n && y >= 0 && y < n && ans[x][y] == -1) {
        return true;
    }
    return false;
}

/*
Check all 8 possible movements, if it's valid and get movements count
Input: 
    1. board matrix,
    2.x coordinate, 
    3.y coordinate, 
    4.rows size and cols size
    5.possible x coordinates array, 
        possibley coordinates array
    6.possible y coordinates array, 
        possibley coordinates array

Ouput: int count of valid movements
Complexity:
    time: O(1)
    extra space: O(1)
 */
int getMovimientos(vector<vector<int> > &ans, int x, int y, int n, int xMove[8], int yMove[8]) {
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        if (isValid((x + xMove[i]), (y + yMove[i]), ans, n)) {
            count++;
        }
    }
    return count;
}

/*
Warnsdorff heuristic
Check all 8 possible movements, move to less possible movements cell
Input: 
    1. board matrix,
    2.x coordinate, 
    3.y coordinate, 
    4.rows size and cols size
    5.possible x coordinates array, 
        possibley coordinates array
    6.possible y coordinates array, 
        possibley coordinates array

Ouput: int count of valid movements
Complexity:
    time: O(n)
    extra space: O(1)
 */
bool warnsdorff(vector<vector<int> > &ans, int *x, int *y, int n, int xMove[8], int yMove[8], int movimiento) {
    // nMoves and new x and y coordinates
    int nMovements, newX, newY;
    
    //Initialize index of coordinate with less possible movements
    int minMovementNumIdx = -1;
    
    //Initialize minimum movements, 8 max
    int minMovementNum = 8;
    
    // Traverse 8 possible movements
    for (int i = 0; i < 8; i++) {
        // Guardamos la nueva x y y
        newX = *x + xMove[i];
        newY = *y + yMove[i];
        
        // get possible movements
        nMovements = getMovimientos(ans, newX, newY, n, xMove, yMove);
        
        // check movement is valid and or its less than current
        if ((isValid(newX, newY, ans, n)) && nMovements < minMovementNum) {
            // De ser asi guardamos el indice de que coordenadas nos dieron el menor
            // numero de movimientos ademas de actualizar el numero minimo de movimientos
            minMovementNumIdx = i;
            minMovementNum = nMovements;
        }
    }
    
    // if no other cell we have reached the end
    if (minMovementNumIdx == -1) {
        return false;
    }
    
    // update new x and y coordinates
    newX = *x + xMove[minMovementNumIdx];
    newY = *y + yMove[minMovementNumIdx];
    
    // Add movement on cell
    ans[newX][newY] = movimiento;
    
    // Update x and y coordinates
    *x = newX;
    *y = newY;
    return true;
}

/*
Create solution matrix
Input: 
    1. int with board dimentions
    2.x coordinate 
    3.y coordinate 

Ouput: int count of valid movements
Complexity:
    time: O(n^2)
    extra space: O(1)
 */
bool findKnightTour(int n, int x, int y) {
    // matrix solution
    vector<vector<int> > ans;
    
    // Init matrix with -1 values
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            temp.push_back(-1);
        }
        ans.push_back(temp);
    }
    
    // Arrays with all possible movements
    int xMove[8] = {1,1,2,2,-1,-1,-2,-2};
    int yMove[8] = {2,-2,1,-1,2,-2,1,-1};
    
    // Set starting position
    ans[x][y] = 0;
    
    // Run movements with all possible movements
    // warnsdorff O(n)
    for (int i = 1; i < n * n; i++) {
        if (warnsdorff(ans, &x, &y, n, xMove, yMove, i) == 0) {
            return false;
        }
    }
    
    // Print matrix
    printMatrix(ans, n);
    return true;
}


int main(){

    //Declare variables
    int n;
    int x, y;

    //Get input
    cin >> n;
    cin >> x >> y;

    //call knights tour algorithm
    findKnightTour(n, x, y);

    
    return 0;
}

