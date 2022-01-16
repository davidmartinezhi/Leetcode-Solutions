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
        //Memory: O(n+m)
        
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

/*
//Respuesta original, optimizada.
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
        
            //Es mejor dejar el memory en O(n)
            //Runtime overall ya es O(n*m). Usarlo
            for(int i = 0; i < m; i++){
                matrix[i] = vector<int>(n, 0);
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
        } 
*/
    //https://www.youtube.com/watch?v=M65xBewcqcI
    //Approach con O(1) memory y O(n*m) runtime

    //Approach muy inteligente, tirangula como si fuera un excel. Checado la columna y renglon.
    //Si alguno tiene un 0, ese valor debe ser 0
    //Como mi primer approach, pero en lugar de crear vectores con los indices con 0 guardado
    //Utilizo el primer renglon y primera columna como vectors. En esos indices coloco 0
        
    //En este approach, el row[0] y col[0]. Son dummies primero.
        int col0 = 1;   //Indica si la primer columna debe ser convertida a 0. Al final (es una flag)
        int rows = matrix.size();
        int columns = matrix[0].size();
        
    //Recorro toda la matriz para saber marcar los dummies
        for(int i = 0; i < rows; i++){
            
            //Checo el valor de la primer columnas, dummi
            if(matrix[i][0] == 0){ col0 = 0; }
            
            for(int j = 1; j < columns; j++){   //Comienza de 1, para saltar el dummie
                //Si ese valor de la matriz tiene un valor de 0
                if(matrix[i][j] == 0){
                    //Ahora en los dummies tendra ese valor
                    matrix[0][j] = 0; //Columnas
                    matrix[i][0] = 0; //Renglones
                }
            }
        }
        
    //Recorro en reversa la matrix
        for(int i = rows-1; i >= 0; i--){
            
            for(int j = columns - 1; j >= 1; j--){
                
                //Si el dummie de renglones o el de columnas tiene un valor 0
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
                
            }
            
            //Si alguno de los renglones en la primer col, tenian un 0
            //Ahora en todos les pondremos un 0
            if(col0 == 0){
                matrix[i][0] = 0;
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