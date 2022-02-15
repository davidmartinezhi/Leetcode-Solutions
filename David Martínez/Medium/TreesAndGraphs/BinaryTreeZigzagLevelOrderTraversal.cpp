#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        /*
        1. listen
            input: root of a binary tree
            output: zig zag level order traversal of node values in a vector of vectors
            
            left -> right
            right -> left
            
            Number of nodes in the tree varies from 0 to 200
            Node val of each node varies from -100 to 100
            
        2. example
            
             3
            / \
           9  20
              / \
             15  17
             
        [[3], [20, 9], [15, 17]]
        
            nullptr
            []
            
            1
            [[1]]
        
        3. brute force
            level by level traversal using queue
            use a counter to know if the nodes should be added from left->right or right->left
            runtime: O(n)
            memory: O(n)
                Only the resulting vector as default, as extra memory
                And the largest possible queue size
                
        
        4.optimize
            I feel that the brute force proposed solution in efficient enough
        
        5.Walkthrough
        
        queue that will have the level nodes
        result vector
        counter starting from 0
        
        while queue is not empty
            get current size (nodes in level)
            add 1 to the counter
            auxiliary vector
            

            
            for loop of nodes on that level
                add left and right child if they exist, to the queue
                    even: left->right
                    odd: right->left
                
                add node value to the aux vector
            
            append aux vector to result
        
        6.implement
        
        7.test         
            Special cases:
                -empty root
            
            To-do:
                Check if Q.front() is correct syntax
        */
        
        if(root == nullptr){
            return {};
        }

        
        //Vector for result
        vector<vector<int>> result;
        
        //Counter
        int counter = 0;
        
        //Queue for level by level traversal
        queue<TreeNode *> Q; 
        Q.push(root);
        
        while(!Q.empty()){
            
            int nodes = Q.size();    //Nodes on the current level
            counter++;  //Increment counter
            vector<int> auxVector(nodes);   //Inicializamos vector con el size del nivel en el que estamos
            
            for(int i = 0; i < nodes; i++){
                
                TreeNode *aux = Q.front();
                Q.pop();
                
                int index = (counter % 2 != 0) ? i : nodes-i-1; //Rellenamos el left->right right->left
                auxVector[index] = aux->val;
                
                if(aux->left) {Q.push(aux->left);}
                if(aux->right) {Q.push(aux->right);}                      
  
            }
            
            //if(counter % 2 == 0){
              //  reverseVector(auxVector);
            //}
            
            result.push_back(auxVector);   
                
        }
        
        return result;
        
    }
    
    
    //Runtime: O(m) elementos en el nivel
    void reverseVector(vector<int> & list){
        //Reverses vector
        int start = 0;
        int end = list.size() - 1;
        
        while(start < end){
            int aux = list[start];
            list[start] = list[end];
            list[end] = aux;
            start++;
            end--;
        }
    }
};

/*
Nota:

    Terminado en 35 minutos.
    Asegurarme de escribir bien los tipos de datos. Perdí mucho tiempo al final buscando un error
        que resulto ser porque no hice la variable result un vector de vectores que tienen enteros.

    Apenas supe que tenía que hacer un level by level traversal y se me hizo muy sencilla la solución.
    Siento que debe existir una solución más optima al moverle a la manera en la que metemos los nodos al queue.

    Lo probaré.

    Si existe una solución más optima.
    Me gustó descubrir que puedo rellenar un vector ya existente de izquierda a derecha con solo i
    Pero que para rellenarlo de derecha a izquierda se usa size - i - 1.

    Siento que es conocimiento muy util para futuros problemas
*/