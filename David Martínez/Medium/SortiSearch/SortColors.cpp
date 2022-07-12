#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
            info
                input: array nums with n objects colored red, white and blue
                        sort them in-place so the numbers of the same color are adjacent
                        in order red(0), white(1) and blue(2)
                        
                output: 
                constraints: 
                    nums length is between 1 and 300
                    only numbers are red white and blue
            
            example
                [2,0,2,1,1,0]
                -> [0,0,1,1,2,2]
                
                [2,0,1]
                -> [0,1,2]
            
            brute force
                merge sort
                complexity:
                    time O(n log n)
                    extra space O(1)
            
            optimize
                create array of size 3, and count the colors appearance
                reconstruct based on the times a color appears
                
                complexity
                    time O(n)
                    space O(n)
            
            walkthrough
            
            test
                all colors are the same
                
        */
        
        //declare variables
        int n = nums.size();
        vector<int> freq(3);
        
        //traverse to fill frequency counts
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }
        
        //construct based on frequency counts
        int index = 0;
        for(int i = 0; i < 3; i++){
            while(freq[i] > 0){
                nums[index] = i;
                index++;
                freq[i]--;
            }
        }
    }
};

/*
14 minutes

complexity
    time: O(n)
    extra space: O(1)

Problema resulto con bastante velocidad, me sentí muy bien con la solución
propuesta y con las alternativas que sugerí

*/