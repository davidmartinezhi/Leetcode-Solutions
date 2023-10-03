#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*
        info
            input:
                - string "s" and string "t"

            output:
                - true if "s" is a subsequence of "t", otherwise false

                - a subsequence is a new string formed from the original string
                  by deleting some characters without disturbing the relative positions
                  of the remaining charactes

            constraints:
                - what type of characters can the strings contain? lowercase english letters
                - what range of sizes can i expect from "s" and "t"? s=[0,100], t=[0,1k]
                - will "s" always be shorter than "t"? i dont know

        example
            s = "abc", t = "ahbgdc"
                    i             i
            -> true

            s = "axc", t = "ahbgdc"
                  i               i
            -> false

        brute force
            have pointer to first index of "s", pointer only moves if letter is found
            on each letter of "t", if the letter is the initial character of "s"
                traverse the rest of "t"
                each time a letter is the same between "s" and "t", move pointer of s
                if we reach the end of "s", return true

            return false

            complexity:
                runtime: O(n^2)
                extra space: O(1)

        optimize
            best conceivable runtime: O(n)

            can i improve de runtime: yes
            maybe a dynammic sliding window?
            s = "abc", t = "aabgdc"

            traverse once and have fixed pointer in "s" that moves when the letter is found


        test
            - "s" is greater in size than "t"
            - is subsequence
            - is not subsequence
        */

        //get sizes
        int n = t.size();
        int m = s.size();

        //check if strings are empty
        if(n == 0 && m == 0) return true;

        //check if "s" is greater in size
        if(m > n) return false;

        //declare variables
        int sIdx = 0;

        /*
        s = "abc", t = "ahbgdc"
        n = 6
        m = 3
        sIdx = 3
        i = 5

        */

        //traverse "t"
        for(int i = 0; i < n; i++){

            //if they are the same letter
            if(s[sIdx] == t[i]) sIdx++;

            //check if we found subsequence
            if(sIdx == m) return true;
        }

        return false;
    }
};