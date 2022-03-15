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