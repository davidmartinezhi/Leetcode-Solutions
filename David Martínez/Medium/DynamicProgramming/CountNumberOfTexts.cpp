#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;  // Define the modulo constant

class Solution {
public:
    int countTexts(string pressedKeys) {
        /*
        info
            input:
                - string "pressedKeys", representing the string received by bob

            output:
                - total number of possible text messages alice could have sent

            constraints:
                - how long can the input string be? range [1, 100000]
                - is the answer inside a 32 bit integer? no, return modulo 10^9 + 7
                - what characters can the string contain? ['2'-'9']

        example
            pressedKeys = "22233"
            -> 2 2 2 3 3
            -> 22 2 3 3
            -> 2 22 3 3
            -> 222 3 3
            -> 2 2 2 33
            -> 22 2 33
            -> 2 22 33
            -> 222 33

            if its 7 or 9 we can check 4 presses at the time

            pressedKeys = "2 2 2 3 3"
                          [1,2,4,1,1,1]
                          4*2 -> 8

            pressedKeys = "2 2 2 2 2"
                          [1,2,4,7,13,0]
                          4*2 -> 8
                          2 2 2 2
                          22 2 2
                          2 22 2
                          2 2 22
                          22 22
                          222 2
                          2 222

            
            pressedKeys = "2 2 2 3 3 1 1"
                          [1,2,4,1,2,1,2]
                          4*2 -> 8

        brute force
            recursively check if substring is valid

            total count = 1*2 = 2*4 = 8
            count = 4
            pressedKeys = "22233"

            could use memoization and keep the complexity efficient
            complexity:
                runtime: O(n)
                extra space: O(n) stack calls

        optimize
            best conceviable runtime: O(n)
            problem is of dynammic programming nature

            I'll use tabulation bottom-up approach

            
        
        test
            * check if answer is larger than module 10^9 + 7
            * string is of size 1

            hotspots:
                - backward check is not out of index
        */

        int n = pressedKeys.size();  // Get the size of the input string
        vector<int> dp(n + 1, 0);  // Initialize the dp array with 0s
        dp[0] = 1;  // Base case: empty string has 1 way to be formed

        // Loop through each character in the input string
        for (int i = 1; i <= n; ++i) {
            char currChar = pressedKeys[i - 1];  // Get the current character
            int options = (currChar == '7' || currChar == '9') ? 4 : 3;  // Determine the number of options for the current digit

            // Loop to find all possible combinations of the current character
            for (int j = i, k = 1; j > 0 && k <= options; --j, ++k) {
                
                // Check if the character matches the current character
                if (pressedKeys[j - 1] == currChar) {
                    // Update dp[i] with the sum of dp[j - 1] and dp[i], modulo MOD
                    dp[i] = (dp[i] + dp[j - 1]) % MOD;
                } else {
                    break;  // If the character doesn't match, break the loop
                }
            }
        }

        return dp[n];  // Return the final answer
    }
};