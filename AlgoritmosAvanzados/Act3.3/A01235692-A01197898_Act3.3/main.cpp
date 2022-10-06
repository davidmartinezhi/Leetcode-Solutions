/*
Act3.3
Knapsack Problem Solution

The input to the program is a number N representing the number of possible elements available,
followed by N integers representing the value of each of those elements,
followed by N integers representing the weights associated with each element.
finally, an integer W, which represents the maximum weight or capacity of the backpack.

The output of the program must be the optimal gain (or benefit) and the elements associated with said gain.

David Gerardo Martínez Hidrogo - A01235692 
Humberto Ricardo Rodriguez Ruán - A01197898

Created: Oct 6, 2022 12:54pm    Last Modification: Oct 6, 2022 01:47pm

*/

#include <iostream>
#include <vector>
using namespace std;

/*
Receive elements with weight and value represented as arrays, and a w capacity
Return optimal benefit and weights associated to that benefit

Complexity
    time: O(capacity(w) * number of elements)
    extra space: O(capacity(w)^2)

*/
void optimalBenefit(vector<int> & values, vector<int> & weights, int & n, int & w){

    //Declare dp vectors
    vector<int> dp(w+1, 0); // optimal benefit
    vector<vector<int> > dpWeights(w+1, vector<int>(0)); //weights associated to optimal benefit

    for(int i = 1; i <= w; i++){ // traverse weight
        for(int j = 0; j < n; j++){ //traverse elements

            //If weight can be checked
            if( i - weights[j] >= 0 ){

                //check if previous weight value + new weight value is bigger than curr index
                if(dp[i] <= dp[i - weights[j]] + values[j]){
                    dp[i] = dp[i - weights[j]] + values[j]; //update index
                    dpWeights[i] = dpWeights[i - weights[j]]; //update vector of values
                    dpWeights[i].push_back(weights[j]); //add value
                }
            }
        }
    }

    cout << dp[w] << " ";//optimal value

    for(int i = 0; i < dpWeights[w].size(); i++){   //weights associated to that optimal value
        cout << dpWeights[w][i] << " ";
    }
    cout << endl;

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
