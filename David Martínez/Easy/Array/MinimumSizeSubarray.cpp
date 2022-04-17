#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    /*
    1. listen
        input: array of positive integers "nums", and a positive integer "target"
        output: minimal length of contiguous subarray of wich the sum is greater or equal to target
        
        if there is not such subarray, return 0
        
    2. example
        target = 7, nums = [2,3,1,3,4,3] -> 2
        target = 4, nums [1,4,4] -> 1
        
    3. brute force
        for each number
            traverse the rest of numbers, until the sum is equal or greater than targer and compare
            
        runtime: O(n^2)
        space: O(1)
        
    4. optimize
        BCR: O(n)
        
        sliding window technique
            runtime: O(n)
            space: O(1)
            
    5. walkthrough
    
        //traverse the list and add tu sum each new number
            if the number is greater or equal to target, move windowStart and subastract
            
            compare current window with minSubarray window
    
    7. test
        no such subarray exists
        subarray exists
    */
        
        int n = nums.size();
        
        int minSub = INT_MAX;
        int currSum = 0;
        
        int windowStart = 0;
        
        for(int windowEnd = 0; windowEnd < n; windowEnd++){
            currSum += nums[windowEnd];
            
            while(currSum >= target && windowStart <= windowEnd){
                minSub = min(minSub, windowEnd - windowStart + 1);
                currSum -= nums[windowStart];
                windowStart++;
            }
            
        }
        
        if(minSub == INT_MAX) return 0;
        
        return minSub;
    }
};
