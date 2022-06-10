#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    int rob(vector<int>& nums) {
        /*
        1. listen:
            first house is neighbour to the last house.
            can't rob adjacent houses
            
            input: integer array nums
            output: max amount of money you can rob
            
        2. example
            nums = [2,3,2]
            -> 3
            
            nums = [1,2,3,1]
            -> 4
            
            
            nums = [2,7,9,3,1]
            -> 11
            
            [0,2,7,11,11]
            [0,7,9,10,10]
            
            -> 11
            
            nums = [1,2,3]
            -> 3
            
            [0,1,2]
            [0,2,3]
            
            nums = [1,2,3,100]
            -> 4
            
            [0,1,2,4]
            [0,2,3,102]
            
        3. brute force
            use recursivity to find all passible convinations of money robbed
        
        4.optimize
            use dp
            O(2n) time
            O(1) extra space
            
        5. walkthrough
            traverse two times
            one starting from first index
            another starting from 2nd index
            
        
        7. test
            -array of size 1
            -array of size 2
            -array of size greater than 2
            
        */
        
        //size of original array
        int n = nums.size();
        
        //check for array of size 1
        if(n == 1) return nums[0];
        
        //check for array of size 2
        if(n == 2) return max(nums[0],nums[1]);
        
        
        //aux vector for dp
        vector<int> dp(n,0);
        dp[0] = 0;
        dp[1] = nums[0];
        
        //variable for max money
        int maxMoney = 0;

        //traverse the list from index 0
        for(int i = 1; i < n-1; i++){
            dp[i+1] = max(nums[i]+dp[i-1], dp[i]);
        }
       
        maxMoney = dp[n-1];

        
        //traverse the list from index 1
        dp[1] = nums[1];
        //[1,2,3,4]
        //[0,2,0,0]
        for(int i = 1; i < n-1; i++){
            dp[i+1] = max(nums[i+1]+dp[i-1], dp[i]);
        }

        //Return
        return max(maxMoney, dp[n-1]); 
    }
};

/*
Notas:
    terminado en 43 minutos
    Me tarde con la logica en el traversal comenzando del 1er index, tener una manera de sibujar en la pantalla
    será muy eficiente y yo diría es un must, el utilizarlo.

    En general, buena performance y buen razonamiento para la respuesta optima. Se puede optimizar, pero el approach
    es el ideal.

    Fue de mucha aayuda el video de nick, explicando house robber 1, me hizo formalizar el pensamiento en dp
    cuando quieres sacar un valor maximo.

*/

int main(){
    return 0;
}