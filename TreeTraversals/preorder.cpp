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
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        /*
        vector<int> result;
        preorder(root, result);
        return result;
        */
        /*
        //Check if root is different from nullptr
        if(root == nullptr) return {};
        
        vector<int> result;
        
        //Create stack and add the root node
        stack<TreeNode*> stack;
        stack.push(root);
        
        while(!stack.empty()){  
            //Recorro hasta la izquierda
            while(root != nullptr){
                result.push_back(root->val);    //Agrego valor al vector de resultado
                stack.push(root);   //Agrego el nodo al stack
                root = root->left;  //Recorro hacía la izquierda
            }
            
            //Si tope con izquierda
            root = stack.top(); //Saco el ultimo nodo visitado
            stack.pop();
            
            root = root->right; //Apunto al lado derecho de ese ultimo nodo seleccionado
        }
        
        return result;
    }
    */
        //Morris Traversal, inorder 
        //O(n) runtime
        //O(1) space
        
        //Whenever I'm in the root, I add it to the inorder vector
        
        vector<int> preorder;
        TreeNode * curr = root;
        
        while(curr != nullptr){
            
            //first edge case, no left child
            if(curr->left == nullptr){
                preorder.push_back(curr->val);   //He is the root, so we add it to the vector
                curr = curr->right; //Move to the right
            }
            //second edge case, left
            else{
                
                TreeNode * prev = curr->left;
                
                while(prev->right && prev->right != curr){  //If it has a right and is not curr
                    prev = prev->right; 
                }
                
                if(prev->right == nullptr){
                    prev->right = curr; //Create thread
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }else{
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        
        return preorder;
    }
    
    void preorder(TreeNode * root, vector<int>& list){
        
        if(root == nullptr) return;
        
        list.push_back(root->val);
        preorder(root->left, list);
        preorder(root->right, list);
        
    }
};