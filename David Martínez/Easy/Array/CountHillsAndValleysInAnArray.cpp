#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int countHillValley(vector<int>& nums) {
        /*
        info
            input: 0 indexed integer array nums
            output: number of hills and valleys in nums
            constraints:
                nums length in range 3 and 100
                nums[i] value in range 1 and 100

            -index i is part of a hill, if closest non equal neighbor of 
            i are smaller than nums[i]

            -index i is part of valley in nums if, closest non equal neighbor 
            are larger than [i]

            -i and j are part of the same hill or valley if nums[i] == nums[j]


        example
            nums = [2,4,1,1,6,5]
            -> 3

            nums = [6,6,5,5,4,1]
            -> 0

        brute force

            on each index, have 2 aux pointers that open from current index
            until it finds two non-equal integers or index gets out of range

            if it gets out of range, leave it and continue

            if it finds 2 non equal integers evaluate

                both are smaller or both are bigger, add 1 to result
                else ignore

            complexity
                runtime: O(n^2)
                space: O(1)

        optimize
            bcr: O(n)

            if it expands to the right as equal number, skip the number
            add a flag and if it repeats to the right
            at the end traverse until we find a new number

            complexity:
                runtime: O(n)
                space: O(1)

        walkthrough
            nums = [2,4,1,1,6,5]
            -> 3

            -> 3

            declare result variable

            traverse nums
                declare pointers
                declare flag of repeats on right

                move left pointer until it finds non repeating number
                    check if next value is the same as previous
                    if it gets out of range, continue

                move right pointer unitl it finds non repeating number
                if it repeats

                evaluate

        test:

        */

        //declare result variable
        int result = 0;

        //traverse
        for(int i = 1; i < nums.size(); i++){
            //declare pointers and flag
            int left = i - 1;
            int right = i + 1;
            bool repeats = false;

            //traverse left pointer (maybe could remove this block of code)
            //while(left >= 0 && nums[left] == nums[i]){
                //left--;
            //}

            //if(left < 0) continue;

            //traverse right pointer
            while(right < nums.size() && nums[right] == nums[i]){

                //check if right repeats
                if(nums[right] == nums[i]) repeats = true;

                right++;
            }

            if(right >= nums.size()) continue;
            
            //compare

            //hill
            if(nums[left] < nums[i] && nums[right] < nums[i]) result++;
            //valley
            if(nums[left] > nums[i] && nums[right] > nums[i]) result++;
            

            //check if right number is repeated
            if(repeats){
                int aux = nums[i];
                while(i < nums.size()-1 && nums[i+1] == aux) i++;
            }
        }

        return result;
        
    }
};

/*
Time: 42 minutes

Got the answer right in the first 25 minutes, but wasted the rest of the time in a bug
due to me not realizing I was moving i, when the characters repeat before comparing id nums[i]
was a hill or a valley.

Still, good effort on my first leetcode problem since november.

Complexity:
    runtime: O(n)
    space: O(1)

Best conceivable comlexity.
I could have used dynammic window technique, and I did, but unconsciously.

The pattern is, I always start from a number which has no repiting numbers on left side, according to my algorithm
because if I found repeating numbers on the right, after comparing. I'll just jump from the current number into the
number that is not being repeated


*/