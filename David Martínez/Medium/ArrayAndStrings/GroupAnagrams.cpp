#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // 1 listen
        // Recibo un array de strings llamado "strs"
        // Regreso una matriz donde cada renglon tenga anagramas juntos
        // Array puede tener hasta 10,000 strings
        // String puede tener entre 0 y 100 characters
        // String consisten solamente de letras minusculas

        // 2 example
        /*
        ["eat","tea","tan","ate","nat","bat"] -> ["bat"],["nat","tan"],["ate","eat","tea"]]
        */

        // 3 brute force
        // Recorrer toda la lista, meter letra y frecuencia(hashtable) de cada palabra en un set.
        // De tal modo ya tengo las hashtables de todos los anagramas existentes.
        // Ahora recorro la lista de anagramas y por cada palabra en strs, checo su hashtable
        // Si es igual a la que tenemos en la lista de anagramas, la meto al vector y regreso

        // runtime: (O(n*m)) n: strs.size(), m: characters en las palabras
        // memory: O(n)

        // 4 optimize
        // Puedo en lugar de hacer hashtable, tener un vector con cuenta en las letras
        // Luego hacer la mate en las palabras cuando las recorremos
        // Si toda la lista da igual a 0, agregamos la palabra. Sino saltamos

        // Puedo hacer helper function de isValidAnagram, luego recorro la lista para hacer
        // hacer set de palabras anagram
        // Luego comparo paralbras en el set con las del array y las hunto

        // 5 walkthrough
        // Creo matriz set con los contadores
        // Creo matriz con los resultados

        // relleno los contadores

        // Por cada contador, recorro el vector
        // Creo vector<string> auxiliar
        // Recorro el vector de strings
        // vector auxiliar que es igual al contador
        // Hago la mate con la palabra
        // Si aplica, la agrego al vector
        // Pushback del vector string auxiliar
        // regreso el resultado

        // 6 implement

        // 7 test
        // Special cases, empty string
        // Strs size 1
        

        //Solución funcional, pero inservible por la mala eficiencia en rutnime
        /*
        //O(k) k siendo los grupos de anagramas
        vector<vector<string>> result;

        if (strs.size() == 1)
        {
            result.push_back(strs);
            return result;
        }

        //O(n) n siendo el numero de frecuencias en palabras
        set<string> anagrams;

        //O(n*m log m)
        for (int i = 0; i < strs.size(); i++)
        {
            string aux = strs[i];
            sort(aux.begin(), aux.end());
            anagrams.emplace(aux);
        }

        //O(n^2*m) = Podría llegar a ser 100,000,000,000 (Horrible)
        for (auto it = anagrams.begin(); it != anagrams.end(); it++)
        {
            vector<string> aux;
            for (int i = 0; i < strs.size(); i++)
            {

                if (isValidAnagram(*it, strs[i]))
                {
                    aux.push_back(strs[i]);
                }
            }

            result.push_back(aux);
        }

        return result;
    }

    // Comparación de palabras
    //runtime: O(m)
    //memory: O(1)
    bool isValidAnagram(string s, string &t)
    {
        // Checo que tengan el mismo size
        if (s.size() != t.size())
        {
            return false;
        }

        // Array para las veces letras del alphabeto ingles
        int count[26] = {0};

        // Recorro ambas arrays para sacar cuentas en count
        // Si count esta llena de 0 al final, la palabra es anagram

        for (char c : s)
        {
            count[c - 'a']++;
        }

        for (char c : t)
        {
            count[c - 'a']--;
        }

        // Recorro la cuenta para saber si todo es 0
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
            {
                return false;
            }
        }

        return true;
    */

//Solución basada en codigo que hice en python
        //Podría usar la tecnica que hice en el ejercicio esay de strings en "isValid Anagram"
        //Y que las keys sean esos arrays. De esa manera en lugar de hacer mlogm ordenando las letras
        //Solo tomaria m, en sacar el array de palabras y ver si ya existe como key
        
        //Runtime: O(n*mlogm) n:recorremos "n" elementos m: las letras de la palabra, mlogm: runtime para ordenar
        //Memory: O(n)
        
        //creo hashtable que va a agrupar los anagramas
        unordered_map<string, vector<string>> hashtable;    //O(n) memory
        
        //Creo vector que tendrá el resultado final
        vector<vector<string>> result;
        
        //Recorro todas las palabras
        for(int i = 0; i < strs.size(); i++){   //O(n) runtime
            
            //Ordeno letras de la palabra
            string aux = strs[i];
            sort(aux.begin(), aux.end());   //O(m log m)
            
            //La palabra sorted, es la key y el value es el vector con las palabras que tienen la misma palabra con ltras ordenadas
            if(hashtable.find(aux) != hashtable.end()){ //Si ya tiene palabras en esa key, hacemos pushback
                hashtable[aux].push_back(strs[i]);
            }
            else{   //Si no tiene palabras, agregamos el vector con una sola palabra
                vector<string> auxVector = {strs[i]};
                hashtable[aux] = auxVector;
            }
        }
        
        //Ahora agrego cada grupo de anagramas al vector con el resultado
        for(auto x: hashtable){ //O(n)
            result.push_back(x.second);
        }
        
        return result;  //Regreso el resultado

    }
};

/*
Codigo funcional y terminado en 43 minutos, ando terminandolos al borde.
Pero no es muy eficiente, con grandes arrays de palabras largas, marca error de runtime

Debo optimizarlo a fuerzas
Esta solución debe estar compuesta por los 2 easy: isValidAnagram y tecnica de remove duplicates from sorted array(tecnica adaptada para agrupar).
O(n*m)
Acomodar
Yase como incrementar la eficiencia, Uso la tecnica de 2 pointers
    Pointer que se queda al frente de los anagrams con la palabra que estamos checando
    De esta manera agrupamos los datos

    Hago bandera para saber que encontramos un anagram

Si no encuentra anagram, regresa la lista original, dentro de result

O(n*m)
Si encuentra anagram
    Dynamic sliding window technique
    Agrego los datos dentro de la window al vector<string> aux;

    agrego el aux a result

regreso el result

runtime: O(n*m) Podría llegar a ser 1,000
memory: O(result)
*/
