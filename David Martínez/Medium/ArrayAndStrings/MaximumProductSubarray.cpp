#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
        1. listen
            input: int array "nums"
            
            -Find the contiguous non-empty subarray that has the largest product
            -subarray is a contiguous subsequence of the array
            
            output: product
            
            answer will fit in a 32-bit integer
            
            array "nums" size ranges from 1 to 20,000
            nums[i] value ranges from -10 to 10
            
            Maybe I could use a kadane's algorithm?
            
        2. example
        
            [1, 2, -2, 4, 5]
            product: 20
            
            [2, 3, -2, 4]
            product: 6
            curr: 6
            
            [-2, 0, -1]
            product: -2
            curr: -2
        
        3. brute force
        
            sliding window technique with a dynamic window
            
            time: O(n^2)
            space: O(1)
        
        4. optimize
        
            traverse the entire array with kadane's algorithm
            runtime: O(n)
            space: O(1)
        
        5. walkthrough
            
            - initialize a maxProsuct variable
            - initialize a currProduct variable
            
            - traverse the array
                curr Product * nums[i]
                if currProduct is greater than maxProduct
                    maxProduct is currProduct
                if currProduct < 0
                    set it to 1

                
        
        6. implement
        
        7. test
            input array of size 1
            product that multiplied gives me a positive number
            
        */
        
        //initialize variables. space: O(1)
        int maxProduct = INT_MIN;
        int currProduct = 1;
        
        // traverse fowards. time: O(n)
        for(int i = 0; i < nums.size(); i++){
            //add product
            currProduct *= nums[i];
        
            //check if curr is greater
            if(currProduct > maxProduct) maxProduct = currProduct;
        
            //check if currProduct is cero, and set it to 1    
            if(nums[i] == 0){
                currProduct = 1;
            }
        }
        
        currProduct = 1;
        
        // traverse backwards. time: O(n)
        for(int i = nums.size() - 1; i >= 0; i--){
            //add product
            currProduct *= nums[i];
        
            //check if curr is greater
            if(currProduct > maxProduct) maxProduct = currProduct;
        
            //check if currProduct is cero, and set it to 1    
            if(nums[i] == 0){
                currProduct = 1;
            }            
        }
        
        return maxProduct;

/*
        //Solution from youtube
        
            //tener variablemaxProduct
            //tener variable max-end y min-end
            //siempre comparo el numero actual, mex-end y min-end
            
            //Así siempre se el valor 
        
        int maxProduct = nums[0];
        int maxEnd = nums[0]; 
        int minEnd = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            //Recorres

            int temp = maxEnd; 
            
            //Sacas el valor mayor entre el numero actual, el más pequeño y el más grande
            maxEnd = max(nums[i], nums[i] * maxEnd);
            maxEnd = max(maxEnd, nums[i] * minEnd);


            //Sacas el valor menor entre el numero actual, el más pequeño y el más grande
            minEnd = min(nums[i], nums[i] * minEnd);
            minEnd = min(minEnd, nums[i] * temp);
            
            //Del valor más grande, lo comparas con el producto maximo
            maxProduct = max(maxProduct, maxEnd);
            
        }
        
        return maxProduct;

*/

    }
};

/*
nota:

    Complejidad
        time: O(n)
        space: O(1)

    -Kadane's algorithm era el truco en este problema
    -Saque la respuesta para numeros positivos en 18 minutos, 
        pero me tarde 39 minutos en total para que funcionara con cualquier tipo de numero

    -Con los test cases que hice, pude darme cuenta de hacer un recorrido en reversa era buena opción

    -Se que funciona y con los test cases me di cuenta que funciona, pero no estoy seguro sobre como explicaría que si funciona

    - Sin kadane's algorithm, nose que habría hecho, es bueno ser constante con la practica. Saque el problema en buen tiempo
        si se siente la mejora con los meses y con los nuevos conceptos vistos.

    - Invertir un poco más de tiempo en crear los test cases sería una buena opción.

Intento de explicación para el movimiento hacía adelante y hacía atras

    If the first number is negative, it has a lot of influence on the total product of the traversal
    If the current number is 0, the product is set to the next number and starts multiplying again, else everything will be 0


*/