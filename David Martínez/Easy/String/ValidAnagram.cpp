#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        //1 listen
            //Recibo dos strings (s y t)
            //Regreso true, si "t" es anagrama de "s"
            //De lo contrario regreso false
            //s y t, pueden tener size entre 1 y 500,000 caracteres
            //Solo consisten de lowercase english letters
            
            //Anagram, palabras con la misma ocurrencia de letras
        
        //2 example
            // s: "iceman", t: "cinema" -> true
            // s: "car", t: "rat" -> false
            
        
        //3 brute force
            //Para un caso general
            //Podría crear 2 hashtables y compararlos
                //Si son iguales, regreso true
                //Si no son iguales, regreso false
            
            
            
        //4 optimize
            //Podría hacer un sort y comparar de manera secuencial
            //Best concievable runtime O(n+n) -> O(n)
            
            //Con hashtables usaria de memoria O(n) y runtime O(n) worst case
            
            //Sorting usaria memoria O(1) y runtime O(n log n) worst case, ya que recorro ambos strings al mismo tiempo.
        
        //5 walkthrough
            //Hago sort de ambas listas y luego comparo cada elemento
        
        //6 implement
        //7 test
            //Palabras anagramas
            //Palabras no anagramas
        
            //Special case
                //Palabras no tienen la misma longitud
                //Una letra, pero ambas diferentes
        
        
        //Solución con sort
        //Runtime: O(n log n)
        //Memory: O(1)
        
        /*
        //Checo si tienen la misma cantidad de caracteres
            //Si no tienen la misma cantidad, no pueden ser anagramas
        if(s.size() != t.size()){
            return false;
        }
        
        //Hago sort de ambos strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        //Ahora recorro ambos strings
        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[i]){   //Si una palabra es distinta
                return false;   //Regreso false
            }
        }
        
        return true;    //Si cruza toda la lista sin problemas, entonces es true
        */
        
        
        //Solución con Hashtable
        //Runtime: O(n)
        //Memory: O(n)
        
        /*
        //Checo si tienen la misma cantidad de caracteres
        //Si no tienen la misma cantidad, no pueden ser anagramas
        if(s.size() != t.size()){
            return false;
        }
        
        //Creo hashtables
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;
        
        //Recorro ambas listas para llenarlas
        for(int i = 0; i < s.size(); i++){
            sMap[s[i]]++;
            tMap[t[i]]++;
        }
        
        return (sMap == tMap);
        */
        
        
        //Solución con cuentas
        //Según las 26 letras en el vocabulario de idioma y que todas son minusculas
        //runtime: O(n)
        //memory: O(1)
        
        //Checo si tienen la misma cantidad de caracteres
        //Si no tienen la misma cantidad, no pueden ser anagramas
        if(s.size() != t.size()){
            return false;
        }
        
        //Creo array con 26 espacios y todos les asigno un 0
        int count[26] = {0};
        
        //Recorro ambos strings para hacer cuentas de letras en el array
        
        for(char c : s){    //Sumo letras en el array, según s
            count[c - 'a']++;
        }
        
        for(char c : t){    //Resto letras en el array, según t
            count[c -'a']--;
        }
        
        //recorro las cuentas y si encuentro un numero dif a 0, regreso false
        for(int i = 0; i < 26; i++){
            if(count[i] != 0){
                return false;
            }
        }
        
        return true;    //Si todo el array contiene 0s, regreso true
    }
};

/*
Notas:  
    -Ayer hice el ejercicio de First Unique character y me fije que si conviene hacer una solución 
        personalizada a tu problematica, en lugar de hacer una solución general

    -Hoy tome 16 minutos en resolverlo, haciendo el metodo que hacía sort, con metodología y todo
        Pero ya había pensado en que debería hacerlo con el array de 26 cuentas
        Solo que lo quise hacer con el sort primero.

    -No me canse nada, haciendo este problema. Ya siento sencillos muchos problemas y dentro de mi alcance
     para hacerlos en menos de 20 minutos cada uno. Se que sigo en la sección facíl, pero apenas los estoy comenzando
     a sentir faciles. Se nota que aprender de cada problema, tener una metodologia y una checklist para optimizaciones en un corto lapzo de tiempo
     hacen un gran favor a la solución de problemas.

*/