#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(): val(0), left(nullptr), right(nullptr){};
    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){};
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        /*
        1. listen
            input: root of a binary tree
            
            invert the tree
            
            output: inverted tree
            
            # of nodes is in range [0, 100]
            node val is between -100 and 100
            
        2. example
            cuaderno
            
        3. brute force
            recursividad dfs
            
            basecase:
                nodo nullptr, regresamos nullptr
            
            treenode * aux -> root->left;
            
            root->left = root->right;
            root->right = aux;
            
            return root;

        4. optimize

        5.walkthrough
        6.implement
        7. test
            Arboles binarios balanceados y de la misma altura de cada lado
            root vacío
            Árbol binario con desbalanceado
        */
        
        //Si el root es nullptr, regreso nullptr como valor
        if(root == nullptr){
            return nullptr;
        }
        
        //LLamo el invert Tree de cada lado para hacer el dfs
        invertTree(root->left);
        invertTree(root->right);
        
        //Creo nodo auxiliar
        TreeNode * aux = root->left;    //Guardo el nodo del lado izquierdo
        root->left = root->right;   //Apuntador del lado izquierdo ahora apunta al lado derecho
        root->right = aux;  //Apuntador de lado derecho ahora apunta a lado izquierdo
        
        return root;    //Regreso el root en el que me encuentro
    }
};

/*
Una vez que me di cuenta de que es primordial saber como se recorren los arboles, antes de hacer cualquier ejercicio
Lo sentí mucho más sencillo que el resto de ejercicios de ahora.

Ahora si examine cual sería la manera más optima de hacer el traversal para lograr lo que quiero.

Como se comportarian los nodo si lo hago de "x" o "y" manera.

Resuelto en poco menos de 22 minutos.

runtime: O(n) porque visitamos cada nodo
memory: creo que O(n) pero no estoy seguro. Debo de repasar big O data structures no lineales y recursividad
*/