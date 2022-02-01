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
        
        //Si alguno de ambos lados es nullptr
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