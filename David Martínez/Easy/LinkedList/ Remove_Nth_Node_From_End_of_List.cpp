#include <iostream>
using namespace std;

//Version, sin saber que N esta en el rango de (0-size)

 // Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Asumiendo que n, es un valor dentro de la linkedlist siempre
        
        //Test cases
            //Elimino un unico nodo y la lista solo tiene un nodo
            //Elimino la cabeza de la linked list
            //Elimino el ultimo elemento de la linked list
            //Elimino un elemento enmedio de la linkedList
            
        
        //Como saber si la lista tiene solo 1 nodo
            //Puede ser con un counter para saber el size de la lista y luego comparar con n
        
        //Como se si estoy en el head?
            //Comparo con el aux, para saber si mover la referencia a head
        
        //En Case de que el nodo este en el cuerpo  
            //Checo si n es igual a 1
                //Si es igual a 1, elimino aux, que es el ultimo nodo
            //Si no es 1, asigno los valores de next a aux, y elimino next
        
        //Counter que sigue a front, para saber la cantidad de nodos en la linkedlist
        int countN = 0;
        
        //Apuntador a head, que voy a regresar
        ListNode * returnNode = head;
        
        //nodo Front, que va a recorrer la lista hasta llegar a nullptr
        ListNode * front = returnNode;
        
        //Nodo auxiliar que eliminara el nodo seleccionado
        ListNode * aux = returnNode;
        
        //Recorro el front, n veces
        for(int i = 0; i < n; i++){
            
            //Si front es nullptr, me salgo del for loop
            if(front == nullptr){
                break;
            }
            
            front = front->next;    //Recorro front
            countN++;    //Sumo la cuenta
            
        }
        
        //Si front es nullptr
            //En este punto:
                //Aux sigue apuntando al nodo en head
                //Sabemos la longitud de la lista
                //Tengo el valor de n
        
        //Si front ya es nullptr
        if(front == nullptr){
            
            /*====Si la lista tiene un solo elemento====
            if(count == 1){
                //Si el dato que voy a eliminar es el unico existente
                if(n == 1){
                    //Asigno el head a nullptr y aux también para asegurar de que no haya error
                    aux = nullptr;
                    returnNode = nullptr;
                    
                    //Regreso nullptr
                    return returnNode;
                }
            }*/
            
            /*====Si la lista tiene más de un elemento====*/
            
            //Si n, es mayor a mi lista. No puedo regresar un dato inexistente
            if(countN < n){  
                return returnNode;  //Regreso la linkedlist original o error
            }
            
            //Si N es igual al tamaño de la lista, estoy eliminando el head
            else if(n == countN){
                returnNode = returnNode->next;  //Checar que no haya error cuando next es nullptr
                aux = returnNode;
                
                return returnNode;  //Regreso la linkedlist con el nuevo head
            }
            
        }
        
        ListNode * aux2;
        //Si tenemos que recorrer
        while(front != nullptr){    //Mientras no lleguemos al final recorro
            front = front->next;
            aux2 = aux;
            aux = aux->next;
            countN++;    //Cuento la cantidad de nodos aún
        }
        
        //Aquí ya recorrí
        //Ahora checo si debo eliminar el ultimo nodo
        if(n == 1){
            aux2->next = nullptr;
            delete aux;
        }
        else{
            //Si es un nodo en el cuerpo de la linked list
            ListNode * next = aux->next;
            
            //Le asigno a aux, el valor de el siguiente nodo
            aux->val = next->val;
            aux->next = next->next;
            
            //Elimino next
            delete next;
        }
        return returnNode;      
    }
};


//Second version

