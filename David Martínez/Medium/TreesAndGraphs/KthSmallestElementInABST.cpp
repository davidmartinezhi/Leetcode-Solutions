#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr){};
    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode* left, TreeNode *right): val(x), left(left), right(right){};
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        /*
        info
        input: root binary search tree and integer k
        output: Kth smallest value of all values of the nodes in the tree
        
        Binnary search tree, left is always smaller and right is bigger
        
        number of nodes in the tree are n
        1 <= k <= 10,000
        node.val between 0 and 10,000   
        
        brute force
        save nodes into a vector and grab the node with the smallest value
        O(n) memory
        O(n+n) runtime
        
        optimize
        inorder traversal
        O(n) runtime
        O(1) memory
        
        Test:
            one node
            k is bigger than the bst size
        */

        int result = -1;
        inorderKthSmallest(root, k, result);
        return result;
    }
    
    void inorderKthSmallest(TreeNode * root, int & k, int & result){
        
        //If root is nullptr
        if(root == nullptr){
            return;
        }

        inorderKthSmallest(root->left, k, result);  //Traverse left
        k--;    //Reduce K
        if(k == 0) result = root->val;
        inorderKthSmallest(root->right, k, result); //Traverse right

    }
};

/*
Terminado en 40 minutos, la manera de solucionarlo la saque en 10 minutos. 
    runtime: O(n)
    space: O(n)
    
Pero batalle en la implementación del inorder traversal, debo familiarizarme con eso.

Recursive: O(n) space O(n)
Iterative with stack: runtime: O(n) space O(n)
Morris Traversal: runtime O(n) space O(1)

Checar el Morris traversal
*/