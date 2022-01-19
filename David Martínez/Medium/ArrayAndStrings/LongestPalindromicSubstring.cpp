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

/*
Al final del día lo que importaba no era el tamaño del string, sino el tamaño del palindromo
Si tuve la idea de comenzar desde en medio pero no descrubrí ese patron.

Siento que debería de quedarme más tiempo trabajando sobre yo entender el patron en el ejemplo. Antes de si quiera sacar el brute force, porque me estanque con el approach que saque como brute force y apenas lo escribí y salte a diferentes maneras de resolverlo con optimmización.

Si antes se me ocurrian maneras diferentes de resolverlo mientras programaba y perdía tiempo. Ahora estoy haciendo lo mismo, pero antes de. Siento que es bueno para sacar un buen approach, pero es de suma importancia entender el patron primero al igual que saber bien la información.

Otra cosa es que me limite a querer hacer uns tring auxiliar siempre, en lugar de querer guardar un index donde comienza el palindromo y usar substring junto con la longitud del palindromo, para sacar el substring de manera directa desde el string.

Siento que estuvo bajo mi nariz, la solución optima y si pense en maneras de hacerlo así. Pero por no sacar el patron de que es muy importante el tamaño del palindromo, es que me desvie a soluciones más complejas y menos eficientes.

Resumen:
    -Entender bien el patron entre input y output. Al igual que la info dentro del input y como se posría relacionar al output.
    -No limitarme a querer tener una variable con la respuesta, puedo tener solo un apuntador al inicio de la respuesta y de ahí saco el resto.
https://www.youtube.com/watch?v=ZJUGtWObroc solución

*/