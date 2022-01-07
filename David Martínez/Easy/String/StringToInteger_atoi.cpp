#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        // 1 listen 
            //Debo implementar atoi, convertir 32-bit string a integer
        
            //Puedo recibir digitos (0-9), whitespace (" "), simbolos (+, -) y punto (.)
            //No ignorar characters al inicio, que no sea whitespace
        
            //Algoritmo consiste en:    
                //Ignorar white space al inicio
                //Checar si el siguiente dato no es un simobolo de suma o resta
                //Leer el siguiente character, hasta topar con un non-digit o llegar al final del str
                //Convertir los digitos a characters
                    //Si no existen digitos en el string, regreso 0
                //Integers mayores a INT_MIN se dejan como INT_MIN, igual con INT_MAX
                //Debo regresar el integer del final result
        
        
            //String contiene entre 0 y 200 characters

        // 2 example
            //"abc-345   " -> -345
            //"      00438a" -> 438
            //"0050" -> 50
            
        
        // 3 brute force
            
            //Limpieza del string
            //Puedo hacer un string auxiliar con los digitos del string
            //Puedo hacer bandera (default true), que lee si el integer es positivo o negativo
            //Primero recorrer el string y filtrarlo, solo trabajar con el entero
                //Solo agregar al string auxiliar, digitos, ignorar el resto
                //Si encuentro signo "-", bandera le hago un set a false
                //Si encuentro un punto, ignoro el resto, porque sería float y no int
        
            //Checo si string aux esta vacío, si si, regreso 0
            
            //Creo función auxiliar
            //Conversión de string a integer
                //Tomando en cuenta INT_MIN y INT_MAX
                //Recorro string y uso (result *10) + digitoString
                
            //Memoria O(n)
            //Runtime O(n)
        
        // 4 optimize
            //Puedo tener memoria O(1) y recorrer menos en runtime
            //Puedo hacerlo todo en usa sola recorrida
            
            //Puedo hacer un while que recorre whitespace y checa simbolos
            //Cuando encuentra numeros, comienza a hacer la conversión con la función que regresa el
                //valor en entero
        
        // 5 walkthrough
            //Creo bandera para saber el simbolo
            //Creo variable result = 0
            //Recorro string mientras sea un non-digit y no sea un símbolo.
                //si encuentra simbolo, updateo bandera
                //Si encuentra un punto, doy return
                //si es entero, lo transformo y agrego al resultado
                
        
        // 6 implement
        
        // 7 test
            //Letras antes de numero
            //Llegada de simbolo positivo y simbolo negativo
            //Letra dspues de numero
            //Simbolo despues de numero
            //Espacios en blanco antes de numero
            //Numeros que cruzan el limite
            //Numeros positivos y negativos
        
            //To-Do
                //Checar como convertir num string a int
                //Checar como validar si me pase del INT_MAX o INT_MIN
        
        //Bandera para saber el signo que es
        bool sign = true;
        
        //Bandera para saber si ya encontre algún digit
        bool digitFound = false;
        
        //Resultado
        long int result = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            //Debo poner caso en el que haya un simbolo positivo también
            if(s[i] == '-' && digitFound == false){ //Si estoy en simbolo negatico y no he encontrado
                                                        //digitos, marco la bandera
                sign = false; //Aviso que el signo es negativo
            }
            else if(isalpha(s[i]) && digitFound == false){
                return 0;
            }
            
            //Si encuentro un punto, regreso
            if(s[i] == '.'){
                return result;
            }

            
            if(isdigit(s[i])){ //Si estoy en un digito
                result = (result * 10) + toInteger(s[i]);
                digitFound = true;  //Aviso que se encontro un digito
            }
            else if((isalpha(s[i]) == true) && (digitFound == false)){    //Si no encuentro digitos y si char
                return 0;   
            }
            
            //Checar que el digito ni cruce los limites
            //Si los cruza, regreso el limite
            unsigned int aux = 2147483648;
            if((result >= INT_MAX) && (sign == true)){
                return INT_MAX;
            }
            else if((result >= aux) && (sign == false)){
                return INT_MIN;
            }
            
            
        }
        
        //Checo por el signo
        if(sign == false){  //Si es falso
            
            return (result*-1);
        }
        return result;  //Regresamos el result
    }
    
    //Helper function
    //Transforma character a entero
    int toInteger(char & c){
        //Array con difitos
        int numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
        
        //Recorre los digitos
        for(int i = 0; i < numbersSize; i++){
            if(numbers[i] == c){
                return i;   //Regresa el digito indicado
            }
        }
        return 0;
    }
};

/*
Nota:
    -Terminados los 45 minutos
    -Perdí tiempo al hacer mucho pesudo codigo en el brute force, debería de hacerlo más breve
    -Al final la versión optimizada fue la que use y fue solo basado en la idea del brute force
        -Si debo checar cada paso, pero tampoco estancarme y trabajarlo de más.
    -No pense en que la resta y suma iban a venir juntos
    -Approach correcto, lo que me fallo fue pensar en pocos casos de prueba
    -Otra perdida de tiempo es la de tratar de sacar uan solución "Ingeniosa", por no
        querer usar el long int. y unsar un unsigned int. Mejor ir por lo seguro y que funcione.
        Yo diria es que la prioridad es que el problema funcione
    -Siento que con apuntadores podría conseguir el numero que representa esa letra. Deberia investigarlo
    
    -Problema tiene dificultad medium, no easy. 

    -Yase como solucionarlo, hacer mi propuesta con while
        Solo salto al inicio todo hasta encontrar un simbolo o un digito
            Si encuentro white space o 0, no pasa nada
            Si encuentro un char, regreso 0
        
        Si salto el simbolo y hay algo que no sea un digito, regreso 0
        Ahora si leo el digito y checo los limites de minimo y maximo, todo mientras sea digito

        Luego ya regreso el numero.

        No import si hay más números despues, terminando de leer el primero. Ya regreso el resultado

*/