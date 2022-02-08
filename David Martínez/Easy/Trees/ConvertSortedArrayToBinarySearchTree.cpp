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
        1. listen
            
            input: integer array "nums" where elements are sorted in ascending order
            output: height balanced binary search tree
        
            nums.length is bewtween 1 and 10,000
            nums is sorted in a strictly increasing order
            
        2. example
            cuaderno 
            
        3. brute force
            pivot = size/2
            Traverse the vector
            before pivot, arreanges the values on the left side
            after pivot, arranges the values on the right side
        
        4. optimize
            BCR: O(n) traverse vector O(log n) inserting values on BST
            BCR: O(n log n)

            Pense que el BCR era n log n, pero en realidad es n. construyo con dfs el arbol de abajo 
            hacía arriba. Pero el memory es de O(n) siempre por la creación de nuevos nodos
            
            Brute force is optimal, since it uses O(1) memory
        
        5. walkthrough
            Check that the list has more than 1 element
            Find the pivot
            the pivot is the root.
            
            For each element in the vector 
                Elements before the pivot fit on the left side
                Create aux pointer for left side insert the value on that left side
                
                Elements after the right pivot
                create aux pointer for right side inser the value on that right side

        6. implement
        7. test
        */
        
        
        /*
        Intento secuencial
        
        int pivot = nums.size()/2; //Pivot Index
        TreeNode * root = new TreeNode(nums[pivot]);   //Root

        //Check that the list has more than 1 value
        if(nums.size() == 1){
            return root;
        }

        //Normal insertion
        
        //Traverse the list
        for(int i = 0; i < nums.size(); i++){
            
            TreeNode * father = root;
            TreeNode * curr = root;
            
            //check if we are on the pivot
            
            //Check left side
            if(i < pivot){
                curr = curr->left;
            }
            
            //Check right side
            if(i > pivot){
                curr = curr->right;
            }
            
            
            if(i != pivot){
                while( curr != nullptr){
                
                    father = curr;
                    curr = (curr->val > nums[i]) ? curr->left : curr->right;
                }
                
                
                if(father->val > nums[i]){
                    father->left = new TreeNode(nums[i]);
                }
                else{
                    father->right = new TreeNode(nums[i]);
                }
            }
            
        }
        
        return root;
    */
        
        //Sabía que era con busqueda binaria, solo no había pensado en como aplicar el concepto con
            //Recursividad
        return dfs(nums, 0, nums.size()-1);
    }

    //Función recursiva que hace mi solución propuesta 
        //de hacerlo implementando el concepto de binary search
    TreeNode* dfs(vector<int> & nums, int start, int end){  //Recibe index start y end
        
        if(end < start){    //Si end no sea mayor a start (no se crucen los pointers)
            return nullptr; //Regreso nullptr
        }
    
        int mid = (start+end) / 2;  //Saco el index de enmedio
        TreeNode * root = new TreeNode(nums[mid]);  //Creo un nodo con ese valor
        
        root->left = dfs(nums, start, mid-1);//El lado izquierdo lo apunto de start a mitad-1
        root->right = dfs(nums, mid+1, end); //El lado derecho lo apunto de mitad+1 a end
    
        return root; //Regreso el root
    }
};