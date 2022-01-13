#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //1. Listen
            //Recibo un array con numeros enteros
            //Números tienen valores entre -100,000 y 100,000
            //El array tiene un tamaño entre 0 y 3,000
            
            //Debo regresar una matriz, donde cada renglon tenga:
                //Una tripleta donde el valor de nums[i], nums[j] y nums[k]. Sea igual a 0
                //i, j y k. No pueden repetir index
                //El set que regreso no puede tener tripletas repetidas
        
        //2. Example
            /*
                [0, 1, -1, 2, -1, 0, 34, 0] -> [ [0, 0, 0], [2, -1, -1], [1, -1, 0] ]
                
            
            */
        //3. Brute Force
            //Tener 3 apuntadores
                //Uno al elemento que estamos checando
                //Otro al siguiente elemento
                //Los sumamos y el resultado, es el otro valor que buscaremos
                //Recorro para encontrar ese número
            //Este aproach tendría runtime de O(n^2 log n)
        
        //4. Optimize
        
            //Dividir por modulos
                //Sacar los datos con 3 sumas
                //Evitar sumas repetidas
        
            //Data structure brainstorm
                //Hashtables
                    //Puedo guardar cada elemento en la hashtable, key: index y value: numero
                //Puedo usar 2 apuntadore ahora, uno para checar un elemento
                //El segundo apuntador va recorriendo la lista, con los otros indices
                //Sacamos la suma de ambos y ese valor lo buscamos en la hashtable.
                
                //Set
                    //Podría servirme para guardar convinaciones, sin que se repitan
            
            //Precompute
                //Podria hacer un sort en los numeros
                //Luego tener 2 apuntadores 
                //Sacamos la suma y con eso, el num para cumplir con la tripleta
                //Si el indice es igual a i o j. Checamos a izquierda y derecha. Si no esta el num. 
                    //No lo metemos
        
        //Hashtables funciona para hacer busqueda en O(1), entonces runtime:O(n^2), pero memory:O(n)
        //Update: No se puede usar hashtable, porque solo puedo buscar con la key y no puedo sacar las keys directo del valor sin recorrer. Sería On^3 casí casí-
        
        //Sort funciona para poder implementar binary search, memory:O(n), pero runtime:O(n log n * log n)
        //Es más eficiente el metodo con sort
        
            //A este punto ya gaste 25 minutos de los 45
        
        //5. Walkthrough
            //Meto todos los datos a la hashtable
            //Por cada numero[i], checo los demas numeros numeros[j]
            //Numero a buscar = (numero[i] + numero[j]) * -1;
            //Si lo encuentra
                //Agrego al set, la tripleta
            //Despues de recorrer toda la lista, regreso el vector con las tripletas
            
        //Podría usar heaps y heapsort?
            
        //Llevo 32 minutos
        
        //6. Implement
        //7. Test
            
            //Checar como funcionan set en c++
                //emplace()
                //This function is used to insert a new element into the set container, only if the element to be inserted is unique and does not already exist in the set.
        
        //Ahora inicio implementación
        //Llevo 36 minutos utilizados
      
        //Vector que regresa el resultado
        vector<vector<int>> result = {};
        
        //Saco el size
        int n = nums.size();
        
        //Si el size es menor a 3, regreso el resultado
        if(n < 3){ return result;}
        
        //Ordeno los numeros en el vector
        sort(nums.begin(), nums.end());
        
        //Recorro cada numero de la lista
        for(int i = 0; i < n; i++){
            
            //Si el numero anterior es diferente a el que estoy actualmente
            //O estoy en el primer indice
            if(i == 0 || nums[i] != nums[i-1]){
                //Creo apuntador de j y de k
                int j = i+1;
                int k = n-1;
                
                //mientras j sea menor a k
                while(j < k){
                    //Saco la suma de los 3 numeros
                    int sum = nums[i] + nums[j] + nums[k];
                    
                    //Si la suma me da igual a cero
                    if(sum == 0){
                        //Agrego la tripleta al resultado
                        result.push_back({nums[i], nums[j], nums[k]});
                        
                        //Ahora recorro los apuntadores para que salten a su siguiente num
                        //Para que no se repitan combinaciones
                        //Esto los deja en el ultimo numero con ese valor
                        while(j < k && nums[j] == nums[j+1]){j++;}
                        while(j < k && nums[k] == nums[k-1]){k--;}
                        
                        //Para el cambio de numero
                        j++;
                        k--;
                    }
                    //Si la suma es mayor a cero
                    else if(sum > 0){
                        //Reduzco K
                        k--;
                    }
                    //Si la suma es menor a cero
                    else if(sum < 0){
                        //aumento j
                        j++;
                    }
                }
                
            }
            
        }

        return result;
    }
};

/*
Si no encuentro manera de sacar la key, con el value. Tengo que usar sort afuerzas
Ya vi que con sort puedo tener o(n^2)
Pero intentar usar lista encadenada
Pero sería hashtable encadenada
HASHTABLE key numeros del array y el value es el index (renglon de la matriz)
Matriz, que contiene los index
Puedo recorrer ese renglon de la matriz, checar que sea diferente a j y a i
Luego ya meto el valor

//Aún así sigue siendo más eficiente las solución con sort

*/

/*
Notas:
    -La verdad comence muy bien el problema, sacando soluciones optimaz con buena eficiencia
        Solo que me tarde unr rato en sacar la solución y saque de más.
        Después de esto solo me quedaron 9 minutos para hacer el codigo y por sacar varias soluciones con un "Flex" de diferentes maneras de resolverlo
        No vi que el metodo que saque con hashtables, en realidad no podía implementarlo como yo lo había visualizado, Hubo una falla por mi parte en la planeación
       
       Fue util el data structure brainstorm, solo que no pense explicitamente en las caracteristicas de la data structure y como aplicarlo.
       Debería ser más cuidadoso. Y enfocarme en una solución eficiente a la vez y también no en tantas soluciones.

    -Pude sacar rapido utilizar sort y un set. con eso ya tenía runtime:0(n2) y memory: O(n)

    -La solución más optima yp creo si me hubiera llevado un poco más de tiempo sacarla, pero aúna así ya estaba cerca.

    -Debería de seguir haciendo ejemplos en mi cuaderno, desde que deje de hacerlos, he estado teniendo fallas. 
    Es mejor no dejarlo todo mental. Esta incomodo hacer ejemplos en la laptop, pero en una entrevista creo que hasta puedo usar un ipad
    para poner mis ejemplos y logica. Entonces si debería hacer los ejemplos en cuaderno.
*/