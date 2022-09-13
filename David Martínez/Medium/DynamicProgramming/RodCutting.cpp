#include <iostream>
#include <vector>

using namespace std;

/*
Find max profit of cutting the rod into different pieces
and selling
*/

int rodCutMem(vector<int> &price, vector<int> &length, vector<vector<int> > &mem, int maxLen, int size)
{

    // base case
    if (size == 0 || maxLen == 0)
        return 0;

    // recursive call

    // exclude length cut
    if (length[size - 1] > maxLen)
    {
        mem[size][maxLen] = rodCutMem(price, length, mem, maxLen, size - 1);
    }
    // Include or exclude
    else
    {
        mem[size][maxLen] = max(price[size - 1] + rodCutMem(price, length, mem, maxLen - length[size - 1], size),
                                rodCutMem(price, length, mem, maxLen, size - 1));
    }

    return mem[size][maxLen];
}

int rodCutIt(vector<int> &price, vector<int> &length, int maxLen){

    //create dp table
    int n = price.size();

    int dp[n+1][maxLen+1];

    //traverse and fill
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= maxLen; j++){

            //first column
            if(j == 0){
                dp[i][j] = 0;
            }
            //first row
            else if(i == 0){
                dp[i][j] = -1e6;
            }

            //exclude
            else if(length[i - 1] > j){
                dp[i][j] = dp[i-1][j];
            }

            //compare include and exclude
            else{
                dp[i][j] = max(price[i-1] + dp[i][j - length[i-1]] , dp[i-1][j]);
            }
        }
    }

    return dp[n][maxLen];
}

int main()
{
    // declare variables

    // profit
    int profit;

    // rod size
    int size = 4;

    // length and price
    vector<int> length;
    length.push_back(1);
    length.push_back(2);
    length.push_back(3);
    length.push_back(4);

    vector<int> price;
    price.push_back(1);
    price.push_back(5);
    price.push_back(8);
    price.push_back(9);

    // memoization
    vector<vector<int> > mem(size + 1, vector<int>(size + 1));

    // call funtion
    //profit = rodCutMem(price, length, mem, size, size);
    profit = rodCutIt(price, length, size);

    // return answer
    cout << "Profit: " << profit << endl;

    return 0;
}
