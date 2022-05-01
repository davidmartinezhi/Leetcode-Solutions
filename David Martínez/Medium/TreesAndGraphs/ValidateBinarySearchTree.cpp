#include <iostream>
#include <stack>
#include <limits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        /*
        info
            input: root of binary tree
            output: true/false, if it's a valid binary search tree

            conditions for a valid binary search tree
                *left subtree is smaller than it's parent node
                *right subtree is greater than it's parent node
                *both the left and right subtrees must also be binary search trees

            constraints:
                number of nodes in the tree is in range [1, 10,000]
                node values are between INT_MIN and INT_MAX

        example
            [2, 1, 3] -> true

                2
              /   \
             1     3


             [5,1, 4, null, null, 3, 6] -> false

                5
              /   \
             1      4
                   /  \
                  3    6


        brute force
            recursion call that compares parent to its childs

            O(n) runtime because the call is going to be called once per node
            O(n) space in stack

            O(1) extra space

        optimize
            Inorder Traversal

            Inorder traversal returns the ordered sequence of a BST
            runtime: O(n)
            space: O(n)

            O(1) extra space

            BCR: O(n)


        test:
            - leave nodes
            - nodes with 1 child
            - nodes with 2 childs
            -check that all nodes in right subtree to be greater
            -check that all nodes in left subtree are lesser

        */

        stack<TreeNode *> stack;

        long leftChild = LONG_MIN;

        while (!stack.empty() || root != nullptr)
        {
            while (root != nullptr)
            {
                stack.push(root);
                root = root->left;
            }

            root = stack.top();
            stack.pop();

            if (root->val <= leftChild)
                return false;
            leftChild = root->val;

            root = root->right;
        }

        return true;
    }
};
