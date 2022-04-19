#include <iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
    /*
        input: sting "s"
        output: number of palindromic substrings in the string
        
        string consists of only lower-case english letters and length between 1 and 1,000
        
        palindrome, string that reads the same fowards and backwards
        
        example:
            "abc" -> 3
            "aaa" -> 6
            
            "ababacd"
            
        brute force:
            for each char, chech the rest of chars and see if they are palindrome
            runtime: O(n^3) on traversal and check if palindrome
            space: O(1)
            
        optimize:
            check for odd length palindrome
                if both ends are the same, add to count
                
            check for even length palindrome
                if both ends are the same, add to count
                
            runtime: O(n^2)
            space: O(1)
            
        test:
            palindrome of odd size
            palindrome of even size
    */
        
        //size
        int n = s.size();
        
        //count
        int substrings = 0;
        
        //check odd size palindrome
        for(int i = 0; i < n; i++){
            int j = i;
            int k = i;
            
            while(j >= 0 && k < n && s[j] == s[k]){
                substrings++;
                k++;
                j--;
            }
        }
        
        //check even size palindrome
        for(int i = 0; i < n-1; i++){
            int j = i;
            int k = i + 1;
            
            while(j >= 0 && k < n && s[j] == s[k]){
                substrings++;
                k++;
                j--;
            }
        }
        
        return substrings;
    }
};