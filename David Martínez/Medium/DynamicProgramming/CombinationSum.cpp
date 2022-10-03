#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        /*
        info
            input: array of distinct inegers "nums" and "target" integer
            output: number of possible combinations that add up to target
            
            constraints:
                test cases generated so that the answer can fit in a 32-bit int
                array length is between 1 and 200
                array values are between 1 and 1000
                all elements are unique
                target is between 1 and 1000
                
        example
            nums = [1,2,3], target = 4
            -> 7
            
            nums[9], target = 3
            -> 0
            
        brute force
            recursively check all possible combinations and add the ones that add 
            up to target
            
            every number has the option of being included or exluded
            complexity:
                time: O(2^n) exponential
                
        Optimize
            
            DP
            Knapsack unbounded problem
                - use tabulation to know how many combinations gets me the value of target
                
            nums = [1,2,3], target = 4
            -> 7       
            
            complexity
                time: O(target*array size)
                extra space: O(n)
                
        walkthrough
            
            declare variables
            traverse dp table
                
                count all possible ways to get a value
                
        test
            target can be made
            target cannot be made
        
        */
        
        //declare variables
        int n = nums.size();
        vector<double> dp(target+1,0);
        dp[0] = 1;
        
        for(int i = 1; i <= target; i++){
            for(int j = 0; j < n; j++){
                //check if j is a valid number
                if( i - nums[j] >= 0){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        
        
       return dp[target];
    }
};

/*

A los 8 minutos ya tenia la respuesta, pero me tarde en programarlo
complexity:
    time: O(array size * target)
    extra space: O(target)

Problema no fue dificil, deberíad e hacer un cheatsheet para tabulación con dp.
Pero en general, se puede decir que estoy listo para entrevistas de dp
*/