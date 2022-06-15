#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{

    //variables
    int val;
    TreeNode * left;
    TreeNode * right;

    //constructors
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* leftP, TreeNode *rightP): val(x), left(leftP), right(rightP) {};
};

