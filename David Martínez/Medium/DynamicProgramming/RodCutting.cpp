#include <iostream>
#include <vector>

using namespace std;

/*
Find max profit of cutting the rod into different pieces
and selling
*/

int rodCutMem(vector<int> &price, vector<int> &length, vector<int> &mem, int size)
{
    //check if value has already been calculated
    if(mem[size] == -1e6){

        //traverse lengths
        for(int i = 1; i <= size; i++){

            //get value of profit of that length, and check amount with rest of money
            int temp = price[i-1] + rodCutMem(price, length, mem, size - i);

            //if we get more profit, we update the max possible profit for that length
            if(temp > mem[size]){
                mem[size] = temp; //update
            }
        }
    }

    return mem[size];
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
    price.push_back(2);
    price.push_back(7);
    price.push_back(14);
    price.push_back(15);

    // memoization
    vector<int> mem(size + 1, -1e6);
    mem[0] = 0;

    // call funtion
    //profit = rodCutMem(price, length, mem, size);
    profit = rodCutIt(price, length, size);

    // return answer
    cout << "Profit: " << profit << endl;

    return 0;
}
