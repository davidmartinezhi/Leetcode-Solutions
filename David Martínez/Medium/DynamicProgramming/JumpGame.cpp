#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*
         1. info
            
            Input: integer array "nums"
                Initially positiones at the arrays first index.
                Each element in the array represents your max jump length at
                that position.
                
            Output: true is you can reach the last index, otehwrise false
            
            Constraints: 
                Array length is between 1 and 10,000
                each cell in the array has value between 1 ans 100,000
                
        2. example
        
            nums = [2,3,1,1,4] -> true
            jump one step from position 0 to 1, then 3 steps to last index
            
            nums = [3,2,1,0,4] -> false
            We arrive at index 3 no matter the option, and it's a dead-end
            
        
        3. brute force
            
            Make jumps and do backtracking if we reach a dead-end or pass 
            the length of the list
            
            complexity: O(!n) runtime
                        O(n) space
        
        4. optimize
        
            Dynamic programming because it looks for from all possible ways,
            look for the one that accomplishes this.
            
            And because we hace a lot of repeated computations
            We need to store middle values.
            
            runtime: O(n)
            space: O(1)
            
        5. walktrhough
            
            Save the number of jumps we can do
            on each advancement, we substract one.
            
            When the number on the cell is bigger than the current possible jumps
            We set that value as the new possible jumps
            
            If the value becomes 0, check if it's at the last index
            
            Variables
            jumps
            jumpIndex
        
        6. implement
        
        7.test:
            array with dead-end
            array without dead-end
        */
        
        //Variables
        int jumps = nums[0];
        int jumpIndex = 0;
        
        //Array Traversal
        while(jumps > 0 && jumpIndex < nums.size()-1){
            
            //Jump one cell
            jumps--;    //Substract possible jumps
            jumpIndex++;    //Jump one index
            
            //If possible jumps on cell is greater than current possible jumps
            if(nums[jumpIndex] > jumps){    
                jumps = nums[jumpIndex];    //now those are our possible jumps
            }
        }
        
        //Return Value
        if(jumpIndex == nums.size()-1) return true;
        
        return false;
    }
};