#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        //1 listen
            //Input: string "s"
            //Output: longest palindromic string of "s"
            
            //Palindrome is a word that is read the same from left to right and from tight to left
            //"s" length ranges from 1 to 1,000
            //"s" consists of only digits and english letters
        
        //2 example
        /*
        "babad" ->"bab"
        "cbbd" -> "bb"
        "abccbaefghi" -> "abccba"
        "cbcbaklmopnp" -> "cbc"
        Puedo comenzar de enmedio
        */
        
        //3 brute force
            //Sliding window technique, donde la ventana crece hasta que no se cumpla el palindrome
            //Cada palindromo puede ser checado con 2 pointers. Uno al inicio y otro al final
                //Si se cumple, incrementamos la ventana por 1 y checamos otra vez
                //Si ya no se cumple, comparamos el size del string con el strngMax
            //Esta solución sería de O(n^3) runtime, casi casi. Necesito algo más eficiente
        
        //4 optimize
            /*
            BCR: O(n)
            
            //Puedo reducir el trabajo a la mitad?
                //Podría hacer dynamic slidin window technique para que se mueva como una oruga
            //Podría sacar frecuencia de las letras y en base a eso, saber cual mover
            
            Optimizaciones sobre mi brute force
            Voy a recorrer hasta encontrar una letra igual a la que estoy, ahí checo si es palindromo
            De lo contrario solo sigo recorriendo
            
            Puedo checar palindromo
            
            Puedo meter todos los datos a una hashtable y cuantas veces aparecen en el string
            Cada que encuentre una letra, le resto 1. Si es igual a 0. La salto.
            
            Si no es igual a 0, recorro hasta encontrar la otra letra igual
                //Comparo para saber si es un palindromo. Si es un palindromo comparo size con maxSub
                
            
            
            Si el substring tiene el tamaó de la mitas de s.size() regreso.
            
            Puedo comenzar de enmedio, debo investifar sobre esta posible solución
            
            
            */
        //5 walkthrough
            /*
            Haré el brute force primero, luego las otras soluciones.
            
            */
        
        //6 implement
        
        
        //7 test
            //Palindomo de tamaño par
            //Palindromo de tamaño non
        
        //Usare el approach de 2 apuntadores que inician desde el centro
            //En easy llegue a checar palindrome, checando de afuera hacía adentro
            //Ahora checare de adentro hacía afuera
        
            //Runtime: O(n^2)
            //Memory: O(1)
        
        int n = s.size();
        
        if(n == 1) return s;
        
        int maxLength = 1;
        int palindromeIndex = 0;
        
        //Tenemos 2 posibilidades
            //Palindromo tiene un tamaño non
                //Eso significa que debemos saltar de 1 a 3 a 5 a 7 en la comparación que hacemos
                
            //Palindromo tiene un tamaño par
                //Eso signifia que debemos saltar de 2 a 4 a 6 a 8 en la comparacion
            
            //Entonces voy a recorrer el string 2 veces, pero de distinta manera
        
        //Non
        for(int i = 0; i < n; i++){
            int l = i;
            int r = i;

            while(l >= 0 && r < n){
                
                if(s[l] == s[r]){
                    l--;
                    r++;
                }
                else{
                    break;
                }
            }
            
            //Comparo substrings
            int len = r-l-1;
            if(len > maxLength){
                maxLength = len;
                palindromeIndex = l+1;
            }
        }
        
        
        //Par
        for(int i = 0; i < n; i++){
            int l = i;
            int r = i+1;

            
            while(l >= 0 && r < n){
                
                if(s[l] == s[r]){
                    l--;
                    r++;
                }
                else{
                    break;
                }
            }
            
            //Comparo substrings
            int len = r-l-1;
            if(len > maxLength){
                maxLength = len;
                palindromeIndex = l+1;
            }
        }        
        
        
        
        return s.substr(palindromeIndex, maxLength);
    }
    
};