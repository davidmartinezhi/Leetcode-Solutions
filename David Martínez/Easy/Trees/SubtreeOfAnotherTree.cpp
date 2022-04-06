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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        /*
        1. listen
            input: root and subroot
            output: boolean if there is a subtree in tree, with the same structure as the subtree
            
            number of nodes in root is in range 1 - 2,000
            number of nodes in the subtree is in range 1 - 1,000
            
            root.val is in range -10,000 and 10,000
            subroot.val is in range -10,000 and 10,000
            
            Can node vals be repeated?
            
        2. example
            cuaderno
        
        3. brute force
            traverse the tree to find the nodes with the same starting value as the subtree
            once we've found it, check for match.
                if we check both trees and a node is different we continue searching the root
                if we come to the end of the subroot, it means we found it
            
            runtime: O(n*m) we are checking each tree level and subtree level node
            space: O(1) we can check it with the same pointers always
            
        4. optimize
            BCR: O(n) nodes in tree
            traverse level by level the root, once the node with the root of subtree matches.
            Traverse both at the same time.
            O(1)
            
            ---
            Maybe could I use something similar to KPM, the algorithm that finds substrings in strs
            with runtime: O(n).
            
            Maybe traverse once and save the nodes with the same root as subroot
            Then traverse those nodes
            
            ---
            Inorder traversal of the tree
            if the value is the same as the root in subtree, traverse the subtree too
            
            recursively and iteratively will be O(n) space?
            
        5. walkthrough
                
         
        7. test
            

            special case
                subroot is bigger than root
                root and subroot are the same
                root has 1 node and is subroot
                root has 1 node and it isn't subroot
        
        */
        
        //Si llegamos al final, no existe el valor
        if(root == nullptr) return false;

         bool aux = false;
        
        //Si el val es igual, mandamos a checar por subtree
        if(root->val == subRoot->val){
            aux = isSubtreeSearch(root, subRoot);
            
            if(aux) return true;
        }
        
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));

    }
    
    
    bool isSubtreeSearch(TreeNode * root, TreeNode * subRoot){
        
        //Base case, llega al final es true
        if(subRoot == nullptr && root == nullptr) return true;
        else if(subRoot == nullptr && root != nullptr) return false;
        else if(subRoot != nullptr && root == nullptr) return false;
        
        //Si es diferente el valor, regresa false
        if(subRoot->val != root->val) return false;
        
        //Recorre ambos arboles
        return (isSubtreeSearch(root->left, subRoot->left) && isSubtreeSearch(root->right, subRoot->right));
    }
};
/*
Notas:
    -Tiempor 21 minutes
    -runtime: O(n*m)    Creo que es porque recorre todo el árbol
    -space: O(n) las llamadas a la función
    (Investigar sobre big o con árboles)

    -Al inicio batalle en descubrír como hacer el recorrido, la lógica la saque relativamente rapido
    Pero no estaba seguro sobre como implementarlo, si ha sido de gran ayuda estar en vanttec y tener a gente competente
    a la mano para preguntarles cualquier duda. Porque beber de una jarra cuando puedes ir al manantial.

    -Fue buena idea la de meter una función dentro de esa función.

    -Debería de recordar en que es posible y no intimidarme cuando no estoy seguro sobre donde comenzar.
    

*/