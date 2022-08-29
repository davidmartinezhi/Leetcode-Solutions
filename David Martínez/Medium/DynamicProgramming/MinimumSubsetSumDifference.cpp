#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution
{
    public:
        int minSubsetSumDifference(vector<int> nums){

            //declare variables
            int n = nums.size();
            int sum = 0;

            //get sum
            for(int i = 0; i < n; i++){
                sum += nums[i];
            }

            //declare matrix
            bool dp[n+1][sum+1];

            //traverse matrix to get subset of sums that can be made
            for(int i = 0; i < n+1; i++){
                for(int j = 0; j < sum+1; j++){
  
                    if(j == 0){
                        //sum equals to 0
                        dp[i][j] = true;
                    }
                    else if(i == 0){
                        //no items
                        dp[i][j] = false;
                    }else if(nums[i-1] > j){
                        //num is bigger than current sum
                        dp[i][j] = dp[i-1][j];
                    }else{
                        dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                    }
                }
            }

            //check the biggest differential
            int diff = INT_MAX;

            //from the first index to the middle
            //if sum can be made, get differential
            for(int i = 0; i < sum/2 + 1; i++){

                int first = i;
                int second = sum-i;

                if(dp[n][i] == true && diff > abs(second-first)){
                    diff = abs(second-first);
                }
            }

            return diff;

        }
};

int main()
{

    vector<int> nums;
    nums.push_back(9);
    nums.push_back(1);
    nums.push_back(2);

    Solution sol;

    cout << endl;
    cout << sol.minSubsetSumDifference(nums) << endl;     
    return 0;
}
