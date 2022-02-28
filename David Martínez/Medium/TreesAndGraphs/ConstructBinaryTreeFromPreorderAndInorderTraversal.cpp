#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr){};
    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode* left, TreeNode *right): val(x), left(left), right(right){};
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*
        1. listen
            input : 2 integer arrays ( inorder and preorder )
            construct the binary tree
            output: binary tree
            
            Constrains:
                -both arrays are of the same size
                -arrays size ranges from 1 to 3000
                -values range from -3000 to 3000
                -both lists consist of unique values
                -each value of inorder also appears in preorder
                -preorder and inorder are guaranteed to be their corresponding traversal of the tree
                
            Prorder : Node, Left, Right. Useful to clone trees
            Inorder: Left, Node, Right. Useful to get binary Search Tree values in order
            
        2. example
            prorder: [3,9,20,15,7], inorder = [9,3,15,20,7]
            
                 3
              /     \
            9        20
          /   \     /   \
        null null  15    7
        
        
        father = i/2
        leftChild = (i*2) + 1
        rightChild = (i*2) + 2
        leafNodes = size/2
        
        pattern, each window of two has pair (a,b) in preorder and (b,a) in inorder
        center left, on the right side, center left, right side center left
        3
    9       20
        15      7
        
        Try on another example:
            There must be a reason to have two lists
            Could make a recursive call of the resulting array and create an array
                if the array is the same as inorder, it's correct
        
        
        3. brute force
        Traverse the array and set each element to his child
        Create an array with nodes and the values of the list
        Traverse the array like a priority queue and assign values
        
        runtime: O(n)
        memory: O(n)
        
        Could check the validation by traversing the array inorder
        runtime would be: O(n+m)
        
        4. optimize
            BCR: O(n)
            
                
        
        5. walkthrough
            
            Pattern
            
                preorder array
                
                fixed window size 2
                first element is node, second element is leftchild
                next window, first element is right of last node
            
            Travers as father and childs
                Create an array with treeNodes and the values of the original preorder
                Fist elemento is father and connects to left, his leftChild
                    Connects to right his rightChild
            
        6. implement
        
        7.test
            -Array sizes of 1 
            -Array sizes of 2
        
        */
        
        /*
        //Vector with tree nodes, initialized as empty
        vector<TreeNode*> vectorTrees = {};
        
        //Fill the vector
        for(int i = 0; i < preorder.size(); i++){
            vectorTrees.push_back(new TreeNode(preorder[i]));
        }
        
        TreeNode * result = vectorTrees[0];
        
        //Recorremos la lista de nodos
        for(int i = 0; i < vectorTrees.size(); i++){
            //Sacamos valores father, leftChild, rightChild
            
            int fatherIndex = (i / 2);
            int leftIndex = (i/2) + 1;
            int rightIndex = (i/2) + 2;
            
            int numChilds = 0;
            
            //Si leftChild existe, conectamos con el padre
            if(leftIndex < vectorTrees.size()){
                numChilds++;
            }
            
            //Si rightChild existe, conectamos con el padre
            if(rightIndex < vectorTrees.size()){
                numChilds++;
            } 
            
            if(numChilds == 0){
                continue;
            }
            else if (numChilds == 1){
                vectorTrees[fatherIndex]->left = vectorTrees[leftIndex];
            }
            else{
                vectorTrees[fatherIndex]->left = vectorTrees[leftIndex];
                
                //Esto es lo que falla
                vectorTrees[fatherIndex]->right = vectorTrees[rightIndex];                
            }
            

        }
        
        //Regresamos el child original
        return result;
        */
        
        //Siento que recursividad puede hacer el truco
        //Siento que recursividad puede hacer el truco
        //Es correcto
        map<int, int> inMap; 

        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        return root;
    }
   TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap) {
        if(preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};
/*
    Solución checada en internet: https://www.youtube.com/watch?v=aZNaLrVebKQ

    La clave es, en cada iteración sacar la posición del root en ambas listas.
    Mandar al lado izquierdo a conectar con left.
    Mandar al lado derecho a conectar con right.

    Es metodo similar a "Easy/Trees/Convert Sorted Array to Binary Search Tree"
    Solo que ahora es con 2 listas al mismo tiempo

*/