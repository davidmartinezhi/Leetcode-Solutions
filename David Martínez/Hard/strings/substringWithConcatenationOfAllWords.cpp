#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // Verificar si la lista de palabras está vacía
        if (words.empty()) return {};
        
        // Crear un mapa para contar la frecuencia de cada palabra en la lista de palabras
        unordered_map<string, int> wordCount;
        for (const auto& word : words) {
            ++wordCount[word];
        }
        
        // Inicializar variables
        int n = s.size();  // Longitud de la cadena s
        int num = words.size();  // Número de palabras en la lista
        int len = words[0].size();  // Longitud de cada palabra
        vector<int> res;  // Resultado final
        
        // Recorrer cada subcadena de tamaño 'len' en 's'
        for (int i = 0; i < len; ++i) {
            int left = i;  // Índice izquierdo de la ventana
            unordered_map<string, int> seen;  // Palabras vistas en la ventana actual
            
            // 'j' es el índice derecho de la ventana
            for (int j = i; j <= n - len; j += len) {
                string word = s.substr(j, len);  // Extraer la palabra en la posición actual
                
                // Si la palabra está en la lista original
                if (wordCount.count(word)) {
                    ++seen[word];  // Aumentar la cuenta de la palabra 'word' en la ventana
                    
                    // Si hay demasiadas instancias de la palabra 'word', mover la ventana hacia la derecha
                    while (seen[word] > wordCount[word]) {
                        string temp = s.substr(left, len);
                        --seen[temp];
                        left += len;
                    }
                    
                    // Comprobar si la ventana tiene el tamaño de todas las palabras combinadas
                    if (j - left == len * (num - 1)) {
                        res.push_back(left);  // Añadir el índice de inicio de la ventana al resultado
                    }
                } else {
                    // Si la palabra no está en la lista original, reiniciar la ventana y 'seen'
                    seen.clear();
                    left = j + len;
                }
            }
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    vector<int> res = sol.findSubstring(s, words);
    for (int idx : res) {
        cout << idx << " ";
    }
    cout << endl;
    return 0;
}