#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> postorderTraversal(TreeNode* root) {
        
        //Recursive
        /*
        vector<int> result;
        postorder(root, result);
        return result;
        */
        
        if(root == nullptr) return {};

        //Iterative
        vector<int> result;
        stack<TreeNode*> stack;
        stack.push(root);
        
        //traversal
        while(!stack.empty()){
            
            while(root != nullptr){
                
                result.push_back(root->val);
                stack.push(root);
                root = root->right;
                
            }
            
            root = stack.top();
            stack.pop();
            root = root->left;
        }
        
        int i = 0, j = result.size()-1;
        while(i < j){
            int aux = result[i];
            result[i] = result[j];
            result[j] = aux;
            i++;
            j--;
        }
        
        
        return result;
    }
    
    void postorder(TreeNode * root, vector<int> & result){
        
        //Base case
        if(root == nullptr) return;
        
        //Recursive step
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
        
    }
};