#include <iostream>
using namespace std;

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

    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelper(root->left, root->right);
    }
    
    bool isSymmetricHelper(TreeNode * left, TreeNode * right){
        
        //Si alguno de los lados es nullptr
        if(left == nullptr || right == nullptr){
            return left == right;   //Regreso si son iguales
        }
        
        //Si los valores no son iguales
        if(left->val != right->val){
            return false;   //Regreso false
        }
        
        //Llamo la función de nuevo y paso los valores a comparar
        return (isSymmetricHelper(left->left, right->right)) && (isSymmetricHelper(left->right, right->left));
        
    }
};

/*
Notas:
    Pense en recorrer como si fuera un array o vector. 

    Pero la solución se encontraba en recorrerlo como si fuera una linked list donde
    se debe ser explicito sobre que se compara y como.

    La Helper function agarra 2 valores y simplemente los compara para saber si tienen el mismo dato
    Luego en la llamada recursiva mando explicitamente cuales son los siguientes nodos a comparar.

    Para resolverlo de manera recursiva puedo acomodar los valores en un vector, igual que en una priority queue
    Luego comparo los indices.
    Para solución iterativa podría utilizar un recorrido ahora si y agrego cada valor al vector de esta manera.

    Debo intentar esta solución.
*/