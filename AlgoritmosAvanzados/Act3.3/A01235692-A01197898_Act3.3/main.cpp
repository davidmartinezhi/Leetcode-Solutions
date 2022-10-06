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

Created: Oct 6, 2022 12:54pm    Last Modification: 

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //Declare vairables
    int n; // number of elements
    int w; //capacity of knapsack
    vector<int> elements;
    vector<int> weights;    //weight of elements

    //Receive information
    cin >> n; //number of elements

    for(int i = 0; i < n; i++){ //elements of kanpsack
        int element;
        cin >> element;
        elements.push_back(element);
    }

    for(int i = 0; i < n; i++){ //weight of value of elements
        int weight;
        cin >> weight;
        weights.push_back(weight);
    }

    cin >> w; //capacity of knapsack


    return 0;
}
