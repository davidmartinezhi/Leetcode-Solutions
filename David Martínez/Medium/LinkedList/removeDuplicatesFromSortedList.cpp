#include <iostream>
#include <unordered_map>

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
    ListNode* deleteDuplicates(ListNode* head) {
        /*
        info
            input:
                * head of sorted linked list

            output:
                * sorted linked list without nodes that repeat numbers

            constraints:
                * what range of sizes can the linked list have? [0, 300]
                * what range fo values will the linked list have? [-100, 100]
                * list is guaranteed to be sorted

        example
            head = [1,2,3,3,4,4,5]
                                i j
                      k
            newHead = [aux,1,2,5]

            -> [1,2,5]

            head = [1,1,1,2,3]
                          i j
            newHead = [a,2]
            -> [2,3]

        brute force
            traverse list and add all nodes with same value to a hashtable to count frequency
            traverse list and add all nodes with values with count of 1 to new head

            complexity:
                runtime: O(n)
                extra space: O(n)

        optimize
            best conceivable runtime: O(n)

            Can I improve memory? yes with pointers

            but I'l code the brute force solution first

        test
            * empty list
            * list with unique values
            * list with one value repeating multiple times
        */


        //check head is not nullptr
        if(!head) return nullptr;

        //declare variables
        unordered_map<int, int> valuesCount;
        ListNode * newHead = new ListNode(INT_MIN); //dummy new head node
        ListNode * aux = newHead;

        //traverse to count values and their frequencies
        ListNode * curr = head;
        while(curr){
            valuesCount[curr->val]++;
            curr = curr->next;
        }

/*
            head = [1,1,1,2,3]
            valuesCount = {
                1: 3
                2: 1,
                3: 1
            }
            newHead = [a,2,3]

*/

        //traverse again to build result list
        curr = head;
        while(curr){
            if(valuesCount[curr->val] == 1){
                aux->next = curr;
                aux = aux->next;
            }
            curr = curr->next;
        }

        //end
        aux->next = nullptr;

        return newHead->next;

    }
};
//23 minutes, non optimal memory solution