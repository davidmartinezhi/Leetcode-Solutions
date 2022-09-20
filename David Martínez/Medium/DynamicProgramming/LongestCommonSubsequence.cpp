#include <iostream>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        //declare variables
        
        //lengths
        int len1 = text1.size();
        int len2 = text2.size();
        
        //dp table
        int dp[len1+1][len2+1];
        
        //traverse and fill table
        for(int i = 0; i <= len1; i++){
            for(int j = 0; j <= len2; j++){
                
                //first row and columns
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                //match
                else if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                //no match
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[len1][len2];
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