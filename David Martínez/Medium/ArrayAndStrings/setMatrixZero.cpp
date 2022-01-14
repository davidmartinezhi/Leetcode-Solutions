#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //1 listen
            //Recibo una matriz de tamaño (n * m)
            //Si un elemento tiene un valor de 0
                //Convierto su columna y su renglon en 0s
            //Debe ser in-place
        
            //m y n, pueden tener rango entre 1 y 200
            //m = numero de renglones
            //n = numero de columnas
        
        //2 example
            //Cuaderno
        
        //3 brute force
            //Puedo regorrer todos los elementos de la matriz y guardar en donde las voy encontrando
            //Guardo los indeces de renglones y columnas donde todo lo convierto a 0
            //Runtime: O(n*m)
            //Memory: (O(n))
            
        //4 optimize
            //Siento que la unica manera de optimzarlo es hacerlo todo en una corrida
            //En el momento no se me ocurre una manera de hacerlo O(m+n)
                //Sería recorrer todos los renglones y luego todas las columnas
        
            //Optimización de memoria siento que puede ser, recorrerlo todo lineal y
                //Apenas encuentre un 0, convierto todo su renglon a 0 y su columna
                //Mientras convierto su renglon a 0 o su columna a 0. Checo si hay otro 0
                
            
        
        //5 walkthrough
            //Inicializo un vector que guarda las columnas
            //Inicializo un vector que guarda los renglones
            //Recorro y guardo las posiciones donde existen digitos 0
            //Luego borro esos digitos selectivamente
        
        //6 implement
        
        //7 test
            //Special Cases
                //Renglones con size 0
                //Comlumnas con size 0
        
        //Vectores renglones y columnas
            //vector<int> renglones = {};
            //vector<int> columnas = {};
        
        //Es más eficiente que no se repitan, usaré set pero dejo comentada opción vectores
        //Da igual si uso set o unorderes_set. La busqueda sera O(1), no n(log n). porque los index
            //Index son numeros ordenados

    //Respuesta original

        /*
        //runtime: O(n*m)
        //Memory: O(n)
        
        //Set de renglones y columnas
        set<int> renglones = {};
        set<int> columnas = {};
        
        //Saco el numero de 
        int m = matrix.size();  //Renglones
        int n = matrix[0].size();   //Columnas
        
        //Checo si ambos son de size 1
        if(n == 1 && m == 1){ return; }
        
        //Comienzo la lectura de la matriz. runtime: O(n*m)
        //Recorro renglones
        for(int i = 0; i < m; i++){
            //Recorro columnas
            for(int j = 0; j < n; j++){
                //Si encuentro un 0
                if(matrix[i][j] == 0){
                    renglones.emplace(i); //Agrego el renglon a renglones
                    columnas.emplace(j);  //Agrego la columna a columnas
                }
                //Podria poner bandera para saber si encontre 0, si encontré 0.
                //Convierto todo el renglon a 0, en este lugar matrix[i] = vector<int>(n, 0);
                //Así ya no utilizo ese set y solo busco los renglones con 0
                    //Si el set de columnas == n, regreso matriz con puro 0    
            }
        }
        
        
        //Ahora comienzo el proceso de eliminación. runtime: O(n*m)
        
        //Checo size de renglon y de columnas
        //Si renglones == m o columnas == n
        //Ahora todo lo hago 0
        if(m == renglones.size() || n == columnas.size()){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        //Si no
        else{        
            //columnas
            //Recorro todos los renglones
            for(int i = 0; i < m; i++){
                //Recorro las columnas a borrar
                for(auto it = columnas.begin(); it != columnas.end(); it++){
                    matrix[i][*it] = 0;
                }
            }
        
            //Renglones
        
            //Recorro los renglones a borrar
            for(auto it = renglones.begin(); it != renglones.end(); it++){
                vector<int> aux(n, 0);
                
                matrix[*it] = aux;
            }
        }

        */  

    //Respuesta original, optimizada. Pero sigue siendo de la misma eficiencia
        //runtime: O(n*m)
        //Memory: O(n)
        
        //Set de renglones y columnas
        //set<int> renglones = {};
        set<int> columnas = {};
        
        int renglones = 0;
        
        //Saco el numero de 
        int m = matrix.size();  //Renglones
        int n = matrix[0].size();   //Columnas
        
        //Checo si ambos son de size 1
        if(n == 1 && m == 1){ return; }
        
        //Comienzo la lectura de la matriz. runtime: O(n*m)
        //Recorro renglones
        for(int i = 0; i < m; i++){
            
            bool foundZero = false; //Checo si el renglon tiene 0
            
            //Recorro columnas
            for(int j = 0; j < n; j++){
                //Si encuentro un 0
                if(matrix[i][j] == 0){
                    foundZero = true;
                    columnas.emplace(j);  //Agrego la columna a columnas
                }
            }
            
                
            if(foundZero){  //Si tiene 0 el renglon, lo convierto en 0s todo
                matrix[i] = vector<int>(n, 0);
                renglones++;
            }
        }
        
        
        //Ahora comienzo el proceso de eliminación. runtime: O(n*m)
        
        //Checo size de renglon y de columnas
        //Si renglones == m o columnas == n
        //Ahora todo lo hago 0
        if(renglones == m){
                return;
        }
        else if(n == columnas.size()){
            /*
            vector<int> auxCol(n, 0);
            vector<vector<int>>auxRen(m, auxCol);
            matrix = auxRen;
            */
            //Es mejor dejar el memory en O(n)
            //Runtime overall ya es O(n*m). Usarlo
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        //Si no
        else{        
            //columnas
            //Recorro todos los renglones
            for(int i = 0; i < m; i++){
                //Recorro las columnas a borrar
                for(auto it = columnas.begin(); it != columnas.end(); it++){
                    matrix[i][*it] = 0;
                }
                
                /*
                for(int j = 0; j < columnas.size(); j++){
                    matrix[i][columnas[j]] = 0;   //Igualo a cero esos valores
                }
                */
            }
        }        
    }
};

/*
    -Me salio, segundos antes de que se acabaran los 45 minutos
        -Runtime: O(n*m)
        -Memory: O(n)

    -Siento que una solución mucho más eficiente sería recursiva, debería investigarlo

    -Yo pienso que para sacar los 0s, afuerzas debes recorrer toda la matríz, haciendo el runtime: O(n*m)
        pero en el followup dice:
            * A straightforward solution using O(mn) space is probably a bad idea.
            * A simple improvement uses O(m + n) space, but still not the best solution.
            * Could you devise a constant space solution?
        
        Entonces voy a investigar si existe una manera más eficiente de hacerlo.

    -Debo investigar más sobre matrices para sentirme más comodo al moverme por renglones y columnas

    -Para ser el 3er ejercicio que hago con matrices, siento que mi perfomance estuvo bien.
        Buen inicio, aún debo mejorar para sacarlo más rapido.

    -Manera de definir el for loop para que se vea más limpio el codigo
    
    x es el entero donde quiero que comience
    #define len(x) x.size()
    #define bf(i, x, n) for(int i = x; i < n; i++) //basic for (<)
*/