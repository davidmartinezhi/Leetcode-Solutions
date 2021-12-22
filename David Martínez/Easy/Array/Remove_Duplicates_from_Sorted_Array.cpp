#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //1) Listen
            //Recibo un array con numeros ordenados de menor a mayor (non-decreasing order)
            //K siendo la cantidad de caráctees unicos
            //Debo quitar los elementos duplicados y que el array tenga elementos unicos en las primeros k celdas
                //Puedo no eliminar los duplicados y solo mandarlos al final
            //Debo regresar el numero de carácterres unicos
            //Debo usar memoria constante O(1)
            //Array puede tener entre 0 y muchos.
        
        //2)Example
            //Cuardeno
        
        //3)Brute Force
            //Hago un apuntador a la posición donde el elemento es unico
            //Cuando un elemento no es unico, se crea un apuntador que busca el proximo unico
                //Si lo encuentra, hace swap
                //Si no lo encuentra, regresa k
            //K sería el indice del primer apuntador (o K+1)
            //Debo poner condición de que el siguiente valor no sea menor
        
        //4)Optimize
            //Siento que esta solución es optima
            //Memoria: O(1)
            //Time: O(N)
        
        //5)Walkthrough
            
            //Tener un apuntador que se ancla al valor que checamos por repetidos
            //Tener un apuntador al siguiente valor, que checa si son iguales
                //Si no son iguales, ambos se recorren
                //Si son iguales
                    //K se recorre y el apuntadore aux, busca por un nuevo valor diferente y mayor.
                        //Al valor en el que esta K, actualmente
                    //Si aux encuentra valor que cumple con la condición, hace switch.
            //Saliendo del loop, se regresa K+1.
        
        //6)Implement
        
        //7)Test
            //Si la lista no tiene ningun valor duplicado
            //Si la lista esta vacía
        
        //Caso de que la lista esta vacía
        if(nums.size() == 0){
            return 0;
        }
        
        //Caso de que solo exista un elemento en la lista
        if(nums.size() == 1){
            return 1;
        }
        
        /* Si existe más de un valor en la lista*/
        
        //valor que sigue a los valores no repetidos
        int k = 0;
        
        //Recorro toda la lista
        for(int i = 0; i < nums.size(); i++){
            //Si el valor es direfente
            //Recorro el apuntador de no repetidos, para poner el no 
            //repetido en su lugar correspondiente
            if(nums[k] != nums[i]){ 
                k++;
                nums[k] = nums[i];
            }
        }
        
        return k+1;
        
        /*
        int j;
        
        //Recorremos la lista, con k 
        for(int k = 0; k <= nums.size()-1; k++){
            //Si k, llega hasta el final, significa que no hay valores repetidos
            j = k;
            if(k == nums.size()-1){
                j = k;
                return k+1;
            }
            
            //Creo el apuntador a la siguiente celda
            int aux = k+1;
            
            //Si son el mismo valor
            if(nums[k] == nums[aux]){
                
                //Recorro auxiliar, hasta encontrar un valor diferente
                while(aux < nums.size()-1){
                    
                    aux++; //Lo recorro un espacio
                    
                    //Comparo con el valor de k. Aux debe ser mayor y diferente el valor
                    if(nums[k] != nums[aux] && nums[k] < nums[aux]){
                        //Aumento 1 en K
                        k++;
                        //Si se cumple, Ponemos el valor no repetido en k
                        nums[k] = nums[aux];
                        break;  //Salimos del loop
                    }
                }
                
                //Saliendo del loop
                //Si aux es el ultimo valor de la lista, regresamos k
                if(aux == nums.size()-1){
                    j = k;
                    return k+1;
                }
            }
               
        }
        
        
        return j+1;
        
        */
        
        /*
        //Si el vector está vacío regresamos 0
        if(nums.size() == 0){
            return 0;
        }
        
        //De no estar vacío, proseguimos
        
        //Index que siempre estará en el valor no repetido, mas reciente
        int previous = 0;   //Previous comienza en 0
        
        //recorro de manera lineal el vector 
        for(int i = 0; i < nums.size(); i++){   //comienzo el recorrido a partir de la segunda celda
            
            //checo si el dato en el que estamos es diferente al que estoy comparando
            if(nums[previous] != nums[i]){  //Si el numero es diferente
                
                previous++; //Recorro el previous una celda, ahí colocaremos el nuevo dato no repetido
                nums[previous] = nums[i];  //A esa celda le doy el valor no repetido
                
            }
            
        }
        
        //Al final, previous estará en el index del valor no repetido
        //La cuenta de valores no repetidos es previous + 1
        return previous + 1;
        */
    }
};

/*
Notas:
    -Me tarde una hora, porque pense en aplicar sliding window technique cuando existia una manera más sencilla de hacerlo
    -Tenía el concepto de tener dos apuntadores bien, y de tener uno que sigue a los no repetidos.
    -Pero dentro del loop hice un desastre con wux y while. Cuando pude haberlo resuelto con un loop y ya
    -Podría funcionar concepto de slifing window, pero lo aplique en fixed points incorrectos.
        -Pude hacer que fuese una sola ventanta y que fuera creciendo y agregando ahí el dato nuevo no repetido.
        -En lugar de verlo como una ventana en cada indice diferente

*/