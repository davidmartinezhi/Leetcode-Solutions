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
};

