#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        /*
        info
            input:
                * strng "s"

            output:
                * reverse order of words
                * should only have single space separating the words

            constraints:
                * what range of sizes can s have? [1, 10k]
                * what type of chars can s have? english letters, digits and spaces
                * there is at least one word

        example
            s = "the sky is blue"
            -> blue is sky the

            s = "  hello world  "
            -> world hello

        brute force
            traverse the array to get all words and store them in an array
            then concatenate the words in a result is reverse order
                traversing the array backwards

            complexity:
                runtime: O(n)
                extra space: O(n)

        optimize:
            best conceivable runtime: O(n)
            can i improve memory? I think yes but while traversing backwards

        test
            * reverse two words 
            * reverse multiple words
        */

        //get size
        int n = s.size();

        //declare variables
        string wordsReversed = "";
        int wordEnd = INT_MAX;
        int fisrtWordIdx = 0;
        /*
            s = "  hello world  "
                        i
                             e
        */

        //find first word idx
        for(int i = 0; i < n; i++){
            if(s[i] != ' '){
                fisrtWordIdx = i;
                break;
            } 
        }

        //traverse backwards
        for(int i = n-1; i >= 0; i--){

            //if we beggin a word, set wordEnd
            if(s[i] != ' ' && wordEnd == INT_MAX){
                wordEnd = i;
            }

            //if we end a word update word end and get previous word
            if(s[i] == ' ' && wordEnd != INT_MAX){
                wordsReversed += s.substr(i+1, wordEnd-i);
                wordEnd = INT_MAX; //update word end

                if(i > fisrtWordIdx){
                    wordsReversed += " ";
                }
            }
        }

        if(s[0] != ' '){
            wordsReversed += s.substr(0, wordEnd+1);
        }

        return wordsReversed;
    }
};

//16 minutes

/*
time: 16 minutes

complexity:
    runtime: O(n)
    extra space: O(n) the size of the result

I did it fast, but only because I had discovered with the previous problem
how to slice efficiently the strings.

Should still try to display graphically on real time with an example how
the code is working.
*/