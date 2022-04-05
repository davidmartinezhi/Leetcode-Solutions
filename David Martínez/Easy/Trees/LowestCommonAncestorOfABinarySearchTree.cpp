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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        1. listen
            It's a binary search tree
            
            Find the lowest common ancestor (LCS) of two given nodes
            LCA is the lowest node in T that has both p and q as descendants
            A node can be a descendant of itself
            
            nodes cuantity are between 2 and 100000
            node val varies from -billion to billion
            All node values are unique
            p != q
            p and q will always exist
            
        2. example
        
        3. brute force
            Save the nodes
        
        4. optimize
            Move two pointers one spot at the time, if they are in the same node, that's the lowest

            Runtime :O(n)
            Space: O(1)
        
        */
        
        TreeNode * pAux = root;
        TreeNode * qAux = root;
        
        TreeNode * lowest = root;
        
        while((pAux != p && qAux != q)){
           
            //Move pAux one node
            if(pAux != p){
               pAux = (pAux->val > p->val) ? pAux->left: pAux->right; 
            }

            //Move qAux one node
            if(qAux != q){
                qAux = (qAux->val > q->val) ? qAux->left: qAux->right;
            }
            
            //Check if both pointers are in the same node
            if(pAux->val == qAux->val){
                lowest = pAux;  //That is the lowest
            }  
        }

        return lowest;
    }
};

/*
16 minutes

    Fue sencillo el problema, solo que no había entendido que querían el más bajo en el árbol
    Yo había entendido que el más bajo en valor


*/