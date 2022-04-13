#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
        1. info
            input: integer array "height" of length "n"
            
            each index represents a line
            
            find 2 lines that together with the x axis form a container
                such that the container contains the most water
                
            output: maximum amount of water a container can store
            
            n == heigh.length
            n <= n <= 100,000
            0 <= height[i] <= 10,000
        
        2. example
            notebook
            
        3. brute force
            nested for loops to check for all possible water containers
            runntime: O(n^2)
            space: O(1)
            
        4. optimize
        
            Two pointer technique (pointer at beginning and at the end)
            the pointer at the index with the shortest line * window is the current window
            compare current window to max window
            
            time: O(n)
            space: O(1)
            
            bcr: O(n)
            
        5. walkthrough
            
            move pointer with that points to the shortest line
            if both lines are the same
                compare next values
                    if the biggest next, is the pointer that moves or if the line is equal as previous
        6. implement
        
        7. test
            -all values are the same
            -pointers have the same value
            -pointers have different values
        */
        
        //runtime: O(n)
        //space: O(1)
        
        //pointers
        int start = 0;
        int end = height.size() - 1;
        
        //max cointainer variable
        int maxContainer = INT_MIN;
        
        //window variable
        int window = height.size() - 1;
        
        //traversal moving start when both indexes have the same number
        while(start < end){
            
            //Calculate current container and compare with maxContainer
            int minLine = min(height[start], height[end]);
            int currContainer = window * minLine;
            
            if(currContainer > maxContainer) maxContainer = currContainer;
            
            //Move shortest pointer
            if(height[start] < height[end]){
                start++;
            }
            else if(height[start > height[end]]){
                end--;
            }
            else{   //If both indexes have the same value
                start++;
            }
            
            window--;
        }

        //pointers
        start = 0;
        end = height.size() - 1;

        //window variable
        window = height.size() - 1;
        
        //traversal moving end when both indexes have the same number
        while(start < end){
            
            //Calculate current container and compare with maxContainer
            int minLine = min(height[start], height[end]);
            int currContainer = window * minLine;
            
            if(currContainer > maxContainer) maxContainer = currContainer;
            
            //Move shortest pointer
            if(height[start] < height[end]){
                start++;
            }
            else if(height[start > height[end]]){
                end--;
            }
            else{   //If both indexes have the same value
                end--;
            }
            
            window--;
        }
        
        return maxContainer;

/*
        //Another solution with just one traversal
        //runtime: O(n)
        //space: O(1)

        //pointer to indexes
        int minIdx = 0;
        int maxIdx = height.size() -1;
        
        //values of indexes
        int minLine = height[minIdx];
        int maxLine = height[maxIdx];
        
        //window
        int window = height.size() -1;
        
        //Set values in case maxLine is shorter than minLine at the beginning
        if(minLine > maxLine){
            minIdx = maxIdx;
            minLine = maxLine;
            
            maxIdx = 0;
            maxLine = height[0];
        }

        //Result variable
        int maxContainer = window * minLine;
        
        //Traverse the array
        while(window > 0){
            
            //Pointer to index with the shortest line
            int idx = minIdx;
            
            //Move to a greater value
            while(height[idx] <= minLine){

                if(minIdx < maxIdx ){
                    idx++;
                }
                else{
                    idx--;
                }
                
                window--;
                
                if(window < 1) break;
            }
            
            //Set variables again 
            if(height[idx] > maxLine){
                minIdx = maxIdx;
                minLine = maxLine;

                maxIdx = idx;
                maxLine = height[idx];
            }        
            else{
                minIdx = idx;
                minLine = height[idx];
            }
            
            //Compare previous container to the new container
            maxContainer = max(maxContainer, window * minLine);
            
        }
        
        return maxContainer;
*/
    }
};

/*
A los 20 minutos ya sabía como lo iba a solucionar
Pero me tarde mucho en sacar la la acción si es que ambos pointer apuntan al mismo valor
    siento que esa parte es la que es relacionada a dynamic programming.
    En total me tarde 43 minutos con pruebas y todo.

Saque una buena solución con O(n+n) runtime. Porque hago 2 traversals de la lista
Pero en overall
    runtime: O(n)
    space: O(1)

    Buena solución, solo debo investigar la parte "dinamica del approach"

*/