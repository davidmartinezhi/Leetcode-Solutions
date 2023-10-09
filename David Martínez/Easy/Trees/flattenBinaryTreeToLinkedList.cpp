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
    void flatten(TreeNode* root) {
        /*
        info
            input:
                * root to a binary tree
            
            output:
                * binary tree with linkedlist structure, left is always null and the rest of nodes
                    are at the right direction

                * order should be the same as a preorder traversal

            constraints:
                * how many nodes can the tree contain? [0, 2000]
                * what range of values a node contain? [-100, 100]

        example
            root = [1,2,5,3,4,null,6]

                            1
                    2               5
                3       4               6

                1->2->3->4->5->6

                    1
                2       3

                1->2->3

                if node has left
                save right on aux variable
                set left as right and its right child is aux

                            1
                                2               
                            3       4

                first recursive call
                1->2
                aux = 5

                second recursive call, made on 2
                2-> 3
                aux = 4

                once it is null, we traverse to the right limit node and set that node at the end

                we currently have 1->2->3
                now we traverse to the end with 4 and add it
                1->2->3->4->

                now we return and do the same with 5
                 1->2->3->4->5

        brute force solution
            preorder traversal and build a new tree, then assign the old tree to the new tree
            we can save stack calls by doing the traversal iterative
            complexity:
                runtime: O(n)
                extra sapce: O(n)

        optimize
            best conceivable runtime: O(n)

            memory can be improved with recursive function

            I'll go for optimal approach

        test
            * tree has 0 nodes
            * tree has 3 nodes, root, left and right
            * tree has 3 nodes, root, left and left
            * tree has 3 nodes, root, right and right
        */

        //base case: check if root is a nullptr
        if(!root) return;


        //faltten left and right subtree
        flatten(root->left);
        flatten(root->right);

        //move left subtree to right
        TreeNode * tmp = root->right;
        root->right = root->left;
        root->left = nullptr;

        //set right subtree on the last node
        TreeNode * aux = root;
        while(aux->right != nullptr) aux = aux->right;
        aux->right = tmp;
        return;
    }
};