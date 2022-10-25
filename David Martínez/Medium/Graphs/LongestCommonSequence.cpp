#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
        info
            input: unsorted array of integers "nums"
            output: length of the longest consecutive elements secuence
            
            constraints:
                -must run in O(n) time
                -nums length is between 0 and 10^5
                -nums values are between -billion to billion
                
        example
            nums = [100,4,200,1,3,2]
            -> 4
            
            because of 1,2,3,4
            
            nums = [0,3,7,2,5,8,4,6,0,1]
            -> 9
            
            because of 0, 1, 2, 3, 4, 5, 6, 7, 8
            
            nums = [0, 0, 0, 0]
            -> 1
            
            because of 0
            
        brute force
            
            sort the array and count consecutive elements secuence
            complexity
                time: O(n log n)
                extra space: O(1)
                
        optimize
            bcr: O(n)
            
            traverse the array once and look for maxValue and minValue
            and add values to hashtable
            
            from minValue add 1 until maxValue and check if the
            value exists in the hashtable
            
            count = 3
            currCount = 3
            {
                -1,
                0,
                2,
                3,
                4
            }
            
            3 7 = 7-3 = 4
            O(maxVal-minVal)
            O(n)
            
            bst?
            insertion is log n
            traversal is n and numbers are in order
            
            ht
                
                4: [3]
                3: [4]
                2: [3, 1]
                1: [2]
        
        test
            -duplicates
            -empty array
            -secuence exists
        */
        
        /*
        //check empty array
        if(nums.size() == 0) return 0;
        
        //declare variables
        unordered_set<int> numsInArray;
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        int lcs = 0;
        int currentLcs = 0;
        
        //traverse to find minVal, maxVal and fill unordered set
        for(int i = 0; i < nums.size(); i++){
            
            //add to unordered set
            numsInArray.insert(nums[i]);
            
            //check min and max
            minValue = min(minValue, nums[i]);
            maxValue = max(maxValue, nums[i]);
        }
        
        //check if they are the same value
        if(minValue == maxValue) return 1;
        
        
        //traverse to find max sequence
        for(int i = minValue; i <= maxValue; i++){
            
            //check if subsequence is made
            if(numsInArray.find(i) != numsInArray.end()){
                currentLcs++;
            }else{
                currentLcs = 0;
            }
            
            lcs = max(lcs, currentLcs);
        }
        
        return lcs;
        
        */
          
        //check empty array
        if(nums.size() == 0) return 0;
        
        //declare variables
        unordered_set<int> numsInArray;
        int lcs = 0;
        int currentLcs;
        
        //traverse to find minVal, maxVal and fill unordered set
        for(int i = 0; i < nums.size(); i++){
            //add to unordered set
            numsInArray.insert(nums[i]);
        } 
        
        //traverse to find longest common sequence
        for(int i = 0; i < nums.size(); i++){
            int currNum = nums[i];  //get num
            currentLcs = 1; //set current count
            
            //if the number is the first in its sequence
            if(numsInArray.find(currNum-1) == numsInArray.end()){
                
                //while value of num+1 exists
                while(numsInArray.find(currNum+1) != numsInArray.end()){
                    currNum++;  //update num
                    currentLcs++;   //update currentLcs
                }
            }
            
            lcs = max(lcs, currentLcs); //save max value
        }
      
        return lcs;
    }
};