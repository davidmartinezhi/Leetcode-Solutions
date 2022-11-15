#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        
        //while b is not 0
        while(b != 0){

            //get the positions where we need to carry
            unsigned carry = a&b;

            //perform sum
            a = a^b;

            //shift carry
            b = carry << 1;
        }

        return a;

    }
};