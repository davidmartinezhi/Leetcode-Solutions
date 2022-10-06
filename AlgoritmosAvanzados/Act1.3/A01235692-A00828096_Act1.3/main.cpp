/*
Utilizando la técnica de programación de "backtracking" y la de "ramificación y poda", escribe en equipos de máximo dos peronas, en C++ un programa que resuelva un laberinto.

El programa recibe dos numeros enteros M y N, seguido de M líneas de N valores booleanos(0|1) separados por un espacio, por la entrada estándar que representan el laberinto.  Un 1 representa una casilla en la que es posible moverse, un 0 es una casilla por la que NO se puede pasar.
El origen o casilla de inicio es siempre la casilla (0,0) y la salida o meta es siempre la casilla (M-1, N-1)
La salida del programa es una matriz de valores booleanos (0|1) que representan el camino para salir del laberinto. Primero debe mostrarse la solución utilizando la técnica de backtracking, y luego utilizando la técnica de ramificación y poda.
Tu programa debe compilar sin errores ni warnings y debe ejecutarse correctamente en en ambiente linux. Piensa en posibles casos de prueba extremos que pueden ser utilizados para probar tu programa.
Tu solución propuesta debe ser correcta y eficiente.

Autores: 
    David Gerardo Martínez Hidrogo - A01235692
    Arturo Garza Campuzano - A00828096 

Creado: Septiembre 1 del 2022. Ultima Actualización: Septiembre 3 del 2022
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


void printSolucion(vector<vector<bool> > laberintoSolucion) {
  for (int i = 0; i < laberintoSolucion.size(); i++) {
    for (int j = 0; j < laberintoSolucion[i].size(); j++) {
      cout << laberintoSolucion[i][j] << " ";
    }
    cout << endl;
  }
}
void printSolucion(vector<vector<int> > laberintoSolucion) {
  for (int i = 0; i < laberintoSolucion.size(); i++) {
    for (int j = 0; j < laberintoSolucion[i].size(); j++) {
      cout << laberintoSolucion[i][j] << " ";
    }
    cout << endl;
  }
}

//===============================
// Solución Recursiva
// convertimos el laberinto a numeros enteros
vector<vector<int> > laberintoToNums(vector<vector<bool> > &laberinto) {
  /*
  Creamos un laberinto equivalente, con numeros enteros
  complexity:
    time: O(row*col)
    memory: O(row*col) por el nuevo laberinto
  */

  // declaramos rows y columns
  int rows = laberinto.size();
  int cols = laberinto[0].size();

  // creamos laberinto para numeros enteros
  vector<vector<int> > laberintoNums(rows, vector<int>(cols));

  // recorremos laberinto original
  for (int i = 0; i < laberinto.size(); i++) {
    for (int j = 0; j < laberinto[0].size(); j++) {

      // si es true, ponemos un 1, de lo contrario un 0
      if (laberinto[i][j])
        laberintoNums[i][j] = 1;
      else
        laberinto[i][j] = 0;
    }
  }

  // regresamos el laberinto con enteros
  return laberintoNums;
}

// convertimos el laberinto a booleano
vector<vector<bool> > laberintoToBool(vector<vector<int> > &laberinto) {
  /*
  Creamos un laberinto equivalente, con valores booleanos
  complexity:
    time: O(row*col)
    memory: O(row*col) por el nuevo laberinto
  */

  // declaramos rows y columns
  int rows = laberinto.size();
  int cols = laberinto[0].size();

  // creamos laberinto para valores booleanos
  vector<vector<bool> > laberintoBools(rows, vector<bool>(cols));

  // recorremos laberinto original
  for (int i = 0; i < laberinto.size(); i++) {
    for (int j = 0; j < laberinto[0].size(); j++) {

      // si tiene un 2, es parte del path
      if (laberinto[i][j] == 2)
        laberintoBools[i][j] = true;
      else
        laberintoBools[i][j] = false;
    }
  }

  // regresamos el laberinto con valores booleanos
  return laberintoBools;
}

// encontramos el path con backtracking
void encontrarCamino(vector<vector<int> > &laberinto,
                     vector<vector<bool> > &resultado, int &rows, int &cols,
                     int row, int col) {

  /*
  Encontramos el camino unico
  complexity:
    time: O(row*col) En el peo de los casos, recorremos cada celda una vez
    memory: O(1)
  */
  // casos base

  // Sale de limites del laberinto
  if (row >= rows || row < 0 || col >= cols || col < 0)
    return;

  // el valor actual es diferente de 1 significa que ya fue visitado o que no
  // hay camino por ahí
  if (laberinto[row][col] != 1)
    return;

  // marcamos como visitado
  laberinto[row][col] = 2;

  // cout << "row: " << row << " col: " << col << endl;

  // checamos si estamos en el final
  if (row == rows - 1 && col == cols - 1) {
    // creamos el resultado
    resultado = laberintoToBool(laberinto);
    return;
  }

  // checamos las celdas adyacentes
  encontrarCamino(laberinto, resultado, rows, cols, row - 1, col); // arriba
  encontrarCamino(laberinto, resultado, rows, cols, row + 1, col); // abajo
  encontrarCamino(laberinto, resultado, rows, cols, row, col - 1); // izquierda
  encontrarCamino(laberinto, resultado, rows, cols, row, col + 1); // derecha

  // regresamos
  laberinto[row][col] = 0;
}

//===============================
// Solución ramificación y poda
// Elegimos hacia donde nos movemos en base a que nodo nos acerca más a la respuesta


// encontramos el path
void encontrarCaminoBranchAndBound(vector<vector<int> > &laberinto,
                                   vector<vector<bool> > &resultado, bool &found, int &rows,
                                   int &cols, int row, int col) {

  /*
  Encontramos el camino unico
  complexity:
    time: O(row*col) En el peo de los casos, recorremos cada celda una vez
    memory: O(1)
  */
  // casos base

  // Sale de limites del laberinto
  if (row >= rows || row < 0 || col >= cols || col < 0)
    return;

  // el valor actual es diferente de 1 significa que ya fue visitado o que no
  // hay camino por ahí
  if (laberinto[row][col] != 1)
    return;

  // marcamos como visitado
  laberinto[row][col] = 2;

  // cout << "row: " << row << " col: " << col << endl;

  // checamos si estamos en el final
  if (row == rows - 1 && col == cols - 1) {
    // creamos el resultado
    found = true;
    resultado = laberintoToBool(laberinto);
    return;
  }

  // O(1) extra espacio, siempre serán de tamaño 4 los vectores
  vector<pair<double, string> > minDistanceToDestiny(4);

  // arriba
  minDistanceToDestiny[0].first =
      ((cols - 1 - col) + (rows - 1 - row + 1)) / 2; 
  minDistanceToDestiny[0].second = "arriba";

  // abajo
  minDistanceToDestiny[1].first =
      ((cols - 1 - col) + (rows - 1 - row - 1)) / 2; 
  minDistanceToDestiny[1].second = "abajo";

  // izquierda
  minDistanceToDestiny[2].first =
      ((cols - 1 - col + 1) + (rows - 1 - row)) / 2; 
  minDistanceToDestiny[2].second = "izquierda";

  // derecha
  minDistanceToDestiny[3].first =
      ((cols - 1 - col - 1) + (rows - 1 - row)) / 2; 
  minDistanceToDestiny[3].second = "derecha";

  
  // O(1), siempre se tardará lo mismo debido a que es de tamaño 4
  // siempre ordena de menor a mayor, entonces siempre checaremos la opción que
  //más nos acerca al destino final.
  sort(minDistanceToDestiny.begin(), minDistanceToDestiny.end());

  //checa el lado, dependiendo de que posibilidad tiene de acercarlo a la meta
  for(int i = 0; i < 4; i++){

    if(minDistanceToDestiny[i].second == "arriba"){ //arriba
      encontrarCaminoBranchAndBound(laberinto, resultado, found, rows, cols, row - 1, col); 
    }
    else if(minDistanceToDestiny[i].second == "abajo"){ //abajo
      encontrarCaminoBranchAndBound(laberinto, resultado, found, rows, cols, row + 1, col);   
    }    
    else if(minDistanceToDestiny[i].second == "izquierda"){ //izquierda
      encontrarCaminoBranchAndBound(laberinto, resultado, found, rows, cols, row, col - 1); 
    }
    else if(minDistanceToDestiny[i].second == "derecha"){  //derecha
      encontrarCaminoBranchAndBound(laberinto, resultado, found, rows, cols, row, col + 1);
    }

    //checamos si ya fue encontrado el camino
    if(found) return;
  }
  
  // regresamos
  laberinto[row][col] = 0;
}

int main() {

  // Declaración de variables
  int numeroFilas = 0, numeroColumnas = 0, fin = 0, contador = 0;
  bool coordenada = false;
  vector<bool> filaLaberinto;
  vector<vector<bool> > laberinto;

  // Lectura de archivo
  ifstream archivoEntrada;
  archivoEntrada.open("archivoEntrada.txt");

  while (archivoEntrada) {
    if (contador == 0) {
      archivoEntrada >> numeroFilas >> numeroColumnas;
    } else if (filaLaberinto.size() != numeroColumnas && contador > 0) {
      archivoEntrada >> coordenada;
      filaLaberinto.push_back(coordenada);
    } else if (filaLaberinto.size() == numeroColumnas && contador > 0) {
      laberinto.push_back(filaLaberinto);
      filaLaberinto.clear();
    } else {
      archivoEntrada >> fin;
    }
    contador++;
  }

  archivoEntrada.close();

  // Hacer laberinto con numeros enteros
  vector<vector<int> > laberintoNums = laberintoToNums(laberinto);
  bool found = false;
  // sacamos el camino unico
  encontrarCaminoBranchAndBound(laberintoNums, laberinto, found, numeroFilas, numeroColumnas, 0, 0);

  // imprime solución
  printSolucion(laberinto);

  return 0;
}