#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(): val(0), left(nullptr), right(nullptr){};
    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){};
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        /*
        1. listen
            input: root of a binary tree
            
            invert the tree
            
            output: inverted tree
            
            # of nodes is in range [0, 100]
            node val is between -100 and 100
            
        2. example
            cuaderno
            
        3. brute force
            recursividad dfs
            
            basecase:
                nodo nullptr, regresamos nullptr
            
            treenode * aux -> root->left;
            
            root->left = F(root->right);
            root->right = F(root->left);
            
            return root;

        4. optimize
        */
        
        if(root == nullptr){
            return nullptr;
        }
        
        invertTree(root->left);
        invertTree(root->right);
        
        TreeNode * aux = root->left;
        root->left = root->right;
        root->right = aux;
        
        return root;
    }
};