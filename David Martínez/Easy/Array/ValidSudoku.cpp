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
        
        //Ahora checo las secciones 3x3
        if(subVectors(board, 0) == false){
            return false;
        }
        
        
        return true;    //Si se cumple todo y cruza las validaciones, es true
    }
    
    bool subVectors(vector<vector<char>>& board, int i){
        unordered_map<char,int> valid;
        
        
        for(int count = 1; count <= 3; i++){   //cuenta de 3, para las subsecciones
            valid.clear();
            int j = i + 3; //i = 0 -> j = 3 //Saca hasta donde vamos a recorrer
            cout << endl;
            for(int k = 0; k < 3; k++){ //Recorro renglones 
                for(; i < j; i++){  //Recorro columnas
                    cout << board[i][k] << " ";
                    
                    if(board[k][i] != '.'){
                        if(valid.find(board[k][i]) == valid.end()){
                            valid[board[k][i]]++;
                        }
                        else{
                            return false;
                        } 
                    } 
                }
            }
            
        }
        return true;

    }
};

/*
Nota:
    -Solución y la logica de porque es optima, lo saque rapido
        -El problema fue el trabajar con las columnas y renglones del vector en 2-D
        -Si creo poder la solución el primero de enero que vuelva a tratar, porque mañana es año nuevo

    -Deberia familiarizarme con matrizes más. y checar diferentes approaches para soluciones en matrizes
*/