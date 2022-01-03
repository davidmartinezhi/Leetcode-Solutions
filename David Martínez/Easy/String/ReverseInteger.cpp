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
        
        
        //Variable que regresa el resultado
        int result = 0; 
        
        //Bandera para saber si el valor es positivo o negativo
        bool positive = true;
        
        //Checo si "x" negativa
        if(x < 0){
            positive = false;
            x *= -1;    //Lo hago positivo
        }
        
        while(x >= 1){
            int aux = x % 10;   //Saco el ultimo digito
            x /= 10;    //Actualizo variable x
            cout << aux << endl;
            
            
            //Si es positivo x
            if(positive){
                
                if((result * 10 + aux) > INT_MAX - aux){  //Si la operación cruza el max
                    return 0;   //Regreso 0
                }
                else{   //De lo contrario
                    result = result * 10 + aux; //Se lleva a cabo la operación
                }
                
            }
            //Si es negativo x
            else if(!positive){ 
                
                if(-1*(result*10+aux) < INT_MIN){ //Si la operación cruza el min
                    return 0;   //Regreso 0
                }
                else{   //De lo contrario
                    result = result * 10 + aux; //Se lleva a cabo la operación
                }
                
            }
        }
        
        //Actualizo el simbolo
        if(!positive){
            result *= -1;   //Lo actualizo
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