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
        
        //O(k) k siendo los grupos de anagramas
        vector<vector<string>> result;

        if (strs.size() == 1)
        {
            result.push_back(strs);
            return result;
        }

        //O(j) j siendo el numero de frecuencias en palabras
        set<string> anagrams;

        //O(n*m log m)
        for (int i = 0; i < strs.size(); i++)
        {
            string aux = strs[i];
            sort(aux.begin(), aux.end());
            anagrams.emplace(aux);
        }

        //O(n^2*m)
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
    }
};

/*
Codigo funcional y terminado en 43 minutos, ando terminandolos al borde.
Pero no es muy eficiente, con grandes arrays de palabras largas, marca error de runtime

Debo optimizarlo a fuerzas

*/
