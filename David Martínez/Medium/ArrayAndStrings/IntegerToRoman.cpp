#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        /*
        1. listen
            input: integer number
            output: string representing that number, in roman number
            constraints:
                input number has value between 1 and 3999
                
        2. example
            num = 3
            -> III
            
            num = 58
            -> LVIII
            
            num = 1994
            -> MCMXCIV
            
        3. brute force
            From right to left read each digit
            and get its corresponding symbol
            time: O(n)
            extra space: O(1)
            
        4.optimize
        
        5. walkthrough
        
        7.test
            
            
        */
        
        //time: O(n)
        //extra space: O(1)
        
        //variables
        int aux = num; //number
        int decimals = 10;  //decimals to get each single digit
        string result;  //Resulting string
        
        while(aux != 0){    //While aux is different from cero
            result = intToRo(aux%decimals) + result;    //Add the digit convertion at the start of the string
            aux -= aux%decimals;    //Remove digits
            decimals *= 10; //Increase decimal
        }
        
        return result;
    }
    
    string intToRo(int digit){
        if(digit == 4){
            return "IV";
        }
        else if(digit == 9){
            return "IX";
        }
        else if(digit == 40){
            return "XL";
        }else if(digit == 90){
            return "XC";
        }else if(digit == 400){
            return "CD";
        }else if(digit == 900){
            return "CM";
        }else{
            string auxDigit = "";
            int aux = digit;
            
            while(aux > 0){
                if(aux/1000 >= 1){
                    auxDigit += "M";
                    aux -= 1000;
                }else if(aux/500 >= 1){
                    auxDigit += "D";
                    aux -= 500;
                }else if(aux/100 >= 1){
                    auxDigit += "C";
                    aux -= 100;
                }else if(aux/50 >= 1){
                    auxDigit += "L";
                    aux -= 50;
                }else if(aux/10 >= 1){
                    auxDigit += "X";
                    aux -= 10;
                }else if(aux/5 >= 1){
                    auxDigit += "V";
                    aux -= 5;
                }else if(aux/1 >= 1){
                    auxDigit += "I";
                    aux -= 1;
                }
            }
            
            return auxDigit;
        }
    }
};

/*
Nota:
    Casí termino de descifrar la solución a los 20 minutos
    Pero por dudar, tarde mucho en comenzar a hacer el programa y resulto salir a la primera.

    Aún así tarde 45+ minutos. Pero de manera innecesaria.
    No debo de hesitar tanto, debo de sacar alguna solución y actuar antes.

*/