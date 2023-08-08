#include <iostream>
using namespaces std;

struct TreeNode{
    //attributes
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}

};


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        /*
        info
            input
                - root binary tree

            output
                - max path sum of any non-empty path

            constraints
                - number of nodes that can be expected (range). 1 and 30,000
                - range of values each individual node can have. -1000 and 1000

        example
            root = [-10,9,20,null,null,15,7]

                         1

                -10              20
            9               15         7

            ->

        brute force

            depth first search
            
            base case
                if nullptr, return 0

                get left by calling function
                get right

                left is max of left and 0
                right is max of right and 0

                maximum sum is max between max sum and root val + left + right

                return root val + max of left or right

                on each node we check if the split is the greatest sum

                and we return the max sum of current val and the max of left and right

                complexity
                    runtime: O(n)
                    extra spcace: O(log n) avergage in balanced tree, else O(n)

        
        test 
            tree of 3 nodes
                left is negative
                right is negative
                root is negative

            


        */

        //declare variables
        int maxSum = INT_MIN;

        int aux = dfs(root, maxSum);

        return maxSum;
    }

    int dfs(TreeNode* root, int & maxSum){

        //base case
        if(!root) return 0;

        //get left and right child values
        int leftSum = dfs(root->left, maxSum);
        int rightSum = dfs(root->right, maxSum);

        //check if we add them to sum or not
        leftSum = max(leftSum, 0);
        rightSum = max(rightSum, 0);

        //check if split has the biggest value
        maxSum = max(maxSum, root->val + leftSum + rightSum);

        //return current value + max of right and left
        return root->val + max(leftSum, rightSum);

    }
};


/*
Time: 45+

Complexity
    runtime: O(n)
    extra space: recursive calls O(n * variables)

Desde el inicio tuve una idea sobre cual iba a ser la solución
Si es similar el concepto al kadanes algorithm pero le agrega otro paso

En kadanes algorithm solo checamos la suma que viene y si es negativo, la cambiamos a 0
representando un corte en el subarray actual y comenzando otro.

En este ejercicio de igual manera se realiza ese corte.

Si hubiera pensado en el split y que con 2 splits se rompe la adyacencia,
lo hubiera terminado en los 25 minutos.
Pero lo que me falto pensar en eso, de todos modos es el primer ejercicio de este estilo que hago
entonces es un modelo mental que me podría funcionar despues.

Porque solo checo si la suma de los 2 lados me da el split mas largo, checo si hacerle caso a la suma
que viene desde cada lado o no. y regreso el numero del maximo sin split

*/