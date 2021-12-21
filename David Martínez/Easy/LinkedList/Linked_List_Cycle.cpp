#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //1)Listen
            //Me dan el head de la linked list y debo determinar si esta ciclada
            //No me dan referencias sobre donde podria estar ciclada, ni si esta ciclada
            //Debo regresar true si es ciclada y false si no
            //Tamaño de lista entre 0 y 10,000 nodos
        
        //2)Example
            //En mi cuaderno
        
        //3)Brute Force
            //Puedo hacer un nodo slow y otro nodo fast
            //Si fast llega a ser nullptr o fast->next es nullptr, regreso false
            //Si fast alcanza a slow, estamos en un una linkedlist ciclada y regreso true
        
        //4)Optimize
            //Best conceivable time sería N
            //Best conceivable memory usage 1
            //Siento que mi solución si es optima
        
        //5)Walk Through
            //Creo apuntador slow y apuntador fast
            //Los recorro hasta que fast o fast->next sea nullptr
            //O si fast alcanza a slow
        
        //6)Implement
        
        //7)Test
            //Lista vacía
            //Lista ciclada con 1 solo elemento
            //Lista no ciclada
            //Lista ciclada con más de 1 elemento
        
        //Checo caso extremo de que la lista esté vacía
        if(head == nullptr){
            return false;
        }
        
        
        //Creo apuntadores
        ListNode * slow = head;
        ListNode * fast = head;
        
        //Mientras fast o fast->next no sea nullptr
        while((fast != nullptr) && (fast->next != nullptr)){
            slow = slow->next;
            fast = fast->next->next;
            
            //Comparo fast y slow
            if(fast == slow){   //Si fast alcanza a slow, regresamos true
                return true;
            }
        }
        
        //Si llegamos a salir del ciclo, significa que la lista no es ciclada
        return false;   //Regreso false
        
    }
};