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
    ListNode* oddEvenList(ListNode* head) {
        // 1 listen
        /*
            Input: The head of a singly linked list
                Group all nodes with odd indexes, followed by nodes with even indexes
                Relative order of odd indexes and even indexes must remain the same
            Output: Reordered List
            
            Nodes in linked list between 0 and 10,000
            Valor dentro del nodo, entre -1,000,000 y 1,000,000
        */
        
        // 2 example
        /*
        
            input: 2 -> 4 -> 6 -> 8 -> 10 -> 78 -> 3 -> 4 -> x
            output: 2 -> 6 -> 10 -> 3 -> 4 -> 8 -> 78 -> 4 -> x
            
            non: 2 -> 6 -> 10 -> 3
            par: 4 -> 8 -> 78 -> 4
            
            2 6 10 3 4 8 78 4
        
        
        */
        
        // 3 brute force
        /*
        
            Hacer dos apuntadores
                uno conecta los nodos nones
                uno conecta los nodos pares
            
            Al final conecto los nodos nones a los pares con su next.
            
            runtime: O(n)
            memory: O(1)
            
        
        */
        
        // 4 optimize
        /*
        
            Necesito apuntadores auxiliares
            
            Non comienza en 0
            
            Par comienza en 1
            
            Cada uno tiene su nodo auxiliar 2 posiciónes enfrente
            
        
        */
        
        // 5 walkthrough
        /*
        
        non begins in head (auxNon advances 2 places)
        even begins in head->next (auxNon advances 2 places)
        
        Mientra ninguno de los auxiliares sea nullptr
        Conecto non con su auxiliar y recorro el auxiliar 2 lugares
        Conecto par con su auxiliar y recorro el auxiliar 2 lugares
        
        Conecto par al final de non
        
        
        */
        
        // 6 implement
        /*
        
        */
        
        // 7 test
        /*
            Especial case:
                Head vacío
                Head->next vacío
                
            
        */
        

        
      /*
      No funciona este codigo, pero fue la base de la solución
        
        //Non
        ListNode * nonHead = head;
        ListNode * nonAux = nonHead;;
            
        //Even
        ListNode * even = head->next;
        ListNode * evenHead = head->next;
        ListNode * evenAux = evenHead;;
        
        while(nonHead != nullptr && evenHead != nullptr){
            
            //Recorro ambos apuntadores auxiliares
            
            if(nonAux->next != nullptr && nonAux->next->next != nullptr){
                nonAux = nonAux->next->next;
            }else{
                nonAux = nullptr;
            }
            
            if(evenAux->next != nullptr && evenAux->next->next != nullptr){
                evenAux = evenAux->next->next;
            } else{
                evenAux = nullptr;
            }
            
            //Apunto Nodos a su respectivo auxiliar
            if(nonAux != nullptr && nonAux->next != nullptr){
                nonHead->next = nonAux;
            }
            
            if(evenAux != nullptr && evenAux->next != nullptr){
                evenHead->next = evenAux;
            }     
        }
        
        nonAux->next = even;
    */
        
        
        //Checo si la lista tiene 2 elementos o menos
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
     
        //Apuntador a nones
        ListNode * non = head;
        
        //Apuntador a pares
        ListNode * even = head->next;   
        ListNode * evenHead = head->next; //Apunta al inicio de pares, para conectarlo despues
        
        ListNode * curr = head->next->next; //Apuntador que recorre la linkedlist de manera lineal
        
        
        //Si curr es nullptr, solo tiene 2 elementos la lista
        if(curr == nullptr){
            return head;
        }
        
        int count = 1;  //Para saber si el index es non o par
        
        //Comienzo a recorrer y avanzar curr
        while(curr != nullptr){
            
            //Checo si es index positivo
            if(count % 2 == 0){
                even->next = curr;  //Apunto even a curr
                even = even->next;  //Recorro even
            } 
            else {
                non->next = curr;   //Apunto non a curr
                non = non->next;    //Recorro non
            }
            
            curr = curr->next;  //Avanzo curr
            count++;    //Actualizo el index
        }
        
        even->next = nullptr;   //Aseguro que even termina en nullptr
        non->next = evenHead;   //Conecto los pares al final de los nones
        
        return head;    //Regreso el head original
        
    }
};

/*
Nota:
    -Me tarde una hora en hacerlo, sentí que estaba muy sencillo y la pense de más
    -Me acelere y no pude pensar claro, sabía que el rumbo de mi solución era correcto pero no me frene a pensar bien en como hacer la asignoación de aux. Asumí que iba a jalar y no fue así

    -Al hacer el walkthrough con el que no servía, se me ocurrío hacer el de tener un nodo auxiliar solamente y que ese nodo determinara cual nodo iba en que lista
    -La solución con un nodo la saque bastante rapida y todavía se puede eficientar al usar menos variables.
    
    Saqué el brute force y como se me hizo bueno, lo mande a optimize y lo establecí como el algoritmo optimizado en lugar de establecerlo como brute force y luego repasarlo

    No brincar un algoritmo de una etapa a otra, etapa 4 es optimize en base al algoritmo de la etapa 3. De Brute Force a Optimize

*/