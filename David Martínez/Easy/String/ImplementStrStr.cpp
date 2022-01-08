#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        //1 listen
            //Return the index of the first ocurrance of needle in haystack
            //If needle isn't in haystack, return -1
            //If needle is an empty string, we return 0
            //Haystack and needle sizes, ranges between 0 and 50,000
        
        //2 example
            // haystack: "hello", needle: "ll" -> 2
            // haystack: "abbccdcdcdcd", needle: "cd" -> 4
            
        //3 brute force
            //Sliding window tecnique and when the substring matches, we return the index.
            //Memory: O(1)
            //Runtime: O(n)

        //4 optimize
            //BCR O(n)
            //If the string was sorted, we could use binary search
                
        
        //5 walkthrough
            //Get size of needle, to create the window
            //If size of needle is 0, return 0
            //Compare it to the haystack size, if neddale is bigger, we return -1
            //Traverse the haystack in search for the needle
                //If found, we return the index
            //If not found, return -1
        
        //6 implement
            //Siento que con pointers, podría no tener que usar el for loope
        
        //7 test
            //needle not in haystack
            //needle in haystack
            //Special cases:
                //Haystack empty
                //needle empty
                //Haystack is smaller than needle
        
            //To do:
                //Double check the condition in for loop
        
        //Eficiencia de runtime: O(n-window * window)
        //Eficiencia memoria: O(1)

        
        int window = needle.size();
        
        //Check if needle is empty
        if(window == 0){ return 0; }
        
        //Check if needle is bigger than the haystack
        if(window > haystack.size()){ return -1; }
        
        //Traverse the string
        for(int i = 0; i <= haystack.size() - window; i++){
            //I coul just do a loop inside this one, 0 < window. and compara haystack[i] and needle[j]
            
            //To optimize I could just check for characters who start with the same letter as window
            if(haystack[i] == needle[0]){
                //If the substring is found
                if(isSubstring(haystack, needle, i, i + window)){
                    return i;   //Return index
                }                
            }
        }
        
        return -1;  //If needle not found, return -1
        
        //"stringtest"
        //"ri"
        //

    }
    
    //Helper funciton to traverse substring
    bool isSubstring(string & haystack, string & needle, int & start, int  end){
        int i = start;
        int j = 0;
        
        while(i < end){
            if(haystack[i] != needle[j]){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};

/*
Notas:
    -Terminado en 32 minutos.
    -Me tarde haciendo la helper function. La ahice para que se viera más estetico el codigo
    -Hubiera primero creado el nested for loop.
        y que solo entrará al loop cuando estamos en una letra igual a la primera letra del haystack
    
    -Se me hizo bastante sencillo el problema
    -Noté que despues de batallar durante 2 días con String to Integer (ATOI), afecto mi confidence
        No debería permitir que me afecte, ya aprendí a trabajar mejor y a ser más cuidadoso. 
        Obvio no todo problema saldra rapido o con la maxima eficiencia, pero debo de esforzarme por que sea así.
        Pero voy puliendo mi approach a la solución de problemas y estoy aprendiendo de cada uno, no hay porque desanimarse


    -Es una solución bastante eficiente, ya que el mejor runtime posible es O(n) y lo tengo en O(n-window * window). Consultar este runtime.

    Checar una posible solución más eficiente

*/