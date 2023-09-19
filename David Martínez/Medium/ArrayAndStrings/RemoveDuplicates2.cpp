#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
        info
            input: 
                * int array "nums"
                * array in in non-decreasing order
            
            output:
                * k, which is the number of num of numbers and their duplicate
                * array must be modified in-place

            constraints:
                * array is in non-decreasing order
                * each number appears at least twice? or should i add some
                * what range of sizes can the array have? [1, 30000]
                * what range of values can each number have? [-10000, 10000]
                * must use O(1) memory

        example
            nums = [1,1,1,2,2,3]
            -> 5, [1,1,2,2,3,_]

            nums = [0,0,1,1,1,1,2,3,3]
            -> 7, [0,0,1,1,2,3,3]

        brute force
            use hashtable to get numbers frequencies 
            traverse array to set values

            complexity:
                runtime: O(n)
                extra memory: O(n)

        optimize
            best conceivable runtime: O(n)

            nums = [1,2,2,3,3]
                        k
                          i
            count = 1
            k = 3
            i = 3

            have static variable k
            have traversing variable i
            have count variable

            if they are the same value
                if count is less than 2
                    k++
                    nums[k] = nums[i]
                    count++
            
            if they are different value
                count = 1
                k++
                nums[k] = nums[i]

        test
            all numbers are unique
            all numbers are duplicate
            all numbers are the same

            hotspot:
                return k or k-1

        */

        //get size
        int n = nums.size();

        //check size
        if(n == 1) return 1;

        //declare variables
        int k = 0;
        int count = 1;

        //traverse nums, from idx 1
        for(int i = 1; i < n; i++){
            //they have the same value
            if(nums[k] == nums[i]){

                //check if count is valid
                if(count < 2){
                    k++;
                    nums[k] = nums[i];
                    count++;
                }

            }
            //they have different values
            else{
                count = 1;
                k++;
                nums[k] = nums[i];
            }
        }

        return k+1;
    }
};
//27 minutes