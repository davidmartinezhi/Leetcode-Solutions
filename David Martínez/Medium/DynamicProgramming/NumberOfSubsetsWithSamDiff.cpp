#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
    int countSubsetsWithSameDiff(vector<int> & nums, int & diff){

        //declare variables
        int n = nums.size();
        int sum = 0;
        int targetSum;

        //get sum of numbers
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        //target sum
        targetSum = sum - diff;

        //declare dp table
        int dp[n+1][targetSum+1];

        //fill the dp table
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= targetSum+1; j++){

                //items
                if(j == 0){
                    dp[i][j] = 1;
                }else if(i == 0){
                    dp[i][j] = 0;
                }else if( nums[ i-1 ] > j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                }
            }
        }

        return dp[n][targetSum];

    }

};

int main()
{
    int diff = 3;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    Solution sol;

    cout << endl;
    cout << sol.countSubsetsWithSameDiff(nums, diff) << endl; 
    return 0;
}
