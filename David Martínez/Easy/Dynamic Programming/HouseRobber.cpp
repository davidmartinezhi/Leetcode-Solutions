#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        int rob(vector<int> & nums){
        /*
        1. listen
            input: integers array "nums", representing the amount of money on each house
            output: maximum amount of money without alerting the police
            
            police is alerted when adjacent houses are robbed
            
            constraints:
                array has length between 1 and 100
                each has can contain between 0 and 400 in money
        
        2. example
            nums = [1,2,3,1]
            -> 4
            
            nums = [2,7,9,3,1]
            -> 12
            
            nums = [3,5,8,10,20,21]
            -> 36
            
            nums = [100, 20, 3, 1]
            -> 103
            
            nums = [100, 20, 3, 400]
            -> 500
            
            [100,99, 20, 19,3, 1]
            103
            101
            
            [3,5,8,10,20,21,200,400]
            prev: 31
            prev-last: 36
            max: 36
            
            [100, 20, 3, 400]
            prev:500
            prev-last:100+400=500
            max:500
            
        3. brute force
            use recursion to find all diferent ways to rob house and select the optimal
            runtime: O(!n)
            extra space: O(n)
        
        4. optimize
            memoization
            need to store info of prev max value on subarray
            and from it, decide what to do
            
            O(n) runtime
            O(1) extra space
            
        5. walkthrough
            traverse to know if the array is sorted
            if sorted, we traverse 2 by 2
            if not sorted
                declare prev, prev-last variable

            
        7. test
            special cases:
                sorted array small to great
                sorted array great to small
                mixed number values
                array with all values the same
        */
        
        
        //variables to know if array is sorted
        bool asc = true;
        bool desc = true;
        
        //declare variables to know if array is sorted
        for(int i = 1; i < nums.size(); i++){
            //descending
            if(nums[i-1] < nums[i]) desc = false;
            
            //ascending
            if(nums[i-1] > nums[i]) asc = false;
        }
        
        if(asc == false && desc == false){
            int prev = nums[0];
            int prevNoLast = 0;
            /*
            [100, 20, 3, 400]
            prev:103
            prevNoLast:100
            max:100
            */
            
            for(int i = 1; i < nums.size(); i++){
                if(prevNoLast+nums[i] > prev){
                    int aux = prev;
                    prev = prevNoLast+nums[i];
                    prevNoLast = aux;
                }
                else{
                    prevNoLast = prev;
                }
            }
            
            return max(prev, prevNoLast);
            
        }else{
            int sum1 = 0;
            int sum2 = 0;
            for(int i = 0; i < nums.size(); i+=2){
                sum1 += nums[i];
                if(i < nums.size()-1){
                    sum2 += nums[i+1];
                }
            }
            
            return max(sum1, sum2);
        }
        
        return 0;
    }
};

/*
Notas:
    terminado en + de 45 minutos
    complejidad:
        time: O(n)
        extra space: O(1)

    Ya sabía que era un problema de programación dinamica, pero tarde en obtener una solución
    Debo precticar más tecnicas para resolver este tipo de problemas
    Este problema lo resolcí al ir guardando siempre valores previos en variables diferentes. 
    Debo de aplicar tecnica y formalizarla para mi kit de dynammic programming problem solving.

*/