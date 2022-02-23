#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        /*
        input: binary array nums
        output: maximum number of consecutive ones in the array
        
        nums length betwwen 1 and 100,000
        
        example:
        
            [1, 1, 1, 0, 1]
            result: 3
            
        brute force:
        
            runtime: O(n)
            memory: O(1)
            
            maxCount
            currCount
            
            recorro el array si es un 1, sumo uno a currCount, 
            si es 0 la cuenta es 0 y comparo el currenteCount con el maxCount
            
        optimize:
            El brute force es bastante eficiente
            Usaria dynamic window technique, pero sienteo que no es necesario
            
        test:
            array con puros 0
            array con puros 1
        
        */
        
        int maxCount = 0;
        int currCount = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){   //Si encuentro un 1
                currCount++;    //Sumo uno al currCount
            }
            else{   //Si encuentra 0
                if(currCount > maxCount){   //si currCount es mayor a maxCount
                    maxCount = currCount;   //Ahora ese es el valor de maxCount
                }
                currCount = 0;  //CurrCount regresa a ser 0
            }
        }
        
        //Compara currCount por ultima vez
        if(currCount > maxCount){
            maxCount = currCount;
        }
        
        return maxCount;
    }
};

/*
Terminado en 11 minutos
    -Primer pensamiento fue en hacerlo con dynamic window technique pero resultó ser inecesario
    -Muy buen performance
*/