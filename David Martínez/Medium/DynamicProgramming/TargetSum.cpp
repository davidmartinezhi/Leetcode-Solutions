#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
        info
            input: int array "nums" and integer "target"
            
                build an expression out of nums by adding one of the simbols
                "+" and "-" before each integer. Then concatenate al integers
                
            output: number of different expressions we can build which evaluates to target
            
            constraints:
                array is between length 1 and 20
                each value in the array is between 0 an 1000
                the sum is between 0 and 1000
                target sum is between -1000 and 1000
            
        example
            nums = [1,1,1,1,1] target = 3
            -> 5
            
            Sum of all elements is 5
            all possible combinations that gives me 3
            
            nums = [1] target = 1
            -> 1
            
        brute force
            recursivity
            complexity is exponential 2^n
            
        optimize
            
            
            bcr: O(n)
            Dynammic programming, tabulation
            
            get all possible ways to get target and divide it by 2
            Should prove it works on all cases
            
        implementation
            declare size and sum variable
            compare if target sum can be made
            
            declare dp table
            fill it
            
            the last cell / 2 is the answer
            
            if answer is equal to 0, return 1
            else return answer
            
        test
            -target greater than sum of all elements
            -target sum equal to 0, if target is 0 return 0, else 1
            
            
            
        */
        
        //brute force

        return recursiveSolution(nums, target, 0, 0);
    }
    
    int recursiveSolution(vector<int> & nums, int & target, int index, int currSum){
        //base cases
        
        //index reaches the end and the sum IS NOT equal to target
        if(index >= nums.size() && currSum != target) return 0;
        
        //index reaches the end and the sum IS equal to target
        else if(index >= nums.size() && currSum == target) return 1;
        
        //keep searching
        else return recursiveSolution(nums, target, index+1, currSum + nums[index]) + recursiveSolution(nums, target, index+1, currSum - nums[index]);     
    }
    
};

//brute force terminado en 25-30 minutos
//checar la manera optima de resolver este problema
//Me va a fallar si le doy correr, pero aún así lo intentare

/*
Tengo una noción sobre como resolverlo de manera dinamica, pero debo de checar bien como
https://www.youtube.com/watch?v=hqGa65Rp5LQ&list=PLEJXowNB4kPxBwaXtRO1qFLpCzF75DYrS&index=13

Checar subset de valores positivos y negativos suena a una buena idea
S1-S2 me da el valor que busco
Debo de sacar S1, ese es el frame que debo de sacar.
Encontrar un valor que me de la respuesta y ya basar la respuesta en eso.

En el video lo hace sonar super simple
    Sacar los subsets donde ese numero - los restante. me dan el resultado
    Es lo que ya he estado haciendo. El framing es muy importante,
    Debería de analizar diferentes maneras de hacer el frame rapido


*/
