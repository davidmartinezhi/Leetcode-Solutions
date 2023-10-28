#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        /*
        info
            input:
                * head of a linked list
                * k, int of rotating places

            output: 
                * head of rotated list

            constraints:
                * what range of sizes will the linked list have?
                * what range of values will the linked list have?
                * what range of sizes will k have?

        example
            head = [1,2,3,4,5], k = 2
                   [3,2,1,5,4]
                   [4,5,1,2,3]

            -> [4,5,1,2,3]

            head = [0,1,2], k = 4
            -> [2,0,1]

        brute force
            create a function to reverse a string from one node to another
            get the size of the linked list
            k % list size, is the number of numbers we'll rotate

            position pointer to list size - k, position

            separate list in two

            rotate right side
            rotate left side
            connect both sides
            rotate the entire list again

            complexity:
                runtime: O(n)
                extra space: O(1)

        optimize
            best conceivable runtime: O(n)

        test
            * head is nullptr
            * head is not nullptr
            * k == 0
        */

        //check head is not nullptr
        if(!head) return nullptr;

        //declare variables
        ListNode* curr = head;
        int n = 0;

        //get size of list
        while(curr){
            n++;
            curr = curr->next;
        }

        //get positions to rotate
        int rotations = k % n;

        //check if we do not need to rotate
        if(rotations == 0) return head;

        //declare variables for rotation
        int m = 0;
        ListNode * splitNode = head;
        while(m < n - rotations - 1){
            m++;
            splitNode = splitNode->next;
        }

        //split list into two
        ListNode * firstPart = head;
        ListNode * secondPart = splitNode->next;
        splitNode->next = nullptr;

        //reverse both parts of the list
        ListNode* reversedFirstPart = reverseList(firstPart);
        ListNode* reversedSecondPart = reverseList(secondPart);

        ListNode* aux = reversedFirstPart;
        while(aux->next){
            aux = aux->next;
        }

        aux->next = reversedSecondPart;

        return reverseList(reversedFirstPart);
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;

        while(curr){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
};

/*
time: 23 minutes
complexity
    runtime: O(n)
    extra space: O(1)

I solved this problem easily because i had experience rotating arrays
and reversing linked lists and this combines both solutions

I'M PROUD OF HOW MUCH I HAVE ADVANCED IN MY PROBLEM SOLVING SKILLS
*/