#include <iostream>
using namespace std;


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        /*
        info
            input
                * 32 bits unsigned integer

            output
                * reversed bit

            constraint
                * input is a binary string of 32 bits

        example
            n = 00000010100101000001111010011100
            ->  00111001011110000010100101000000

            result = 0

            get Bit = 0

            position it at the other end in a sum

            do result | sum

            complexity
                runtime: O(32) -> O(1)
                extra space: O(1)

        brute force
            have result
            traverse bits
                get bit
                add to toAdd int in correct position
                do result or toAdd

            return result

        test
            * reverse bits
            * palindrome
        */

        //Declare variables
        int result = 0;

        /*
        n = 00001
        bit = 00001

        5
        0
        5-(5-i)
        5-(5-0) = 0
        5-(5-1) = 1
        5-(5-2) = 2
        5-(5-3) = 3

        */

        for(int i = 0; i < 32; i++){

            //get bit
            int bit = (n >> i) & 1;

            //set bit on correct position
            bit = (bit << 31-i);

            //do or operation on bit and result
            result |= bit;
        }

        return result;
    }
};

/*
time: 15 minutes

complexity:
    runtime: O(32) -> O(1)
    extra space: O(1)

Estoy comenzando a entender bastante bien bit manipulation, aunque no creo tener que llegar
a usarlo en alguna entrevista.



*/