/*
Descripción breve del programa: Recibe como entrada dos números enteros M y N, seguido de N valores booleanos(0|1) 
separados por un espacio. Después, recibe como entrada dos números enteros: P y Q. 
Donde P representa el precio de un producto dado y Q es el billete o moneda con el que se paga dicho producto.
La salida es una matriz de valores booleanos (0|1) que representa el camino para salir del laberinto.

David Gerardo Martínez Hidrogo - A01235692
Humberto Ricardo Rodriguez Ruán - A01197898

Last modified: Nov 1, 2022
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

/*
Traverse a matrix and prints all values
complexity
    time: O(cols*rows)
    extra space: O(1)
*/
void printMatrix(const vector< vector<int> > & matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
}


// Backtracking 
/*
Checks if current cell in the path is a valid
input: original matrix, rows in matrix, cols in matrix, current row being checked and current col being checked
output: boolean value if cell is valid
complexity:
    time: O(1)
    extra space: O(1)
*/
bool isValid(vector<vector<int> > & matrix, int & rows, int & cols, int row, int col) {
    
    // Check if path is valid and in bounds
    if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row][col] == 1) {
        return true;
    }

    //else return false
    return false;
}

/*
Build unique path in matrix to bottom-right corner
input: original matrix, new matrix, rows in matrix, cols in matrix, current row being checked and current col being checked
output: boolean value if path is valid
complexity
    time: O(n*m) traverse all matrix with backtracking
    extra space: O(n+m) recursive calls to bottom-right corner
*/
bool backtracking(vector<vector<int> > & matrix, vector<vector<int> > & laberinth, int & rows, int & cols, int row, int col) {
    
    //base cases
    //check if we are at the last position of the laberinth
    if (row == rows-1 && col == cols-1 && matrix[row][col] == 1) {
        laberinth[row][col] = 1; // set solution cell as true
        return true;    //return true
    }
    
    // Check if the path is valid
    if (isValid(matrix, rows, cols, row, col)) {

        // If path already part of solution
        if (laberinth[row][col] == 1) {
            return false; //return
        }

        // Add path to our solution
        laberinth[row][col] = 1;
        
        // Move to path one cell down
        if (backtracking(matrix, laberinth, rows, cols, row+1, col)) {
            return true;
        }
        
        // Move to path one cell right
        if (backtracking(matrix, laberinth, rows, cols, row, col+1)) {
            return true;
        }
        
        //if there is no valid path, set cell as 0 and return false
        laberinth[row][col] = 0;
        return false;
    }

    return false;
}


/*
Return matrix with path to bottom-right corner using backtracking
input: original matrix, number of rows and cols in original matrix
output: matrix with valid path represented with 1s
complexity
    time: O(n*m) traverse all matric with backtracking
    extra space: O(n*m) clones the matrix to return a new one with the path
*/
vector<vector<int> > findPathBacktracking(vector<vector<int> > matrix, int rows, int cols) {
    
    //clone smatrix
    vector<vector<int> > laberinth(rows, vector<int>(cols));

    //call backtracking function to get unique path
    backtracking(matrix, laberinth, rows, cols, 0, 0); 

    return laberinth; //return matrix with unique path
}

/*
Return matrix with all possible path to bottom-right corner using branch and bound
input: original matrix, new matrix, flag to know when we found the valid path ,
       rows in matrix, cols in matrix, current row being checked and current col being checked
output: none
complexity
    time: O(n+m)
    extra space: O(n+m) recursive calls
*/
void branchAndBound(vector<vector<int> > & matrix, vector<vector<int> > & laberinth, bool & found, int & rows, int & cols, int row, int col){

    //out of range
    if (row >= rows || row < 0 || col >= cols || col < 0) return;

    //cell is different from 1
    if (matrix[row][col] != 1) return;

    //mark cell as visited, if it's 1
    matrix[row][col] = 2;

    //if it has arrived the bottom-right cell. we found it
    if (row == rows - 1 && col == cols - 1) {
        found = true;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 2) laberinth[i][j] = 1;
                else laberinth[i][j] = 0;
            }
        }
         
        return;
    }

    //vector of distances to vector, depending on direction we move
    vector<pair<double, string> > minDistanceToDestiny(4);

    //distances of columns

    //top
    minDistanceToDestiny[0].first = ((cols - 1 - col) + (rows - 1 - row + 1)) / 2; 
    minDistanceToDestiny[0].second = "arriba";

    //down
    minDistanceToDestiny[1].first = ((cols - 1 - col) + (rows - 1 - row - 1)) / 2; 
    minDistanceToDestiny[1].second = "abajo";

    //left
    minDistanceToDestiny[2].first = ((cols - 1 - col + 1) + (rows - 1 - row)) / 2; 
    minDistanceToDestiny[2].second = "izquierda";

    //right
    minDistanceToDestiny[3].first = ((cols - 1 - col - 1) + (rows - 1 - row)) / 2; 
    minDistanceToDestiny[3].second = "derecha";

    //sort distances from smallest value to greatest
    sort(minDistanceToDestiny.begin(), minDistanceToDestiny.end());

    //traverse list of possible movements, depending on distance to objective
    for(int i = 0; i < 4; i++){

      //top
        if(minDistanceToDestiny[i].second == "arriba"){
            branchAndBound(matrix, laberinth, found, rows, cols, row - 1, col); 
        }
      //down
        else if(minDistanceToDestiny[i].second == "abajo"){
            branchAndBound(matrix, laberinth, found, rows, cols, row + 1, col);   
        }  
      //left
        else if(minDistanceToDestiny[i].second == "izquierda"){
            branchAndBound(matrix, laberinth, found, rows, cols, row , col - 1);  
        }
      //right
        else if(minDistanceToDestiny[i].second == "derecha"){
            branchAndBound(matrix, laberinth, found, rows, cols, row , col + 1);  
        }

      //return true if we have found it
        if(found) return;
    }

    //paths not taken get set to 0
    matrix[row][col] = 0;
}

/*
Return matrix with all possible path to bottom-right corner using branch and bound
input: original matrix, number of rows and cols in original matrix
output: matrix with valid path represented with 1s
complexity
    time: O(n+m)
    extra space: O(n*m) for the cloneation of the amtrix
*/
vector<vector<int> > findPathBranchAndBound(vector<vector<int> > matrix, int rows, int cols){
    
    //clone matrix
    bool found = false;
    vector<vector<int> > laberinth(rows, vector<int>(cols));

    //get laberinth from backtracking
    branchAndBound(matrix, laberinth, found, rows, cols, 0, 0);

    return laberinth;

}

int main() {

    //Declare Variables
    //Matrix dimentions
    int rows;
    int cols;

    cin >> rows;
    cin >> cols;

    vector< vector<int> > laberinth(rows, vector<int>(cols));

    //fill the laberinth matrix
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            int aux;
            cin >> aux;
            laberinth[i][j] = aux;
        }
    }

    //Find paths
    vector< vector<int> > laberinthBacktracking = findPathBacktracking(laberinth, rows, cols);
    vector< vector<int> > laberinthBranchAndBound = findPathBranchAndBound(laberinth, rows, cols);
    
    //print solutions
    printMatrix(laberinthBacktracking);
    cout << endl;
    printMatrix(laberinthBranchAndBound);

    return 0;
}