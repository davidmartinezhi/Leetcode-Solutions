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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        /*
        info
            input: roots of two binary trees "p" and "q"
            
                -write a function that checks if they are the same
                -they must be structurally identical, and nodes have the same value
            
            output: true/false
            
            constraints:
                -number of nodes in both trees is in range [0, 100]
                -node.val is in range [-10,000 , 10,000]
            
        example
        
            p = [1, 2, 3], q = [1, 2, 3] -> true
            p = [1, 2], q = [1, null, 2] -> false
            p = [1, 2, 1], q = [1, 1, 2] -> false
            
        brute force
            traverse both lists and add the values to arrays
            compare both arrays
            
            runtime: O(n) n being the tree with most nodes
            space: O(n)
        
        optimize
            bcr: O(n)
            
            recursivity
            runtime: O(n)
            space: O(height of tree)
            
        test:
            nullptr root
            
            check: 
                both nullptrs equal to nullptr return true
            
        */
        
        
        if(q == nullptr && p == nullptr){
            return true;
        }
        else if(q == nullptr || p == nullptr){
            return false;
        }
        else if(q->val != p->val){
            return false;
        }
        else{
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }  
    }
};

/*
Me tarde 40 minutos en resolverlo, pero las condiciones ya las tenía desde los primeros 10 minutos.
complejidad: runtime: O(n), time: O(n)


Mi error en el que me tarde, fue en que la función debía de regresar a fuerzas un valor y ese return afectaba todo
Lo que debo de hacer con este tipo de problemas es que no poner varios if's sueltos, mejor, si el problema aplica,
poner if else is else, porque eso hace la estructura más lógica.


*/
