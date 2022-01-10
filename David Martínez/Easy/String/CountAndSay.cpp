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
        
        //Runtime: O(n * log n)
        //Primero validamo sel input

        /*
        if(n <= 0){
            return "";
        }
        
        //Base Case
        string result = "1";
        
        while(n > 1){   //Mientras n sea diferente a 1
            
            //Creamos string auxiliar que estará vacío
            string curr = "";
            
            //For loop para recorrer el result
            for(int i = 0; i < result.size(); i++){
                
                int count = 1;  //Contador
                
                //Mientras el numero sea el mismo y no lleguemos al final de la lista
                while(i+1 < result.size() && result[i] == result[i+1]){
                    count++;    //Aummentamos la cuenta
                    i++;    //Seguimos recorriendo
                }
                
                curr += to_string(count) + result[i];   //Sumamos al string auxiliar la cuenta y el digito
            }
            result = curr;  //El string auxiliar se convierte en nuestro resultado
            
            n--;    //Restamos uno a n
        }
        
        return result;  //Regresamos el resultado

        */

               //Respuesta recursiva
        
        //Si n es igual a 1, regresa 1
        if(n == 1) return "1";
        
        string s = countAndSay(n-1);   //Recursivamente bajamos hasta que nos de "1"
        string res = "";    //String donde guardamos el resultado
        
        int i = 0;  //Index
        while(i < s.length())   //Mientras no recorramos el string auxiliar
        {
            int l = i;  //Index para recorrer las letras
            while(l < s.length() && s[i] == s[l])
            l++;    //Recorro el indice
            int count = l-i;    //Cuenta es lo recorrido - el indice en el que estamos
            char c = count + '0';   //Char con la cuenta
            res += c;   //Sumamos al resultado
            res += s[i];    //Agregamos el sigito
            i = l;  //I ahora es igual a la posición del nuevo digito
        }
        return res; //Regresamos respuesta
    }
};

/*
Nota:
    -Primer ejercicio recursivo que me topo
    -Tenía bien la idea para solucionar el problema, solo que no se me ocurrio bajar en la recursividad
        para hacer las operacionesd e subida.
    
    -Primero debo definir el base case
    -Luego ver el recorrido que debo hacer, en este caso era "lineal". Pero sacando la idea de como lo haré
    -Para estar bien posicionado y solo preocuparme por hacer las operaciones

    -Se me terminaron los 45 minutos al resolver este problema
    -Debo practicar más problemas dond aplique recursividad

    //Debo checar el big O en recursividad, pero por el momento creo que la eficiencia en este problema es de
    Runtime: O(levels * length de string)
    Memory: O(n)


*/