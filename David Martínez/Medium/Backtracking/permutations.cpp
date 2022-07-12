#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    /*
    info
        input: array nums of disctint integers
        output: all possible permutations, can return in any order
        constraints:
            nums length is between 1 and 6
            nums[i] is between -10 and 10
            all integers are unique
    
    example
    [1]
    [[1]]
    
    [0,1]
    [[0,1], [1,0]]
    
    brute force
        backtracking
        
    optimize
    
    walkthrough
    
    test
    
    */
        
        //declare variables
        vector<vector<int>> result;
        vector<int> perm;
        vector<bool> used(nums.size(), false);
        
        //backtrack
        backtrack(result, nums, perm, used);
        
        //return result
        return result;
        
    }
    
    void backtrack(vector<vector<int>>& result, vector<int>& nums, vector<int> & perm, vector<bool> & used){
        
        //base case, if the permutation has all the numbers on the array, add it and return
        if(perm.size() == nums.size()){ 
            result.push_back(perm);
            return;
        }
        
        //traverse possible coices
        for(int i = 0; i < nums.size(); i++){

            if(!used[i]){ //if the number has not been visited
                //make choice
                used[i] = true; //mark as visited
                perm.push_back(nums[i]);    //add it to the permutation
                backtrack(result, nums, perm, used);    //send to backtrack the next numbers
                //undo choice
                used[i] = false;    //liberate the number
                perm.pop_back();    //remove last element
            }
        }
    }
};

/*
video: https://www.youtube.com/watch?v=Nabbpl7y4Lo
time: undefinec, utilice el tiempo para estudiar el concepto, más que para ahcerlo rapido
complexity: 
    time: O(n^2 * n!) factorial y n^2 por recorrer toda la lista por cada numero en cada permutación
    extra space: O(n) n being the number of numbers

    Backtracking es un concepto abstracto pero ya logre entender que es lo que pasa en el codigo 
    y como puedo obtener las posibles combinaciones de algun array o string.

    backtracking consiste en avanzar hasta el final
        en el camino marcas lo que haz visitado, para no visitarlo de nuevo
        y cuando regresas, exploras los posibles nuevos caminos.

        Siento que esto es dfs

*/