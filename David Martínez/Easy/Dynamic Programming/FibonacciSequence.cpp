#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        /*
            info
                input: n
                output: fibonacci number on the sequence
                constraints: n is between 0 and 30
                
            example
                n = 2
                -> 1
                
                0 1 1
                
                n = 3
                -> 2
                
                0 1 1 2
                
            brute force
                recursively get the number on the sequence
                complexity: 
                    time: O(n)
                    extra space: O(2^n)
            
            optimize
                use two ints and update them for constant memory
                time: O(n)
                
                bcr: O(n)
                
            walkthrough
                set both variables
                check if number is 1 or 2
                else start process
                
            test
            
                
        */
        
        int first = 0;
        int second = 1;
        
        //check if n is 0 or 1
        if(n == 0) return first;
        else if(n == 1) return second;
        
        //if n is grater than 1
        while(n > 0){
            int aux = second;
            second = first + second;
            first = aux;
            n--;
        }
        
        return first;
    }
};