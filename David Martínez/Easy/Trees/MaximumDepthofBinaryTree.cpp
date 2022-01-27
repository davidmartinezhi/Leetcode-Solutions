#include <iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        /*
        1. listen
            input: root of a binary search tree
            output: max length
            
            # of nodes between 0 and 10,000
            node values from -100 to 100
            
        2. example
        
        3. brute force
            recursive, traverse each node until the next node is nullptr
            return the biggest side between left and right + 1.
            
        4. optimize
        5. walkthrough
        6. implement
        7. test
            special case:
                0 nodes in the tree
                
        */
        
        //Base Case
        if(root == nullptr){
            return 0;
        }
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
        
       /*
        //Comparison
        int leftSide = maxDepth(root->left);
        int rightSide = maxDepth(root->right);
        
        //Returns the biggest side
        return (leftSide > rightSide) ? leftSide + 1 : rightSide + 1;
        */
    }
    
};

/*
Terminado en 13 minutos.
//O(n) runtime
//O(maximum height) memory

Aún tengo buen entendimiento de lo basic de binary search tree y como recorrerlo. 

Investigar Big O en recursicidad
*/