#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(): val(0), left(nullptr), right(nullptr), next(nullptr) {};
    Node(int x): val(x), left(nullptr), right(nullptr), next(nullptr) {};
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {};
};

class Solution {
public:
    Node* connect(Node* root) {
        /*
        1. listen
            input: prefect binary tree, all leaves are on the same level and parents have 2 children
            Every pointer has a next pointer
            Initially all next pointers are set to nullptr
            
            Populate all next pointers with their respective next node
            
            The number of nodes in the tree is in the range [0, 212 - 1]
            -1000 <= Node.val <= 1000
            
        2. example
            cuarderno
            
        3. brute force
            Level by level traversal
            save all nodes in a vector in each level and connect them all
            
            Debo repasar big O de arboles
            
        4. optimal solution
            
            Podría ser con recursividad
        
        5. walkthrough
            create a queue
            add root to it
            while the queue is not empty
                save it's size
                aux vector
                for(i to n)
                    get the front
                    add the front to the vector
                    if it has left, add it to the queue
                    if it has right, add it to the queue
                
                traverse the aux vector with fixed window 2
                    connect left to right
                
                connect last element in vector to nullptr
                
                
        7. Test
            Test on any tree, they are all perfectly balanced trees with 2 children
            Test on empty root
        */
        
        
        //Check if root is nullptr
        if(root == nullptr) return root;
        
        //Create Queue for level by level traversal
        queue<Node*> Q;
        Q.push(root);
        
        while(!Q.empty()){
            int n = Q.size();
            vector<Node *> aux;
            
            for(int i = 0; i < n; i++){
                Node * auxNode = Q.front();
                Q.pop();
                
                aux.push_back(auxNode);
                
                if(auxNode->left) Q.push(auxNode->left);
                if(auxNode->right) Q.push(auxNode->right);
            }
            
            for(int i = 1; i < aux.size(); i++){
                aux[i-1]->next = aux[i];
            }
            aux[aux.size()-1]->next = nullptr;
        }
        
        return root;
    }
};


