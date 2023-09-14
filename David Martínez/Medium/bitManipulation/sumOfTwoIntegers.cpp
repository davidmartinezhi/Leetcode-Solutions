#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {

        /*
       int carry = 0, result = 0;

        for (int i = 0; i < 32; ++i) {
            int aBit = (a >> i) & 1;
            int bBit = (b >> i) & 1;

            // Suma de bits individuales
            int sum = aBit ^ bBit ^ carry;

            // Actualizar el acarreo para el siguiente ciclo
            carry = (aBit & bBit) | (carry & (aBit ^ bBit));

            // Colocar el bit de suma en el resultado
            result |= (sum << i);
        }

        return result;
        */
        
        //while b is not 0
        while(b != 0){

            //get the positions where we need to carry, where values are the same (1&1)
            //unsigned para tomarlo como positivo y no darle importancia al simbolo
            unsigned carry = a&b;

            //perform sum, where values are different, we set 1s
            a = a^b;

            //shift carry, by one
            b = carry << 1;
        }

        return a;

    }
};

/*
Notes:

Complexity:
    time: O(1) **Verificar que la complejidad sea correcta** pudiese ser O(log b)
    extra space: O(1)
    Pregutnar complejidad a Osuna
    También preguntar como es que funciona con números negativos

De lo que tengo entendido este tipo de operaciones no se usan en la vida real
ni en entrevistas, pero pueden tocar.

Creo que tuve un entendemiento de como es que funciona la solución

& to know where to carry
^ for addition
<< left shift operator

agregada solución propia
*/