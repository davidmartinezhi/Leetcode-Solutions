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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 1 listen
            /*
            input: 2 non-empty linked-lists, representing 2 non-negative integers
            
            The digits are stored in reverse order
            Each of the nodes contains one single digit
            
            Add the two numbers and return the sum as a reversed linked list
            The numbers don't contain any leading zeros
            LinkedLists contienen entre 1 y 100 nodos
            Cada nodo tiene un valor entre 0 y 9
            
            output: reversed linked list with the answer
            
            */    
        
        // 2 example
        
        /*
        
        l1 = 2 -> 3 -> 1 -> x
        l2 = 4 -> 5 -> 0 -> 9- > 1 -> x
        
        19054 + 132 = 19186 
        
        output -> 6 -> 8 -> 1 -> 9 -> 1
        
        
        

        
        19286
        
        output -> 6 -> 8 -> 2 -> 9 -> 1
        
        192+19994 = 20186
       
        l1 = 2 -> 9 -> 1 -> x
        l2 = 4 -> 9 -> 9 -> 9- > 1 -> x
        
        output: 6 -> 8 -> 1 -> 0 -> 2
        
        l1 = 2 -> 9 -> 1 -> x
        l2 = 4 -> 9 -> 9 -> 9- > 1 -> x       
        */
        
        // 3 brute force
        /*
        Reverse both linked lists O(2*n) runtime
        fill two integer variables O(1) memory
        make a sum of those two variable O(1) memory
        

        sum % 10, add the number to the resulting linked list, until the sum is equal to 0
        
        runtime:O(n)
        memory: O(m) m being resulting linked list. no extra space overall
        */
        
        // 4 optimize
        /*
        
        If linked list has 100 nodes, I won't be able to do the sum of two variable
        
        Traverse both linked lists
        get the result of summing both nodes
        if it's bigger than 9, we add 1 to the next node
        add each node to the result
        
        
        */
        
        // 5 walkthrough
            /*
            reverse both linked lists
            sum each node
                bigger than 9 , % 10 is the node, add 1 to the next node
            add that node to the final result linked list
            reverse the resulting linked list and return
            */    
        
        // 6 implement
        /*
        Comienzo a implementar con 25 minutos restantes
        */
        
        // 7 test
            //Numbers that 
        
        
        //Pointer to the head of each linked list
        ListNode * head1 = l1;
        ListNode * head2 = l2;
        
        ListNode* headResult = nullptr;
        ListNode* tailResult;
        
        int add = 0;
        
        //Traverse both linked lists
        while(head1 != nullptr && head2 != nullptr){
            
            int sum = head1->val + head2->val;
            sum += add;
            add = 0;
            
            //Checo si la suma es mayor a 9
            if(sum > 9){
                add += (sum / 10);
                sum %= 10;
            } 


            //Agrego sum a la respuesta
            if(headResult == nullptr){
                headResult = new ListNode(sum);
                tailResult = headResult;
            }else{
                tailResult->next = new ListNode(sum);
                tailResult = tailResult->next;              
            }

            head1 = head1->next;
            head2= head2->next;
            
        }
        
        //Agrego numeros restantes en la linked list que aún tenga nodos
        ListNode * aux;
        
        if(head1){
            aux = head1;
        }else {
            aux = head2;
        }
        
        if(aux != nullptr){
            while(aux){
                int sum = aux->val;
                sum += add;
                add = 0;
            
                if(sum > 9){
                    add += (sum/10);
                    sum %= 10;
                }

                
                tailResult->next = new ListNode(sum);
                tailResult = tailResult->next;
                
                aux = aux->next;
            }            
        }
        
        //Checo si add es distinto a 0
        if(add != 0){
            //Agrego al result el valor de add
            tailResult->next = new ListNode(add);
        }
        
        
        //Sum of the value on each linked list
        
        return headResult;
    }
};

/*
Tarde 1 hora en terminarlo.

Fue buena idea seccionarlo, hice buen trabajo en saber lo que iba a hacer y como lo iba a hacer.
Otra cosa que me ayudo fue el walkthrough, porque me di cuenta que si una lista tiene muchos nodos, no cabe la info en un integer
    Pude buscar una alternativa, de manera rapida

Un tip que me pudo hacer más rapido, fue pensar en la data structure y en que puedo hacer un add first o un add last
Me di cuenta tarde, pero antes de hacer el reverse linked list, lo cual fue bueno.

Si lo hubiera pensado antes, hubiera pensado antes la logica sobre como hacer el return.

Overall, buena performance para ser el primer ejercicio de LinkedLists
*/