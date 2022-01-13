#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //1) Listen
            //Recibo un array con enteros, que representa un entero grande
            //Ahora sumar uno al entero grande y regresar el resultado con el array
            //Array tiene un tamaño entre 1 y 99 celdas.
            //El valor de cada digito es entre 0 y 9
            //No tiene ningun 0 al principio
        
        //2) Example
            //[2, 9, 3] -> [2, 9, 4] El ultimo número no es 9, se le suma 1
            //[1, 9, 9] -> [2, 0, 0]
            //[9 , 9] -> [1, 0, 0] Cuando todos son 9, se agrega un 0
            //[9, 1, 9] -> [9, 2, 0] Cuando no todos son 9, el primer no-9 se incrementa 1
            //[9, 2, 9, 9] -> [9, 3, 0, 0]    
        
        //Observo 4 casos
            //Ultimo numero es 9
            //No todos los numeros son 9, se le suma 1 (Se le suma 1 y el resto se hace 0)
            //Todos los numeros son 9 (agrego 0 al final, 1 al inicio y cambio el resto a 0)
            //El ultimo numero no es 9
        
        //3) Brute Force
            //Checar el ultimo numero
            
            //Si el ultimo número es 9, checar el array de final a inicio
                //Si encuentra un número menor a 9, le suma 1 y el resto a la derecha lo hace 0
                //Si llega al final y todos fueron 9
                    //Se le suma uno al primero, se agrega un 0 al final y todos se hacen 0
            //Si el ultimo número no es 9, se le suma 1
            
            //Tendría runtime(O(n)). Si tiene que cambiar a 0s todo sería (n + n). Overall(O(n))
            //Memory O(1)
        
        //4) Optimize
            //Siento que es una solución bastante optima y sin incluir matematicas
            //Probaré otros casos para ver el patron, si es correcto
        
        //5) Walkthrough
            //Checar el ultimo número
            //Es 9
                //Recorremos hacía atras
                //Encuentra un número que no es , se le suma 1 y el resto a derecha se le hace 0
                //Recorre hasta el inicio y todos son 9, se agrega 0 al final, inicia en 1 y todo 0
            //No es 9
                //Se le suma 1
        
        //6) Implementation
        
        //7) Test
            //Todos 9
            //El inicio distinto a 9
            //Enmedio distinto a 9
            //Ultimo distinto de 9
            
        
        
        int size = digits.size();
        
        if(digits[size-1] == 9){    //Checo si el ultimo número es 9
            //Se recorre hacía atras hasta encontrar un número no 9
            
            bool flag = false; //Flag para saber si hay un número distinto a 9
            
            for(int i = size-2; 0 <= i; i--){   //Recorro desde el penultimo
                
                
                if(digits[i] != 9){ //Si encuentra un numero distinto a 9
                    
                    digits[i]++; //Se le suma 1
                    flag = true;    //Aviso que se encontro un numero distinto a 9
                    
                    for(int j = i+1 ; j < size; j++){   //El resto a la derecha se hace 0
                        digits[j] = 0;
                    }
                    
                    break;  //Me salgo del for loop
                }
            }
            
            //Si salgo del loop, checo si hubo numero distintos a 9
            //Si todos los digitos son 9
            if(flag == false){   //la flag es false
                digits[0] = 1;  //Primer dato es 1
                
                for(int i = 1; i < size; i++){  //El resto los hago 0
                    digits[i] = 0;
                }
                
                digits.push_back(0);    //Le agrego un 0 al final
            }
        }
        else{
            //Si el ultimo digito no es 9, le sumo 1
            digits[size-1]++;
        }
        return digits;
    }
};

/*
Notas:
    -Orgulloso de este resultado.
    -Me tomo 41 minutos, pero lo saque desde 0, sin ayuda y me salio a la primera.
    -Talvez deba checar respuesta unado matematicas, pero aún así considero que fue una respuesta bastante eficiente.
    -Lo hice a mi ritmo y si me dio buen tiempo.
    -El paso 4, enserío me ayudo a optimizar la respuesta a simplificar los casos.
    -Paso 5 enserio me hizo darme una buena idea de que hacer y como.
        Una vez que estaba programando, cuando se me iba el hilo o veia que necesitaba usar algo diferente
        El paso 5 me ayudo a mantener la mente enfocada en el objetivo de ese paso y como se relaciona al resto del codigo en la solución
        El paso 5 fue como una brujula, así yo podía enfocarme en hacer que algo funcionara y al terminar tener el hilo de nuevo.
    
    -Optimización:
        Puedo hacer que se recorra y mientras encuentre 9 lo cambia a 0, si encuentra uno no-9, suma 1.
        Si el final el primer numero es cer0, le inserto un 1 al inicio.
        Así sería O(n), siendo siempre el worst case O(n) en lugar de O(n+n).

    -Debo de usar modulos (Write beautiful code), por ejemplo:
        Para convertir los datos de la derecha en 0, a partir de cierto index, pude hacer una función
        a la que solo le paso el array y el index. Ya apartir de ese index transforma todo en 0s.
*/