#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        info
            input: 
                * tree node root, tree node p and tree node q
            
            output:
                * lca lowest common ancestor between p and q
                * a node can be a descendant of itself

            constraints:
                * what range of nodes should i expect? [2, 100k]
                * what range of values can the tree nodes have? [-10e9, 10e9]
                * are all nodes unique? yes
                * p and q are always different? yes

        example
            root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 0

                        3
                5               1
            6       2       0       8
                7      4 

        brute force solution

            have global variable for lca

            dfs

            traverse to the bottom of the tree

            on return check if we have found both tree nodes, and return boolean

            complexity:
                runtime: O(n)
                extra space: O(n) for not balanced trees

        optimize
            best conceivable runtime: O(n)

            can memory be improved?
            With an iterative traversal

            Ill try the recursive approach first

        test
            tree with just two nodes
            p or q is the lca
            lca are in different branches
        */

        //validate root
        if(!root) return nullptr;

        //declare variables
        TreeNode* lca;
        
        //traverse the tree and check nodes
        if(!findLowestCommonAncestor(lca, p, q, root)){
            return nullptr;
        }

        return lca;
    }

    bool findLowestCommonAncestor(TreeNode* & lca, TreeNode* & p, TreeNode* & q, TreeNode* currNode){

        /*
                        3
                5               1
            6       2       0       8
            p = 2, q = 0   


        
        */

        //base case: we are at a null pointer
        if(!currNode) return false;

        //recursive call
        bool leftFound = findLowestCommonAncestor(lca, p, q, currNode->left);
        bool rightFound = findLowestCommonAncestor(lca, p, q, currNode->right);

        //check if current node is a pointer we look for
        bool currFound = (currNode == p || currNode == q);

        //check left and right have found the answer
        if(leftFound && rightFound) lca = currNode;


        //check if left and current have found the answer
        if(leftFound && currFound) lca = currNode;


        //check if right and current have found the answer
        if(rightFound && currFound) lca = currNode;


        return currFound | leftFound | rightFound;

    }
};

/*
time: 26 minutes

complexity:
    runtime: O(n)
    extra space: O(n) with no balanced trees

Notes:
    I'm getting pretty good at implementing algorithms based on just
    ideas of how i can traverse the tree.

    Nice Jobs. I've came a long way and I have succeded in all my technical interviews
    since i'vve been practicing leetcode.

*/