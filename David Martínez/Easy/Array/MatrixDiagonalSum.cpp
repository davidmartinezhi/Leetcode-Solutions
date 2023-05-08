#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        /*
        info
            input: square matrix "mat"
            output: sum of matrix diagonals
            constraints:
                * include cell in diagonals just once, don't repeat
                * mat lenght and values are in gange n
                * n is in range 1 and 100 included

        example
            mat = [
            [1,2,3],
            [4,5,6],
            [7,8,9]
            ]

            -> 15+10 = 25

            mat = [
            [1,2,3],
            [4,5,6],
            [7,8,9]
            ]

            firstDiagonal = [0,0], [1,1], [2,2]
            secondDiagonal = [2,0], [0,2]


            mat = [
            [1,2,3,4],
            [5,6,7,8],
            [9,10,11,12],
            [13,14,15,16]
            ]
    
            firstDiagonal = [0,0], [1,1], [2,2], [3,3]
            secondDiagonal = [3,0], [0,3], [1,2], [2,1]

        brute force
            count from 0 to n-1 on coordinates [i][i] and add to sum

            then on two variables:
                -first variable goes from 0 to n-1
                -second variable goes from n-1 to 0
                add [first][second] and [second][first] until they are different

            complexity:
                runtime: O(n)
                extra space: O(1)

        optimize
            best conceivable runtime: O(n), the brute force solution is optimal

        test
            mat of size 1*1
            mat of odd size
            mat od even size
        */

        //size of matrix
        int n = mat.size();

        //check if matrix is of size 1
        if(n == 1) return mat[0][0];

        //Declare variables
        int sumOfDiagonals = 0;
        int i = 0;
        int j = n-1;

        //add first diagonal values
        while(i < n){
            sumOfDiagonals += mat[i][i];
            i++;
        }

        //reseet i variable value
        i = 0;

        //add second diagonal values
        while(i < j){
            sumOfDiagonals += mat[i][j];
            sumOfDiagonals += mat[j][i];
            i++;
            j--;
        }

        return sumOfDiagonals;
    }
};

/*
Time to complete: 12 minutes

Complexity:
    runtime: O(n)
    extra space: O(1)

Me sentí bastante comodo con esta respuesta,
La clave es entender como se deben mover los apuntadores.


*/