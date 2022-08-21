/*
David Gerardo Martínez Hidrogo - A01235692
Humberto Ricardo Rodriguez Ruán - A01197898

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
*/

#include <iostream>
#include <vector>
using namespace std;

#include "./mergeSortBigToSmall.h"


//dynamic solution
vector<int> coinChange(vector<int> &coins, int amount)
{
    /*
        Returns array with coin denominations needed
        complexity:
            time: O(array size * amount)
            space: O(2(array size * amount)) = O(array size * amount)
    */

    // set variables
    int n = coins.size();

    // matrix minimum coins
    vector<int> aux(amount+1);
    vector<vector<int> > dp(n+1, aux);
    
    // matrix coin denominations array
    vector<vector<vector<int> > > dpDenomination(n + 1, vector<vector<int> >(amount+1));

    // traverse the matrix
    for (int i = 0; i <= n; i++)
    {
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
                dp[i][j] = dp[i - 1][j];
                dpDenomination[i][j] = dpDenomination[i - 1][j];
            }
            // comparison
            else
            {
                if(1 + dp[i][j - coins[i - 1]] < dp[i - 1][j]){
                    dp[i][j] = 1 + dp[i][j - coins[i - 1]];
                    dpDenomination[i][j] = dpDenomination[i][j - coins[i-1]];
                    dpDenomination[i][j].push_back(coins[i-1]);
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                    dpDenomination[i][j] = dpDenomination[i - 1][j];
                }
            }
        }
    }

    // check if the amount of money could be made
    if (dp[n][amount] > 1e4)
        return dpDenomination[0][0];

    return dpDenomination[n][amount];
}

//dynamic solution
vector<int> coinChangeGreedy(vector<int> &coins, int amount)
{
    /*
        Returns array with coin denominations needed
        complexity:
            time: O(n log n)
            space: O(1)
    */

    // set variables
    int n = coins.size();
    vector<int> result;

    //sort array
    sort(coins.begin(), coins.end());

    //grab coins
    for(int i = coins.size() - 1; i >= 0; i--){
        int auxN = coins[i];

        while(auxN <= amount){
            result.push_back(auxN);
            amount -= auxN;
        }

    }

    return result;
}

int main()
{
    //set variables for problem
    int p, q; //price and bill used to pay
    int n;  //number of denominations
    vector<int> list; //denominations
    vector<int> result;

    //create list for problem
    cin >> n;
    
    while(n > 0){
        //adds numbers to the list
        int auxN;
        cin >> auxN;
        list.push_back(auxN);
        n--;
    }

    //get price of product and bill it is payed with
    cin >> p;
    cin >> q;

    //get vector with corresponding denominations for minimum coins
    result = coinChange(list, q-p);
    //result = coinChangeGreedy(list, q-p);

    //sort the array from greater to smaller
    vector<int> aux(result.size());
    mergeSort(result, aux, 0, result.size()-1); //complexity: time O(n log n)
    
    //print resulting list
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
