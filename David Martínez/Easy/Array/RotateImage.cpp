#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //1 listen
            //Recibo una matriz nxn, que representa una imagen
            //Debo rotar la imagen en 90 grados
            //Debo hacerlo in-place, sin implementar otra matriz. Con memoria O(1)
            //n, esta en el rango de 1 y 20
            //Los valores de la matriz son entre -1000 y 1000
        
        //2 example
            /*
            [1, 2, 3],      [7, 4, 1],
            [4, 5, 6], ->   [8, 5, 2],
            [7, 8, 9],      [9, 6, 3]
            
            //2, 0 se coloca en 0, 0
            //1, 0 se coloca en 0, 1
            //0, 0 se coloca en 0, 2
            
            //2, 2 se coloca en 2, 0
            //2, 1 se coloca en 1, 0
            //2, 0 se coloca en 0, 0
            */
            
        
        //3 brute force
            //Brute force sería recorrer de 0 a n-1
            //Hacer un for loop anidado de i a n-1
            //Hacer switch
            //Con este approach la memoria se queda en O(1)
            //Runtime podria ser de O(N)
        
        //4 optimize
            //Siento que es la solución más optima
        
        //5 walkthrough
            //Creo un for loop de 0 a n-1, que es i
            //Ahora anido un for loop llamado j que es i
                //Hago switch [i][j] por [j][i]
        
        //6 implement
            
        //7 test
            //Array de 1 elemento (1x1)
            //Array con más de 1 elemento

            //to do:
                //Checar como quedan los datos despues de hacer swap entre columnas y renglones
        
        //Saco el tamaño de las dimensiones en el array
        int n = matrix[0].size();
        
        if(n == 1){ //Si el array es de un solo elemento, regreso de manera directa
            return;
        }
        
        //Reacomodando los subarrays
        //O(N)
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){

                int aux = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = aux;
            }
        }
        

        //Posicionando los elementos en la posición adecuada
        //Mi implementación fue de N*(N/2), que equivale a O(N^2).
        //Puede ser optimizada la solución con hacer un reverse, sin usar variable auxiliares
        for(int i = 0; i < n; i++){ //Recorro cada renglon

            //Creo apuntador al inicio y al final de ese renglon
            int start = 0;
            int end = n-1;
            
            //Hago reverse
            while(start < end){
                int aux = matrix[i][start];
                matrix[i][start] = matrix[i][end];
                matrix[i][end] = aux;
                start++;
                end--;
            }
        }
        
    }
};

