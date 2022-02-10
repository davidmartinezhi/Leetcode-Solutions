#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{

    //Atributes
    int val;
    TreeNode *left;
    TreeNode *right;

    //Constructor
    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode * left, TreeNode* right): val(x), left(left), right(right) {};
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        /*
            input: root of binary tree
            output: array with average value on each level in form of an array
            
            Number of nodes ranges between 1 and 10,000
            each node->val can be between INT_MIN and INT_MAX
            
            example on notebook
            
            Brute Force
        -Traverse level by level with a queue
        
        -Before adding new nodes, get size of the current queue to know how many    
        nodes we have in that level
        
        -start level sum from 0
        
         -For loop from cero to the amount of nodes on that level - 1
         
            pop node from queue
            Add node->val to that level sum
         
            if it has left child, add to queue
            if it has right child, add to queue
        
        -after the for loop append sum/nodes in level
        
        runtime: O(n)
        memory: O(n)
        
        Test:
            Tree with 1 node
            root with equal height on both subtrees
            tree not balanced
            
        */
        
        //Start Queue and add root
        queue<TreeNode*> Q;
        Q.push(root);
        
        //Vector with the result
        vector<double> result;
        
        //Level by level traversal, BFS
        while(!Q.empty()){  //While the queue is not empty
            
            int levelNodes = Q.size();  //Nodes on level
            double levelSum = 0;   //Current Sum
            
            //runtime: O(n)
            for(int i = 0; i < levelNodes; i++){
                TreeNode * aux = Q.front(); //Get Node
                Q.pop();    //Remove node from queue
                
                levelSum += aux->val;   //Add value to sum
                
                //Check for left child
                if(aux->left) Q.push(aux->left);
                
                //Checl for right child
                if(aux->right) Q.push(aux->right);
            }
            
            //Pushback average into the result vector
            result.push_back(levelSum/levelNodes); 
        }
        
        return result;
    }
};

/*
Terminado en 27 minutos.

Chulada el haber entendido que casí toda la solución se encuentra en como harás el traversal de la infor
Fue bastante rapido

Al inicio anote todos los pasos de la metodología. Pero los borre y trate de hacerlo ya todo mental pero acordandome de ir paso por paso


*/