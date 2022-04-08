#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        /*
        
        info:
            input: array nums of distinct integers
            output: all possible permutations

            output can be returned in any order
        
        example:
            nums = [1,2,3]
            -> [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
            
            nums = [0, 1]
            -> [ [0, 1], [1, 0]]
            
            nums = [1]
            -> [[1]]
            
        brute force:
        
        recursively create all permutations
        
        */
    
        
        if(nums.size() <= 1) return {nums};
        
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); ++i){
            vector<int> v(nums.begin(), nums.end());
            v.erase(v.begin() + i);
            
            auto res = permute(v);
            
            for(int j = 0; j < res.size(); ++j){
                vector<int> _v = res[j];
                _v.insert(_v.begin(), nums[i]);
                result.push_back(_v);
            }
        }
        
        return result;
    }
};

//45 miuntes+
/*
Nota:
    Batalle mucho con este problema, debo de repasarlo el lunes
    runtime: O(!n)
    space(n)

*/