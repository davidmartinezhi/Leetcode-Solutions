#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //1. Listen
            //Debo regresar true si la linkedlist es un palindromo
            //Palindromos se escriben igual derecha a izquierda, que izquierda a derecha
            //Valor de nodo es entre 0 y 9
            //tamaño de linked list entre 1 y 100,000
        
        //2.Ejemplo
            //En mi cuarderno
        
        //3.Brute force
            //Meter los datos a un array
            //Checar si el tamaño es non o par, para ajustar el corte
            //La segunda mitad la reverseo para comparar con la primera mitad
        
        //4.Optimize
            //Puedo usar un ponter para saber la longitud de la link list
            //Luego la mitad agregarlo a un vector
            //En la mitad, solo comparo el vector de fin a principio, con el resto de la lista
            
        
            //Puedo recorrer toda la link list y meterla a un array, ahora comparo inicio con fin
            //La solución sería N(tiempo) en recorrer linkedList, y N en recorrer las comparaciones.
            //La memoria sería N también.
                //Time: O(n+n) = O(n)
                //Memory: O(n)
        
        //5.Walkthrough
            //Leer toda la linkedlist y agregar los valores a un vector
            //Creo apuntador a inicio y apuntador a final
            //Inicio aumenta y final disminuye, mientras se comparan
            //Si no son iguales, regresamos false
            //Si no es el caso, al final regresa true
        
        //6.Implement
        
        //7.Test cases
            //To do list
        
        //Todo list
            //Checar la condición start <= end
        
        //Llenado del vector
        vector<int> values = {};
        
        //Creo apuntador que recorre la linked list
        ListNode * aux = head;
        
        //Recorro la linkedlist hasta nullptr
        while(aux != nullptr){
            
            values.push_back(aux->val);  //Agrego valor de aux
            aux = aux->next; //Recorro aux
            
        }
        
        //Ahora creo qpuntadores que checaran que el array contenga un palindromo
        int start = 0;
        int end = values.size() - 1;
        
        while(start <= end){
            //Comparamos
            if(values[start] != values[end]){   //Si el dato es diferente
                return false;   //Regresamos falso
            }
            
            //Modifico start y end
            start++;
            end--;
        }
        
        //Si salimos del grupo sin haber tenido errores, significa que si en palindromo
        return true;
    }
};