#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Listen
            //I receive an array (nums) with integers and a target integer
            //I must return two indices, the numbers that add up to the target
            //Each input has exactly one solution
            //I can't use the same element twice
            //I can return the answer in any order
            //Array size varies between 2 and 10,000
            
        // Example
            // nums = [1, 2, 3, 7, 10] , target = 17 -> [3, 4]
            // nums = [0, 2, 3], target = 2 -> [0, 1] 
        
            //Solo observo el caso de que si existe una solución
            //Siento que no existe un special case en este problema
        
        // Brute Force
            //Por cada numero, recorrer el resto de la lista para comparar la suma con el target
            //Tendría eficiencia runtime O(N^2) y memory O(1)
            
        // Optimize
            //Si decido iterar ambas listas, deberia almenos poner un break cuando encuentre la pareja
                //O regresar los indices de manera directa
        
            //Podría meter los datos a un BST
                //Luego buscar datos menores al target que nos puedan dar el resultado
                //Tendria runtime O(N) y Memory O(N)
        
        // Walkthrough
            //Primero haré el approach de O(N^2) de manera secuencial
            //Por cada numero de la lista, recorro los numeros restantes a la derecha
                //Si encuentro la suma que me regresa el target, regreso la respuesta
        
        // Implement
        // Test
            //Asumire que todas las respuestas tienen una solución y no pondre un caso de que no tenga
            
        
        for(int i = 0; i < nums.size() - 1; i++){   //Recorro cada numero
            for(int j = i + 1; j < nums.size(); j++){   //Recorro el resto de numeros a su derecha
                
                //Checo si la suma es igual al target
                if(nums[i] + nums[j] == target){    //Si es así
                    vector<int> aux = {i, j};   //Creo vector auxiliar con respuesta
                    return aux; //Regreso resultado
                }
            }
        }
        
        return vector<int>(0);
    }
};
/*
Nota:
    Terminado en menos de 20 minutos, pero se que podría mejorar la eficiencia al hacer un precompute en el array, antes de analizarlo y hacer la logica.
*/