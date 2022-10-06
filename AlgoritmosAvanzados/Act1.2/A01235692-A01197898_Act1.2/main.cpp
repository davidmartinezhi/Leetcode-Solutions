/*
Instrucciones:
Utilizando las técnicas de programación de "programación dinámica", y la de "algoritmos avaros",
escribe en equipos de máximo dos personas, en C++ un programa que resuelva el problema del cambio de monedas.

El programa recibe un numero entero N, seguido de N valores enteros (uno en cada línea)
que representan las diferentes denominaciones disponibles de las monedas.

Seguido de esto, el programa recibe dos números enteros: P y Q, (uno en cada línea) por la entrada estándar,
que representan P: el precio de un producto dado y Q: es el billete o moneda con el que se paga dicho producto.

La salida del programa es una lista de N valores correspondientes al número de monedas de cada denominación,
de mayor a menor, una en cada línea, que se tienen que dar para dar el cambio por el producto pagado,
primero utilizando programación dinámica, y luego utilizando un algoritmo avaro.

David Gerardo Martínez Hidrogo - A01235692
Humberto Ricardo Rodriguez Ruán - A01197898

Last modified: Oct 4, 2022
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "./mergeSortBigToSmall.h"


/*
With a Dynammic Programming approach
Receives array of coin denominations and a target
Returns array of min coins that add up to target
complexity:
    time: O(array size * amount)
    space: O((array size * amount2))
*/
vector<int> coinChange(vector<int> &coins, int amount)
{

    // set variables
    int n = coins.size();

    //matrix minimum coins
    vector<vector<int> > dp(n + 1, vector<int>(amount + 1));

    // matrix coin denominations array
    vector<vector<vector<int> > > dpDenomination(n + 1, vector<vector<int> >(amount + 1));

    // traverse matrix
    //for every coin denomination
    for (int i = 0; i <= n; i++)  
    {
        //check how many are needed for min coins that sum to target
        for (int j = 0; j <= amount; j++) 
        {
            // first col
            if (j == 0)
            {
                dp[i][j] = 0;
            }
            // first row
            else if (i == 0)
            {
                dp[i][j] = 1e5;
            }
            // if current value is greater, we skip
            else if (coins[i - 1] > j)
            {
                //just set cells as values previously found
                dp[i][j] = dp[i - 1][j];
                dpDenomination[i][j] = dpDenomination[i - 1][j];
            }
            // comparison
            else
            {
                //if the current coins needed for target is smaller than the previously found
                if (1 + dp[i][j - coins[i - 1]] < dp[i - 1][j])
                {
                    dp[i][j] = 1 + dp[i][j - coins[i - 1]]; //Set value of min coins needed for that value
                    dpDenomination[i][j] = dpDenomination[i][j - coins[i - 1]]; //Set vector as the one in that position
                    dpDenomination[i][j].push_back(coins[i - 1]); //add new coin adn denomination
                }
                else
                {
                    //bring values previously found to that cell
                    dp[i][j] = dp[i - 1][j]; 
                    dpDenomination[i][j] = dpDenomination[i - 1][j];
                }
            }
        }
    }

    // check if the amount of money could be made
    if (dp[n][amount] > 1e4)
        return dpDenomination[0][0];

    //reverse list
    for(int i = 0; i < dpDenomination[n][amount].size()/2; i++){
        int size = dpDenomination[n][amount].size();

        int aux = dpDenomination[n][amount][size-i-1];
        dpDenomination[n][amount][size-i-1] = dpDenomination[n][amount][i];
        dpDenomination[n][amount][i] = aux;

    }

    //Return list
    return dpDenomination[n][amount];
}

/*
With a greedy approach
Receives array of coin denominations and a target
Returns array of min coins that add up to target
complexity:
    time: O(n log n), due to the sorting algorithm
    space: O(1)
*/
vector<int> coinChangeGreedy(vector<int> coins, int amount)
{

    // set variables
    int n = coins.size();
    vector<int> result;

    // sort array
    vector<int> aux(coins.size());
    mergeSort(coins, aux, 0, coins.size() - 1); // complexity: time O(n log n)

    // grab coins
    for (int i = 0; i < coins.size(); i++)
    {
        int auxN = coins[i]; //current coin

        while (auxN <= amount)  //while coin is smaller or equal to amount
        {
            result.push_back(auxN); //Add coin
            amount -= auxN; //substract from amount to find
        }
    }

    //check if amount can be made
    if(amount != 0) return vector<int>(0);

    return result;
}

/*
Print list
receives a list and prints the values it contains
complexity
    time: O(n), n being the number of elements in the list
    extra space: O(1)
*/
void printList(const vector<int> &list)
{
    // traverse list
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " "; // print values
    }
    cout << endl;
    return;
}

int main()
{
    // Declare variables
    int price, bill;
    int n;                     // number of denominations
    vector<int> denominations; // denominations
    vector<int> resultDp;      // result for Dynammic Programming method
    vector<int> resultGreedy;  // result for Greedy method

    // Get Coin denominations
    cin >> n; // get amount of coins

    while (n > 0) // get coin denominations
    {
        int auxN;
        cin >> auxN;
        denominations.push_back(auxN);
        n--;
    }

    // Get Price of product and bill it is payed with
    cin >> price; // price
    cin >> bill;  // bill

    // Get denominations for change with both methods
    resultDp = coinChange(denominations, bill - price);
    resultGreedy = coinChangeGreedy(denominations, bill - price);

    // print resulting denominations
    printList(resultDp);
    printList(resultGreedy);

    return 0;
}
