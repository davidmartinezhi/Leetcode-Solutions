#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        // 1 Listen
            //Recibo un array con characters y representan un string
            //Debo hacer reverse del array, in-place
            //Array tiene tamaño entre 1 y 100,000
            //S[i] es printable ascii character
        
        // 2 Example
            //["h", "o", "l", "a"] -> ["a", "l", o, "h"]
        
        // 3 Brute Force
            //Se puede usar el reverse de los vectores en c++, pero mejor lo hago a mano
            //Puedo usar apuntador a inicio y otro a final
            //Luego hacer swap hasta que se topen (ini < fin)
            //Tendría runtime de O(n) y memory O(1)
        
        // 4 Optimize
            //Este approach es el más eficiente
        
        // 5 Walkthrough
            //Creo dos apuntadores, uno al inicio y otro al final de la lista
            //Hago swap de sus valores respectivos en el array, hasta que se crucen o topen
        
        // 6 Implement
        
        // 7 Test
            //Lista con un solo elemento
            //Lista con más de un elemento
        
        int start = 0;  //Apuntador a inicio
        int end = s.size() - 1; //Apuntador a final
        
        while(start < end){
            swapChar(s, start, end);
            start++;
            end--;
        }
    }
    
    void swapChar(vector<char>& s, int & i, int & j){
        //char * aux1 = &s[i];
        //char * aux2 = &s[0] + j;
        //cout << "aux1: " << *aux1 << " aux2: " << *aux2 << endl;
        
        char aux = s[i];    //Guardo el valor en s[i]
        s[i] = s[j];    //S[i] ahora tiene el valor de s[j]
        s[j] = aux; //S[j] ahora tiene el valor de s[i] 
    }
};

/*
Nota: 
    -Sabía como hacerlo desde el principio pero quise hacer la metodología a fuerzas
    -Terminado en 18 minutos
    -Quise practicar pointers, pero son irrelevantes para el problema, por eso esatn comentados
*/