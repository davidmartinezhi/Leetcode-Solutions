#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        //iterativo otra vez
        
        // left, node, right
        vector<int> result;     
        stack<TreeNode*> stack;
  
        
        while(!stack.empty() || root != nullptr){
            
            while(root != nullptr){
                //Traverse all the way to the left
                stack.push(root);
                root = root->left;
            }
            
            TreeNode* aux = stack.top(); //Pop the top value
            stack.pop();
            
            //Add the value to result
            result.push_back(aux->val);
            root = aux->right;
        }
        
        
        return result;
        
        
        
        
        
        
        
        
        
        /*
        stack<TreeNode *> stack;
        vector<int> result;
        
        while(!stack.empty() || root != nullptr){
            
            while(root != nullptr){
                stack.push(root);
                root = root->left;
            }
            
            TreeNode * aux = stack.top();
            stack.pop();
            
            result.push_back(aux->val);
            root = aux->right;
        }
        
        return result;
        
        */
        
        
        /*
        //Recursivo
        vector<int> result;
        inorder(result, root);
        return result;
        */
        /*
        //Iterativo
        stack<TreeNode*> stack; //Stack vacío
        vector<int> result; //Vector vacío
        
        while(!stack.empty() || root != nullptr){   //Stack no vacío o root no nullptr
            
            while(root != nullptr){ 
                stack.push(root);   //Agrego nodo
                root = root->left;  //Recorro hasta tope izquierdo
            }  
            
            root = stack.top(); //Saco el primer valor del stack
            stack.pop();
            
            result.push_back(root->val);    //Agrego su valor a la lista de resultados
            root = root->right;   //Ahora el root es su subarbol izquierdo
        }
        
        return result;
        */
    }
    
    /*
    void inorder(vector<int> & list, TreeNode * root){
        //Utíl para conseguir los valores de menor a mayor
        //Cuando el root sea nullptr, regresa
        if(root == nullptr){
            return;
        }
        
        inorder(list, root->left);  //Manda a llamar la función con el subarbol izq
        list.push_back(root->val);  //Agrega el valor del nodo actual
        inorder(list, root->right); //Manda a llamar al nodo del lado derecho
        
    }
    
    */
};