#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        info:
            input: array prices where i is the stock price on a given day
            ouput: maximum profit achievable
            
            max profit by buying stock on a single day and selling it in the future
            if no profit can be achieved, return 0
            
            constraints:
                array size is between 1 and 100,000
                stock prices varie from 0 to 10,000
        
        example:
            [7,1,5,3,6,4]
            -> 5
            
            [7,2,5,1,3,6,4,1]
            -> 5
            5
            
            [7,1,5,3,6,4]
            -> 0
            
        brute force:
            for each day in the array
                traverse the rest of days and compare the maximum achievable profit
            complexity: 
                time: O(n^2)
                extra space: O(1)
        
        optimize:
        
            Best Case Running Time: O(n)
            
            Two pointer technique
            kadane's algorithm
            
        test:
            hotspot: i runs until array size -1
            
            
        
        */
        
        //brute force
        /*
        //max profit varibale
        int maxProfit = INT_MIN;
        
        //travers
        for(int i = 0; i < prices.size() - 1; i++){
            for(int j = i+1; j < prices.size(); j++){
                if(prices[j]-prices[i] > maxProfit) maxProfit = prices[j]-prices[i];
            }
        }
        
        if(maxProfit <= 0) return 0;
        
        return maxProfit;
        */
        
        //optimize
        
        //profit variable
        int maxProfit = -1;
        
        //low price index
        int low = 0;

        //traverse the array
        for(int i = 1; i < prices.size(); i++){
            int profit = prices[i] - prices[low];
            if(profit < 0) low = i;
            else maxProfit = (maxProfit < profit) ? profit : maxProfit;
        }
        
        if(maxProfit < 0) return 0;
        return maxProfit;
        
    }
};


