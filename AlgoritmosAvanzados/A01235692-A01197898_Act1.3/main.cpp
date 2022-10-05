/*
Descripción breve del programa: Recibe como entrada dos números enteros M y N, seguido de N valores booleanos(0|1) 
separados por un espacio. Después, recibe como entrada dos números enteros: P y Q. 
Donde P representa el precio de un producto dado y Q es el billete o moneda con el que se paga dicho producto.
La salida es una matriz de valores booleanos (0|1) que representa el camino para salir del laberinto.

David Gerardo Martínez Hidrogo - A01235692
Humberto Ricardo Rodriguez Ruán - A01197898

Last modified: Oct 4, 2022
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

/*
Return matrix with all possible paths to bottom-right corner using backtracking
complexity
    time: O(n*m)
    extra space: O(n*m)
*/
void backtracking(vector<vector<int> > & matrix, vector<vector<int> > & laberinth, int & rows, int & cols, int row, int col){

    //base cases 
    if(row >= rows || row < 0 || col >= cols || col < 0 || matrix[row][col] != 1) return; //no path

    
    matrix[row][col]++; //mark cell as visited

    if(row == rows-1 && col == cols-1){ //path found
        matrix[row][col] = 0;
        laberinth[row][col] = 1;
        return;
    }

    //check other possible paths
    backtracking(matrix, laberinth, rows, cols, row, col+1); //right
    backtracking(matrix, laberinth, rows, cols, row+1, col); //bottom
    backtracking(matrix, laberinth, rows, cols, row, col-1); //left
    backtracking(matrix, laberinth, rows, cols, row-1, col); //up

    matrix[row][col] = 0;
    laberinth[row][col] = 1;
}

/*
Return matrix with all possible paths to bottom-right corner using backtracking
complexity
    time: O(n*m)
    extra space: O(n*m)
*/
vector<vector<int> > findPathBacktracking(vector<vector<int> > matrix, int & rows, int & cols){

    //clone matrix
    vector<vector<int> > laberinth(rows, vector<int>(cols));
    
    //get laberinth from backtracking
    backtracking(matrix, laberinth, rows, cols, 0, 0);
    //printMatrix(matrix);

    return laberinth;
}

/*
Return matrix with all possible path to bottom-right corner using branch and bound
complexity
    time: O(n+m)
    extra space: O(n+m)
*/
void branchAndBound(vector<vector<int> > & matrix, vector<vector<int> > & laberinth, bool & found, int & rows, int & cols, int row, int col){

    //out of range
    if (row >= rows || row < 0 || col >= cols || col < 0) return;

    //cell is different from 1
    if (matrix[row][col] != 1) return;

    //mark cell as visited, if it's 1
    matrix[row][col] = 2;

    //if it has arrived the bottom-left cell. we found it
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
complexity
    time: O(n+m)
    extra space: O(n+m)
*/
vector<vector<int> > findPathBranchAndBound(vector<vector<int> > matrix, int rows, int cols){
    
    //clone matrix
    bool found = false;
    vector<vector<int> > laberinth(rows, vector<int>(cols));

    //get laberinth from backtracking
    branchAndBound(matrix, laberinth, found, rows, cols, 0, 0);
    //printMatrix(matrix);

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

    //printMatrix(laberinth);

    //Find paths
    vector< vector<int> > laberinthBacktracking = findPathBacktracking(laberinth, rows, cols);
    vector< vector<int> > laberinthBranchAndBound = findPathBranchAndBound(laberinth, rows, cols);
    
    //print solutions
    printMatrix(laberinthBacktracking);
    cout << endl;
    printMatrix(laberinthBranchAndBound);

    return 0;
}