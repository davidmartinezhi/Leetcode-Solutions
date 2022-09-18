#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    vector<int> ListPreffixSuffix(string str){
        
        //create array for preffix-suffix matches
        vector<int> LPS(str.size(), 0);
        /*
        //traverse the string
        int i = 1;
        int j = 0;
        
        
        //traverse the string
        while(i < str.size()){
            
            //if letters match
            if(str[i] == str[j]){
                LPS[i] = j + 1; //we add matches + 1
                j++;    //update matches
                i++;    //move pointer to next char
            }
            //if letters don't match
            else if(str[i] != str[j]){
                
                //check if j is at 0
                if(j == 0){
                    LPS[i] = 0; //set that cell as 0, there are no matches
                    i++;
                }else{
                    j = LPS[j-1];   //set that cell as the value in the index of the previous value of j
                }
                
            }
        }
        */
        
        //value is the number of matches
        int prev = 0;
        
        //traverse the needle
        for(int i = 1; i < str.size(); i++){
            
            //match
            if(str[i] == str[prev]){
                LPS[i] = prev+1;    //add matches count + 1
                prev++; //update matches count
            }
            //no match
            else{
                if(prev == 0){  //if we are at 0 matches
                    LPS[i] = 0; //set value at i as 0
                }
                else{   //if we are not at 0 matches
                    prev = LPS[prev-1]; //return to previous match index
                    i--;    //decrease i, to check the char again with ne new value
                }

            }
        }
        
        
        return LPS;
    }
    
    int strStr(string haystack, string needle) {
        
        //declare variable for pattern matching
        int j = 0;
        
        //create list of preffix suffix pattern matching
        vector<int> LPS = ListPreffixSuffix(needle);
        
        //traverse haystack to find needle
        for(int i = 0; i < haystack.size(); i++){
            
            if(haystack[i] == needle[j]){ //match
                j++;    //update pointer of matches found
            }
            else{             //no match
                if(j != 0){ //if we are not at initial index
                    j = LPS[j-1];   //go to end of preffix
                    i--;    //substract i, to compare char with the new char
                }
            }
            
            //check if we have found the answer
            if(j == needle.size()) return i - j + 1;
        
        }
 
        return -1;
    }
};

/*
Conseguido ver logica y programarlo por mi cuenta
Me gusto el tener un mejor comprendimiento del algoritmo y entender a profundidad su funcionamiento

complexity
    time: O(n+m)
    extra space: O(m)
*/