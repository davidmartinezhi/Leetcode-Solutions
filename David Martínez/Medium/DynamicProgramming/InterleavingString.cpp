#include <iostream>
#include <unordered_map>

using namespace std;

/*
info
    input: 3 strings (s1,s2,s3)
    output: true/false in case s3 is formed by an interleaving of s1 and s2
    constraints:
        strings s1 and s2 have length between 0 and 100
        string 3 has length between 0 and 200
        all strings consist of only lowercase english letters
        
example
    s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
    -> true
    
    s1 = "aabcc", s2 = "dbbca"
               i            j
    
    s3 = "aadbbcbcac"
                    k
    
    s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
    ->false
    
brute force
    -send recursively to check each index on both string and if they match with that index at s3 and move pointers
    -if one pointer is at the end, just send the pointer of the other string
    -use hashtable and keys for memoization, to avoid unnecessary calculations
    
    complexity:
        time: O(s1*s2)
        extra space: O(s1*s2*s3)
        
optimize:
    bcr: O(s1+s2+s3)
    
    Since we have to work with permutations of combinations from both strings
    recursivity is clear to give an answer
    
walkthrough

    recursive
    
        set global ht
        
        get lengths
        call recursive function with strings, lengths and strting indexes
        
        base case
        to know if we reached the end
        if(pointer3 == length 3) return (p1 == length 1 && p2 == length 2)
        
        create key for ht
            check if key already exists
                if it already exists, return it
        
        check if we have reached the end on only one pointer
        
        send both pointers to check
        
        return if any of them is true
        
test
    
    empty string
    interleaving is true
    interleaving is false
    
    
        
*/
class Solution {
    
    unordered_map<string, bool> mem;
    
    bool checkInterLeave(string &s1, string &s2, string &s3, int &len1, int &len2, 
                         int &len3, int p1, int p2, int p3){
        
        //check if we have reached the end of s3
        if(len3 == p3) return (p1 == len1 && p2 == len2);
        
        //make key
        string key = to_string(p1) + "*" + to_string(p2) + "*" + to_string(p3);
        //check if key already exists
        if(mem.find(key) != mem.end()) return mem[key];
        
        
        //check if we have reached the end in one of both strings
        //if pointer 1 has reached the end
        if(p1 == len1) 
            //if the char in s2 is the same as s3, keep checking, else return false
            return mem[key] = 
            (s2[p2] == s3[p3]) ? checkInterLeave(s1, s2, s3, len1, len2, len3, p1, p2+1, p3+1): false;
        
        if(p2 == len2) 
            //if the char in s1 is equal to char in s3, keep checking, else return false
            return mem[key] = 
            (s1[p1] == s3[p3]) ? checkInterLeave(s1, s2, s3, len1, len2, len3, p1+1, p2, p3+1): false;
        
        //if no pointer has reached the end, and the value has not been seen before
        bool one = false, two = false;
        
        //check if char in s1 is the same as the one in s3
        if(s1[p1] == s3[p3])
            one = checkInterLeave(s1, s2, s3, len1, len2, len3, p1+1,p2,p3+1);
        
        //check if char in s2 is the same as the one in s3
        if(s2[p2] == s3[p3])
            two = checkInterLeave(s1, s2, s3, len1, len2, len3, p1,p2+1,p3+1);  
        
        return mem[key] = (one || two);
        
    }
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        //declare variables
        
        //lengths
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        
        //check if operation can be made
        if(len3 != (len1+len2)) return false;
        
        return checkInterLeave(s1, s2, s3, len1, len2, len3, 0, 0, 0);

    }
};