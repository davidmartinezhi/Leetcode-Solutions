#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //bottom up approach
        int n = s.size();
        
        //create dp array for valid word connections
        vector<bool> dp(n+1, false);
        dp[n] = true;   //set last value as true
        
        //traverse string backwards
        for(int i = n-1; i >= 0; i--){
            
            //traverse words dictionary
            for(string w: wordDict){
                
                //check if word size is valid and if word matches
                if(i + w.size() <= n && s.substr(i,w.size()) == w){
                    dp[i] = dp[i+w.size()]; //set if it matches and the order
                }
                
                if(dp[i]) break; //if we found a true value, we jump to next index
            }
        }
        
        //Return if the string can be made
        return dp[0];
    }
};

/*
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //bottom-up approach
        
        //declare variables
        int n = s.size();   //string size
        bool dp[n+1][n+1];  //dp table
        
        unordered_set<string> myset;    //unordered set
        
        //add dictionary words to unordered set
        for(auto word: wordDict)
            myset.insert(word);
        
        //traverse the dp array and fill values
        for(int length=1;length<=n;++length) //Window Size
        {
            int start = 1;  //declaring starting point of window
            int end = length;   //declaring end point of window
            
            while(end<=n) //Sliding Window moves while end hasn0t reach the end
            {
                string temp = s.substr(start-1,length); //declare substring of indexes in window
                
                //if word exists in dictionary
                if(myset.find(temp)!=myset.end()){
                    dp[start][end] = true;  //set cell as true
                }   

                //if word doesn't exists, check if it has been found before
                else
                {
                    bool flag = false;
                    
                    //decrease window all the way to the end
                    for(int i=start;i<end;++i)
                        
                        //if we have found a word in current index and on previous index
                        //checa todo posible combinación de partición que nos valide hasta
                            //el dato en el que estamos
                        if(dp[start][i] and dp[i+1][end])
                        {   
                            //set as true that cell
                            flag = true;
                            break;
                        }
                    dp[start][end] = flag;
                }
                
                //move the sliding window
                start += 1;
                end += 1;
            }
        }
        
        //return if sordbreak has been found
        return dp[1][n];
    }
};
*/
/*
Time: 45+ minutes

Complexity:
    time: O(n^3)
    extra space: O(n)

No estuve muy alejado de una solución optima. El tratar de conseguir algo O(n^2) me hizo perder mucho
tiempo y pensamiento.

Si de plano no puedo pensar en el bcr, que muchas veces no se puedde hacer. Debería de intentar irme con lo siguiente mejor
que se me pueda ocurrir. en este caso si pude iniciar con brute force y checar mempization para optimizar
Y no iba a estar lejos de la solución más optima

Pero esta solución es muy optima también y resuelve mis dudas sobre trabajar con substrings ya encontrados.
Lo cual es algo que ya había curioseado, pero no lo había aplicado. Enotnces me alegra que haya salido.

Podría hacer algo de permutaciónes de una palabra con esto? Creo que si
    Creo que es lo mismo que dijo Kevin sobre el problema de las ranas, sería fibonacci en log n
*/