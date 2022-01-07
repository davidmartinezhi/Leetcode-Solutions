#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        // 1 listen
            // recibo un 32-bit integer "x"
            //Si es menor a -2147483648 o mayor a 2147483647, regreso 0
            
        // 2 example
            //123 -> 321
            //-123 -> -321
            //120 -> 21
            //Siento que la unica manera de hacerlo de manera eficiente es con math
        
            //123
            //123 % 10 = 3 *
            //123 / 10 = 12
        
            //12 % 10 = 2 *
            //12 / 10 = 1
        
            //1 % 10 = 1 *
            //1 / 10 = 0.1 menor a 1, me detengo
        
            //opcion 1
            //Voy agregando a un array
                //Hago reverse en ese array y con el size yase cuantos 0s agregar al result
                
            //opcion 2
            //Yase como separarlos, ahora como los junto?
                //result = 0
                //result = (result * 10) + numero que ando agregando
                
                //result = (0*10) + 3 = 3
                //result = (3*10) + 2 = 32
                //result = (32*10) + 1 = 321
                
                //Puedo guardar un bool expresion para saber si el valor orig era negativo o no
        
        // 3 brute force
            //Puedo meter cada digito a un vector, aplicar reverse y luego juntarlo
            //Sería Memoria O(n) y runtime O(n)
            
        
        // 4 optimize
            //Puedo hacerlo de manera directa con operaciónes matematicas sobre cada digito
            //memoria O(1) y runtime de O(n)
        
        // 5 walkthrough
            //Creo variable "resultado y la igual a 0"
            //El integer que me dan, checo si es positivo o negativo
            //Si es negativo puedo hacerlo positivo y solo ajustar al final, para evitar errores
                //En otra iteración y con pruebas, checo la optimización, pero es lo mismo
            //Creo un loop en el que, mientras "x" sea mayor a 1
                //variable entera aux guarda (x%10)
                //resultado = resultado * 10 + aux
                //ajusto x, con x /= 10
            //Saliendo del loop, regreso el result
        
        // 6 implement
        
        // 7 test
            //Prueba con numero negativo
            //prueba con numero positivo
            //prueba con 0
            //preuba con limitMAX y limitMIN
        
            //todo
                //checar si funciona igual con simbolo negativo que no simbolo positivo
        
        //Creo limites que no podremos pasar, si no queremos regresar 0
        //int limitMAX = 2147483647;
        //int limitMIN = -2147483648;
        
        //Primer resupuesta
        /*
        //Variable que regresa el resultado
        long int result = 0; 
        
        //Bandera para saber si el valor es positivo o negativo
        bool positive = true;
        
        //Checo si "x" negativa
        if(x < 0){
            positive = false;
            long int aux = x;
            aux = aux * -1;
            if(aux > INT_MAX){  //Checo si no cruza el limite, al hacerlo positivo
                return 0;
            }
            
            x *= -1;    //Lo hago positivo
        }
        
        while(x >= 1){
            int aux = x % 10;   //Saco el ultimo digito
            x /= 10;    //Actualizo variable x
            result = result * 10 + aux;
            
            //Checo que no cruce los limites
            if(result > INT_MAX && positive){
                return 0;
            }
            else if(result > INT_MAX && !positive){
                
                return 0;   
                
            }

        }
        
        
        //Actualizo el simbolo
        if(!positive){
            result *= -1;   //Lo actualizo
        }
        
        return result;
        */
        
        //Respuesta eficiente encontrada en leetcode
        /*
        Puedo checar que no cruce, al checar que no sea mayor a INT_MAX/10 y el dato a agregar
        sea menor a 7
        De igual manera con el min, pero que no cruce el -8
        
        int output = 0;
        while (x != 0) {
            int temp = x % 10;
            if (output > INT_MAX/10 || (output == INT_MAX/10 && temp > 7)) return 0;
            if (output < INT_MIN/10 || (output == INT_MIN/10 && temp <= -8)) return 0;
            output *= 10;
            output += temp;
            x /= 10;
        }
    
        return output;
    }
        
        */
        
        //Segunda respuesta mía, ya simplificada
        
        //Creo variable donde creare el resultado
        int result = 0;
        
        //Proceso x, hasta que sea menor a 1
        while(x != 0){  //Mientras sea diferente a 0, así no importa si input es positivo o negativo
            
            int aux = x % 10; //Creo variable auxiliar con el valor a agregar
            x /= 10;    //Actualizo x
            
            //Creo los filtros para no cruzar los limites
            //INT_MAX 2,147,483,647
            //INT_MIN -2,147,483,648
                
            //Filtro para que no cruze INT_MAX
            if(((result == INT_MAX/10) && (aux > 7)) || result > INT_MAX/10){
                //Si el resultado es igual a 214,748,364 y aux es mayor a 7
                //O resultado ya es mayor a 214,748,364
                return 0; //regreso 0
            }
            
            //Filtro para que no cruze el INT_MIN
            if(((result == INT_MIN/10) && (aux < -8) )|| result < INT_MIN/10){
                ////Si el resultado es igual a -214,748,364 y aux es menor a -8
                //O resultado ya es menor a -214,748,364
                return 0;   //Regreso 0
            }
            

            result = result * 10;  //Agrego un 0
            result = result + aux;  //Le sumo el valor de aux
        }
        
        return result;
    
    }
};

/*
Nota:

    -Lo saque en 40 minutos
        -El unico test que no he podido resolver y debo checar
        -Solución funcional con todo tipo de dato, solo me sale error cuando cruzo el limite
        -Es como saber que no estoy cruzandome del limite, sin hacerlo
*/