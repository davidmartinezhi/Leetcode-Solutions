#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    /*
    info
        input: array nums of disctint integers
        output: all possible permutations, can return in any order
        constraints:
            nums length is between 1 and 6
            nums[i] is between -10 and 10
            all integers are unique
    
    example
    [1]
    [[1]]
    
    [0,1]
    [[0,1], [1,0]]
    
    brute force
        backtracking
        
    optimize
    
    walkthrough
    
    test
    
    */
        
        vector<vector<int>> result;
        vector<int> perm;
        vector<bool> used(nums.size(), false);
        
        backtrack(result, nums, perm, used);
        
        return result;
        
    }
    
    void backtrack(vector<vector<int>>& result, vector<int>& nums, vector<int> & perm, vector<bool> & used){
        
        //base case
        if(perm.size() == nums.size()){ 
            result.push_back(perm);
            return;
        }
        
        //traverse possible coices
        for(int i = 0; i < nums.size(); i++){
            if(!used[i]){ //if its valid
                
                //make choice
                used[i] = true;
                perm.push_back(nums[i]);
                backtrack(result, nums, perm, used);
                //undo choice
                used[i] = false;
                perm.pop_back();
            }
        }
    }
};