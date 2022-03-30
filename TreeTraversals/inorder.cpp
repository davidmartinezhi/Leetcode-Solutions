#include <iostream>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        //Recursivo
        /*
        vector<int> result;
        inorder(root, result);
        return result;
        */
        
        //Iterativo
        //O(n) space
        //O(n) runtime
        
        /*
        vector<int> result;
        stack<TreeNode*> stack;
        
        while(!stack.empty() || root != nullptr){
            
            //Mientras root es diferente a nullptr
            while(root != nullptr){
                stack.push(root);   //Meto el root al stack
                root = root->left;  //Recorro por el hijo izquierdo
            }
            
            //Si estoy en el extremo
            root = stack.top(); //Saco el ultimo valor del stack y lo asigno en root
            stack.pop();
            result.push_back(root->val);    //Agrego ese valor a la lista de resultados
            root = root->right; //asigno al root como el nodo right
        }
        
        return result;
        */
        
        
        //Morris Traversal, inorder 
        //O(n) runtime
        //O(1) space
        
        //Whenever I'm in the root, I add it to the inorder vector
        
        vector<int> inorder;
        TreeNode * curr = root;
        
        while(curr != nullptr){
            
            //first edge case, no left child
            if(curr->left == nullptr){
                inorder.push_back(curr->val);   //He is the root, so we add it to the vector
                curr = curr->right; //Move to the right
            }

            //second edge case, left exists
            else{
                TreeNode * prev = curr->left;   //marcamos el subarbol izquierdo

                while(prev->right && prev->right != curr){  //If it has a right and is not curr
                    prev = prev->right; //Nos movemos hasta el predecesor
                }
                
                if(prev->right == nullptr){
                    prev->right = curr; //Create thread
                    curr = curr->left;  //Move to the left subtree
                }else{
                    prev->right = nullptr;  //Remove thread
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
        return inorder;
    }
    
    
    void inorder(TreeNode * root, vector<int> & array){
        //base case
        if(root == nullptr) return;
        
        inorder(root->left, array); //Traverse left
        array.push_back(root->val); //Insert Node's val in the array
        inorder(root->right, array);//Traverse right
    }
};