#include <iostream>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        /*
        info
            input: string "s" consisting of words
            output: length of the last word in the string
            constraints:
                * what type of chars can the string contain? english letters and space ' '
                * what range of sizes can "s" have? [1, 10k]
                * what range of sizes can the las word have? [1, 10k]
                * there will be at least one word in s

        example
            s = "Hello World"
            -> "World" = 5

            s = "   fly me   to   the moon  "
            -> moon = 4

            s = "HelloWorld   "

        brute force
            start from end
            have a flag to know when we have reached a character
            have pointer to first character found

            if we find white space and character has been found
            return substring length of substring from i+1 to firstcharacter found+1

            if we traverse all the string return size of substr of 0 to found+1

            complexity:
                runtime: O(n)
                extra space: O(1)

        optimize
            best conceivable runtime: O(n)

        test
            * string contains one word and no white spaces
            * last word starts from 0 to another value inside the body
            * last word startf from the body until last index

            hotspot:
                check if i shoul return begin + i+1 or just begin + i
        */

        //get size
        int n = s.size();

        //check size 1
        if(n == 1 && s[0] != ' ') return 1;
        else if(n == 1 && s[0] == ' ') return 0;

        //declare variables
        int firstCharFound = INT_MAX;

        //traverse string backwards
        for(int i = n-1; i >= 0; i--){

            //check if we have found first char
            if(s[i] != ' ' && firstCharFound == INT_MAX){
                firstCharFound = i;
            } 
            
            //check if we reach white space and have allready found first char
            if(s[i] == ' ' && firstCharFound != INT_MAX){
                return firstCharFound-i;
            }

        }
        /*
        "   fly me   to   the moon  "
        firstChar = 24
        i = 20
        

        */

        return firstCharFound+1;
    }
};

//23 minutes
/*
time: 23 minutes
complexity:    
    runtime: O(n)
    extra space: O(1)

I struggled a little with some hotspots, but I was able to solve it
I should try to stop and think about some logic that is making some noise and
try to explain graphically what is happening
*/