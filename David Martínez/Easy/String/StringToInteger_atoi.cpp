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
            //"abc-345   " -> 0
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
            //Cuento los signos que aparecen
            //Creo variable result = 0
            //Recorro string mientras sea un non-digit y no sea un símbolo.
                //si encuentra simbolo, updateo bandera y contador
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
        
        /*
     -Yase como solucionarlo, hacer mi propuesta con while
        Solo salto al inicio todo hasta encontrar un simbolo o un digito
            Si encuentro white space o 0, no pasa nada
            Si encuentro un char, regreso 0
        
        Si salto el simbolo y hay algo que no sea un digito, regreso 0
        Ahora si leo el digito y checo los limites de minimo y maximo, todo mientras sea digito

        Luego ya regreso el numero.

        No importa si hay más números despues, terminando de leer el primero. Ya regreso el resultado       
        */
       //Respuesta checada en youtube: https://www.youtube.com/watch?v=FyTpsuWAoc8
        //Puedo hacer operaciones matematicas con characters, int con numeros
        //int num2 = result * 10 + (s[0] - '0'); Así saco valor numerico con characters

        //Runtime: O(n)
        //Memory: O(1)
        
       //Apuntador
        int i = 0;
        
        //Salto whitespace
        while(i < s.size() && s[i] == ' '){
            i++;
        }
        
        //Checo si recorrí toda la lista
        if(i >= s.size()){ return 0; }
        
        //Checo simbolo, en caso de haberlo encontrado
        int sign = 1;
        if(s[i] == '+' || s[i] == '-'){
            sign = (s[i] == '+') ? +1 : -1;
            i++;
        }
        
        
        //Checo si recorrí toda la lista
        if(i >= s.size()){ return 0; }
        
        //Ya que esoty en el integer, lo recorro para sacar el resultado
        int result = 0;
        for(; i < s.size() && isdigit(s[i]); i++){
            
            if(result > INT_MAX/10 ||
              (result == INT_MAX/10 && s[i] - '0' > INT_MAX % 10)){
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = (result * 10) + (s[i] - '0');
        }
        
        //Nota: De manera implicita, si encuentra un valor alphabetico.Se atora ahí,nunca lee el digito y regresa 0
       //Luego cuando hay digitos despues, ni los checa porque solo importa el numero
        
        //Muy buena solución, debería de pensar en una manera de lograr cosas implicitamente tmbn. 
        return result * sign;
        
        /*
        //Bandera para saber el signo que es
        bool sign = true;   //Podría quitar esta bandera
        
        //Contador para saber cuantos signos contiene el string
        int countSimbols = 0;
        
        //Bandera para saber si ya encontre algún digit
        bool digitFound = false;
        
        //Resultado
        int result = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            //Si encontramos algún simbolo
            if(s[i] == '-' || s[i] == '+'){
                
                //actualizamos cuenta
                countSimbols++;
                
                //Si ya encontramos 2 simbolos
                if(countSimbols == 2){
                    return 0;   //Regresamos 0
                } 
                
                //Si el simbolo es negativo, actualizamos el signo
                if(s[i] == '-'){   
                    sign = false;   //Aviso que el simbolo es negativo
                }
                
            }
            
            //Si encontramos un punto
            if(s[i] == '.'){
                return result;  //Regreso el resultado, porque es entero. No float
            }
            
            //Si encuentro un valor alphabetico antes de un digito
            if(isalpha(s[i]) && digitFound == false){
                return 0;
            }
            
            //Si encuento un digito
            if(isdigit(s[i])){
            
                //Saco el valor que voy a agregar
                int aux = toInteger(s[i]);
                
                //Checo si ya encontre un número que no sea 0
                if(aux != 0){
                    digitFound = true; //Confirmo que encontre un digito
                }
                
                //Si digitFound = True, Ya comienzo a agregar datos
                if(digitFound){
                    //Checo que el resultado no cruce los limites
                    //INT_MAX
                    if(sign){
                        if((result > INT_MAX/10) || (result == INT_MAX/10 && aux > 7)){
                            return INT_MAX;
                        }
                    } 
                    //INT_MIN
                    else {
                        if((result > INT_MAX/10) || (result == INT_MAX/10 && aux > 8)){
                            return INT_MIN;
                        } 
                    }
                
                    //Si no cruza los limites, agrego el digito
                    result *= 10;
                    result += aux;
                }
                else{
                    return 0;
                }
            }
        }
        
        if(sign == false){
            result *= -1;
        }
        return result;
        */
        
        /*for(int i = 0; i < s.size(); i++){
            
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
        return result;  //Regresamos el result*/
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

    -Debo de ser más especifico con mis preguntas y restricciones, no tener las restricciones bien definidas en este problema
     me llevo a hacerlo bien, pero no lo que querían que yo hiciera.
    -Lo hice para un caso más general según la descripicón, pero me lo piden más simple

    //Lecciones aprendidas
        //Puedo hacer matematica entre chars y enteros. Obvio tienen sus limites, pero es posible.
        //Sao un numero en char a entero escribiendo en el integer s[i] - '0'

    Tengo que pensar sobre porque se me complico tanto el problema, me hice bolas
    Ya tenía la idea de como solucionarlo, pero me metí a demasiados detalles.

    Ver el big picture del problema primero.
    Luego ver si lo puedo dividir en modulos.
    Tambíen, en ninguna parte decía que solo se le hacía caso al primer digito encontrado.
    Siento que el problema no fue muy especifico, pero esta bien. Trataré de hacerlo de la forma más simple a la proxima
    Aprendí sobre convertir characteres a enteros y como se maneja casí universalmente el no cruzar los limites INT_MAX y INT_MIN
    Aparte es muy eficiente checar el simbolo con sign siendo 1 o -1, así solo multiplicas al final. Yo lo hacía un booleano.
*/