#include <iostream>
using namespace std;

struct ListNode{

    //Attributes
    int val;
    ListNode* next;

    //Constructor
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
}


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        /*
        info
            input: head of linked list
            output: new head of linked list

            constraints:
                - number of nodes is in range 0 - 100 
                - nodes values are in range 0 and 100
                - only node pointer can be modified, not the values

        example

            head = [1,2]
            -> [2,1]

            1 -> 2 -> nullptr

            2 -> 1 -> nullptr


            head = [1,2,3]
            -> [2,1,3]

            2->1->3->nullptr
            p. c. n

            2->1->3->nullptr
               p.  c.  n

            head = [1,2,3,4]
            -> [2,1,4,3]

            1 -> 2 -> 3 -> 4 -> nullptr
            2 -> 1 -> 3

            2->1->4 - nullptr

            2->1->4->3->nullptr



            [1,2]
            1->3->nullptr
            p. c  n

            3->1->nullptr


            [1,2,3,4]
            1->2->3->4->nullptr
            p. c. n. 

            2->1->3->4->nullptr
            c. p. n. 

            2->1->3->4->nullptr
               p. c. n. 

            2->1->4. 3->4
                p. n. c. n

            
            2->1->4. 3->4 -> nullptr
                   c. p. c.   n. 

            2->1->4->3->nullptr


            link update (curr points to prev and prev to next)

            reorder values (p is c and c is p)

            if next
                move once
                point prev to next
                prev is curr
                curr is next
                next is next->next
            
            else break


            if next
                move once
            else break


        brute force
            commplexity:
                runtimme: O(n)
                space: O(1)

        optimize
        best conceivable runtime: O(n)
        the approach is optimal


        test
            - no nodes in list
            - even quantity of nodes in list
            - odd quantity of nodes in list
        */


        //check if list has no nodes
        if(!head) return nullptr;

        //check if list has only one node
        if(!head->next) return head;

        //declare variables

        //pointers
        ListNode* prev = head;
        ListNode* curr = head->next;

        //return value
        ListNode* newHead = curr;

        //traverse list
        while(curr){
            ListNode* next = curr->next;

            //nodes swap
            curr->next = prev;
            prev->next = next;

            //reorder pointers order in linked list
            ListNode* aux = curr;
            curr = prev;
            prev = aux;
            
            //move once to update pointer before swapping again
            if(next && next->next){

                //move pointer
                prev = prev->next;
                curr = curr->next;
                next = next->next;

                //update link
                prev->next = next;

                //update pointers order
                prev = curr;
                curr = next;

            }else{break;}
        }

        return newHead;
    }
};

