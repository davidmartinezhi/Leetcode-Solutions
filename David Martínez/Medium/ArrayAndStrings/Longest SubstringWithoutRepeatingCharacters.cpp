#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // 1 listen
        // Input: string "s"
        // Output: int of the longest substring without repeating characters

        //"s", length ranges between 0 and 50,000 characters
        //"s", consists of englidh letters, digits, simbols and spaces

        // 2 example
        /*
        s = "abcabcbb" -> 3 ["abc"]
        s = "bbbbb" -> 1 ["b"]
        s = "pwwkew" -> 3 ["wke" o "kew"]
        s = "abcdabcdea" -> 5 ["abcde"]
        */
        // 3 brute force
        /*
        Sliding window technique with a dynamic window and a hashtable that checks char frequency
        If a char repeats, we compare de dynamic window count, with the maxCount
        runtime: O(n^2) if non of the characters is repeated
        Memory: O(n)
        */

        // 4 optimize
        /*
        Check until we reach the last element, then break.
        Runtime: O(n log n) - O(n^2)
        Memory: O(n)

        BCR: O(n)
        */

        // 5 walkthrough
        // Creo contador por fuera con maxCount de 0
        // Recorro el string
        // Creo contador auxiliar
        // Creo hashtable vacía

        // Recorro la ventana mientras el char no este actualmente en el hashtable
        // Si se repita, comparo contadores y dejo el más grande

        // Si j llega a ser igual que i, salgo del for loop

        // 6 implement

        // 7 test
        // Todos los char son diferentes
        // Todos los char son iguales
        // Diferentes chars pero si se repiten

        // Special cases:
        // String vacío

        /*
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
       */

        // Dynamic Window, Slidin window technique
        // Runtime: O(n + n)
        // Memory: O(n)
        /*
        int maxCount = 0;   //Contador con palabras

        unordered_map<char, int> ht;    //Hashtable, repositorio de palabras O(n) memory

        //Comienzo de i
        //Muevo j hasta que se repita un character
        //Comparo la cuenta actual con el maxCount

        //Agrego todas las letras existentes y les pongo contador de 0
        //Paso extra para mejorar entendimiento en este ejemplo, abajo viene ejemplo sin esto
        for(int i = 0; i < s.size(); i++){  //O(n) runtime
            if(ht.find(s[i]) == ht.end()){
                ht[s[i]] = 0;
            }
        }

        //Recorro i, hasta que no se repita la letra que se repitió

        int i = 0;
        int j = 0;

        //Proceso de agregar al hashtable las letras
        //Mientras j sea menor a s.size() y la letra no esté en 0
        int windowCount = 0;
        while(j<s.size() && (ht[s[j]] <= 1)){   //O(n) runtime

            //Sumamos uno a esa letra
            ht[s[j]]++;
            windowCount++;  //Sumo esa palabra en la cuenta de la ventana actual

            if(ht[s[j]] > 1){   //Si esa key tiene un valor mayor a 1

                //Comparo la ventana, restandole el 1 a la letra que se acaba de repetir
                maxCount = (windowCount - 1 > maxCount) ? windowCount - 1 : maxCount;

                while(ht[s[j]] != 1 && i < j){  //Mientras esa letra tenga un valor diferente a 1
                                                //Sabemos que se repitio, por eso sabemos que es más que 1
                    ht[s[i]]--; //La letra en i, la disminuyo
                    i++;    //Recorro i
                    windowCount--;  //Actualizo la ventana
                }
            }

            j++; //Recorremos al siguiente dato
        }

        //Proceso de comparación, en el caso de que j haya llegado al final. Para que haga comparación
            //Con la ultima window Activa
        if(j == s.size()){
            maxCount = (windowCount > maxCount) ? windowCount : maxCount;
        }

    return maxCount;
    */

        // El mismo codigo pero más simplificado
        // Dynamic Window, Slidin window technique
        // Runtime: O(n)
        // Memory: O(n)

        int maxCount = 0; // Contador que guarda la cuenta maxima

        unordered_map<char, int> ht; // Hashtable, repositorio de palabras

        // Comienzo de i
        // Muevo j hasta que se repita un character
        // Comparo la cuenta actual con el maxCount

        // Recorro i, hasta que no se repita la letra que se repitió

        int i = 0; // Apuntador que se queda atras y avanza cuando se repite alguna letra
        int j = 0; // Apuntador que avanza en busca de más letras, hasta encontrar una repetida

        int windowCount = 0; // Contador dinamico, va a cambiar con las letras
        while (j < s.size() && (ht.find(s[j]) == ht.end() || ht[s[j]] <= 1))
        //Mientras no lleguemos al final de la lista y esa letra no esté en la hashtable o tenga cuenta menor a 2
        {

            // Sumamos uno a esa letra o agregamos con valor de 1 si es que no existe
            ht[s[j]]++;
            windowCount++;  //Incremento tamaño de la ventada 

            if (ht[s[j]] > 1)   //Si esa letra es repetoida
            {
                maxCount = (windowCount - 1 > maxCount) ? windowCount - 1 : maxCount;   //Comparo la cuenta maxima, con la ventana, sin contar la letra que repetida que acabo de agregar
                while (ht[s[j]] != 1 && i < j)  //Mientras esa letra tenga un valor mayor a 1
                {
                    ht[s[i]]--; //Restamos la letra en la posición de i
                    i++;    //Recorremos i
                    windowCount--;  //Updateamos la ventana

                    //Esto, hasta que la letra no se repita
                }
            }
            j++; // Recorremos al siguiente dato
        }

        // Proceso de comparación
        if (j == s.size())
        {
            //Si no se pudo comparar la ultima cuenta activa, la commparo aquí
            maxCount = (windowCount > maxCount) ? windowCount : maxCount;
        }
        
        return maxCount;
    }
};

/*

Solución creada paso todas las pruebas y es aceptada. Pero se puede optimizar bastante

Siento que se podría hacer en solo una recorrida, pero debo repasar la dynamic window.
Para que la ventana se mueva como una oruga arrastandose, en lugar de una ventana nueva que se abre en cada index.

También tratar de hacerlo todo, pensando en ingles. Para no batallar en traducir cuando este en la entrevista


Haciendo enfasís en esta parte del brute force
"Sliding window technique with a dynamic window and a hashtable that checks char frequency
If a char repeats, we compare de dynamic window count, with the maxCount"

Puedo hacer la window más pequeña desde la izquierda hasta que esa letra que se repitio solo tenga valor de 1
Sería remover esos valores de la hashtable

Así ya avancé i, hasta un punto donde no se estan repitiendo los valores. Haciendo que ahora si sea un solo recorrido como oruga.
En lugar de checar Para cada letra, hasta que char ya no se repite.
//O(n) runtime
//O(n) hashtable

*Debo ser capaz de sacar estas ideas a la primera, debería buscar alguna manera de recordar o repasar conceptos.

*/