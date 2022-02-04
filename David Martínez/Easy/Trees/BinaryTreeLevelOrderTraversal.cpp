#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* left ,TreeNode* right): val(x), left(left), right(right){};
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        /*
        1. listen
            input: root
            output: level order traversal (left to right)
            
            Tree has between 0 and 2,000 nodes
            Node val between -1000 and 1000
        
        2. example
        
            cuaderno
        
        3. brute force
            creo array donde pongo los nodos de cada nivel, luego agrego ese array a la solución final
            
            Recorrido levelByLevel y agregar todos los valores a un vector.
            Luego recorro los indices del vector para sacar los hijos
            
        4. optimize
            
            Tratare de hacer el brute force antes de optimizar
            
            No me salio el problema en hora y media. Lo busque en youtube, iba bien con la solución.
            Pero el patron solo era modificarlo poco.
            
        5. walkthrough
            
            creo array de resultado, que contendra arrays con enteros
            Mando el root a la helper function junto al array de result
            
            Concateno el array aux izquierdo más el derecho y lo agrego a result
        
        6. implement
        
        7. test
            
        */

        //Si el root es nullptr, regreso un vector vacío
        if(!root) return {};
        
        //Si el árbol tiene nodos
        
        queue<TreeNode*> Q; //Creo una queue y le paso el root
        Q.push(root);
        
        vector<vector<int>> result; //Creo el vector para el resultado
        
        //Mientras la fila no esté vacía
        while(!Q.empty()){
            
            //Checo cuantos nodos existen actualmente en la lista
            //Esa es la cantidad de nodos en el nivel que estamos
            int count = Q.size();
            
            vector<int> level_nodes;    //Vector auxiliar para guardar los valores del nivel actual
            
            //Con count, yase los nodos existentes en el nivel actual
            //Esos son los nodos que agregare a level_nodes y saco del queue
            for(int i = 0; i < count; i++){ 
                
                TreeNode* n = Q.front();  //Apuntador al primer valor de la fila
                Q.pop();    //Quito ese valor de la fila
                
                if(n->left) Q.push(n->left);    //Si tiene hijo izquierdo lo agrego a la fila
                if(n->right) Q.push(n->right);  //Si tiene hijo derecho lo agrego a la fila
                
                level_nodes.push_back(n->val);  //Agrego el valor del nodo actual, a la lista aux
            }
            
            result.push_back(level_nodes);  //Agrego la lista aux a el resultado
        }      
        return result;     
    }
};