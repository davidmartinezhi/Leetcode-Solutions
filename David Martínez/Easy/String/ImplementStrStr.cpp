#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        //1 listen
            //Return the index of the first ocurrance of needle in haystack
            //If needle isn't in haystack, return -1
            //If needle is an empty string, we return 0
            //Haystack and needle sizes, ranges between 0 and 50,000
        
        //2 example
            // haystack: "hello", needle: "ll" -> 2
            // haystack: "abbccdcdcdcd", needle: "cd" -> 4
            
        //3 brute force
            //Sliding window tecnique and when the substring matches, we return the index.
            //Memory: O(1)
            //Runtime: O(n)

        //4 optimize
            //BCR O(n)
            //If the string was sorted, we could use binary search
                
        
        //5 walkthrough
            //Get size of needle, to create the window
            //If size of needle is 0, return 0
            //Compare it to the haystack size, if neddale is bigger, we return -1
            //Traverse the haystack in search for the needle
                //If found, we return the index
            //If not found, return -1
        
        //6 implement
            //Siento que con pointers, podría no tener que usar el for loope
        
        //7 test
            //needle not in haystack
            //needle in haystack
            //Special cases:
                //Haystack empty
                //needle empty
                //Haystack is smaller than needle
        
            //To do:
                //Double check the condition in for loop
        
        //Eficiencia de runtime: O(n*window)
        //Eficiencia memoria: O(1)

        
        int window = needle.size();
        
        //Check if needle is empty
        if(window == 0){ return 0; }
        
        //Check if needle is bigger than the haystack
        if(window > haystack.size()){ return -1; }
        
        //Traverse the string
        for(int i = 0; i <= haystack.size() - window; i++){
            //I coul just do a loop inside this one, 0 < window. and compara haystack[i] and needle[j]
            
            //To optimize I could just check for characters who start with the same letter as window
            if(haystack[i] == needle[0]){
                //If the substring is found
                if(isSubstring(haystack, needle, i, i + window)){
                    return i;   //Return index
                }                
            }
        }
        
        return -1;  //If needle not found, return -1
        
        //"stringtest"
        //"ri"
        //

    }
    
    //Helper funciton to traverse substring
    bool isSubstring(string & haystack, string & needle, int & start, int  end){
        int i = start;
        int j = 0;
        
        while(i < end){
            if(haystack[i] != needle[j]){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};