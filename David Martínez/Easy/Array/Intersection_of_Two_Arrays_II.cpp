#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //1) listen
            //Recibo 2 arrays (nums1 y nums2)
            //Debo regresar un array con sus intersecciones
                //Cada elemento del array debe tener la misma frecuencia de apariciones de cada integer
            //Puedo regresar el resultado en cualquier orden
            //Arrays tienen entre 1 y 1,000 elementos
            
        //2) example
            //Cuaderno
        
        //3) brute force
            //Sería recorrer ambas listas; O(n+m) runtime
            //Puedo crear un hashtable para cada lista  O(n+m) memoria
            //Recorrer una y si ese dato también esta en la otra lista runtime O(n+m)
                //Agregar ese numero k veces al nuevo array memory: O(n)
                //k veces, siendo la frecuencia menor en ambos hashtables, de el mismo numero
            //Regresar el nuevo array
        
            //Runtime overall: O(n+m)
            //Memory overall: O(m+n)
        
        //4) optimize
            //Bottleneck
                //Recorrer ambas listas y guardarlas en un hashtable
                
            //Best concievable runtime sería O(n+m). porque sería recorrer ambas listas
            
        //5) walthrough
            //Recorrer ambas listas y hacer una hashtable para cada una
            //Recorrer las hashtables y checar si existe un entero en la otra
                //Si existe en la otra, checar cual frecuencia es menor y agregarla al array sol
            //Regresar array solución
            //15 minutos en sacar solución, me tardare más por tener que investigar maps
        
        //6) implement
        
        //7) test
        
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