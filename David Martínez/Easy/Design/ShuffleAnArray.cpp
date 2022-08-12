#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

/*
info
    input: integer array "nums"
        design an algorithm to randomly shuffle the array
        All permutations of the array should be equally likely as the result of the shuffle
        
    constraints:
        array length is between 1 and 50
        nums[i] is between -million and million
        all elements are unique
        at most 10,000 calls will be made to reset and shuffle
        
Example

Brute Force shuffle and reset
    save original array
    generate random numbers
    
    get random number for indexes shuffled, get random number for shuffled indexes
    

*/
class Solution {
private:
    vector<int> nums;
    vector<int> original;
    
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        this->original = nums;
    }
    
    vector<int> reset() {
        nums = original;
        return original;
    }
    
    vector<int> shuffle() {
        random_shuffle(nums.begin(), nums.end());
        return nums;
    }
};

//14 minutes with random_shuffle function
/*
Debo incluir libreria random y algorithm
auto rd = random_device {};
auto rng = default_random_engine {rd()};
random_shuffle(nums.begin(), nums.end());
Then shuffle

*/

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */