//Lo hice practicando los 2 tipos de sliding window technique
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //Debo iterar el vector prices
        
        //En cada indice debo decidir si comprar o vender mi stock
            //Voy a tener stock guardado y stock actual del día
        
        //Debo comprar por primera vez, cuando el stock actual sea menor al siguiente
        
        //Sliding window of size 2
        
            //Debo comparar
                //Si izquierda es mayor, no compramos
                //Si derecha es mayor, sumamos (derecha - izquierda)
        
        
        /*
        //Fixed Window Sliding Techinique
        //Variable donde guardo las profits
        int maxProfit = 0;
        
        //Creo recorrido del 1 al final de la lista
        for(int i = 1; i < prices.size(); i++){ //Recorro prices hasta el ultimo elemento
            
            //Checo si el valor de la derecha es mayor
            if(prices[i-1] < prices[i]){
                maxProfit += (prices[i] - prices[i-1]); //Sumamos (derecha - izquierda)
            }
            //Si no es mayor, no hacemos nada
        }
        
        //Regresamos el maximo profit
        return maxProfit;
        */
        
        //Dynamic variant Window Sliding Technique
        
        //Variable donde guardo las profits
        int maxProfit = 0;
        
        //Recorro la lista secuencialmente
        for(int i = 0; i < prices.size() - 1; i++){ //Aquí recorro desde la primera celda a la penultima
            
            int j = i+1;  //Agarro el index del siguiente elemento
            
            if(prices[i] < prices[j]){  //si j es mayor a i
                
                while(j < prices.size()-1){  //mientras j no sea la ultima casilla
                    
                    int k = j+1;    //Sacamos K
                    
                    if(prices[j] < prices[k]){    //Si k es mayor a j
                        j++;    //aumento j
                    }else{  //Sino
                        break;  //Salimos del while loop
                    }
                }
                
                maxProfit += (prices[j] - prices[i]); //sacamos el profit
                i = j;  //Actualizamo i
            }
        }
        return maxProfit;
    }
};