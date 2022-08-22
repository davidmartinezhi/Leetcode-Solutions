#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        /*
        info
            input: string "s" containing only digits
            output: number of ways to decode it
            constraints:
                -string length is between 1 and 100 chars long
                -string contains only digits and may have 0s
                -test cases fit 32-bit integers
                
        example
        
            s = "12"
            -> 2
            
            s = "226"
            -> 3
            
            s = "06"
            -> 0
            
        Brute force
            backtracking to get single digits and composed digits, numbers
            time complexity: O(2^n)
              
        Optimize
            Dynammic Programming, memoization to avoid repeating calculations
            best case running time:
                O(n)
        
        walkthrough
            base cases
                empty string
                digit starts with 0
            recursive call for one digit
            recursive call for 2 digits
        
        test
            empty string
            0 at the beginning
            0 in the middle
            
            check toInt function
            
        */
        
        vector<int> aux(s.size()+1, -1); //memoization array
        return helper_dp(s, s.size(), aux);
    }
    
    int helper_dp(string s, int k, vector<int> & aux){
        
        //base cases
        //empty string
        if(k == 0) return 1;
            
        //digit starts with 0
        int i = s.size() - k;
        if(s[i] == '0') return 0;
        
        //digit has already been calculated
        if(aux[k] != -1) return aux[k];
        
            
        //recursivity
        int result = helper_dp(s, k-1, aux);
        
        if(k >= 2 && toInt(s.substr(i,i+2)) <= 26){
            result += helper_dp(s, k-2, aux);
        }
        
        aux[k] = result;
        return result;
        
    }
    
    int toInt(string s){
        int result = 0;
        
        for(int i = 0; i < 2; i++){
            result = (result*10) + (s[i] - '0');
        }
        
        return result;
    }
};

//45+ minutes