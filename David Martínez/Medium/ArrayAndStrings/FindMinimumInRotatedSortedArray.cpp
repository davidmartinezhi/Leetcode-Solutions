#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
       /*
        1. listen
            input: sorted array nums of unique elements
            ouput: minimum element of the array
            
            must be in o n log n
            
            nums size is between 1 and 5000
            all integers in nums are unique
            nums is sorted and rotated between 1 and n times
        
        2. example
            [1,2,3,4,5] -> 1
            
            [4,5,1,2,3] -> 1
            
            [2,3,4,5,1] -> 1
            
            [5,1,2,3,4] -> 1
            
            
            left is smaller and right is greater, return left
            left and right are greater, go left including pivot
            right and left are smaller, go right
            

            
        3. brute force
        
            traverse iteratively
            runtime: O(n)
            space:O(1)
            
        
        4. optimize
            binary search
            find the pivot
            
        5. walkthrough

                binarySearch for pivot
                
        7. test
            special case:
                array of size 1
            
       */ 
        
        //Check if the array is of size 1
        if(nums.size() == 1) return nums[0];
        
        //Check if the array has not been rotated (has been rotated n times)
        if(nums[0] < nums[nums.size()-1]) return nums[0];
        
        //Index of the smallest value in the array, runtime O(n log n)
        int smallestValueIdx = binarySearchSmallestIdx(nums, 0, nums.size()-1);
        
        return nums[smallestValueIdx];
    }
    
    int binarySearchSmallestIdx(vector<int> & nums, int i, int j){
        
        int pivot = (i+j)/2;
        
        //if the right extreme number is bigger than pivot
        if(nums[pivot] < nums[j]){
            return binarySearchSmallestIdx(nums, i, pivot); //Check left including the pivot
        }
        else if(nums[pivot] > nums[j]){ //If the right extreme number is smaller than pivot
            return binarySearchSmallestIdx(nums, pivot+1, j);   //Check right
        }
        
        return pivot;   //pivot equals the right extreme number, return pivot
    }
};
/*
Nota:
    La idea de como resolverlo la tuve a los 5 minutos
    Batalle en definir las condiciones del binary search

    Me sirvío muchisimo hacer el DIY, pude saber que era util tomar como base solo un extremo, en lugar de ambos


*/