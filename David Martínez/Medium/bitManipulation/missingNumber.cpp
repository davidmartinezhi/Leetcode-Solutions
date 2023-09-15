#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
        info
            input:
                * array "nums" containing n distinct numbers in range [0,n]

            output:
                * the only number in that range that is missing

            constraints:
                * what range of sizes can nums have? [1, 10000]
                * all numbers are unique
                * n == nums.length
                
        example
            nums = [3,0,1]
            -> 2

            for each number in a hashtable set its binary value as key and int value as val

            then start with a bit representation of 0 and move all the way up to n

            if the bit representation is not found, return it as value

        brute force
            * have an array of size n
            *for each num we see we set its value in the array to 1

            *traverse array and index that is 0, is the value we return

            complexity:
                runtime: O(n*2) -> O(n)
                extra space: O(n)

        optimize
            best conceivable runtime: O(n)

            does bit manipulation can be helpful?
            I believe it can, I know there is a method where we can add
            values an it will take them in the nexxt corresponding order

        test:
            * 0 is missing
            * last number is missing
            * number in between 0 and n is missing
        */
        int n = nums.size();
        long int sum = (n*(n+1))/2, sum2 = 0;
        for(int num : nums) sum2 += num;
        return sum-sum2;

        /*
        //declare variables
        int n = nums.size();
        vector<bool> numbersFound(n+1,false);

        //traverse nums, to set found nums
        for(int i = 0; i < n; i++){
            numbersFound[nums[i]] = true;
        }

        //search for num not found
        for(int i = 0; i <= n; i++) if(numbersFound[i] == false) return i;

        return 0;
        */

    }
};

//18 minutes

/*
Debo investigar cual era el metodo con el que conseguía los valores en orden,
así sabía cuales numeros faltaban.

Estoy mejorando en bit manipulation.

Buen inicio, pero el syntax aún me hace un poco de ruido

*/