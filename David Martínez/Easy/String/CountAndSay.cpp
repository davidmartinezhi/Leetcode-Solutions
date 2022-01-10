#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        //1 listen
            //Recibo un entero que representa num de recursividades
            //Hago recursión de 1 a n
            //Debo regresar la frecuencia de los digitos y los digitos en string
            
        //2 example
            //n=5
            //(1) -> 1
            //(2) -> 11
            //(3) -> 21
            //(4) -> 1211
            //(5) -> 111221
        
            //n=6
            //(1) -> 1
            //(2) -> 11
            //(3) -> 21
            //(4) -> 1211
            //(5) -> 111221
            //(6) -> 312211
            
        
        //3 brute force
            //Siento que lo hago con numeros de ida y strign de regreso
            //Debo contar frecuencia y mandar a recursividad la fecuencia concatenada a su digito
            //Cada sección de numeros la puedo mandar a su propoa recursividad y regresar todo junto
        
            //Mientras no sea diferente el numero, lo cuento.
            //Se hace diferente y mando la frecuencia + el digito
            //Puedo mandar un string desde el inicio y leer los char
            
        
        //4 optimize
            //Se hace a fuerza con recursividad.
            
            
        //5 walkthrough
            //Creo el string y el contador.
            //Cuenta las ocurrencias del numero, hasta que cambie de numero o llegue al final
            //Cada vez que se cumple una de esas condiciones, manda el contador y el digito como recursividad
        
        //6 implement
        //7 test
            //Primero mandando digitos por serparados, a la recursión
        
        //Primero validamo sel input
        if(n <= 0){
            return "";
        }
        
        //Base Case
        string result = "1";
        
        while(n > 1){
            
            //String auxiliar
            string curr = "";
            
            //For loop para recorrer el result
            for(int i = 0; i < result.size(); i++){
                
                int count = 1;  //Contador
                
                //Mientras el numero sea el mismo y no lleguemos al final de la lista
                while(i+1 < result.size() && result[i] == result[i+1]){
                    count++;
                    i++;
                }
                
                curr += to_string(count) + result[i];
            }
            result = curr;
            
            n--;
        }
        
        return result;
    }
};