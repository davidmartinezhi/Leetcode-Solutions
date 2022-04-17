#include <iostream>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
    /*
    1. listen
        input: string "s" and integer "k"
            I can change any char in the sring and change it to any other uppercase letter
            I can perform this operarion "k" times
        
        output: length of the longest substring containing the same letter
                after performing the previous operation
    
    2. example
    
        cuaderno
    
    3. brute force
        know the unique characters that exist in the string
        for each character, implement kadanes algorithm and compare window
        sliding window technique con wndow dinamica que se estira cuando es igual o hay reserva
        sino, quita de atras, si es igual la letra la agrega a reserva y sino solo la recorre
        
        runtime: O(n^2)
        space: O(n)
    
    4. optimize
    
        BCR: O(n)
        save the previous next char
        
        Sliding winddow technique
        
    5. walkthrough
    
    6. implement
    
    7. test
        all letters are the same
        all letters are different
        mixed letters
    */
        

        int n = s.size();
        int charCounts[26] = {0};   //Array con 26 letras del alfabeto 
        
        int maxLength = 0;  
        int windowStart = 0;
        int maxCount = 0;

        for(int windowEnd = 0; windowEnd < n; windowEnd++){
            charCounts[tolower(s[windowEnd]) - 'a']++;  //Aumenta 1 a esa letra
            int currentCharCount = charCounts[tolower(s[windowEnd]) - 'a']; //Saca la freq de la ult letra actualizada
            maxCount = max(maxCount, currentCharCount); //Saca cual es la Freq más grande
            
            while(windowEnd - windowStart - maxCount + 1 > k){  //Si se pasa de k
                charCounts[tolower(s[windowStart]) - 'a']--;    //Movemos el primer pointer y quitamos la freq del array
                windowStart++;
            }
            
            maxLength = max(maxLength, windowEnd - windowStart + 1);    //Sacamos max
        }
        
        
        return maxLength;

    }
};