#include <iostream>

using namespace std;


class Solution {
public:

    bool isVowel(char & c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' ||c == 'u') return true;
        return false;
    }

    int maxVowels(string s, int k) {
        /*
        info
            input: string "s" amd integer "k"
            output: maximumm number of vowel letters in any substring of "s" with length "k"
            constraints:
                *string length is in range 1 and 100,000
                *s consists f lowercase english letters
                *k is in range 1 and s.length


        example

            s = "abciiidef", k = 3
            -> 3

            s = "aeiou", k = 2
            -> 2

            s = "leetcode", k = 3
            -> 2

        
        brute force
            for each letter

                traverse k and count vowels
                
                compare current vowels with maxVowels

                if maxVowels equal to k, return k

            
            complexity:
                runtime: O(n*k)
                extra space: O(1)

        
        optimize
            best conceivable runtime: O(n)

            Can I optimize runtime?

                *sliding window technique

            

            s = "abciiidef", k = 3
            -> 3

            complexity:
                runtime: O(n)
                extra space: O(1)

        walkthrough
         declare variables
         windows, current count and max count

         traverse end window to reach k-1 position while counting vowels

         traverse array
            is start is vowel, substract from current
            move pointers
            if end is vowel, add to current count

            compare

        test
           * substring contains k vowels
           * s contains no vowels
        
        */


        /*
        s = "abciiidef", k = 3

        int maxCount = 3;
        int currCount = 2;

        //pointers
        int startW = 4;
        int endW = 7;
        */

        //declare variables

        //counters
        int maxCount = 0;
        int currCount = 0;

        //pointers
        int startW = 0;
        int endW = 0;

        //traverse end Window to k-1 position
        while(endW < k){
            if(isVowel(s[endW])) currCount++;
            endW++;
        }

        //assign current count as max count
        maxCount = currCount;

        //traverse the rest of the string
        while(endW < s.size()){

            //check if startWindow is a vowel
            if(isVowel(s[startW])) currCount--;

            //move both pointers
            startW++;

            //check if end window is a vowel
            if(isVowel(s[endW])) currCount++;


            //update maxCount
            maxCount = max(currCount, maxCount);

            endW++;
        }

        return maxCount;

    }
};

/*
Time: 25 minutes
Complexity.
    runtime: O(n)
    extra space: O(1)

Me sentí muy comodo y veloz al hacer la solución.
Tener un whiteboard si es de demasiada ayuda al momento de tener una soluci´n
Debería practicar hacer las cosas sin whiteboard para acostumbrarme o poder hacerlo
y seguir dandome a entender. En el caso de no tener un whiteboard en la entrevista.
Porque poder garabatear me ayuda mucho a sacar una solución rapido.

*/