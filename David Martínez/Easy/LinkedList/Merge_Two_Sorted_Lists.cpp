#include <iostream>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //1)Listen
            //Me dan el head de 2 linkedlists ya ordenadas en sus valores
            //Debo unir ambas linkedlists y regresar el head
            //Ambas listas tienen nodos entre 0 y 50 nodos
            //Ambas listas estan ordenadas en non-decreasing order
            
            
        //2)Example
            // En el cuaderno 
        
        //3)Brute Force
            //Hacer un pointer que primero apunte al head con valor mas chico
            //Luego recorrer el apuntador de la lista con la que seleccione el head
            //Ahora comparar de nuevo los pointers en ambas listas y el auxiliar se conecta al menor
            //Cuando una lista llega a nullptr, se conecta el nodo de la lista restante y se termina
            
        
        //4)Optimized Solution
            //Siento que es la solución más optima
        
        //5)Walthrough
            //creo head para la nueva lista
            //Creo apuntador auxiliar que se encarga de conectar las listas
            //Recorro los heads ya conectados y los recorro, par seguir comparando
            //Si una lista se termina
                //checamos la otra
            //Si en la otra aún hay elementos, conectamos al head que queda y regresamos apuntador aux
            
        
        //6)Implement
        
        //7)Test
            //cases
                //Listas vacías
                //una lista vacía
                //podria hacer contador para checar el largo de las listas y si el largo no queda, pero eso aplicaría más en un problema de la visa real. me voy a apegar a lo que me piden
        
        //Primero checo los extreme test cases
        //Checo si las listas están vacías
        
        if(list1 == nullptr && list2 == nullptr){   //Si ambas están vacías
            return nullptr; //Regreso nullptr
        }
        else if (list1 == nullptr){ //Si la primera está vacía
            return list2;   //Regreso la segunda
        }
        else if(list2 == nullptr){  //Si la segunda está vacía
            return list1;   //Regreso la primera
        }
        
        
        //Si ambas listas tienen nodos
        
        //Creo el nuevo head para la lista que voy a regresar
        ListNode * newHead;
        
        //Checo cual lista comienza con el valor más pequeño
        if(list1->val < list2->val){
            //Si el valor del head1 es menor al de head2, ese es nuestro nuevo head
            newHead = list1;
            
            //Ahora recorro el valor del head en list1
            list1 = list1->next;
        }
        else{
            //Si list2 es menor o igual, ahora ese es nuestro nuevo head
            newHead = list2;
            
            //Ahora recorro el valor del head en list2
            list2 = list2->next;
        }
        
        //Creo el nodo auxiliar con el que conectare ambas listas
        ListNode * aux = newHead;
        
        //Ahora comienzo a comparar los apuntadores de ambas listas, hasta que una sea nullptr
        while((list1 != nullptr) && (list2 != nullptr)){
            
            //comparo apuntadores
            if(list1->val < list2->val){    //Si list1 es menor a list2
                
                aux->next = list1;  //Conecto al valor menor
                list1 = list1->next; //Recorro list1
            }
            else{   //Si list2 es menor o igual a list1
                aux->next = list2;  //Conecto a list2
                list2 = list2->next;    //Recorro list2
            }
            
            aux = aux->next;    //Recorro aux a su nuevo valor
        }
        
        //Una vez fuera del ciclo
        //Checo si alguna de las listas esta vacía, para conectar con la otra
        
        if(list1 != nullptr){   //si la primera lista aún tiene elementos
            aux->next = list1; //Lo conecto con el resto de la lista
        }
        
        if(list2 != nullptr){   //Si la segunda lista aún tiene elementos
            aux->next = list2;  //Lo conecto con el resto de la lista
        }
        
        //Al final regreso el nuevo head
        return newHead;
        
        
        
    }
};