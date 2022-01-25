#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        
        // 1 listen
            //Palindrome es cuando una palabra se lee igual al derecho y al revex
            //Pero debe ser todo en minusculas y no tener characteres que no sean numeros o letras
        
            //Recibo un string "s" y debo checar si es un palindromo
                //Regreso true, si es un palindromo
                //Regreso false, si no es un palindromo
            //El string contiene entre 1 y 200,000 caracteres
        
        // 2 example
            //"A man, a plan, a canal: Panama" -> "amanaplanacanalpanama" -> true
            //"race a car" -> "raceacar" -> false
        
        // 3 brute force
            //Convierto mayusculas a minusculas
            //Hacer 2 arrays y cuando encuentre un valor alfanumerico, lo agrego
            //Recorrer la lista de final a inicio y guardarla en un array
            //Recorrer la lista de inicio a final y guardarlo en otro array
            //Si son iguales, regreso true, sino regreso false
                
        // 4 optimize
            //Puedo solo usar un apuntador a inicio y otro a final
            //Recorro y comparo al mismo tiempo ambos hasta que se crucen
            //Me aseguro de recorrerlos a su siguiente valor alphanumerico antes de comparar
            //Si no coinciden los caracteres, regreso false
            //Si se cruzan los pauntadores y nunca regreso false, regreso true
        
        // 5 walkthrough
            //Convierto string a minusculas
            //Creo apuntadores(start, end)
            //Recorro (start < end)
            //Checo posición de cada apuntador, para saber si esta en valor alfanumerico sino recorro
            //comparo
        
        // 6 implement
        // 7 test
            //Puro whitespace
            //to-do
                //Debo averiguar como convertir mayuscula en minuscula
                    //Es una lambda function
                    // transform(data.begin(), data.end(), data.begin(), [](unsigned char c){ return std::tolower(c); });
    
                //Debo averiguar como saber si estoy en un valor alphanumerico
                    //isalnum()
        

        //convierto a lowercase Runtime: O(n)
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){return tolower(c);});
        
        //Creo apuntadores de start y end: Memory O(1)
        int start = 0;
        int end = s.size();
        
        //Bandera para saber si se encontro algún valor alpha numerico
        //bool alnum = false;
        
        //Los recorro Runtime: O(n)
        while(start < end){
            
            //Recorro start, mientras no sea alphanumerico y no se cruce con end
            while(!isalnum(s[start]) && (start<end)){
                start++;    //Lo recorro
            }
            
            //Recorro end, mientras no sea alphanumerico
            while(!isalnum(s[end]) && (start < end)){
                end--;
            }
            
            //Comparo si son diferentes los valores
            if(s[start] != s[end]){
                return false;   //Si son diferentes, regreso false
            }
           // else if(s[start] == s[end] && (isalnum(s[start]))){   //Checo si son iguales y alnum
                //alnum = true;
            //}
            
            //Recorro los apuntadores
            start++;
            end--;
            
        }

        //Ya se recorríeron todos los caracteres y no se encontraron caracteres diferentes
        //Ahora checo si existían caracteres en el string
        return true;
    
    /*
        Gran idea de Alexa usar tolower(), para comparar en el momento. En lugar de convertir

        //Declarar mis dos apuntadores
        int start = 0;
        int end = s.size() -1;
        
        //Mientras no se crucen en medio
        while(start < end){
            
            //Mientras s[start] no sea alphanumerico, avanzo
            while(!isalnum(s[start]) && start < end){
                start++;
            }
            
            //Recorremos el apuntador del final hasta encontrar un valor que es alphanum
            while(!isalnum(s[end]) && start < end){
                end--;
            }
            
            //Comparar que las letras sean iguales
            if(tolower(s[start]) != tolower(s[end])){
                return false;
            }
            
            //Para que sigan el recorrido
            start++;
            end--;
            
        }
        

        return true;
        */
                
    }
};

/*
Nota:
    -Solución sacada en 31 minutos
        Pero en lo que más me tarde fue en descubrir como convertir a minusculas.
        Siento que pude acabarlo en 20-25 minutos. Si ya hubiera sabido como convertir a lowercase
        
    -Solución bastante eficiente
    -Deberia de memori<ar como transformar a minusculas o mayusculas. Algún string.
    - También es bueno saber de la función isalnum y correspondientes. Han de ser muy utiles.

*/