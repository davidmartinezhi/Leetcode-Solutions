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
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        /*
            info
                input:
                    * root node of binary tree
                    * binary tree contains digints from 0-9 only
                    
                    * each root to leaf path represents a bumber 1->2->3 = 123

                output:
                    * sum of all root to leaf numbers

                constraints:
                    * what range of sizes can the tree have? [1, 1000]
                    * nodes contain only digits from 0-9
                    * answer will fit a 32-bit integer
                    * depth of tree will not exceed 10

            example
                        root = [1,2,3]
                                1
                            2       3
                        ->12      ->13

                        root = [4,9,0,5,1]

                                4 (0)
                        9 (4)           0
                    5 (49)      1         ->40
                ->(495)    ->491

                        -> 1096

            brute force
                dfs traversal, top-bottom

                have global sum variable, each time we get to a nullptr we sum the current value

                recursive appraoch
                base case
                    if node is nullptr, we add to glbal sum the current sum

                recursive call
                    call to left side with curr Value being (currValue*10)+current node number
                    currValue=10 nodeValue=5
                    10*10 = 100 + 5 ? 105

                complexity:
                    runtime: O(n) we traverse each node once
                    extra space: O(h), H bring the height, but we know depth of tree will not exceed 10
                    so extra space: O(1)

            optimize
                best conceivable runtime: o(n)
                approach is optimal

            test
                * empty tree
                * tree with only one node
                * tree with all nodes to the left
                * tree with all nodes to the right
        */

        //check if root is null
        if(!root) return 0;

        //declare global sum
        int sum = 0;

        //recursive call
        sumNumbersByTreePath(sum, root, 0);

        return sum;
    }

    /*
    sum = 0
    currSum = 495
                                4 (0)
                        9 (4)           0
                    5 (49)      (49)         ->40
                ->(495)    ->491    
    */

    void sumNumbersByTreePath(int & sum, TreeNode * node, int currSum){

        //base case: node is null
        if(!node){
            return;
        }

        //base case: node is leaf
        if(!node->left && !node->right){
            sum += (currSum*10) + node->val;
            return;
        }
        
        //recursive calls
        sumNumbersByTreePath(sum, node->left, (currSum*10) + node->val); //left path
        sumNumbersByTreePath(sum, node->right, (currSum*10) + node->val); //right path

        return;
    }
};