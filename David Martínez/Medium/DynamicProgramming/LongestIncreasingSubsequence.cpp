#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
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
*/