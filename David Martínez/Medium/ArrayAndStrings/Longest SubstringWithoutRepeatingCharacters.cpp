#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //1 listen
            //Input: string "s"
            //Output: int of the longest substring without repeating characters
            
            //"s", length ranges between 0 and 50,000 characters
            //"s", consists of englidh letters, digits, simbols and spaces
        
        //2 example
            /*
            s = "abcabcbb" -> 3 ["abc"]
            s = "bbbbb" -> 1 ["b"]
            s = "pwwkew" -> 3 ["wke" o "kew"]
            s = "abcdabcdea" -> 5 ["abcde"]
            */
        //3 brute force
            /*
            Sliding window technique with a dynamic window and a hashtable that checks char frequency
            If a char repeats, we compare de dynamic window count, with the maxCount
            runtime: O(n^2) if non of the characters is repeated
            Memory: O(n) 
            */
        
        //4 optimize
            /*
            Check until we reach the last element, then break.
            Runtime: O(n)
            Memory: O(n)
            
            BCR: O(n)
            */
        
        //5 walkthrough
            //Creo contador por fuera con maxCount de 0
            //Recorro el string
                //Creo contador auxiliar
                //Creo hashtable vacía
        
                //Recorro la ventana mientras el char no este actualmente en el hashtable
                //Si se repita, comparo contadores y dejo el más grande
                
        //Si j llega a ser igual que i, salgo del for loop
        
        //6 implement
        
        //7 test
        //Todos los char son diferentes
        //Todos los char son iguales
        //Diferentes chars pero si se repiten
        
            //Special cases:
                //String vacío
                
        int maxCount = 0;
        
        
        for(int i = 0; i < s.size(); i++){//O(n)
            //Creo el contador de la ventana y hashtable para checar frecuencia de letras
            int windowCount = 0;
            unordered_map<char, int> letters;
            
            //O(n)
            int j = i;//Comienzo la ventana en i
            while(j < s.size()){    //Mientras no lleguemos al final
                
                
                //Si la letra se encuentra en el hashtable
                if(letters.find(s[j]) != letters.end()){
                    maxCount = (maxCount > windowCount) ? maxCount : windowCount;
                    break;

                }
                else{   //Si la letra no se encuentra en la hashtable
                    letters[s[j]]++;  //La agrego al hashtable
                    windowCount++;  //Aumento la windowCount
                }
                
                //Aumento j
                j++;
                
            }
            
            //Si J ya esta en el final, comparamos ultima ventana y regreso resultado
            if(j == s.size()){
                maxCount = (maxCount > windowCount) ? maxCount : windowCount;
                break;
            }
        }
        
        return maxCount;
        
    }
};