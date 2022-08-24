#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubsets(vector<int>& nums, int sum) {

        //set variables
        int n = nums.size();

        //create dp table
        int dp[n+1][sum+1];

        //traverse the dp table
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= sum; j++){

                if(j == 0){
                    dp[i][j] = 1;
                }else if(i == 0){
                    dp[i][j] = 0;
                }
                else if(nums[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                }
            }
        }

        //return
        return dp[n][sum];

    }
};

int main()
{
    int sum = 3;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);

    Solution sol;

    cout << endl;
    cout << sol.countSubsets(nums, sum) << endl; 
    return 0;
}

/*
complexity:
    time: O(items in array * sum)
    extra space: O(items in array * sum)

    Tabulation method
*/