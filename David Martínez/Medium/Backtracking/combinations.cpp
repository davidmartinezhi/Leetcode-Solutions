#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        /*
        info
            input: 
                * integers n and k

            output:
                * all possible combinations of k numbers chosen from the range [1,n]

            constraints:
                * what range of values can k have? [1,20]
                * what range of values can n have? [1,20]
                * k is smaller of equal to 20

        example
            Input: n = 4, k = 2
            Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]

            Input: n = 1, k = 1
            Output: [[1]]

        brute force
            n = 4, k = 2
            1, 2, 3, 4

            [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]

            n = 4, k = 3
            1, 2, 3, 4

            [[1,2,3],[1,2,4],[1,3,4],[2,3,4]]

            With this pattern i wont need memoization to keep the patterns we have already visited

            complexity:
                runtime: O(n^k)
                extra space: O(k) 

        optimize
            best conceivable runtime: O(n^k)

        test
            * k == 1
            * k == n
            * k < n
        */

        //Declare variables
        vector<vector<int>> combinations;
        vector<int> combination;

        //traverse the numbers from 1 to k
        for(int i = 1; i <= n; i++){
            findCombination(n, k, combinations, combination, i);
            combination.clear();
        }

        return combinations;
    }

    /*
    
            n = 4, k = 2
            1, 2, 3, 4
            
            combinations=[[1,2],[1,3],[1,4]]
            combination=[]
            i=2
    */

    void findCombination(int&n, int&k, vector<vector<int>>&combinations, vector<int>&combination, int i){

        //base case: we are out of bounds
        if(i > n) return;

        //add value to combination
        combination.push_back(i);

        //check if combination has k size
        if(combination.size() == k){
            combinations.push_back(combination); //add to combinations
            return; //return
        }

        //traverse the rest of numbers until n
        for(int j = i+1; j <= n; j++){

            findCombination(n, k, combinations, combination, j); //make recursive call to add next value
            combination.pop_back(); //remove value we just added to make room for the next one
        }

        return;
    }
};

/*
Time: 27 minutes

complexity:
    runtime: O(n^k)
    extra space: O(k) 

    best conceivable runtime: O(n^k)

notes:
    I came up with a solution very fast and was able to code it
    in a short amount of time.

    I have done a well job. I'll keep practicing for my interview with microsoft.
*/