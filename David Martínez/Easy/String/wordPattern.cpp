#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        /*
        info
            input: string "pattern" and string "s"
            follow means a full match, such that there is a bijection between a letter in pattern
            and a non-empty word in "s".

            output: tue if s follows pattern, else false

            conatraints:
                * what range of sizes can the pattern have? [1, 300]
                * what range of sizes can "s" have? [1, 3k]
                * what characters can "s" have? only lowercase english letters
                * does s contain any leading or trailing white space? no
                * are all words in s separated by a single space? yes

        example
            pattern = "abba", s = "dog cat cat dog"
            -> true

            {
                "dog" : "a",
                "cat" : "b"
            }
            {
                "a": "god",
                "b": "cat"
            }

            pattern = "abba", s = "dog cat cat fish"
            -> false

            {
                "dog" : "a",
                "cat" : "b"
            }
            {
                "a": "god",
                "b": "cat"
            }

            pattern = "aaaa", s = "dog cat cat dog"
            -> false

        brute force
        get all words into an array of words

        example 1
        ["dog", "cat", "cat", "dog"]
        pattern = "abba"

        check if word does not already exists
        check if letter does not already exists


            {
                "dog" : "a",
                "cat": "b"
            }
            {
                "a": "dog",
                "b": "cat"
            }

        example 2
        ["dog", "cat", "cat", "fish"]
        pattern = "abba"

        if they already exists check that there exists bijection 
            word is that letter
            and letter is that word

            else return false

        check if letter does not already exists
            if word exists, return false
            else add word to letter and letter to word

        check if word does not already exists, 
            if letter exists, return false
            else add word to letter and letter to word

        -> false

            {
                "a": "dog",
                "b": "cat"
            }
            {
                "dog": "a",
                "cat": "b"
            }

        complexity: 
            runtime: O(string length + pattern length)
            extra space: O(n*3) -> O(n)

    optimze
        best conceivable runtime: O(patttern length + stringn length)

        I think my algorithm is optimal in runtime, and memory
        because we need to keep track of mapping between words and pattern

    test
        * string matches pattern
        * pattern does not match string
        * pattern of length 0
        * string of length 0
        */

        //get lengths
        int patternLength = pattern.size();

        //declare variables
        vector<string> words = buildArrayOfWords(s); //get array of words in string separated by " "
        unordered_map<string, char> wordToLetter;
        unordered_map<char, string> letterToWord;

        //check length of pattern and words
        if(words.size() != patternLength) return false;

        //traverse pattern
        for(int i = 0; i < patternLength; i++){

            //get word adn letter
            char letter = pattern[i];
            string word = words[i];

            // Search once and store the iterator
            auto wordToLetterIt = wordToLetter.find(word);
            auto letterToWordIt = letterToWord.find(letter);

            //check if letter and word already exist
            if(wordToLetterIt != wordToLetter.end() && letterToWordIt != letterToWord.end()){
                //check bijection
                if(wordToLetter[word] != letter || letterToWord[letter] != word) return false;
            }
            //check if letter does not exists
            else if(letterToWord.find(letter) == letterToWord.end()){
                //check if word exists
                if(wordToLetterIt != wordToLetter.end()) return false;
                else{
                    wordToLetter[word] = letter;
                    letterToWord[letter] = word;
                }
            }
            //check if word does not exists
            else if(wordToLetter.find(word) == wordToLetter.end()){
                //check if letter exists
                if(letterToWordIt != letterToWord.end()) return false;
                else{
                    wordToLetter[word] = letter;
                    letterToWord[letter] = word;
                }
            }
        }

        return true;
    }

    vector<string> buildArrayOfWords(string & s){

        //declare variables
        int sLenght = s.size();
        vector<string> words;
        string word = "";

        //traverse s to get words
        for(int i = 0; i < sLenght; i++){

            //building string word
            if(s[i] != ' '){
                word += s[i];
            }
            //adding word to array
            else{
                words.push_back(word);
                word = "";
            }
        }

        //add last word
        words.push_back(word);

        return words;

    }
};

// 41 minutes