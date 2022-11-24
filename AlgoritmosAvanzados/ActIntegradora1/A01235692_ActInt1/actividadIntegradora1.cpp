/*
Descripción breve del programa: Su funcionalidad se divide en tres procesos:
1. Analiza si el contenido de los archivos mcode#.text está en los archivos de transimission#.txt y despliega 
true o false dependiendo de si es que las secuencias de chars están contenidas o no.
2. Suponiendo que el código malicioso tiene siempre código "espejeado", se busca este tipo de código en los
archivos de transmisión. El programa regresa dos enteros separados por un espacio, los cuales correponden a
la posición inicial y final del código espejeado más largo para cada archivo de transmisión. 
3. Analiza que tan similares son los archivos de transmisión. Muestra la posición inicial y final del substring
común más largo entre ambos archivos de transmisión.
Autores: Arturo Garza Campuzano, Matricula: A00828096; David Gerardo Martínez Hidrogo, Matrícula: A01235692
Fecha de creación: 08/09/2022, Ultima fecha de modificación: 28/09/2022
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/*
Descripción de la función leerArchivo: tiene como finalidad leer archivos y guardar el contenido de estos. 
Recibe como parámetros la cadena de texto "nombreArchivo"; la cual representa el nombre del archivo de text junto con su 
extensión; y otra cadena de texto "contenidoArchivo"; la cual se utiliza para guardar el contenido del archivo mientras 
se lee. Este último parámetro tiene como característica que es por referencia; lo cual indica que tiene un comportamiento
similar a una variable global.
Parámetros:
1. string nombreArchivo: para abrir y leer un archivo determinado. 
2. string &contenidoArchivo: guarda el contenido del archivo leeido. 
Complejidad ---> O(n): está definida por el número de líneas de contenido presentes en el archivo.
*/
void leerArchivos(string nombreArchivo, string &contenidoArchivo){
	string linea;
	fstream archivoEntrada;
	archivoEntrada.open(nombreArchivo);
	
	while(getline(archivoEntrada, linea)){
		contenidoArchivo += linea;
	}
}

/*
Descripción de la función setLPSTable: sirve como función auxiliar para computar la función de transición de manera eficiente.
Siguiendo el proceso para implementar el algoritmo Knuth-Morris-Pratt, formamos un vector prefijo-sufijo.
Utilizando la terminología del libro de Thomas H. Cormen, para cualquier estado "q" y cualquier caracter "a", el valor list[q]
contiene la información que necesitamos para calcular la función de transisión sin depender de "a". 
Parámetros:
1. const string s: su finalidad consiste en ser comparada en una cadena de texto; para averiguar si se encuentra en esta.
2. vector<int> &list: proporciona una tabla prefijo-sufijo, la cual sirve para encontrar la subcadena en la cadena de texto.
Complejidad ---> O(m): delimitada por el tamaño m del vector. 
*/
void setLPSTable(const string s, vector<int> &list){
  	int i = 1;
  	int prev = 0;
        
  	while(i < s.size()){      
    	if(s[prev] == s[i]){  
      		list[i] = prev+1; 
      		prev++;
      		i++;
    	}
    	else{   
      		if(prev == 0){  
        		list[i] = 0;    
        		i++;    
     	 	}
      		else{  
        		prev = list[prev-1];
      		}
    	}
  	}
}

/*
Descripción de la función maliciousCodePresent: utiliada para comparar los elementos en T (transmission#.txt) y P (mcode#.txt), 
para verificar si coinciden o no, con la ayuda del vector prefijo-sufijo. Recibe como parámetros la cadena de texto "str" (T) y 
el patrón "sbstr" (P).
Parámetros:
1. string str: cadena de texto en la cual se averigua si la subcadena esta en ella. 
2. string substr: subcadena de texto de la cual se forma el vector prefijo-sufijo.
Complejidad ---> O(n): definida por el tamaño n de la cadena de texto (T). 
*/
void maliciousCodePresent(string str, string substr){
	bool found = false;

	if(substr.size() == 0){
		cout << found << endl;
		return;
	} 

	vector<int> LPS(substr.size(), 0);
	setLPSTable(substr, LPS);

	int i = 0, j = 0;

	while(i < str.size()){
		if(str[i] == substr[j]){  
			i++;
			j++;
		}
		else if(j == 0){
			i++;
		}
		else{
			j = LPS[j-1];
		}

		if(j == substr.size()){
			found = true;
			cout << found << " " << i - j;
			cout << endl;
		return;
		}
	}

	cout << found << endl;
	return;
}

/*
Descripción de la función findLongestPalindromicString: encuentra el palindromo más largo en una cadena expandiendose alrededor
del centro de esta y utilizando calculos previos para omitir algunos calculos. Recibe como parámetro una cadena de texto,
en la cual se busca el palíndromo más largo dentro de esta. 
Parámetros:
1. string str: cadena de texto de la cual se va a encontrar el palíndromo más largo. 
Complejidad ---> O(n): delimitada por el tamaño n de la cadena de entrada. 
*/
void findLongestPalindromicString(string str){
    int size = str.size();
    if(size == 0) return;
    size = 2 * size + 1; 
    int longestPalindromicString[size];
    longestPalindromicString[0] = 0;
    longestPalindromicString[1] = 1;
    int centerPosition = 1, rightPosition = 2, currentRightPosition = 0, currentLeftPosition, maxLPSLength = 0, maxLPSCenterPosition = 0, start = -1, end = -1, diff = -1;
     
    for (currentRightPosition = 2; currentRightPosition < size; currentRightPosition++){
        currentLeftPosition = 2*centerPosition-currentRightPosition;
        longestPalindromicString[currentRightPosition] = 0;
        diff = rightPosition - currentRightPosition;
        if(diff > 0) 
            longestPalindromicString[currentRightPosition] = min(longestPalindromicString[currentLeftPosition], diff);

        while ( ((currentRightPosition + longestPalindromicString[currentRightPosition]) < size && (currentRightPosition - longestPalindromicString[currentRightPosition]) > 0) && ( ((currentRightPosition + longestPalindromicString[currentRightPosition] + 1) % 2 == 0) || (str[(currentRightPosition + longestPalindromicString[currentRightPosition] + 1)/2] == str[(currentRightPosition - longestPalindromicString[currentRightPosition] - 1)/2] ))){
            longestPalindromicString[currentRightPosition]++;
        }
        if(longestPalindromicString[currentRightPosition] > maxLPSLength){
            maxLPSLength = longestPalindromicString[currentRightPosition];
            maxLPSCenterPosition = currentRightPosition;
        }
 
        if (currentRightPosition + longestPalindromicString[currentRightPosition] > rightPosition){
            centerPosition = currentRightPosition;
            rightPosition = currentRightPosition + longestPalindromicString[currentRightPosition];
        }
    }
    start = (maxLPSCenterPosition - maxLPSLength)/2;
    end = start + maxLPSLength - 1;
    for(currentRightPosition=start; currentRightPosition<=end; currentRightPosition++){
        if(currentRightPosition == start){
            cout << currentRightPosition << " ";
        }
        else if(currentRightPosition == end){
            cout << currentRightPosition;
        }
    }
    cout << endl;
}

/*
Descripción de la función longestCommonSubstring: encuentra la cadena de texto común más larga entre dos cadenas de texto. Para
esto se utiliza programación dinámica, creando una matriz para almacenar las longitudes de las subcadenas de ambas cadenas; para
así ahorrarnos calculos ya realizados.
Parámeteros:
1. string str1: cadena de texto #1 (X), la cual se va a comparar con una segunda cadena de texto (Y).
2. string str2: cadena de texto #2 (Y), la cual se va a comparar con la primera cadena de texto (X).
Complejidad ---> O(m*n): definida por el tamaño m de la cadena de texto #1 (X) y el tamaño n de la cadena de texto #2 (Y).
*/
void longestCommonSubstring(string str1, string str2){
    int size1 = str1.size();
    int size2 = str2.size();

    int dp[size1+1][size2+1];

    int substrIdx = 0;
    int maxSubstr = 0;

    for(int i = 0; i < size1 + 1; i++){
      	for(int j = 0; j < size2 + 1; j++){
        	if(i == 0 || j == 0){
          		dp[i][j] = 0;
        	}
        	else if(str1[i] == str2[j]){
        		dp[i][j] = 1 + dp[i-1][j-1];
        		if(dp[i][j] > maxSubstr){
        			maxSubstr = dp[i][j]; 
            		substrIdx = i; 
          		}
        	}
        	else{
          		dp[i][j] = 0;
       	 	}
        
      	}
    }

  	cout << substrIdx - maxSubstr + 1 << " " << substrIdx + 1 << endl;
  
}

/*
Descripción de la función main: tiene como finalidad sintetizar las tres partes que se piden como funcionalidad. En primer lugar, 
se leen todos los archivos y se guarda su contenido. En segundo lugar, se verifica si hay alguna coincidencia entre los archivos 
con código malicioso y los archivos de transmisión. En tercer lugar, se encuentra el palíndromo más largo en los dos archivos de 
transmisión. Y en último lugar, se averigua que tanta coincidencia hay entre los archivos de transmisión. 
Parámteros: Ninguno.
Complejidad ---> O(n): definida por la complejidad de todos los algoritmos utilizados en este programa. 
*/
int main(){
	string nombreTransmission1 = "transmission1.txt", nombreTransmission2 = "transmission2.txt"; 
	string contenidoTransmission1, contenidoTransmission2;
	string nombreMcode1 = "mcode1.txt", nombreMcode2 = "mcode2.txt", nombreMcode3 = "mcode3.txt";
	string contenidoMcode1, contenidoMcode2, contenidoMcode3;

	leerArchivos(nombreMcode1, contenidoMcode1);
	leerArchivos(nombreMcode2, contenidoMcode2);
	leerArchivos(nombreMcode3, contenidoMcode3);
	leerArchivos(nombreTransmission1, contenidoTransmission1);
	leerArchivos(nombreTransmission2, contenidoTransmission2);

	maliciousCodePresent(contenidoTransmission1, contenidoMcode1);
	maliciousCodePresent(contenidoTransmission1, contenidoMcode2);
	maliciousCodePresent(contenidoTransmission1, contenidoMcode3);
	maliciousCodePresent(contenidoTransmission2, contenidoMcode1);
	maliciousCodePresent(contenidoTransmission2, contenidoMcode2);
	maliciousCodePresent(contenidoTransmission2, contenidoMcode3);

	findLongestPalindromicString(contenidoTransmission1);
	findLongestPalindromicString(contenidoTransmission2);

	longestCommonSubstring(contenidoTransmission1, contenidoTransmission2);
	return 0;
}