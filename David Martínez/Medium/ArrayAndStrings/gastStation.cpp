#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*
        info
            input:
                * int array "gas"
                * int array "cost"

            output:
                * starting gas station index if we can travel around the
                circuit in the clockwise direction

                * otherwise return -1

            constraints:
                * If solution exists, it is guaranteed to be unique
                * what range of sizes can both arrays have? [1, 100k]
                * what range of values can can gas array have? [0, 10k]
                * what range of values can cost array have? [0, 10k]

        example
            gas = [1,2,3,4,5], 
            cost =[3,4,5,1,2]
            -> 3

            tank = 0 + 3 = 3
            move = 3 - 1 + 4 = 6
            move = 6 - 2 + 5 = 9
            move = 9 - 3 + 1 = 7
            move = 7 - 4 + 2 = 5
            
        brute force 
            recursive solution
            starting from every index, unitl we reach that index again

            //base cases
            set new tank value
            if tank reaches 0 or less, return false

            if index is the same as starting index, return true

            if index is last index of array, next one is 0

            recursive call to next index


            complexity:
                runtime: O(n^2)
                extra space: O(n) recursive calls and maybe aux array

        optimize
            best conceivable runtime: O(n)

            it is a dp problem

            maybe I could use a matrix and use top down approach

            or memoization

            I'll do the brute force solution first

        test
            * solution does not exists
            * solution exists
        */

        int totalGas = 0, totalCost = 0, tank = 0, start = 0;
        
        for (int i = 0; i < gas.size(); ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];
            
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        
        return (totalGas < totalCost) ? -1 : start;
    }
};

/*
time: 45+

complexity:
    runtime: O(n)
    extra space: O(1)

        
            gas = [1,2,3,4,5]
            cost =[3,4,5,1,2]
            totalGas = 1+2=3+3=6+4=10+5=15
            totalCost = 3+4=7+5=12+1=13+2=15
            tank = 4-1=3+5=8-2=6
            start = 3

            i = 4

            if there is more total gas than cost, it's possible
            use kadanes algorithm to mantain starting idx of trip


I had really no idea how could i get the solution with complexity of O(n)
and extra space of O(1), i thought it must be a dp solution to achieve O(n)

I will reflect more on this problem to find how could I identify faster the
possible solution


*/