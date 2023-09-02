#include <iostream>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {

        // declare variables

        // lengths
        int len1 = text1.size();
        int len2 = text2.size();

        // dp table
        int dp[len1 + 1][len2 + 1];

        // traverse and fill table
        for (int i = 0; i <= len1; i++)
        {
            for (int j = 0; j <= len2; j++)
            {

                // first row and columns
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                // match
                else if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                // no match
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[len1][len2];

        /*
                // Declarar variables
        int len1 = text1.size();
        int len2 = text2.size();
        vector<int> dp(len2 + 1, 0); // Usamos un vector unidimensional para ahorrar espacio
        int prev; // Variable para almacenar el valor anterior de dp[j]

        // Recorrer el vector
        for (int i = 1; i <= len1; ++i) {

            prev = 0; // Inicializar prev para cada nueva fila

            for (int j = 1; j <= len2; ++j) {

                int temp = dp[j]; // Almacenar el valor actual de dp[j] antes de actualizarlo

                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = prev + 1;

                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }

                prev = temp; // Actualizar prev para la siguiente iteración
            }
        }

        return dp[len2];
        
        */
    }
};

/*
Debo comenzar a tomar tiempo otra vez

Complexity:
    time: O(text1 * text2)
    extra space: o(text1 * text2)

Es igual que cuando queria checar longest common substring
Pero substring buscaba a los que estuviesen pegados.

En este caso, arrastramos el valor maximo hasta que hayan más updates
y seguimos comparando

*/