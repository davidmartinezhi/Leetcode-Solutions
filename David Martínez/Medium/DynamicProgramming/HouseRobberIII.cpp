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

class SolutionArray{
    int rob(TreeNode* root) {
    /*
    1. listen
    
        input: only one entrance, which is the "root"
            each house has only one parent house, forming a binary tree
            
        output: max amount of money that can be robbed without alerting the police
        
        contraints: nodes in the binary tree are between 1 and 10,000
                    node values are between 0 and 10,000 also
    
    2. example
        notebook
        
        [3,2,3,null,3,null,1]
        -> 7
        
    3. brute force
        dfs and compare returning values
        O(n) time
        O(n) extra space
    
    4.optimize
        bcr: O(n)
        
    5. walkthrough
        dfs left and right
        
        compare fathe + prevleft + prevright and actual left+ actual right
        return the max
        
        if father + prevs is bigger, the actuals become prev
        if actuals are bigger, actuals become the prev
        
    7. test
        tree of one node
        
    */
        return robHelper(root, {0,0})[1];
        
    }
    
    vector<int> robHelper(TreeNode* root, vector<int> money) {
        
        //base case
        if(root == nullptr) return {0,0};
        
        //values variables
        vector<int> left = robHelper(root->left, {0,0});
        vector<int> right = robHelper(root->right, {0,0});
        
        //compare
        int actual = root->val + left[0] + right[0];
        int prev = left[1] + right[1];
        
        if(actual > prev){
            return {prev, actual};
        }
        
        return {prev, prev};
    }
};
/*
44 minutes
El problema fue muy estimulante
Me gusto que es la primera vez que aplico el optimize ans solve technique de "base case and build"

Me siento orgulloso de que pude sacar la solución a tiempo. Aparte hoy fue mi entrevista con el ingeniero de facebook
y mme comento que no hay duda de mis problem solving abilities. Trabajaré más en solucionar gastando un poco menos de tiempo
en la planeación del inicio.
    -Solo escribir lo escencial
*/


class SolutionPair {
public:
    int rob(TreeNode* root) {
    /*
    1. listen
    
        input: only one entrance, which is the "root"
            each house has only one parent house, forming a binary tree
            
        output: max amount of money that can be robbed without alerting the police
        
        contraints: nodes in the binary tree are between 1 and 10,000
                    node values are between 0 and 10,000 also
    
    2. example
        notebook
        
        [3,2,3,null,3,null,1]
        -> 7
        
    3. brute force
        dfs and compare returning values
        O(n) time
        O(n) extra space
    
    4.optimize
        bcr: O(n)
        
    5. walkthrough
        dfs left and right
        
        compare fathe + prevleft + prevright and actual left+ actual right
        return the max
        
        if father + prevs is bigger, the actuals become prev
        if actuals are bigger, actuals become the prev
        
    7. test
        tree of one node
        
    */
        pair<int,int> money;
        money.first = 0;
        money.second = 0;
        return robHelper(root, money).second;
        
    }
    
    pair<int,int> robHelper(TreeNode* root, pair<int,int> money) {
        
        //base case
        if(root == nullptr) return {0,0};
        
        pair<int,int> aux;
        aux.first = 0;
        aux.second = 0;
        
        //values variables
        pair<int,int> left = robHelper(root->left, aux);
        pair<int,int> right = robHelper(root->right, aux);
        
        //compare
        int actual = root->val + left.first + right.first;
        int prev = left.second + right.second;
        
        if(actual > prev){
            aux.first = prev;
            aux.second = actual;
            return aux;
        }
        
        aux.first = prev;
        aux.second = prev;        
        return aux;
    }
};

