#include <iostream>
#include <vector>
#include<queue>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
            info
                input: array of k linked lists
                       each linked lists is sorted in ascending order
                        
                output: merge all linked lists into one sorted linked list and return it
                
                constraints:
                    k == linked lists length
                    j is between 0 and 10,000
                    node values range from -10,000 to 10,000
                    
                    sum of lengths of linked lists will not exceed 10,000
                
            example
                [[1,4,5],[1,3,4],[2,6]]
                ->1->1->2->3->4->4->5->6
                
            brute force
                traverse the list and compare each current node value
                connect that current node value to the answer linked list
                
                complexity: 
                    time O(n^2)
                    extra space O(1)
                    
            optimize
                have a min heap for each for all current nodes
                after joining a node, pop that element and add the next node
                continue while the queue is not empty
                
                complexity:
                    Add elements to min heap O(n) to traverse O( log n ) to set in rigth position
                    while k is not empty check top and connect, reacommodation of elements O(log n)
                    
                    time: O(all nodes)
                    extra space: O(k)
                    
            walkthrough
            
                set variables
                    priority queue
                    answer root node
                    k
                
                fill the priority queue
                
                while queue is not empty
                    aux pointer to min index in the array
                    auc pointer to node in the array
                    
                    if(next is diff from null) add next to priority queue
                    
                    get min and add to answer root node
                    update curr node
            
            test
                special case: empty lists
                              empty linkedlists in lists
                               
        */
        
        //check if lists is empty
        if(lists.size() == 0) return nullptr;
        
        //set variables
        int k = lists.size();
        ListNode * ansHead = nullptr;
        ListNode * ansCurr;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minH;
        
        //fill priority queue O(k)
        for(int i = 0; i < k; i++){
            if(lists[i] != nullptr) minH.push(make_pair(lists[i]->val, i));
        }
        
        int index;
        ListNode * auxNode;
        ListNode * prevNode;
        
        //set ansHead and ansCurr O(1)
        if(!minH.empty()){
            
            //get values
            index = minH.top().second;
            minH.pop();
            
            //set nodes info
            ansHead = new ListNode(lists[index]->val);
            ansCurr = ansHead;

            //update linked list at lists[i] head
            prevNode = lists[index];
            auxNode = prevNode->next;
            
            if(auxNode != nullptr){
                minH.push(make_pair(auxNode->val, index));
                prevNode->val = auxNode->val;
                prevNode->next = auxNode->next;
                delete auxNode;
            } 
            
        }
        
        //while queue is not empty O(nodes)
        while(!minH.empty()){
            
            //get info
            index = minH.top().second;
            minH.pop();
            auxNode = lists[index];
            
            //add node to answer and move there
            ansCurr->next = new ListNode(lists[index]->val);
            ansCurr = ansCurr->next;

            //update linked list at lists[i] head
            prevNode = lists[index];
            auxNode = prevNode->next;
            
            if(auxNode != nullptr){
                minH.push(make_pair(auxNode->val, index));
                prevNode->val = auxNode->val;
                prevNode->next = auxNode->next;
                delete auxNode;
            } 
        }

        
        //return root
        return ansHead;
    }
};
