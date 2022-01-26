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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
        // 1. listen
            input: head of two singly linked lists
            output: node value where both linked lists intersect, 
                    if there isn`t a intersection return null
        
            There are no cycled linked lists
            
            Linked Lists must retain their original structure
            
            Both linked lists can have differente sizes (between 1 and 30,000)
            
            Nodo se encuentra entre el inicio y final, de cada lista
            
        
        // 2. example
        
            input:
            [2,3,4,5,6,8,2]
            [4,5,7,8,9,1]
            
            output: 4
            
        // 3. brute force
            
            //Using hashtables
            Hashtable for one linked list
                
                value = Pointer to thar node
            
                Traverse one list and add each value to the hashtable
                Traverse the next list
                    if the value exists in the hashtable, return the value
            
                return nullptr;
            
                //runtime: O(n+m)
                //memory: O(n)
            
            //Traverse one list for each element
            
            For each node in one list, traverse the other list
                //runtime: O(n*m)
                //memory: O(1)
            
            
        // 4. optimize
            //BCR
                Best conceivable runtime: O(n+m)
            
            //Possibly a slow pointer and a fast pointer
                Debo pensar en las propiedades de linked lists, no me salío por no pensar eso
                
        // 5. walkthrough
        // 6. implement
        // 7. test 
            Valor al inicio de una lista
            Valor no se encuentra en las listas 
        */
        
        /*
        //Hashtable
            //runtime: O(n+m)
            //memory: O(n)
            
        unordered_map<ListNode*, int> hashTable;
        
        ListNode * curr = headA;
        
        while( curr != nullptr){

            if(hashTable.find(curr) == hashTable.end()){
                hashTable[curr] = curr->val;
            }
            
            curr = curr->next;
        }
        
        curr = headB;
        
        while(curr != nullptr){
            
            if(hashTable.find(curr) != hashTable.end()){
                
                return curr;

            }
            curr = curr->next;

        }
        
        return nullptr;
        */
        
        
        //Math logic
            //Runtime: O(n+m)
            //Memory: O(1)
            
        //Size of each linked list
        int sizeA = 1;
        int sizeB = 1;
        
        ListNode * curr = headA;
        
        while(curr != nullptr){
            sizeA++;
            curr = curr->next;
        }
        
        curr = headB;
        
        while(curr != nullptr){
            sizeB++;
            curr = curr->next;
        }
        
        //Diference in sizes     
        int diff;
        ListNode * aux;
        
        if(sizeA > sizeB){
            diff = sizeA - sizeB;
            curr = headA;
            aux = headB;
        }else{
            diff = sizeB - sizeA;
            curr = headB;
            aux = headA;
        }
        
        for(int i = 0; i < diff; i++){
            
            curr = curr->next;
        }
        
        while(curr != nullptr){
            if(curr == aux){
                return curr;
            }
            curr = curr->next;
            aux = aux->next;
        }
        
        return nullptr;
        
    }
};

/*
Puedo y debería de hacer una helper function para sacar el size. Así solo paso el head y me lo regresa
Sin hacer mucho show en el codigo.

Me tarde mucho en la solución no optima, porque no me puse a pensar en los valores de las key en hashtable
Estaba poniendo el value, en lugar del apuntador. Si lo pude haber sacado a los 30 minutos esa solución.

La solución más optima se me ocurrio solo cuando hice el ejemplo en el cuaderno, debo ver como hacer eso en la entrevista.
Podría usar un whiteboard o algo por el estilo. La respuesta más optimas, por lo general las saco siempre con un DIY cuando batallo

Debo pensar en como voy a usar las data structures, que data va a entrar y como, en hashtables debo pensar en el valor unico(key)
que sea relevante.

*/