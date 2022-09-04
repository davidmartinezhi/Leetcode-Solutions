#include<iostream>
#include<vector>
#include <math.h>

using namespace std;

//El secreto es solo sacar lo que buscas, en esrte caso S1 y S1 es (sum+diff)/2
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

            
        test
            -target greater than sum of all elements
            -target sum equal to 0, if target is 0 return 0, else 1
            
            
            
        */
        
        //optimal solution
        
        // get sum of all elements
        int sum = 0;
        int ceroesCount = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(nums[i] == 0) ceroesCount++;
        }
        
        //check if value is possible or sum+target are an odd number
        if(target > sum || (sum + target) % 2 != 0) return 0;
        
        //get Subset we are searching for
        int s1 = abs((target + sum) / 2);
        
        //create dp table to know what value we are looking for
        int dp[nums.size()+1][sum+1];
        
        for(int i = 0; i < nums.size()+1; i++){
            for(int j = 0; j < sum+1; j++){
                
                //first col
                if(j == 0){
                    dp[i][j] = 1;
                }
                
                //first row
                else if(i == 0){
                    dp[i][j] = 0;
                }
                
                //current num is greater than sum we are on
                else if(nums[i-1] > j || nums[i-1] == 0){
                    dp[i][j] = dp[i-1][j];
                }
                
                //comparison
                else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                }
            }
        }
        
        //return value at position s1 multiplied by 0s frequency to the power of 2
        //if there are no 0s, answer will hace 1 * dp[nums.size()][s1];
        return pow(2, ceroesCount) * dp[nums.size()][s1] ;
        //return dp[nums.size()][s1];
    }
};
/*
Terminado en 45+

Brute force salio en 25 minutos.
Pero esta solución si fue pensar un poco más.

Literal era la solución que ya había hecho para subsets with given difference.
Es encontrar la cantidad de subsets que hacen un valor.
Ese valor lo encuentro con: (sum+targer/diff)/2

*/
