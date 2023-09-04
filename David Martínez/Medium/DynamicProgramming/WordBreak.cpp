#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*
        info
            input: 
                - string "s"
                - dictionary of strings "wordDict"

            output:
                - true if s can be segmenteeed into a space separated
                  sequence of one or more dictionary words

            constraints:
                - can words in dictionary be reused? yes
                - how many words can i expect in the dictionary? [1, 1000]
                - what range of size can i expect strings to be? s:[1,300], inside dict: [1,20]
                - what type of characters will the string have? lowercase english letters

        example
        Input: s = "leetcode", wordDict = ["leet","code"]
        -> true
        leetcode can be segmentes as leet code
          [l,e,e,t,c,o,d,e]
          [1,0,0,0,1,0,0,0,1]

        s = "applepenapple", wordDict = ["apple","pen"]
        -> true
        apple pen apple
        [a,p,p,l,e,p,e,n,a,p,p,l,e]
        [1,0,0,0,0,1,0,0,1,0,0,0,0,1]

        s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
        -> false
        [c,a,t,s,a,n,d,d,o,g,s]
        [0,0,0,,0,0,0,0,0,0,0]

        brute force
            since we need to know all possible arrangements of dictionary words in s
            it is a dynammic programming approach problem

            tabular approach is efficient

            starting from the end
            for each cell in dp array
                if the word matches
                    set as the value in the dp

            complexity:
                runtime: O(size of s * (dictionary size * largest string))
                extra space: O(size of s)

        optimize
            best conceivable runtime: O(size of s + (dictionary size * largest string))

            approach is optimal

        test
            - s can be separated into a space-separated sequence
            - s cannot be separated
        */

        //declare variables
        int n = s.size();
        int m = wordDict.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;

        //traverse each letter of s, backwards
        for(int i = n-1; i >= 0; i--){

            //traverse each word
            for(int j = 0; j < m; j++){

                string word = wordDict[j];

                //if it fits the answer and is a substring, check 
                if(i + word.size() <= n && s.substr(i, word.size()) == word){
                    dp[i] = dp[i + word.size()];
                }

                if(dp[i]) break;
            }
        }

        return dp[0];
    }
};

/*
Time: 32 minutes

complexity:
    runtime: O(s size * dict size * word size)
    extra space: O(s size)

He avanzado bastante en programación dinamica. Hace un año
este problema era mi pesadilla pero ahora lo pude solucionar relativamente rapido y de la 
manera más eficiente.

Pero aún debo de checar y saber cuando utilizar el patron de recorrer desde atras.
Podría servir más que nada para cuando quieres saber si algo contiene otra cosa.

También se podría hacer recorriendo hacía adelatne y lo voy a tratar de hacer así

No se puede hacer comendzando desde el primer indice hacía el ultimo, debe ser del ultimo al primero

En estos casos aplica más el recorrer del final hacía el inicio.

* Dependencias hacia atrás: Cuando el estado actual depende de estados futuros, es más fácil calcular los estados futuros primero y luego usarlos para calcular los estados actuales.
* Optimización de Memoria: En algunos casos, solo necesitas mantener un subconjunto de todos los estados posibles en la memoria en un momento dado. Al recorrer de atrás hacia adelante, puedes sobrescribir estados que ya no son necesarios, ahorrando memoria.
* Subproblemas Anidados: En problemas donde los subproblemas están anidados de una manera que el subproblema más grande necesita ser resuelto antes que los más pequeños (por ejemplo, en la programación de intervalos), es útil recorrer de atrás hacia adelante.
* Problemas de Secuencia: En problemas donde estás tratando con secuencias (como cadenas de texto o arrays) y la solución óptima a un subproblema depende de las soluciones a los subproblemas que vienen después en la secuencia.
*/