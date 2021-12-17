
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
    ListNode* reverseList(ListNode* head) {
        //Me llega head
        //Debo regresar la linked list reverseada
        
        //Como la reverseo?
            //3 pointers
            //Uno en el nodo actual
            //Otro en el nodo de atras
            //Otro en el nodo siguiente
        
            //Nodo atras comienza en null y siempre tendra de valor el nodo al que conectaremos
            //El nodo actual siempre le cambiare el apuntador, al nodo de atras
            //El nodo siguiente esta encargado de no perder el resto de la lista
                //Entonces luego de que el nodo actual apunte hacía atras
                //atras ahora apunta a actual
                //Nodo actual ahora apunta a siguiente
                //Siguiente ahora apunta a su next
            //Se lleva a acabo este proceso hasta que nodo siguiente sea nullptr
        
        //Test cases:
            //Lista de un solo nodo
            //Lista vacía
            //Lista con más de un elemento
        
        //Checo si el head es igual a nullptr
        //Si es así, la lista esta vacía
        if(head == nullptr){
            return head;
        }
        
        //Checo si la lista tiene un solo nodo
        if(head->next == nullptr){
            return head;
        }
        
        //Nodos
        ListNode * prevN = nullptr; //Comienza desde nullptr
        ListNode * currN = nullptr;    //Comienza en nullptr
        //Estoy usando head, como si fuera un nodo next, al recorrerlo
        
        //Ahora declaro el ciclo
        while(head != nullptr){    //Mientras el siguiente nodo es diferente a nullptr
            
            currN = head;  //Defino el valor de curr, al valor actual
            head = head->next;  //Head lo revorro al siguiente valor
            
            currN->next = prevN; //Nodo actual ahora apunta hacía atras
            
            //Ahora recorro los nodos
            prevN = currN;  //El nodo anterior, ahora apunta a el nodo actual
            
            
        }
        
        //Regreso el nodo actual, que ahora es el head
        return currN;
        
        //Podría usar head, como uno de los apuntadores, aún así la memoria sería constante
        //No encontre otra solución más eficiente.
        //Unica optimización que encuentro es la de usar el head como apuntador
        //tiempo big O: O(N)
        //Memory big O: O(1)
        
    }
};