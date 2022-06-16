#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char palabra[100];  //Arrays de chars = string
    char result[100];
    int i;

    cout << "Ingresa la palabra: ";
    cin >> palabra;

    //Mientras leemos palabra, vamos rellenando result
    //'\0' es como c++ sabe que llegaste al final del string en un array de chars
    //Por eso la condición en el for loop es que avance hasta encontrar ese char especial

    for(i = 0; palabra[i] != '\0'; i++){    
        int currLetter = palabra[i]-'a';    //Sacas index de la letra en el alfabeto
        
        if(currLetter + 4 >= 25){   //Si pasa o llega al ultimo, le ponemos z
            result[i] = 'z';
        }
        else{   //Agregamos la letra + 4 espacios en el alfabeto
            result[i] = palabra[i] + 4;
        }
        
    }

    result[i] = '\0';   //marca de donde termina el string que acabamos de crear, para que c++ sepa

    cout << endl;
    cout << result;
    cout << endl;

    return 0;
}
