#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
            info
                input: integer array "nums"
                output: array with all triplets nums[i], nums[j] and nums[k] such that:
                    i != k, i != j, j != k, and nums[i] + nums[j] + nums[k] = 0
                    
                array size varies from 0 to 3,000
                nums[i] value varies from -100,000 to 100,000
                
            example
                [-1,0,1,2,-1,-4]
                -> [[-1, 0, 1], [2,-1,-1]]
                
                [3,-3,0,2,1]
                ->[[-3,3,0], [-3,2,1]]
                
                []
                ->[]
                
                [0]
                ->[]
                
            brute force
                3 nested for loops to check for all possible triplets and find matches
                runtime: O(n^3)
                space: O(1)
            
            optimize
                options:
                    *precompute the array
                        sort. n log n
                        [-1,0,1,2,-1,-4]
                        
                        [-4,-1,-1,0,1,2]
                        -> [[-1, 0, 1], [2,-1,-1]]
  
                        runtime: O( n^2 + n log n )
                        extra space: O(1)
                        
                        
                7. test
                    special cases:
                        array of size 2 or less
                        no valid triplets
                            
        */
        
        /*
        //Check for array with size less than 3
        if(nums.size() < 3) return {};
        
        //sort
        sort(nums.begin(), nums.end());
        
        //result array
        vector<vector<int>> result;
        
        //create pointers
        int start = 0;
        int end = nums.size() - 1;
        
        //Sum and needed
        int sum;
        int needed;
        
        //traverse until pointers meet
        while(start < end){
            sum = nums[start]+nums[end];
            needed = sum * -1;
            
            int aux;
            
            if(sum == 0){
                aux = start+1;
                while(nums[aux] <= 0 && aux < end){
                    if(nums[aux] == 0 && aux != end){
                        vector<int> auxVector = {nums[start], nums[aux], nums[end]};
                        result.push_back(auxVector);
                    }
                    aux++;
                }
            }
            else if(needed < 0){
                aux = start + 1;
                while(nums[aux] < 0 && aux < end){
                    //if lesser + 1 is equal
                    if(nums[aux] == needed && aux != end){
                        vector<int> auxVector = {nums[start], nums[aux], nums[end]};
                        result.push_back(auxVector);    
                        break;
                    }
                    else if(nums[aux] > needed){
                        break;
                    }
                    aux++;
                }
            }
            else{
                aux = end-1;
                while(nums[aux] > 0 && aux < end){
                    if(nums[aux] == needed && aux != start){
                        vector<int> auxVector = {nums[start], nums[aux], nums[end]};
                        result.push_back(auxVector);    
                        break;                        
                    }
                    else if(nums[aux] < needed){
                        break;
                    }
                    aux--;
                } 
            }
                
            while(start < end){
                if(nums[start] == nums[start+1] && nums[end] == nums[end-1]){
                    start++;
                    end--;
                }else if(nums[start] != nums[start+1]){
                    start++;
                    break;
                }else if(nums[end] != nums[end-1]){
                    end--;
                    break;
                }
            }
        }
        
        return result;
        */
        
        /*
        Primer pointer siempre ser un valor diferente
        A partir de ahí, se crea el pointer low & high, i+1 & nums.size()-1
    
            check for possible error in if statement
        */
        
        //Check for array with size smaller than 3
        if(nums.size() < 3) return {};
        
        //size variable and result vector
        vector<vector<int>> result;
        int n = nums.size();
        
        //sort the original array
        sort(nums.begin(), nums.end());
        //traverse the array
        for(int i = 0; i < n; i++){
            
            //If we are at the first index or in an index where that number is its first ocurrance
            if(i == 0 || (nums[i] != nums[i-1])){
                //set pointers for two pointer technique starting from extremes
                int j = i+1;
                int k = n-1;
                
                while(j < k){
                    int sum = nums[i] + nums[j]+ nums[k];   //Get the sum
                    
                    //If the sum is equal to 0
                    if(sum == 0){
                        //add resulting vector
                        vector<int> auxVector = {nums[i], nums[j], nums[k]};
                        result.push_back(auxVector);
                        
                        //Move pointers to their next number to avoid repeating triplets
                        while(j < k && nums[j] == nums[j+1]) j++;
                        while(j < k && nums[k] == nums[k-1]) k--;
                        
                        j++;
                        k--;
                    }
                    //if the sum is greater than 0
                    else if(sum > 0){
                        //we lower k
                        k--;
                    }
                    //if the sum is lesser than 0
                    else if(sum < 0){
                        //we increment j
                        j++;
                    }
                }
            }
            
        }
        
        return result;
    }
};


//45+ minutes
/*
Lo que me descarrilo en el problema es el haber sacado un mal bcr, el querer siempre sacar un bcr es bueno.
Pero clavarme ahí me hace perder mucho tiempo y darle muchas vueltas al asunto.
Me hizo tener tunnel vision y no buscar ningún approach diferente. Me quito mucha flexibilidad.

El approach de sort y luego 2 pointer technique, se me hizo muy bueno y cumple con memory: O(1)
time complecity lo mantiene estable en n log n + n^2 = n^2

El approach en por cada numero, hacer el two pointer technique, se me hizo muy inteligente.
Pero lo descarte porque no me iba a dar O(n) runtime. Lo cual ni es posible.

Debo de sacar un bcr. Pero desarrollar desde una solución que ya tenga yo pensado.
Podría ser, sacar la solución más optima y funcional que pueda. Luego cuando me queden 15 minutos, si no he sacado algo más, programarla.
*/

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