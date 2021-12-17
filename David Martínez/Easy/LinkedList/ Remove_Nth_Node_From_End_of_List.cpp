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
            
            //Si n, es mayor a mi lista. No puedo regresar un dato inexistente
            if(countN < n){  
                return returnNode;  //Regreso la linkedlist original o error
            }
            
            //Si N es igual al tamaño de la lista, estoy eliminando el head
            else if(n == countN){
                returnNode = returnNode->next;  //Checar que no haya error cuando next es nullptr
                delete aux;
                
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


//Version asumiendo que N esta dentro del rango (0 a size siempre)

/*
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
        
       
        
        //nodo Front, que va a recorrer la lista hasta llegar a nullptr
        ListNode * front = head;
        
        //Nodo auxiliar que eliminara el nodo seleccionado
        ListNode * aux = head;
        
                
        //Recorro el front, n veces
        for(int i = 0; i <= n; i++){
            
            //Si front = nullptr, estamos en el fin de la linkedlist y el dato a borrar es el head
            if(front == nullptr){
                
                
                head = head->next;
                delete aux; //Elimino el head anterior
                
                return head;  //Regreso la linkedlist con el nuevo head
                
                //Si la lista es de un elemento, regresa nullptr
                
                //Si la lista es de mas elementos, regresa con nuevo head
            }
            
            if(i != n){ //No recorre en la ultima vuelta
                front = front->next;    //Recorro front 
            }
                   
        }
 
        //Si N es diferente al numero de nodos en la linkedlist
        ListNode * aux2;
        //Puedo recorrer front una vez
        //front = front->next;
        //Luego ya no usar aux2, solo aux normal pero apuntando a next next
        
        //Si tenemos que recorrer
        while(front != nullptr){    //Mientras no lleguemos al final recorro
            front = front->next;
            aux2 = aux; //Nodo auxiliar para ajustar apuntador
            aux = aux->next;
        }
        
        //Aquí ya recorrí
        //Ahora checo si debo eliminar el ultimo nodo
        if(n == 1){
            aux2->next = nullptr;   //Ajusto apuntador que apunta a aux
            delete aux; //Elimino aux
        }
        else{
            //Si es un nodo en el cuerpo de la linked list
            ListNode * next = aux->next;    //Apuntador al siguiente nodo
            
            //Le asigno a aux, el valor de el siguiente nodo
            aux->val = next->val;
            aux->next = next->next;
            
            //Elimino next
            delete next;
        }
        return head;      
    }
};
*/


//Optimización de memoria utilizada

/*
//Runtime: 3 ms, faster than 82.23% of C++ online submissions for Remove Nth Node From End of List.
//Memory Usage: 10.7 MB, less than 73.08% of C++ online submissions for Remove Nth Node From End of List.

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
        
       
        
        //nodo Front, que va a recorrer la lista hasta llegar a nullptr
        ListNode * front = head;
        
        //Nodo auxiliar que eliminara el nodo seleccionado
        ListNode * aux = head;
        
                
        //Recorro el front, n veces
        for(int i = 0; i <= n; i++){
            
            //Si front = nullptr, estamos en el fin de la linkedlist y el dato a borrar es el head
            if(front == nullptr){
                
                
                head = head->next;
                delete aux; //Elimino el head anterior
                
                return head;  //Regreso la linkedlist con el nuevo head
                
                //Si la lista es de un elemento, regresa nullptr
                
                //Si la lista es de mas elementos, regresa con nuevo head
            }
            
            if(i != n){ //No recorre en la ultima vuelta
                front = front->next;    //Recorro front 
            }
                   
        }
 
        //Si N es diferente al numero de nodos en la linkedlist
        
        //Puedo recorrer front una vez
        front = front->next;
        //Luego ya no usar aux2, solo aux normal pero apuntando a next next
        
        //Si tenemos que recorrer
        while(front != nullptr){    //Mientras no lleguemos al final recorro
            front = front->next;
            aux = aux->next;
        }
        
        //Aux ahora se queda un valor antes del ultimo
        
        //Aquí ya recorrí
        //Ahora checo si debo eliminar el ultimo nodo
        ListNode * next = aux->next;    //Nodo que voy a borrar
        if(n == 1){
            aux->next = nullptr;    //ahora aux apunta a nullptr
            delete next; //Elimino next
        }
        else{
            //Si es un nodo en el cuerpo de la linked list
            aux->next = next->next;
            //Elimino next
            delete next;
        }
        return head;      
    }
};


*/

/*

Notas sobre este ejercicio:
    -Debo asegurarme de ser explicito con la asignación de apuntadores 
    -Si voy a eliminar un nodo, debería de asegurarme en donde estoy poniendo el apuntador del valor anterior
    -Debo recordar la tecnica de tener varios apuntadores
    -Debo hacer los test cases desde el inicio, para estar bien preparado
*/
