#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
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
        
            //Podria hacer un sort
                //Luego usar metodo estilo binary search para comparar valores
                //Podría sacar O(N log N) runtime y memoria O(N)
        
            //Puedo usar hashtables
                //Meto los datos y luego al recorrer la lista
                //Saco target - el valor en el que estoy
                    //Lo busco en la hashtable, si existe me da el resultado
                //Puede sacar memoria O(N) y runtime O(N) average, 
                    //si existieran colisiones en todas las celdas del hashtable sería runtime O(N^2)
                    //Considerando que yo fuera a usar unordered_map
            
        
        // Walkthrough
            //Primero haré el approach de O(N^2) de manera secuencial
            //Por cada numero de la lista, recorro los numeros restantes a la derecha
                //Si encuentro la suma que me regresa el target, regreso la respuesta
        
        // Implement
        // Test
            //Asumire que todas las respuestas tienen una solución y no pondre un caso de que no tenga
            
        
        //Unordered map, que implementa hash tables
        
        vector<int> result = {};
        
        unordered_map<int, int> um;
        
        for(auto num: nums1){   //Meto todos los valores de nums1 en el hashtable
            um[num]++; //Creo el key y le sumo uno al valor
        }
        
        //recorro la segunda lista
        for(auto num: nums2){
            if(um[num] > 0){    //Si el valor existe, tendrá más de 0
                result.push_back(num);  //Se agrega el valor a result, mientras se repita
                um[num]--;  //Una vez agregado, restamos la frecuencia, porque ya la consideramos
            }
            //Lo que pasa es que si en nums1 el valor aparece menos, llegará a cero su ocurrecia en um
            //Si aparece menos en nums2, no llegará a 0 den nums2, pero solo se agregara k veces
                //K siendo las veces que aparece el valor en nums2
            
        }
        
        //Regreso el array con el resultado
        return result;
        
        /*
        //Map, no aplica porque maps usan BST
        map<int, int> mapNums1;
        map<int, int> mapNums2;
        
        //Recorro el primer array O(n^2)
        for(int i = 0; i < nums1.size(); i++){
            if(mapNums1.find(nums1[i]) == mapNums1.end()){
                mapNums1.insert(pair<int, int> (nums1[i], count(nums1.begin(),nums1.end(),nums1[i])));
            }
        }
        
        //Recorro el segundo array O(n^2)
        for(int i = 0; i < nums2.size(); i++){
            if(mapNums2.find(nums2[i]) == mapNums2.end()){
                mapNums2.insert(pair<int, int> (nums2[i], count(nums2.begin(),nums2.end(),nums2[i])));
            }
        }
        
        //Ahora recorro uno solo
        for(int i = 0; i < mapNums1.size(); i++){
            for(int j = 0; j < mapNums2.size(); j++){
                if(mapNums2[j][0] == mapNums1[i][0]){
                    int k;
                    if(mapNums2[j][1] < mapNums1[i][1]){
                        k = mapNums2[j][1];
                    }
                    else{
                        k =  mapNums1[i][1];
                    }
                    
                    for(int h = 0; h < k; h++){
                        result.append(mapNums2[j][0]);
                    }
                    break;
                }
                
                else if(mapNums2[j][0] > mapNums1[i][0]){
                    break;
                }
            }
        }
        
        cout << "Corriendo bien" << endl;
        return vector<int>(0);
        */
    }
};