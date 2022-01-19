#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        /*
        1. listen
            Input: array "nums"
            Output: Bool (true/false)
            
            return true if there exists a triple of indices (i, j, k)
                such that i < j < k and nums[i] < nums[j] < nums[k]
            
            Nums: puede tener longitud entre 1 y 500,000
            
        2. example
            [1,2,3,4,5] -> true
            [2, 1, 3, 1, 5] -> true
            [5, 4, 3, 2, 1] -> false
            [2,1,5,0,4,6] -> true
        
        3. brute force
            Por cada numero, recorrer hasta encontrar uno mayor o recorrer toda la lista
            Si encuentra un numero mayor, hacer otro loop para encontrar el 3ero mayor
            runtime: O(n^3)
            memory: O(1)
            
        4. optimize
            BCR: O(n), con memoria de O(1)
            
            Dentro de mi alcance para sacarlo en 45 minutos, mejor hago el approach que estoy seguro puedo sacar. 
            Puedo hacer que tengo runtime de O(n^2) y memory O(n)
            
            
            Puedo hacer 3 apuntadores. (i, j, k)
            Cada apuntador es como una estaca que se queda en su valor correspondiente

        //Teoría de solución con 3 pointers
            Inicio con i, y recorro j.
                Si numsj es menor a i, ahora i tiene ese index y sigo recorriendo j
                Si numsj es igual a i, lo salto
                Si numsj es mayor, lo dejo en ese lugar y ahora recorro k
                
                Ahora inicio con j y k se recorre.
                    Si k es mayor que nums[i] y menor que nums[j], ahora j tiene ese valor
                    Si nums[k] es mayor a nums[j], regreso true.
                    
            Si j o k, llegan al final de la lista, regreso false
        
        5. walkthrough
            Para eficiencia O(n^2) runtime
            Recorro todo elemento de la lista
            Por cada elemtno de la lista, mando 2 pointers (j, k)
            
            Mientras j y k no llegue al final de la lista
                Si nums[j] es menor o igual a nums[i], sigo recorriendo
                Si nums[j] es mayor a nums[i]
                
                Despliego k,
                    Mientras k no llegue al final
                    si nums[k] es mayor a nums[i] y menor a nums[j]
                        j es igual a k y sigo avanzando k
                        Si nums[k] es mayor a nums[j]
                            regreso true
            
            Si no regresa true, el loop
            regreso false
            
        6. implement
        7. test
            Special case:
                La lista tiene menos de 3 elementos

        */
        
        /*
        //Brute force approach O(n^3)
        //Respuestas correctas pero time limit exceeded
        //Checo el tamaño de la lista
        if(nums.size() < 3) return false;
        
        //Recorro cada numero
        for(int i = 0; i < nums.size() - 1; i++){
            
            for(int j = i+1; j < nums.size() - 1; j++){
                
                if(nums[j] > nums[i]){
                    
                    for(int k = j; k < nums.size(); k++){
                        if(nums[k] > nums[j]){
                            return true;
                        }   
                    }
                } 
            }
        }
        
        return false;
        */
        
        /*
        //Optimized Brute Force
        //Runtime: O(n^2)
        //Memory: O(n) n siendo los diferentes numeros dentro de nums
        
        //Checo el tamaño de la lista
        if(nums.size() < 3) return false;   //Si tiene menos de 3 elementos, elimino
        
        
        //Recorro el set para saber si tiene 3 elementos diferentes
        unordered_map<int, int> numbers;
        for(int i = 0; i < nums.size(); i++){
            if(numbers.find(nums[i]) == numbers.end()){
                numbers[nums[i]]++;
            }
        }
        
        //Checo que existan más de 3 elementos unicos en nums
        if(numbers.size() < 3){
            return false;
        }
        
        //Recorro cada numero de la lista hasta el penultimo
        for(int i = 0; i < nums.size() - 1; i++){
            
            //Ahora recorro lo que queda de la lista
            int j = i + 1;
            int k = 0;
            
            while(j < nums.size() - 1 && k < nums.size()){
                
                //Si nums[j] es mayor a nums[i]
                if(nums[j] > nums[i]){  //Despliego k
                    k = j + 1;
                    while(k < nums.size()){
                        //Si nums[k] esta entre nums[j] y nums[i]
                        if(nums[k] > nums[i] && nums[j] > nums[k]){
                            j = k;
                        }
                        else if(nums[k] > nums[j]){
                            return true;
                        }
                        k++;
                    }
                }
                j++;
            } 
        }
        
        return false;
        
        */
        /*
        //Respuesta optima encontrada en leetcode
        //Es muy simple la respuesta, si me lo complique de más
        
        //Creo enteros que tengan el valor maximo que un entero pueda tener
        int l = INT_MAX, r = INT_MAX;
        
        //Recorro todos los numeros
        for(auto num : nums) {
            
            //Primero checo j, que en este caso es l. 
            if(num <= l) l = num; //Si el numero es menor o igual a j, j es ese numero
            else if(num <= r) r = num;  //Si el numero es menor o igual a k, k es ese numero
            else return true;   //Si no se cumple, es porque i < j < k y nums[i] < nums[j] < nums[k]
        }
        return false;
        */
    
        //Mismo, pero con mejor explicación

        int c1 = INT_MAX, c2 = INT_MAX;
        for (int x : nums) {
            if (x <= c1) {
                c1 = x;           // c1 is min seen so far (it's a candidate for 1st element)
            } else if (x <= c2) { // here when x > c1, i.e. x might be either c2 or c3
                c2 = x;           // x is better than the current c2, store it
            } else {              // here when we have/had c1 < c2 already and x > c2
                return true;      // the increasing subsequence of 3 elements exists
            }
        }
    return false;
    }
};

/*
Tengo buena intuición y ya sabía que era con 3 pointers la mejor solución. 3 pointers usandolos como estadas
Es lo que hice en la optimización de mi brute force. runtime O(n+n^2), memory O(n)
Solo por el penultimo test, donde se hace un recorrido de los 500,000 elementos, pero solo existen 2 elementos unicos
    es que puse el hashtable. 

No se me ocurrío al inicio pensar en la posibilidad de que solo existieran 2 elementos unicos en la lista.

Me gusto el approach de la solución más optima, siento que es el mismo ya visto en otros ejercicios, pero aplicado diferente.
Ya vi porque es muy util cuando me dicen de que rango a que rango pueden ser los numeros.Vi que eran para 32 bits, 
    pero no imagine poder usarlo en la solución, porque no existía un limite en los numeros.

Sirve mucho el hacer estacas que apunten a un valor infinito, como en grafos antes de sacar el Djikstra, hacer los arcos con distancia infinita(Max).
Luego cuando se vayan cumpliendo las condiciónes, los bajo a su valor.
Poruqe yo usé estacas que comenzaban desde 0 y tuve que comparar mucho para que saliera el resultado.

Cuando usas estacas, pensar en comenzarlas desde el valor maximo. No limitarse. Pueden ser estacas que comienzan desde 0, que no tienen valor aún o que tengan valor max.
Todo depende del problema y el contexto.

*/