#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*
        info
            input: array "nums" containing only positive integers
            
                find if the array can be partitioned into 2 subsets
                such that sum of elements in both subsets is equal
                
            output: boolean
            
            constraints:
                -array is non-empty
                -array has length between 1 and 200
                -each index has value in range between 1 and 100
                
        example
            nums = [1, 5, 11, 5]
            -> true
             5+5+1 = 11 and 11 = 11
             
             nums = [1,2,3,5]
             -> false
             
             when sum is odd, we return false
             
        brute force
            *investigar brute force para estos problemas*
            
            get permutations of array and it's sums
            if there are two permutations with same sum
            
        optimize
            use dynammic programming
            it's a bounded 0/1 knapsack problem 
            
            if sum can be made, we get the value sum/2
            if that sum can be made, it's true
            
            tabulation, top-down approach can work
            complexity:
                time: O(items + (sum of elements/2))
                extra space: O(items + (sum of elements/2))
                
        walkthrough
            traverse array to get sum
            if sum is odd, return false
            create dp matrix
            traverse matrix
                at row 0 or col 0, value will be false
                if value is greater than sum at that index, copy the one on top
                if the value is equal, set it to true
                else compare top or top - num[i]
            
        test
            array of odd size
            array of even size
            subset can be created
            subset cannot be created
            
        */
        
        int n = nums.size();
        
        //declare sum
        int sum = 0;
        
        //do sum of elements
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        
        //check if sum is odd
        if(sum % 2 != 0) return false;
        
        //is even, create dp table
        bool dp[n+1][sum/2 + 1];
        
        /*
        nums = [1,2,1]
        [ 0    , 1.   ,   2 ,  
        0[false, false, false],
        1[false, true,  false],
        2[false, true,  true,],
        1[false, true,  true]
        ]
        */
        
        //traverse dp table
        for(int i = 0; i <= n; i++){
            
            for(int j = 0; j <= sum/2; j++){
                
                if(i == 0 || j == 0){
                    //0 sum or 0 items
                    dp[i][j] = false;
                    
                }else if(nums[i-1] > j){
                    //num is greater than current sum value
                    dp[i][j] = dp[i-1][j];
                    
                }else if(nums[i-1] == j){
                    //num is equal to the needed sum
                    dp[i][j] = true;
                    
                }else{
                    //check if it can be achieved from previous sum or can be done
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                }
            }
        }
        
        //return
        return dp[n][sum/2];
    }
};

/*
Finished in 32 minutes

    complexity:
        time: O(items * sum/2)
        extra space: O(items * sum/2)

    El problema fue igual que equal sum subset.
    Solo que ahora era checar primero si es posibles hacer la suma
        Ya que vimos que era posible, es ver si hay alguna suma que logre llegar a la mitad
        Eso significa que si se pueden crear 2 subsets con la misma suma.

*/