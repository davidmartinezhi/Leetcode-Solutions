#include <iostream>
#include <vector>

using namespace std;

/*
Find max profit of cutting the rod into different pieces
and selling
*/

int rodCut(vector<int> &price, vector<int> &length, vector<vector<int> > &mem, int maxLen, int size)
{

    // base case
    if (size == 0 || maxLen == 0)
        return 0;

    // recursive call

    // exclude length cut
    if (length[size - 1] > maxLen)
    {
        mem[size][maxLen] = rodCut(price, length, mem, maxLen, size - 1);
    }
    // Include or exclude
    else
    {
        mem[size][maxLen] = max(price[size - 1] + rodCut(price, length, mem, maxLen - length[size - 1], size),
                                rodCut(price, length, mem, maxLen, size - 1));
    }

    return mem[size][maxLen];
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
    profit = rodCut(price, length, mem, size, size);

    // return answer
    cout << "Profit: " << profit << endl;

    return 0;
}
