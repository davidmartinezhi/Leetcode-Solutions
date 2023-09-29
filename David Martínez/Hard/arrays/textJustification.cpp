#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        /*
        info
            input: array of string "words" and int "maxWidth"
            output: array of strings

                * pack as many words as possible in each line

                * pad extra space ' ' when necessary so each line has length of maxWidth

                * extra space between words should be distributed as evenly as possible

                * if # of spaces on a line does not divide evenly between words,
                 empty slots on the left should be assigned more spaces than the slots on the right

                * last line of text is left justified, and no extra space is inserted between words

            constraints:
                * how many words can the array contain? [1, 300]
                * what range of sizes can each word have? [1, 20]
                * what type of characters can each character have? english letters and symbols
                * what range of values can maxWidth have? [1, 100]
                * legth of waord will always be smaller or equal to maxWidth

        example
            words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
               [0123456789,10,11,12,13,14,15,16]
                This
                     is
                        an

                        16 - 8 = 8 white spaces
                        traverse each word to be inserted and add ' ' * white spaces number / words-1

                        if its odd, first word receives one extra white space

                        if we reached the end of words
                            insert all words whit just a white space and add the rest as white space
  
            ->[
               ["This    is    an"],
               [""]
            ]

        brute force
            traverse words array : 0(n*m) character*word
            if word fits in maxWidth, add word to words to be inserted
                get size of all words
                get whitespaces to add maxWidth-length of words to add 

                if odd, mark flag

                if we are at end: O(n)
                    traverse words to add
                        insert word and whitespace

                    fill the rest with whitespace
                else
                    traverse words to add
                        insert word 
                        if flag add 1 whitespace and turn off flag

                        add corresponding whitespaces

            complexity
                runtime: O(char*word)
                extra space: O(words)

        optimize

            best conceivable runtime: O(n*m) char*word

            brute force solution is greedy and optimal

        test
            * all words have maxWidth
            * each word is one char
            * odd number of whitespaces to distribute
            * even number of whitespaces to distribute
        */
        vector<string> result;
        int i = 0, n = words.size();
        
        while (i < n) {
            int length = 0;
            int last = i;
            
            // Determine how many words fit on this line
            while (last < n && length + words[last].length() + (last - i) <= maxWidth) {
                length += words[last].length();
                last++;
            }
            
            // Calculate the number of spaces needed
            int totalSpaces = maxWidth - length;
            
            // Initialize the line with the first word
            string line = words[i];
            
            // If this is the last line or there's only one word on this line,
            // left-justify and add all remaining spaces at the end.
            if (last == n || last - i == 1) {
                for (int j = i + 1; j < last; ++j) {
                    line += ' ' + words[j];
                }
                line += string(maxWidth - line.length(), ' ');
            }
            else {
                // Otherwise, distribute the spaces as evenly as possible
                int spaces = totalSpaces / (last - i - 1);
                int extraSpaces = totalSpaces % (last - i - 1);
                
                for (int j = i + 1; j < last; ++j) {
                    line += string(spaces + (j - i <= extraSpaces ? 1 : 0), ' ');
                    line += words[j];
                }
            }
            
            result.push_back(line);
            i = last;
        }
        
        return result;
    }
};
