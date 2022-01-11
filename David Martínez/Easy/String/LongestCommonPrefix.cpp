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
            //memory: O(n)
            //runtime: O(n * prefix)
        
        // optimize
            //Si el array tiene un elemento, retorno ese elemento
            //Si una palabra tiene size 0, retorno un empty string
        
            //Puedo tener apuntador al indice en donde son iguales las palabras
            //solo sería comparar size de la palabra con el apuntador
            //Puedo sacar el size del primer prefix al comparar las primeras 2 palabras
            //Asi siempre tengo el dato de hasta donde recorrer, pero mantengo memory O(1)
            //Runtime BCR: O(elementos de la lista * prefix) O(n log n)
        
        // walkthrough
            //Checo si el array tiene 1 elemento, si si, regreso el elemento dentro
            //Creo entero para el indice
            //Comparo las primeras dos palabras hasta que no sean iguales
            //Ahora creo un for loop de todas las palabras restantes
                //Si la palabra esta vacía, regreso ""
                //Si la palabra es diferente de su antecesor en un char o llego al final, recorro el apuntador a izq
        
            //Si el apuntador llega a -1, regreso ""
        
        // implement
            //
        
        // test
            //Array con puro empty string
        
            //Special case:
                //Array con 1 elemento
                //Palabras que no coinciden
        
        //Checo el size del array
        //Si es de un elemento, regreso ese elemento
        if(strs.size() == 1){ return strs[0]; }
        
        //Creo apuntador al valor donde termina el prefix.
        //Su primer valor es el size del primer elemento de la lista
        int prefixPosition = strs[0].size();
        
        //Si es 0, regreso un empty string
        if(prefixPosition == 0){ return ""; }
        
        //Recorro la lista
        for(int i = 1; i < strs.size(); i++){
            
            //Checo si la palabra está vacía
            if(strs[i].size() == 0){ return ""; }
            
            //Recorro la palabra
            int size = (strs[i].size() > strs[i-1].size()) ? strs[i-1].size() : strs[i].size();
            for(int j = 0; j < size; j++){

                //Checo hasta donde coincide con la palabra anterior
                if(strs[i][j] != strs[i-1][j]){
                    
                    if(prefixPosition > j -1){  //Si el prefix es mayor, le damos el valor
                        prefixPosition = j-1;   
                    }
                    
                    break;//Dejamos de recorrer las letras de la palabra
                }
                
                //Si el prefix es menor a 0, regreso string vacío
                if(prefixPosition == -1){ return ""; }
            }
        }
        
        string result;
        for(int i = 0; i <= prefixPosition; i++){
            result += strs[0][i];
        }
        cout << prefixPosition << endl;
       
        return result;
    }
};

/*
    Es muy sencillo, pero no estaba pensando claro.

*/