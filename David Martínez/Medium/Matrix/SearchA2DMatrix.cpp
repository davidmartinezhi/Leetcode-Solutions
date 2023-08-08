#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        info
            input
                * m*n integer matrix and integer target
                * each row is sorted in non-decreasing order
                * first integer of each row is greater than the last
                integer of previous row

            output
                * true if target is in matrix, else false

            constraints
                * must be log(m*n) complexity
                * what size can m and n have? between 1 and 100
                * what range of numbers can each cell have  -40,000 and 40,000
                * what range of values target can have. -40,000 and 40,000

        example
            matrix = [
                [1,3,5,7],
                [10,11,16,20],
                [23,30,34,60]
                ], 
                target = 3


        brute force
            traverse matrix
            complexity:
                runtime: O(n*m)

        optimize
            best conceivable runtime:
                - normally O(n*m)
                - since they are sorted maybe binary search could work

            could apply binary search to each row
                complexity: O(rows * log(columns))

            could apply binary search to get row then column

                complexity:
                    runtime: O(log(rows)+log(cols))

        test
            number exists on first row
            number exists on last row
            number exists between first and last row
            number does not exist

        */

/*
        //get sizes
        int rows = matrix.size();
        int cols = matrix[0].size();

        //traverse rows
        for(int i = 0; i < rows; i++){
            //if found return true
            if(binarySearch(matrix[i], target, 0, cols-1) != -10e5) return true;
        }


        return false;

*/

    int i = 0;
    int j = matrix[0].size() -1;

    while(i < matrix.size() && j >= 0){

        if(matrix[i][j] == target) return true;
        else if(matrix[i][j] > target) j--;
        else if(matrix[i][j] < target) i++;

    }

    return false;


    }

    int binarySearch(vector<int> &array, int &target, int left, int right){

        if(left <= right){

            int mid = ((right-left)/2) + left;

            if(array[mid] == target) return 1;
            if(array[mid] < target) return binarySearch(array, target, mid+1, right);
            else if(array[mid] > target) return binarySearch(array, target, left, mid-1);
        }

        return -10e5;

    }
};

/*
time: 30 minutes

complexity
    runtime: O(log(n*m))
    extra space: O(1)

La solución con binary search es muy buena, pero la solución con dos pointers resultó
ser más sencilla y optima. talvez deba tratar de resolverlo lo más simple posible
por un momento.

*/