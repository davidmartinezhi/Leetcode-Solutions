#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        /*
        1. info
            input: array of strings
            output: grouped anagrams (any order)
            
            anagram is a word/phrase fromed by rearranging the letters of a different word/phrase
            
            the array has between 1 and 10,000 words
            word has between 0 and 100 characters
            each word consists only of lowercase english letters
            
            *in interview ask about phrases in array or just words. to know if I shoyld care about
                whitespace and special characters
            
        2. example
        
        ["eat", "tea", "tan", "ate", "nat", "bat"]
        -> [["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]
        
        [""]
        ->[[""]]
        
        ["a"]
        ->[["a"]]
        
        3. brute force
            traverse to create an array with hashtables that don't repeat   time:0(n*m) space:(n*m)
            traverse the hashtables array and add to a vector, each word that matches in strs time(n*m)
            Then add the vector to the resulting vector
            
        4. optimize
            bcr: O(n*m) I need to forcefully traverce the words array and each char
            
            Can I optimize the memory usage?
            
            precompute?
                sort each word: n * (m log m) while comparing
                then compare O(m)
            

            create a hashtable with sorted word as key and vector as value
            if a word matches, it's added to the vector in the array
            
            at last, add all vectors to resulting array
                
        
        5. walkthrough
            
        6. implement
        
        7. test
            empty array
            no anagrams
            anagrams

        */
        
        //first version
        //runtime: O(n* k log k)
        //space: O(n)
        
        vector<vector<string> > result;
        if(strs.size() == 0) return result;
        
        unordered_map<string, vector<string> > ht;   //space: O(n)
        
        //runtime: O(n)
        for(int i = 0; i < strs.size(); i++){
            string aux = strs[i];
            sort(aux.begin(), aux.end());   //runtime: O(m log m)
            
            ht[aux].push_back(strs[i]); //runtime: O(1)
        }
        
        //runtime: O(n)
        for(auto word: ht){
            result.push_back(word.second);
        }
        
        
        return result;
        
    }
};
/*
runtime: O(n*(m log m))
space: O(n)
Terminado en 45 minutos, pero ahora la soluciçon fue originalmente mia y fue la solución más eficiente
para alguién que no esté en programación competitiva.

La solución más eficiente es creando tu propia función de hashing, lo hace:
    runtime: O(n*k)
    space: O(n)


*/

/*
Codigo funcional y terminado en 43 minutos, ando terminandolos al borde.
Pero no es muy eficiente, con grandes arrays de palabras largas, marca error de runtime

Debo optimizarlo a fuerzas

La idea principal sobre como resolverlo, fue bueno. Pero hacía mucho duplicate y uneccesary work.
Un hashtable me hubiera hecho la vida mucho más sencillo.

Hashtable convinado con vectores hace la vida muy sencilla.
En 3 sum, si pude haer mi approach con hashtables, poniendo el numero y los indices que tienen el valor
*/

int main()
{
    Solution solution;
    vector<string> anagrams;
    anagrams.push_back("eat");
    anagrams.push_back("tea");
    anagrams.push_back("tan");
    anagrams.push_back("ate");
    anagrams.push_back("nat");
    anagrams.push_back("bat");

    vector<vector<string> > result = solution.groupAnagrams(anagrams);

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

