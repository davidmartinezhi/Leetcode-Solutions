#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        info
            input:
                * int array nums

            output:
                * majority element

            majority element is the element that appears more than n/2 times

            constraints:
                * majority element always exists
                * what range of sizes can the array have? [1, 50000]
                * what range of values can the number have? [-90000, 90000]

        example
            nums = [3,2,3]
            -> 3

            nums = [2,2,1,1,1,2,2]
            -> 2

        solution
            best conceivable runtime: O(n)

            have a hashtable to know numbers frequency
            traverse array to fill hashtable
                if frequency appears more than n/2 return number

            complexity
                runtime: O(n)
                extra space: O(n)

        test
            
        */

        //get size
        int n = nums.size();

        //declare variables
        float majority = n/2;
        unordered_map<int, int> ht;

        //traverse array
        for(int num: nums){
            ht[num]++;

            if(ht[num] > majority) return num;
        }

        return -1;

    }
};
//8 minutes
/*
time: 8 minutes
complexity:
    runtime: O(n)
    extra space: O(n)

I have really come a long way, this question was easy
*/