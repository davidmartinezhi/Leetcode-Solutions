#include <iostream>
#include <vector>

using namespace std;

int cutRibbon(int & n, int & a, int & b, int & c ){

    //declare variables
    vector<vector<int> > dp(4, vector<int>(n+1, 0));
    vector<int> ribbonCuts;

    //add cut options
    ribbonCuts.push_back(a);
    ribbonCuts.push_back(b);
    ribbonCuts.push_back(c);

    //unbounded knapsack
    /*
    vector<int> dp(n+1, 0);
    //traverse each ith position in the ribbon, time O(n)
    for(int i = 1; i <= n; i++){

        //traverse possible cuts. time O(1), always 3
        for(int j = 0; j < 3; j++){

            //check if ribbon cut can be done
            if( i - ribbonCuts[j] >= 0){
                dp[i] = max(dp[i - ribbonCuts[j]] + 1, dp[i]);
            }
        }
    }
    */

    //bounded knapsack
    //traverse possible cuts. time O(1), always 3
    for(int i = 0; i <= 3; i++){

        //traverse each position in the ribbon. O(n)
        for(int j = 0; j <= n; j++){

            
            if(i == 0){ //first row
                dp[i][j] = -1;
            }
            else if(j == 0){ //first col
                dp[i][j] = 0;
            }
            else if(ribbonCuts[i-1] > j){ //cut cannot be made
                dp[i][j] = dp[i-1][j]; //value in that index that makes up quantity
            }
            else{
                //max between new cut + previous before that length and previous cuts to that length
                dp[i][j] = max(dp[i][j - ribbonCuts[i-1]] + 1, dp[i-1][j]);
            }
        }
    }    

    //return max number of cuts
    return dp[3][n];
}

int main()
{
    //declare variables
    int n, a, b, c;

    //receive input
    cin >> n >> a >> b >> c;

    //cutRibbon to get max pieces
    cout << cutRibbon(n, a, b, c) << endl;

    return 0;
}
