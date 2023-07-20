#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode
{

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(0), left(left), right(right) {}
};

class TreeTraversals
{

public:
    // recursive
    void preorderRec(TreeNode *root);
    void inorderRec(TreeNode *root);
    void postorderRec(TreeNode *root);

    // iterative
    void preorderIt(TreeNode *root);
    void inorderIt(TreeNode *root);
    void postorderIt(TreeNode *root);

    // level by level
    void levelByLevel(TreeNode *root);
};

void TreeTraversals::preorderRec(TreeNode *root)
{

    // base case
    if (root == nullptr)
        return;

    cout << root->val << " ";
    preorderRec(root->left);
    preorderRec(root->right);
}

void TreeTraversals::inorderRec(TreeNode *root)
{

    // base case
    if (root == nullptr)
        return;

    inorderRec(root->left);
    cout << root->val << " ";
    inorderRec(root->right);
}

void TreeTraversals::postorderRec(TreeNode *root)
{

    // base case
    if (root == nullptr)
        return;

    postorderRec(root->left);
    postorderRec(root->right);
    cout << root->val << " ";
}

void TreeTraversals::preorderIt(TreeNode *root)
{

    // declare variables
    stack<TreeNode *> stack;

    while (!stack.empty() || root != nullptr)
    {

        while (root != nullptr)
        {

            // print value or add it to vector
            cout << root->val << " ";

            // add node to stack
            stack.push(root);

            // move to left side
            root = root->left;
        }

        // once we hit left-most tree node
        root = stack.top();
        stack.pop();

        root = root->right;
    }
}

void TreeTraversals::inorderIt(TreeNode *root)
{

    // declare variables
    stack<TreeNode *> stack;

    while (!stack.empty() || root != nullptr)
    {

        while (root != nullptr)
        {

            // add node to stack
            stack.push(root);

            // move to left side
            root = root->left;
        }

        // once we hit left-most tree node
        root = stack.top();
        stack.pop();

        // print value or add it to vector
        cout << root->val << " ";

        root = root->right;
    }
}

void TreeTraversals::postorderIt(TreeNode *root)
{

    // declare variables
    stack<TreeNode *> stack;
    vector<int> traversal;

    while (!stack.empty() || root != nullptr)
    {

        while (root != nullptr)
        {

            // print value or add it to vector
            traversal.push_back(root->val);

            // add node to stack
            stack.push(root);

            // move to left side
            root = root->right;
        }

        // once we hit left-most tree node
        root = stack.top();
        stack.pop();

        root = root->left;
    }

    reverse(traversal.begin(), traversal.end());

    for (int val : traversal)
        cout << val << " ";
}

void TreeTraversals::levelByLevel(TreeNode *root)
{

    // declare queue
    queue<TreeNode *> q;

    // add root to queue
    q.push(root);

    // while que is not empty
    while (!q.empty())
    {

        // get queue length, # of nodes in current level
        int n = q.size();

        // here it can go a aux vector for interaction with level nodes

        for (int i = 0; i < n; i++)
        {

            // get node
            TreeNode *aux = q.front();
            q.pop();

            // print node value
            cout << aux->val << endl;

            // if it has children add them to queue
            if (aux->left)
                q.push(aux->left);
            if (aux->right)
                q.push(aux->right);
        }
    }
}

int main()
{

    TreeTraversals trav;

    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);

    node5->left = node3;
    node5->right = node6;

    node3->left = node2;
    node3->right = node4;

    node2->left = node1;

    trav.postorderIt(node5);

    return 0;
}