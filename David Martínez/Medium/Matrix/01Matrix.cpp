#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        /*
        info
            input
                - m*n binary matrix "mat"

            output
                - martix with distance of nearest 0 for each cell

            constraints
                - cells only contain 0 and 1? yes
                - how many rows can i expect? [1, 1000]
                - how many rows can i expect? [1, 1000]
                - what if there is no 0? there will always be a 0 in the matrix


        example
            mat = [
                [0,0,0],
                [0,1,0],
                [0,0,0]]

            ->
            mat = [
                [0,0,0],
                [0,1,0],
                [0,0,0]]


            mat = [
                [0,0,0],
                [0,1,0],
                [1,1,1],
                [1,1,1]
                ]

             mat = [
                [0,0,0],
                [0,1,0],
                [1,2,1],
                [2,3,2]
                ]

            ->
            mat = [
                [0,0,0],
                [0,1,0],
                [1,1,1]]

        brute force
            use backtracking
            once 0 is found, return 0
            on each cell call recursively the other 4 adjacent sides
            return min of sides + 1

            complexity:
                runtime: ((n*m)^2) 
                extra space: O(n*m)

        optimize
            best conceivable runtime: O(n*m^2)

            how can i improve runtime: 

        test
            - all 0
            - just one 0
        
        */


        //declare variables
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0)); //visited cells
        vector<vector<int>> distance(rows, vector<int>(cols, 0)); //result array with distances
        queue<pair<pair<int,int>, int>> q; //queue for nodes visits

        
        //traverse to find cells with 0: O(n*m)
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){

                if(mat[row][col] == 0){ //if we find 0
                    q.push({{row,col}, 0}); //add that value to the queue 
                    visited[row][col] = 1; //set matrix position as visited
                }
            }
        }

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        //breath first search: O(n*m*4)
        while(!q.empty()){ //while queue is not empty

            //get values
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;

            //pop item
            q.pop();

            //Set steps
            distance[r][c] = steps;

            //traverse sides
            for(int i = 0; i < 4; i++){

                int nRow = r + delRow[i];
                int nCol = c + delCol[i];

                //check we are in bounds
                if(nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols){
                    
                    //if we have not visited that cell
                    if(visited[nRow][nCol] == 0){
                        q.push({{nRow,nCol}, steps+1});
                        visited[nRow][nCol] = 1;
                    }
                }
            }
        }


        return distance;
    }


    //30 min
    int DFS(vector<vector<int>>& mat, vector<vector<int>>& result,int & rows, int & cols, int row, int col){

        //base case: in bounds
        if(row < 0 || row == rows || col < 0 || col == cols) return 10000;

        //base case: cell already visited
        if(mat[row][col] == 2) return 10000;

        //base case: 0 found
        if(mat[row][col] == 0) return 0;

        int aux = mat[row][col];
        mat[row][col] = 2;

        int minPathTop =  DFS(mat, result, rows, cols, row+1, col);
        int minPathBottom =  DFS(mat, result, rows, cols, row-1, col);
        int minPathLeft =  DFS(mat, result, rows, cols, row, col-1);
        int minPathRight =  DFS(mat, result, rows, cols, row, col+1);

        mat[row][col] = aux;

        return min(min(minPathTop, minPathBottom), min(minPathLeft, minPathRight)) + 1;

    }

    
};

/*
time: 45+ minutes
      30 minutes for DFS approach

Complexity:
    runtime: O(n*m + n*m*4)
    extra space: O(n*m*2)

Desde el comienzzo supe como debería de ser el traversal pero no me había dado cuenta
que con matrices solo había aplicado el DFS para buscar cosas y también para backtracking.

Pero no se me había ocurrido que no he implementado BFS en matrices. La solución si es mucho
más eficiente con BFS.

Debería de detenerme un momento y pensar "Que tipo de recorrido debo implementar en este momento?"

Aún así saque una respuesta a la pregunta, me gustó mucho este problema. Tratare de encontrar
otro problema donde se implementé BFS en una matriz para ver si lo puedo implementar desde 0 yo solo
*/