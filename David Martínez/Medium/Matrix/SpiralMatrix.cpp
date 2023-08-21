#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        /*

        info:
            input: n x m matrix
            output: all the elements in the matrix in spiral order

            constraints:
                m and n are between 1 and 10
                values inside matrix range from -100 to 100

        example:
            notebook

        brute force:
            create pointers as coordinates, they move according to their movement
            ex. rightMovemevnt pointer, followed by downMovementPointer, followerd by leftMov. and upMove

            traverse the list according to limits
            rightMove: limit is down.x
            downMove: limit is left.y
            leftMove: limit is up.x
            upMovement: limit is right.y

            when they the result list has m*n size, we know we are donw with the traversal

            runtime: O(n^2) for the traversal of the whole list
            space: O(1) extra space
                    O(n*m) counting the result array

        optimize:
            The brute force solution is pretty efficient

        test:
            limits are respected


        */

        //space: O(1) extra space
        // rows length
        int colSize = matrix.size();
        int rowSize = matrix[0].size();

        // result array
        vector<int> result;

        // coordinate pointers
        vector<int> right = {0, 0};
        vector<int> left = {rowSize - 2, colSize};
        vector<int> up = {0, colSize - 2};
        vector<int> down = {rowSize - 1, 0};

        // traversal runtime: O(n^2)
        while (result.size() != (colSize * rowSize))
        {

            int i;

            // right traversal
            i = right[0];

            while (i < down[0])
            {
                result.push_back(matrix[right[1]][i]);
                i++;
            }
            right[0]++;
            right[1]++;

            if (result.size() == (colSize * rowSize))
                return result;

            // down traversal
            i = down[1];
            while (i < left[1])
            {
                result.push_back(matrix[i][down[0]]);
                i++;
            }

            down[0]--;
            down[1]++;

            if (result.size() == (colSize * rowSize))
                return result;

            // left traversal
            i = left[0];
            while (i >= up[0])
            {
                result.push_back(matrix[left[1] - 1][i]);
                i--;
            }
            left[0]--;
            left[1]--;

            if (result.size() == (colSize * rowSize))
                return result;

            // up traversal
            i = up[1];
            while (i >= right[1])
            {
                result.push_back(matrix[i][up[0]]);
                i--;
            }
            up[0]++;
            up[1]--;

            if (result.size() == (colSize * rowSize))
                return result;
        }

        return result;
    }

    vector<int> spiralOrderRecursive(vector<vector<int>>& matrix) {
        /*
        info
            input:
                - m*n matrix

            output:
                - vector with all elements of the matrix in spiral order

            constraints:
                - what values to expect from n and n. range[1, 10]
                - what values would i expect on each cell? [-100, 100]

        example
            [
                [$,$,$],
                [$,$,$],
                [$,$,$]
            ]

            -> [1,2,3,6,9,8,7,4,5]

        brute force
            recurively call, and do backtracking
            starting with left side, go right until we reach end or find special number then go down
            go down until end or find special number then go left
            go left until end or find special char then go up
            go up until end or special char, then go right

            complexity:
                runtime: O(n*m)
                extra space: O(n*m)

        optimize
            best conceivable runtime: O(n*m)

            can i improve memory?

        test
            - matrix 1*1
            - matrix 2*2
            - matrix 3*3
            - matrix 2*4        
        */

        //declare variables
        vector<int> spiralOrder;
        int rows = matrix.size();
        int cols = matrix[0].size();

        traverseSpiral(matrix, spiralOrder, rows, cols, 0, 0, 'r');

        return spiralOrder;
        
    }

    void traverseSpiral(vector<vector<int>>& matrix, vector<int> & spiralOrder, 
    int&rows, int&cols, int row, int col, char direction){

        /*
        [INT_MAX,2,3],
        [4,5,6],
        [7,8,9]

        -> []
        
        */

        //base case: in bounds
        if(row < 0 || row == rows || col < 0 || col == cols) return;

        //base case: special character
        if(matrix[row][col] == INT_MAX) return;

        spiralOrder.push_back(matrix[row][col]);
        matrix[row][col] = INT_MAX;

        if(direction == 'r'){
            traverseSpiral(matrix, spiralOrder, rows, cols, row, col+1, 'r');
            traverseSpiral(matrix, spiralOrder, rows, cols, row+1, col, 'd');
        }else if(direction == 'd'){
            traverseSpiral(matrix, spiralOrder, rows, cols, row+1, col, 'd');
            traverseSpiral(matrix, spiralOrder, rows, cols, row, col-1, 'l');
        }else if(direction == 'l'){
            traverseSpiral(matrix, spiralOrder, rows, cols, row, col-1, 'l');
            traverseSpiral(matrix, spiralOrder, rows, cols, row-1, col, 'u');
        }else if(direction == 'u'){
            traverseSpiral(matrix, spiralOrder, rows, cols, row-1, col, 'u');
            traverseSpiral(matrix, spiralOrder, rows, cols, row, col+1, 'r');
        }

    }
};



/*
Nota:
    Tiempo: +45

    Saque el diseño de la solución desde el principio, pero me tarde con la logica y los tests de los pointers
    Talvez checar la lógica un poco más y asegurarme de como funcionará, sea mejor a hacer más esfuerzo mental

    Si es mejor en papel asegurarme de que estoy haciendo y como lo haré. En lugar
    de estar a medio codigo y estar trabajando la lógica.

    Solo improvisar y sacar la solución a medio sprint, cuando no exista alternativa. No apresurarme
    Si no hay razón para apurarme de la manera en la que me apuré, debo de no apurarme


Nota:
    Tiempo: 25 minutos con soluución recursica
*/