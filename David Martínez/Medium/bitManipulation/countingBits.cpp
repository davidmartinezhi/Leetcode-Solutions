#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> countBits(int n) {
        /*
        info
            input: integer "n"

            output: array "ans" of length "n+1"
                    such that each i (0 <= i <= n), ans[i]
                    is the number of ones in the binary representation

            constraints:
                - what range of numbers can the integer have? [0, 10^5]
        
        example
            n = 2
            -> [0,1,1]

            n = 5
            16 8 4 2 1 0
            0 1 2 4 8 16
            0 1 1 2 1 2

            on each index number, count the integer number of bits being '1' and return

        brute force
            - use a mask
            for each index the answer is the number of 1s 

            integer has 32 bits

            complexity:
                runtime: O(32*n) -> O(n)
                extra space: O(n)

        optimize
            best conceivable runtime: O(n)

        test:
            * n == 0
            * n > 0

        */

        //declare variables
        vector<int> numOfOnes(n+1, 0);

        for(int i = 0; i <= n; i++){
            //numOfOnes[i] = countOnes(i);
            numOfOnes[i] = __builtin_popcount(i);
        }

        return numOfOnes;
    }

    int countOnes(int num){
        /*
        //declare variables
        int count = 0, mask = 1;

        //traverse the integer
        for(int i = 0; i < 32; i++){

            //check if bit position containts a 1
            if((num&mask) != 0) count++;
            mask = mask << 1;
        }

        return count;
        */
        
        int count = 0;

        while(num != 0){
            num = num&(num-1);
            count++;
        }
        return count;
    }
};

//15 minutes