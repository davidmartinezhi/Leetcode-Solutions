/*
Act3.3
Knapsack Problem Solution

The input to the program is a number N representing the number of possible elements available,
followed by N integers representing the value of each of those elements,
followed by N integers representing the weights associated with each element.
finally, an integer W, which represents the maximum weight or capacity of the backpack.

The output of the program must be the optimal gain (or benefit) and the elements associated with said gain.

David Gerardo Martinez Hidrogo - A01235692 
Humberto Ricardo Rodriguez Ruan - A01197898

Created: Oct 6, 2022 12:54pm    Last Modification: Oct 18, 2022 02:12pm

*/

#include <iostream>
#include <set>
#include <vector>
#include <iterator>
using namespace std;

/*
Receive elements with weight and value represented as arrays, and a w capacity
Return optimal benefit and weights associated to that benefit

Complexity
    time: O(capacity(w) * number of elements)
    extra space: O(capacity(w) * number of elements)

*/

/*
void optimalBenefit(vector<int> & values, vector<int> & weights, int & n, int & w){

    //dp tables
    vector<vector<int> > dp(n+1, vector<int>(w+1));
    vector<vector<vector<int> > > dpWeights(n+1, vector<vector<int> >(w+1, vector<int>()));

    //traverse the tables
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= w; j++){

            //first row and col
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            //check if weight is valid
            else if(j < weights[i-1]){
                dp[i][j] = dp[i-1][j];
                dpWeights[i][j] = dpWeights[i-1][j];
            }
            //check for max value
            else{
                //add 
                if(dp[i-1][j] < dp[i-1][j-weights[i-1]] + values[i-1]){
                    dp[i][j] = dp[i-1][j-weights[i-1]] + values[i-1];
                    dpWeights[i][j] = dpWeights[i-1][j-weights[i-1]];
                    dpWeights[i][j].push_back(i);
                }else{
                    dp[i][j] = dp[i-1][j];
                    dpWeights[i][j] = dpWeights[i-1][j];
                }
                //dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i-1]] + values[i-1]);
            }
        }
    }

    cout << dp[n][w] << " ";
    for(int i = dpWeights[n][w].size() - 1; i >= 0 ; i--){
        cout << dpWeights[n][w][i] << " ";
    }

}
*/

/*
Receive elements with weight and value represented as arrays, and a w capacity
Return optimal benefit and weights associated to that benefit

Complexity
    time: O(capacity(w) * number of elements)
    extra space: O(capacity(w) * number of elements)

*/
void optimalBenefit(vector<int> & values, vector<int> & weights, int & n, int & w){

    //dp tables
    vector<vector<int> > dp(n+1, vector<int>(w+1));

    //get optimal value
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= w; j++){

            //first row and col
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            //check if weight is valid
            else if(j < weights[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            //check for max value
            else{
                //add 
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i-1]] + values[i-1]);
            }
        }
    }

    //get weights associated to optimal value
    //optimal value
    int optimalVal = dp[n][w];
    cout << optimalVal << " ";

    //traverse matrix backwards
    for(int i = n; i > 0; i--){

        bool found = false; //search for optimal value first instance

        for(int j = w; j >= 0; j--){

            //check if optimal value has appeared previously
            if(dp[i-1][j] == optimalVal){
                found = true;
            }

        }

        //if we found the first instance
        if(!found){
            cout << i << " ";   //print position
            optimalVal -= values[i-1]; //update optimal value
        }
    }
}

/*
Get Optimal benefit of fitting elements of weights and values
into a limited weight capacity

Complexity
    time: O(capacity(w) * number of elements), due to getting optimal benefit
    extra space: O(capacity(w)^2)
*/
int main()
{
    //Declare vairables
    int n; // number of elements
    int w; //capacity of knapsack
    vector<int> values; //values of each element
    vector<int> weights;    //weight of each element

    //Receive information
    cin >> n; //number of elements

    for(int i = 0; i < n; i++){ //value of elements
        int value;
        cin >> value;
        values.push_back(value);
    }

    for(int i = 0; i < n; i++){ //weight of elements
        int weight;
        cin >> weight;
        weights.push_back(weight);
    }

    cin >> w; //capacity of knapsack

    //display optimal benefit and elements associated with that benefit
    optimalBenefit(values, weights, n, w);


    return 0;
}
