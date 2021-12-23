#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //1)Listen
            //Me llega un array de integers llamado nums
            //Regreso true si existen elementos duplicados
            //Regreso false si todos los elementos son distintos
            //1 <= nums.length <= 105
            //-10^9 <= nums[i] <= 10^9 (1,000,000,000)
        
        //2)Example
            //Cuaderno
        
        //3)Brute Force
            //Mi primer idea es la de usar hashtables
            //Para recorrer la lista una vez y saber la frecuencia(veces que aparece) de los numeros
            //Tendría time:O(N)
            //Tendría Memory: O(N)
            //Siento que esto es mejor a usar un fast y un slow pointer, sería time:O(N^2), memory:O(1)
            //Podria hacer un sort O(nlogn) y luego recorrer la lista, con ventana que cheque por repetidos
            //Time (n log n), memory (1) o Log N por espacio auxiliar con el sort de vector
        
        //4)Optimize
            //Usar Hashtables para tener conocimiento de los numeros y la frecuencia
            //Como puedo usar hashtables en c++? Puede ser con un set o map
        
        //5)Walkthrough
            //Recorro la lista nums y voy metiendo los datos al set
            //Si el dato ya existe dentro de set, regreso true
            //Si recorro nums hasta el final, regreso false
        
        //6)Implement
        
        //7)Test
            //Set de 1 valor
            //Set con valores no repetidos
            //Set con valores repetidos
        
        set<int, greater<int> > values;
        
        //El find de set, cuando no encuentra el elemento regresa el ultimo
        //Entonces haré que el ultimo sea uno que no podamos acceder
        
        for(int i = 0; i < nums.size(); i++){//Checa cada valor de nums
            
            if(values.find(nums[i]) == values.end()){//Si llega al final, significa que no existe el numero
                values.insert(nums[i]);  //Agregamos el dato al set
            }
            else{   //Si existe el dato
                return true;    //Regreso false
            }
        }
        return false;   //Si llego al final, significa que no se repiten caracteres y regreso false
        
        
    }
};

/*
    -Si fue de gran ayuda aprender set
    -Siento que pudo ser más rapída la hashtable si usaba maps
    -Tarde media hora, pero por aprender como se usaba set
    -Sietno que me estoy apresurando demasiado en los problemas y paso por alto algunos detalles
        Mañana voy a darle con calma y poner temporizador, para ver si a mi ritmo hago buen tiempo o si debo acelerar el paso
        Si llego a necesitar acelerar el paso, checar que metodologia o tips, puedo aplicar para tener atajos mentales
*/