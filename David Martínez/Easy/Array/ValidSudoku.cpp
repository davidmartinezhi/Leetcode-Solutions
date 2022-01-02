#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Listen
            //Recibo un vector de 2 dimensiones
            //Solo las celdas no vacías deben ser validadas
            //Cada sub-vector 3x3, debe tener numeros del 1-9 sin repetirse
            //Cada renglón y columna debe tener números del 1-9 sin repetirse
            //Si esto es valido para todo el sudoku, regresamos true
        
        // Example
            //Cuaderno
        
        // Brute Force
            //Sería checar todos los renglones, luego las columnas y por ultimo los sub-vectores
            //Cada checada sería con el mismo hashtable, si se repite un numero regresamos false
                //En cualquier etapa
            //En teroría sería O(1), checar renglones y columnas. Siempre serán 9x9
            //También tomaria O(1), memoria porque siempre sería 9x9 en strings
            //Puedo hacer función que cheque subsecciones de arriba para abajo
                //En codigo principal lo recorro de izquierda a derecha y en el modulo, arriba a abajo
            
        // Optimize
            //Siento que esta es la manera más eficiente de resolver el problema
            //Cualquier otra solución no tendría un gran impacto en la eficiencia
        
        // Walkthrough
            //Creo hashtable para comparaciónes
            //Recorro renglones mientras comparo
            //Recorro columnas mientras comparo
            //Creo modulo que compare secciónes 3 x 3
            //Recorro esas secciones de 3x3
        
        // Implement
        
        // Test
            //Renglon no valido
            //Columna no valida
            //Sub-vector 3x3 no valido
        
        //Creo el hashtable para hacer comparaciones
        unordered_map<char,int> valid;
        
        //Valido los renglones
        for(int j = 0; j < 9; j++){ //Recorro renglones
            valid.clear();
            for(int i = 0; i < 9; i++){ //Recorro las celdas
                
                if(board[j][i] != '.'){ //Si es una celda no nula
                    if(valid.find(board[j][i]) == valid.end()){ //Si no se encuentra el valor
                        //La agrego al hashtable
                        valid[board[j][i]]++;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        
        //Valido las columnas
        for(int j = 0; j < 9; j++){
            valid.clear();
            for(int i = 0; i < 9; i++){
                if(board[i][j] != '.'){
                    if(valid.find(board[i][j]) == valid.end()){
                        valid[board[i][j]]++;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        
        //Valido secciones 3x3
        //Siempre va a correr la misma cantidad de veces
        //Entonces es irrelevnte que tenga 4 for loops anidados, los de arriba siempre recorreran 3 (0, 3, 6)
        //Al igual que los de abajo (0,1,2)
        for(int i = 0; i < 9; i += 3){  //Salta de 3 en 3 los renglones
            for(int j = 0; j < 9; j += 3){  //Salta de 3 en 3 las columnas
                
                valid.clear();  //Borra los datos en la hashtable
                
                //Para sacar los datos del subarray
                for(int k = 0; k < 3; k++){ 
                    for(int h = 0; h < 3; h++){
                        if(board[i+k][j+h] != '.'){
                            if(valid.find(board[i+k][j+h]) == valid.end()){
                                valid[board[i+k][j+h]]++;
                            }
                            else{
                                return false;
                            }
                        }        
                    } 
                }
            }
        }
        
        
        return true;    //Si se cumple todo y cruza las validaciones, es true
    }
};

/*
Nota:
    -Como la matriz siempre tendra una matriz 9x9 del tipo de dato char.
    -El runtime siempre será de O(1) y memoria de O(1)

    -Solución y la logica de porque es optima, lo saque rapido
        -El problema fue el trabajar con las columnas y renglones del vector en 2-D
        -Si creo poder la solución el primero de enero que vuelva a tratar, porque mañana es año nuevo

        -update: lo termine en 15 minutos, solo que por querer a fuerzas hacerlo un modulo, no pense en que lo podia sacar de manera directa.


    -Posible optimización:
        Podría de alguna manera checar en una recorrida todo?
        Si, podría usar el recorrido del final 3x3, y guardar en 3 hashtables los datos.
        Del tal manera recorro 1 vez la tabla en lugar de 3. Aunque siento que no sería una grn diferencia en eficiencia.

    
    -Deberia familiarizarme con matrizes más. y checar diferentes approaches para soluciones en matrizes
    -Matrizes se ven más intimidantes de lo que en realidad son. No initimidarme al ver el problema, nunca.
*/