#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        // 1)Listen
            //Recibo un string "s"
            //Debo encontrar el primer caracter que no se repite y regresar su index
            //Si todos los caracteres se repiten, regresar un -1
            //String tiene entre 1 y 10,000 caracteres
            //s solo contiene letras en minusculas
        
        // 2)Example
            //"abbcc" -> 0
            //"abbaccd" -> 6
            //"abcabddaff" -> 2
        
        // 3)Brute Force
            //Puedo recorrer el string y guardar ocurrencias en hashtable
            //Luego recorrer la lista de nuevo y checar la frecuencia
                //Si la frecuencia es igual a 1, regreso el index
                //Si llega al final y no encontro carcter con frecuencia 1, regreso -1
            //Este approach sería runtime O(n+n) = O(n) y memoria O(n).
        
            //Si implemento Hashtable con unordered_map, el worst case scenario es:
                //O(n^2) por la collision
        
        // 4)Optimize
            //El BCR (Best Conceivable runtime) es de O(n).
            //No hay manera de comenzar a comparar antes de recorrer los datos por lo menos 1 vez
            //Entonces a fuerzas sería O(n+n) el runtime
        
            //Si hiciera un sort, los index serían distintos. 
            //Entonces no podría sacar el resultado bien, con memoria de O(1)
        
            //Siento que mi propuesta original es eficiente
            //Estoy seguro que no bit-maniputaion, se podría sacar de manera más eficiente
                
        // 5)Walkthrough
            //Creo un hashtable para guardar la frecuencia
            //Recorro la lista y guardo los carácteres en el hashtable
            //Recorro la lista otra vez y checo la frecuencia de cada character
                //frecuencia = 1, regreso index
            //Si no encuentra un valor unico, regresa -1
        
        // 6)Implement
        
        // 7)Test
            //2 valores unicos
            //1 valor unico
            //0 valores unicos
            //String de 1 character
        
            //To-do:
                //Confirmar que dict[s[i]], me regresa el value y no la key
        /*    
        
        //Solución con hashtable
        //RunTime: O(N) average case
        //RunTime: O(N^2) worst case
        //Memory: O(N)

        unordered_map<char, int> dict;
        
        //Agrego los characteres y la frecuencia, al hashtable
        for(int i = 0; i < s.size(); i++){
            dict[s[i]]++;
        }
        
        //Ahora recorro otra vez la lista
        for(int i = 0; i < s.size(); i++){
            if(dict[s[i]] == 1){    //Checo la frecuencia de ese character en mi diccionario
                return i;   //Si la frecuencia es 1, regreso el index
            }
        }
        
        //Si no lo encuentra, regresa -1
        return -1;*/
        
        //Solución con array
        //Esta solución es optima porque se pueden usar los char como indexes, pero si tuvieramos
            //más characters, es mejor usar un approach más general como el de hashtables

            //Runtime: O(n)
            //Memory usage: O(1)

        //O(1) memory
        int count[26] = {0};
        
        //O(N) runtime 
        for(char c: s){
            //c-'a' le resta una letra a la posición en el array de minusculas
            count[c-'a']++;
        }
        
        //O(N) runtime
        for(int i = 0; i < s.size(); i++){
            if(count[s[i] - 'a'] == 1){
                return i;
            }
        }
        
        return -1;
    }
};

/*
Nota:
    -Saque la solución en 24 minutos
    -Solución muy optima
    -Siento que la puedo mejorar, debo buscar solución alterna

    -Si es un problema más general, con más de 26 characters. Si es más recomendado el hashmap.

*/