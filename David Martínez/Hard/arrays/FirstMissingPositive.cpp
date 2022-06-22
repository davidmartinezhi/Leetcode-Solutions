#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
        info
            input: unsorted integer array "nums"
            output: smallest missing positive integer
            constraints:
                - must run in O(n)
                - array size between 1 and 500,000
                - nums[i] value is between INT_MIN and INT_MAX
                
        example
            [1,2,0]
            ->3
            
            [3,4,-1,1]
            ->2
            
            [7,8,9,11,12]
            -> 1
            
        brute force
            -traverse the entire array and fill hashtable
            -then from 1, check if that number exists in the hashtable, 
                if not increment and repeat
                
            time: O(n)
            extra space: O(n)
            
        optimize
            Best case running time: O(n)
            
            Can I do better with memory?
            sorting and making a binary search tree to find 1, then count
            time: O(n log n)
            extra space: O(1)
        
        test:
            Special cases:
                all negative numbers
                all numbers are the same
                
                
                
            
        */
        
        //O(n) runtime
        //O(n) extra space
        
        //declare hashtable and int result
        unordered_map<int, int> numsFreq;
        int positiveInt = 1;
        
        //traverse the array to fill the hashtable
        for(int i = 0; i < nums.size(); i++){
            numsFreq[nums[i]]++;
        }
        
        //get min positive integer
        while(numsFreq[positiveInt] > 0){
            positiveInt++;
        }
        
        return positiveInt;
        
    }
};