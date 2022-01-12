#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // listen
            //Recibo un array con strings
            //Escribir una función para encontrar el prefix mayor, que comparten todas las palabras
            //Si no lo encuentro, regreso un empty string
            //El array puede tener entre 1 y 200 palabras
            //Cada palabra puede tener entre 0 y 200 characters
        
        // example
            //["arandano", "argelia", "argentina"] -> "ar"
            //["flower", "flow", "flight"] -> "fl"
            
        
        // brute force
            //Puedo hacer un array con characters de la primera palabra
            //La siguiente palabra checar las letras que son iguales, cuando exista una dif la borro
            //Hago lo mismo para las demas, pero solo checo el size del array de prefix
            //Al final regreso todos los elementos en el array, juntos
            //memory: O(m)
            //runtime: O(n * m)
        
        // optimize
            //Si el array tiene un elemento, retorno ese elemento
            //Si una palabra tiene size 0, retorno un empty string
        
            //Puedo tener apuntador al indice en donde son iguales las palabras
            //solo sería comparar size de la palabra con el apuntador
            //Puedo sacar el size del primer prefix al comparar las primeras 2 palabras
            //Asi siempre tengo el dato de hasta donde recorrer, pero mantengo memory O(1)
            //Runtime BCR: O(elementos de la lista * prefix) O(n log n)
        
            //Simplify and generalize
                //Primero lo aplicare con 2 palabras nadamas, el recorrido
                //Luego lo haré con un recorrido de sliding window technique
            
            //Puedo usar un string auxiliar y ese compararlo con el result
            //
            
        
        // walkthrough
            // 
        
        // implement
            //
        
        // test
            //Array con puro empty string
        
            //Special case:
                //Array con 1 elemento
                //Palabras que no coinciden
                //Strs con strings vacíos
        
        
        
        //Runtime: O(n * m) n: elementos en la lista, m: tamaño de prefix
        //Memory: O(1)


        
        //Checo el size del array
        //Si es de un elemento, regreso ese elemento
        if(strs.size() == 1){ return strs[0]; }
        
        //Si tiene más de un elemento 
        //El primer prefix es la primer palabra completa
        string result = strs[0];
        
        //Recorremos la lista de strings
        for(int i = 0; i < strs.size()-1; i++){
            
            string aux; //String auxiliar
            
            //Saco la palabra de menor tamaño, para no pasarme de indice
            int size = (strs[i].size() > strs[i+1].size()) ? strs[i+1].size() : strs[i].size();
            //Saco si el prefix tiene menor tamaño que la palabra
            size = (size > result.size()) ? result.size() : size;
            
            //De esta manera el size siempre nos va a hacer recorrer los menor carácteres posibles
            
            //Recorro el size
            for(int j = 0; j < size; j++){
                
                //Si las letras coinciden
                if(strs[i+1][j] == strs[i][j]){
                    aux += strs[i][j];  //La agregamos al string auxiliar
                }
                else{
                    break;  //Cuando no coinciden, dejamos de checar
                }
            }
            
            //Si la primer letra no coincidío y el aux esta vacío
            if(aux == ""){return "";}   //Regresamos un string vacío
            
            //El resultado es el string con menor tamaño entre aux y el resultado
            result = (aux.size() > result.size()) ? result: aux; 
        }

        return result;  //Regresamos el string resultante
        
        
        //Idea de Optimización, el mío ya hace lo mismo pero yo lo hago al trabajar en size, no string
        //Puedo hacer la primer palabra, el prefix
        //Y despues solo ir restando letras
    }    
};
/*
    Es muy sencillo, pero no estaba pensando claro.

*/