#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

//2022
    /*
    int lengthOfLIS(vector<int>& nums) {
        
        //declare aux vector for dp
        vector<int> aux(nums.size(), 1);
        
        //declare varibale for longest subsequence
        int longest = 1;
        
        //traverse the array
        for(int i = 1; i < nums.size(); i++){
            
            //traverse from first index to i
            for(int j = 0; j < i; j++){
                
                //if the front index is bigger, and it has a shortest or equal subsequence count
                //counts how many numbers in front are smaller. if they have a greater increasing subsew
                    //add their increasing subseq + 1
                if(nums[i] > nums[j] && aux[i] <= aux[j]){
                    aux[i] = aux[j] + 1;    //add the subsequence of the smaller number and add 1
                    
                    longest = max(longest, aux[i]); //save the number of longest subsequence
                }
            }
        }
        
        //return longest subsequence
        return longest;
    }
    */

//2023
    int lengthOfLIS(vector<int>& nums) {
        /*
        info
            input: integer array "nums"
            output: length of longest strictly increasing subsequence
            constraints: 
                * array length in range 1 and 2500
                * nums[i] values in range -10,000 and 10,000
                
        example
           nums = [10,9,2,5,3,7,101,18] 
           -> 4
           
           nums = [0,1,0,3,2,3]
           -> 4
           
           nums = [7,7,7,7,7,7,7]
           -> 1
           
        brute force
            dynammic programming
            
            nums = [0,1,0,3,2,3]
            
            dp = [1,2,2,3,3,4]
            
            complexity:
                runtime: O(n^2)
                extra space: O(n)
                
        walkthrough
        
            for each number
                traverse previous numbers
                    if(value in array is lesser than current value)
                        value in dp array is max of currValue idx and value at position of value + 1
                        if value bigger than max value, last index is maxValue
                        save max value at last index
                        
        
        test
            *Carry max value
            *Don't carry max calue
        
        */
        
        
        /*
            nums = [0,1,0,3,2,3] 
            dp =   [0,1,0,2,2,3]
            maxValue = 2
        
        */
        
        
        //declare variables for dp
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxValue = 1;
        
        //traverse original array
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){ //traverse previous values before current idx
                if(nums[j] < nums[i]){ 
                    dp[i] = max(dp[j]+1, dp[i]);
                    maxValue = max(dp[i], maxValue);
                }   
            }
        }
        return maxValue;
    }
};

/*
Notas:
    Time: 45+

    complexity
        time: O(n^2)
        extra space: O(n)

    Tuve la idea de un approach que también servía en tiempo O(n^2) y extra space O(n)
    Entonces estuvo bien la intuición. Solo me falto la ejecución en ese algoritmo

    La solución es muy simmilar a la solución de coinchange cuando usas memoria O(n)
    Debería de observar ambos patrones para identificarlos mejor. Hacer matríz o no

    En coin change, quería checar todas las monedas siempre, por eso el segundo loop es hasta el final
    En increasing subsequence, solo es, hasta el index actual. por eso esa es la diferencia.

    Debería de repasar dp y hacer una lista pequeña de patrones importantes y el setup



8 meses despues volcí a ver este problema y lo resolví en 20 minutos.
El concepto lo entendói bien y la solución quedo aún más limpia.
A seguir trabajando.
*/