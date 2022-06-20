#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        /*
         1. info
            input: 2 strings "s" and "t" of length "m" and "n"
            
            output: minimum window substring of "s" such that every character
                in "t" (including duplicates) is included in the window.
            
                If the string doesn`t exists, return an empty string "".
            
            constraints: length of strings is between 1 and 100,000
                both strings consist of uppercase and lowercase english letters
                
        2. example
        notebook:
            s = "ADOBECODEBANC", t = "ABC"
            -> "BANC"
            
        3. brute force
            for each letter in s, that appears on t.
                traverse the rest of s to look for the remaining letters
            
            time: O(n^2 * m)
            extra space: O(n+m)
            
        4. optimize
            BCR: O(n)
            
            
        7. test
            hotspots:
                check correctness of string traversal s.size - t.size. correct
                check correctnes of substring indexes. correct
                check characters at last index
                
            special cases:
                t bigger than s, return empty string
                t not in s
                t equal to s
        */
        
        //brute force
/*        
        //check if t is bigger than s
        if(t.size() > s.size()) return "";
        
        
        //variables
        string minWindow = s;
        int charsToFind = 0; 
        bool found = false;
        
        //hashtables
        unordered_map<char, int> tHt;
        
        //fill tHt and set chrsToFind
        for(int i = 0; i < t.size(); i++){
            tHt[t[i]]++;
            charsToFind++;
        }

        //traverse the string
        for(int i = 0; i < s.size()-t.size()+1; i++){
            unordered_map<char, int> auxHt = tHt;
            int auxCount = charsToFind;
            
            if(auxHt[s[i]] > 0){
                for(int j = i; j < s.size(); j++){
                
                    if(auxHt[s[j]] > 0){    //Substract if we found a valid char that matches
                        auxHt[s[j]]--;
                        auxCount--;
                    }
                
                    //if we have found all chars, check the substring
                    if(auxCount == 0){
                        found = true;
                        if(minWindow.size() > j+1-i){
                            minWindow = s.substr(i, j+1-i); 
                            break;
                        }
                    }
                }                
            }
        }
        
        if(!found){
            return "";
        }
        
        return minWindow;   
    */
    
    //optimized
        
        //check if t is greater than s
        if(s.size() < t.size()) return "";
        
        //indexes
        int start = 0;
        int end = 0;
        
        //found substr
        bool found = false;
        
        //hashtables for chars frequencies
        unordered_map<char, int> tHt;
        unordered_map<char, int> sHt;
        
        //characters found
        int charsToFind = 0; 
        int charsFound = 0;
        
        //resulting string
        string minWindow = s;
        
        //fill tHt and set chrsToFind
        for(int i = 0; i < t.size(); i++){
            tHt[t[i]]++;
            charsToFind++;
        }
        
        
        while(end < s.size()){
            
            //add the char
            int tAux = tHt[s[end]];
            int sAux = sHt[s[end]];
            
            if(tAux != 0){  //if char exists in t
                
                sHt[s[end]]++;    //add it
                
                if(sAux < tAux){
                    charsFound++;
                }
            }
            
            
            
            //if condition is met
            while(charsToFind == charsFound && start <= end){
                found = true;
                auto tAux = tHt[s[start]];
                auto sAux = sHt[s[start]];     
                
                if(tAux != 0 && tAux == sAux){
                    sHt[s[start]]--;
                    charsFound--;
                    
                }else if(tAux != 0){
                    sHt[s[start]]--;
                }
                minWindow = (minWindow.size() > end+1-start) ? s.substr(start, end+1-start) : minWindow;
                start++;
            }
            
            end++;
        }
        
        if(!found) return "";
    
        return minWindow;    
    }
};