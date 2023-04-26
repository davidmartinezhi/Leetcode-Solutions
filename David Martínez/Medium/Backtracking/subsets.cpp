#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
        info
            input: integer array "nums" of unique elements
            output: all possible subsets
            constraints:
                *solution must not contain duplicate subsets
                *solution can be in any order
                *array length is between 1 and 10
                *all the numbers in the array are unique
                
        example
            nums = [1,2,3]
            -> [[],[1], [2], [3], [1,2], [1,3], [1,2,3]]
            
        brute force
            
            recursive solution
            backtracking fits because its a state space tree
            
            complexity:
                runtime: O(n^n)
                extra space: O(recursive calls)
                
        optmimize
            backtracking is the only way we'll find all permutations
            use memoization to optimize memory
            
        walkthrough
            traverse array
                add, send to recursive call
                don't add, send to recursive call
            
        test
            * array length one
            * array length more than one
        
        */
        
        vector<vector<int>> result;
        vector<int> subset;
        
        backtracking(result, nums, subset, 0);
        
        return result;
        
        
    }
    
    void backtracking(vector<vector<int>> & result, vector<int> & nums,vector<int> subset, int idx){
        
        if(idx >= nums.size()){
            result.push_back(subset);
            return;
        }
        
        subset.push_back(nums[idx]);
        backtracking(result, nums, subset, idx+1);
        subset.pop_back();
            
        backtracking(result, nums, subset, idx+1);
        
        
    }
};

/*
Time: 45+

Complexity:
    runtime: O(2^n)
    extra space: O(n)

Tuve la idea correcta desde el inicio, solo batalle en plasmar la implementación
pero de calmarme y pensar en la manera más simple de implementarlo es lo correcto.

*/