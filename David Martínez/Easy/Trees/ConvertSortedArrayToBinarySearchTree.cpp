#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode * left, TreeNode * right): val(x), left(left), right(right){};
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    /*
    info
        input: integer array "nums" where elements are sorted in ascending order
        
        convert it to a height balanced binary search tree
        
            height balanced bst:
                depth of subtrees of every node never differs by more than one
        
        constraints:
            nums length ranges from 1 to 10,000
            nums[i] ranges from -10,000 to 10,000
            strictly sorted in increasing order
    
    example
    
    [1, 3] -> [3, 1]
    
    cuaderno
    
    brute force:
    
        traverse the list though a binary search andset that value as the root, then left child
        and right child come from doing binary search on both extremes
        
        runtime: O(log n)
        space: O(n) for the creatin of the bst
        extra space:O(1)
        
    optimize:
        
        BCR: log n
        
        I think my approach is the most efficient way of creating the bst
    
    walkthrough:
        
    
    test:
        array of size 1
        array of odd size
        array of even size

    */
        
        return binaryBSTConstruction(nums, 0, nums.size()-1);
    }
    
    TreeNode * binaryBSTConstruction(const vector<int> & nums, int i, int j){
        
        int mid = i + (j-i) / 2;
        
       //base case
        if(i > j) return nullptr;
        
        TreeNode * aux = new TreeNode(nums[mid]);
        
        //left
        aux->left = binaryBSTConstruction(nums, i, mid-1);
        aux->right = binaryBSTConstruction(nums, mid+1, j);
        
        return aux;
    }
    
};

/*
Solución elaborada 100% por mi

Me tarde 15 minutos en sacar el aproach más optimo
Pero si me tarde los 45 minutos porque se me olvido que el mid es i + (j-i) / 2. Yo estaba poniendo solo (j-i) / 2

Aún así si hice una buena implementación del binary search y crear un arbol balanceado

*/