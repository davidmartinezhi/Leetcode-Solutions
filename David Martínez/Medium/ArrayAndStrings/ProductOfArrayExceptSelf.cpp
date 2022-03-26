#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        1
        input: int array "nums"
        output: array "answer"
        answer[i] == to the product of all elements of nums except nums[i]
        
        prefix and suffix guaranteed to fit in a 32-bit integer
        
        runtime must be O(n) without using the division operation
        
        nums length between 2 and 100000
        nums[i] betwwen -30 and 30
        
        2
        [1,2,3,4] -> [24,12,8,6]
        [-1, -1, 0, -3, -3] -> [0,0,9,0,0]
        
        3
        have an aux vector
        for each element, traverse again
        multiply that element on each cell except in i
        
        runtime: O(n^2)
        space: O(n)
        
        4
        bottlneck, tener que checar toda la lista, por cada elemento
        
        Tradeoffs
        space
        
        2 auxiliary vector
        one that saves values from left to right
        another from right to left
        
        ans[i] = leftToRight[i-1] * rightToLeft[i+1]
        ans[0] = right[1]
        ans[nums.size()-2]
        
        runtime: O(n)
        memory: O(n)
        
        */
        
        //Runtime: O(n)
        //Memory: O(n)
        /*
        int n = nums.size();
        vector<int> left(n, nums[0]);
        vector<int> right(n, nums[n-1]);
        vector<int> result(n);

        for(int i = 0; i < n; i++){
            if(i != 0){
                left[i] = nums[i]*left[i-1];
            }
            else{
                left[i] = nums[i];
            }
        }
        
        for(int i = n-1; i >= 0; i--){
            if(i != n-1){
               right[i] = nums[i] * right[i+1]; 
            }else{
                right[i] = nums[i];
            }   
        }
        
        result[0] = right[1];
        result[n-1] = left[n-2];
        
        for(int i = 1; i < n-1; i++){
            result[i] = left[i-1] * right[i+1];
        }

        return result;
        */
        
        //Runtime O(n)
        //Space O(1)
        
        //Vector answer
        vector<int> ans = nums;
        
        int product = 1;    //Product
        
        //traverse from left to right
        for(int i = 0; i < nums.size(); i++){
            product *= nums[i]; //Product is multiplied by the value at i
            ans[i] = product;   //value at i is the current product
        }
        
        product = 1;
        //traverse from right to left
        for(int i = nums.size()-1; i > 0; i--){
            ans[i] = ans[i-1] * product;    //Answer at i is equal to his previous values * product
            product *= nums[i];     //Product is multiplied by that value at nums[i]
        }
        
        ans[0] = product;
        
        return ans;
    }
};