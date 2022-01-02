
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            result ^= nums[i];
        }
        
        return result;
    }
};

/*
Nota:
    Esta solución la saque de youtube, no tenía idea que se podia representar el xor de tal manera.
    Aparte lo resuelve dentro de un solo espacio de memoria.
    Solución explicada: https://www.youtube.com/watch?v=krgK0UlfNYY&t=249s

    Esto representa la ayuda que es el saber manipular bits.
    Debo recordar, checar este tema con los demás.

    Debo tratar de solucionar la respuesta por mi cuenta
    También hice el problema antes de seguir la metodología del libro. Luego debo intentarlo de nuevo


*/