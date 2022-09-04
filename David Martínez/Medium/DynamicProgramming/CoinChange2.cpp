#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*
        info
            input: integer array "coins", integer "amount"
            output: number of combinations that make up that amount
                if the amount of money cannot be made, return 0
                
            constraints:
                -we may assume we have infinite number of each kind of coin
                -answer fit 32-bit integer
                -array has length between 1 and 300
                -array values range between 1 and 5000
                -all the values are unique
                -amount is between 0 and 5000
                
        example
            amount = 5, coins = [1,2,5]
            -> 4
            
            amount = 3, coins = [2]
            -> 0
            
            amount = 10, coins = [10]
            -> 1
            
        brute force
            recursive solution
            
            each coin can be added or not
            
            complexity: O(# of coins ^ max level) exponential
            
            while value is less than amount
            if value is equal to amount return 1
            else 0
            return  recursive call adding the number again + 
                    recursive call jumping to next denomination
        
        optimize
            knapsack unbounded (infinite instances can be included)
            dp programming
            
            Count Subsets with given amount
            Tabulation matrix, where we count the number of ways we can
            create an amount, with different subsets
            
            complexity:
                time: O(denominations*sum)
                extra space: O(denominations*sum)
        
        walkthrough
            get sum of all denominations
            create dp table
                fill the table
            return last row and amount column
            
        test
            amount can't be done
            amount can be done
            
            amount is greater than sum
            amount is lesser than sum
            
                
        */
        
        int n = coins.size();
        
        //create dp table
        int dp[n+1][amount+1];
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= amount; j++){
                //first col
                if(j == 0){
                    dp[i][j] = 1;
                }
                //first row
                else if(i == 0){
                    dp[i][j] = 0;
                }
                //current num can't make the sum
                else if(coins[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                //update
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
            }
        }
        
        return dp[n][amount];
    }
};
/*
terminado en 43 minutos

complexity:
    time: O(# of coins * amount)
    extra space: O(# of coins * amount)

Entendí muy bien el problema, me quede ciclado en conseguir el numero de subsets en bounded knapsack
Porque en ese se toma como base la suma maxima de todos los numeros, pero en unbounded puedes
tener cualquier numero infinita cantidad de veces. Entonces es mejor tomar como referencia el amount
que te piden.
*/