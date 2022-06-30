#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        /*
            info
                input: int array "nums"
                output: number of good pairs
                
                    a pair (i,j) is good if nums[i] == nums[j] and i < j
                
                constraints:
                    array size is between a and 100
                    nums[i] is between 1 and 100
                    
            example
                [1,2,3,1,1,3]
                -> 4
                
                [1,1,1,1]
                -> 6
                
            brute force
                for each number, traverse the rest of the list looking for pairs
                complexity:
                    time O(n^2)
                    extra space O(1)
                    
            optimize
                Best case runningtime O(n)
                
                [1,2,3,1,1,3]
                -> 3 + (2-1) = 4
                hashtable
                    [
                        1: 3,
                        2: 1,
                        3: 2,
                    ]
                    
                [1,1,1,1]
                -> 3 + 4-1 = 6
                ht
                [
                    1: 4
                ]
                
                complexity
                    time: O(n)
                    extra space: O(n)
                    
            walkthrough
                declare ht and counter
                traverse list
                    for each key element that appears
                        add one to its frequency of appearance
                        sum value - 1 to counter
            
            test
                no pairs in the array
                one pair in the array
                multiple pairs of one number in the array
                multiple pairs of multiple numbers in the array
        */
        
        //declare variables
        unordered_map<int, int> numFreq;
        int counter = 0;
        /*
        [1,1,1,1]
        -> 1+2+3 = 6
        
        [
            1: 4
        
        ]
        */
        //traverse list
        for(int i = 0; i < nums.size(); i++){
            //add one to number (key) frequency
            numFreq[nums[i]]++;
            
            //add to counter frequency - 1    
            counter = counter + (numFreq[nums[i]] - 1);
        }

        return counter;
        
    }
};

