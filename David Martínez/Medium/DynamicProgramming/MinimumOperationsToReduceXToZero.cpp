#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

        /*
            info
                input:
                    integer array "nums" and integer "x"
                    
                output:
                    minimum number of operations to reduce x to exactly 0
                    If it's not possible, return -1
                    
                In one operation, you can either remove the leftmost or rightmost
                element from the array and substract its value from "x"
                
                constraints:
                    - array length is between 1 and 100,000
                    - array values range from 1 and 10,000
                    - x has value between 1 and 10,000
                    
            
            example
                [5,6,7,8,9] x=4
                -> -1
                
                [3,2,20,1,1,3] x=10
                -> 5
                all elements except 20
                
                [3, 1, 1, 5, 2, 3] x = 5
                -> 2
                
            brute force
                use recursion to see all possible combinations
                on each side we have the oportunity to include or exclude that value
                complexity
                    time: O(2^n) exponential
                    space: O(2^n) exponential
                    
            optimize
                use memoization to avoid calcultions that we have already made
                complexity
                    time: O(n)?
                    extra space: O(n)
                    
            walkthrough
                have private hashtable
                create helper funtion
                
                    if x == 0 return count
                    else if x < 0 return -1
                    
                    check if already calculated
                        return already calculated
                        
                    check left
                    check right
                    save min of left and right
                    
                return value
                
            test
                can reduce x to 0
                can't reduce x to 0
                      
                    
        */

class Solution {
    
    //global cache for memoization
    unordered_map<string, int> mem;
    
    int getMinOperationsRecursive(vector<int>& nums, int x, int left, int right, int count){
        
        //base cases
        if(x == 0) return count;
        else if(x < 0 || left > right) return INT_MAX;
        
        //create key for hashtable key
        string key = to_string(left) + "*" + to_string(right) + "+" + to_string(x);
        
        //check if value has already been calculated
        if(mem.count(key)) return mem[key];
        
        //check left and right side
        int l = getMinOperationsRecursive(nums, x - nums[left], left+1, right, count + 1);
        int r = getMinOperationsRecursive(nums, x - nums[right], left, right -1, count + 1);
        
        //save value in mem hashtable
         return mem[key] = min(l, r);//return value
        
    }

    
public:
    int minOperations(vector<int>& nums, int x) {
        
        //iterative, 2 pointers technique
        
        //declare variables
        /*
        get the biggest window that gives me the sum - diff
        
        */
        int target = -x; //target
        int result = -1;
        int sum = 0;
        
        //pointer
        int left = 0;
        
        //get target value
        for(int x : nums) target += x;
        
        //check if all nums are requiered to sum 0
        if(target == 0) return nums.size();
        
        //check if the numbers cannot get us to 0
        if(target < 0) return -1;
        
        //traverse
        for(int right = 0; right < nums.size(); right++){
            
            //update sum
            sum += nums[right];
            
            //if sum is bigger thatn target, move left pointer
            while(sum > target){
                sum -= nums[left];
                left++;
            }
            
            //check if sum is equal to target
            if(sum == target){
                result = max(result, right-left+1);
            }
        }
        
        return result == -1 ? -1 : nums.size() - result;
        
    
        //recursive
        /*
        //get result
        int result = getMinOperationsRecursive(nums, x, 0, nums.size()-1, 0);
        
        //check if calculation is possible
        if(result == INT_MAX) return -1;
        
        return result;
        */

    }
};