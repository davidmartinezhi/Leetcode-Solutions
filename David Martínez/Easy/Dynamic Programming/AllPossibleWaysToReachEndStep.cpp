#include <iostream>
using namespace std;

class Solution
{
    public:

    int allPossibleWaysToReachEndEstep(int & n)
    {
        /*
        Without matrix
        complexity
            time: O(3*n) = O(n)
            extra space: O(n)
        */

        //check if n is less or equal than 2
        if(n == 2) return 2;
        else if(n == 1) return 1;
        else if(n == 0) return 0;

        //create dp array of stairs
        int dp[n+1];
        dp[0] = 1; 

        for(int i = 1; i <= n; i++){
            dp[i] = 0;
            for(int j = 1; j <= 3; j++){
                
                //for each step that can be reached jumping either with 1,2 or 3 steps
                if(i >= j){

                    //the way to get all possible ways to reach that stair. 
                    //is to add all the possible ways that can get us to that stair.
                    //so at the end, we add up. dp[i-1] + dp[i-2] + dp[i-3] = dp[i].
                    //It's like fibonacci, but summing the last 3 digits, instead of 2
                    dp[i] = dp[i] + dp[i-j];  
                }
            }
        }
        for(int i = 0; i < n+1; i++){
            cout << dp[i] << " ";
        }
        cout << endl;

        return dp[n];
        }
};

int main()
{
    int n = 5;
    Solution solution;

    cout << solution.allPossibleWaysToReachEndEstep(n) << endl;

    return 0;
}
