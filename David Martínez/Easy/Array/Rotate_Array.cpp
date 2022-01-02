#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
       int n = nums.size();
        k %= n;
        
        //Reverse es aplicado en el vector, es un rango de 2 parametros
            //Primer parametro es index de inicio
            //Segundo parammetro es el index final
        
        
        //Reverseo el array del principio hasta que comience el subarray que debo rotar
        reverse(nums.begin(), nums.begin() + n - k);
        
        //Reverseo el subarray que voy a rotar
        reverse(nums.begin()+n-k, nums.end());
        
        //Reverseo todo el array
        reverse(nums.begin(), nums.end());

    }
};

/*
Nota: 
    -No lo solucione yo de manera eficiente.
    -Lo agarre de youtube, pero se puede implementar para cualquier problema donde pidan hacer este tipo de rotate
    solución: https://www.youtube.com/watch?v=5D9OrHsw3M0

    Pero también hice el problema antes de seguir la metodología del libro. Luego debo intentarlo de nuevo

*/