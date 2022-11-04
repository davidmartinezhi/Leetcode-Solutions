/*
Act2.1

1)
    Finds if a pattern "P" exists inside a text using hashstrings.
    Program must convert the pattern and each word inside the text in their hash string equivalent.
    See if pattern matches with any Hash strings in the text

2)
    Search all appearances of the pattern using KMP or z function.

Input:
    string pattern
    Text

Output:
    Found Positions must be displayed on console. One for each line
    Especifying the number of line, starting index of pattern and ending index pattern


El texto a procesar deberá ser cualquier archivo de texto (extensión .txt).
El nombre de este archivo de texto debe ser enviado por la línea de comandos (./a.out < in.txt).
Text only contains lowercase letters of the english alphabet
(a, b, c, d, e , f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z).


David Gerardo Martínez Hidrogo - A01235692
Humberto Ricardo Rodriguez Ruán - A01197898
Last modified: October 4 2022
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>
using namespace std;

// string hash

/*
Create hash key for strings
Receives a string and converts it into a double value

complexity
    time: O(m), m being the size of the string
    extra space: O(1)
*/
double toHash(string word)
{

    int g = 31;      // prime number, helps avoid collisions
    double hash = 0; // hash value

    // traverse the word
    for (int i = 0; i < word.size(); i++)
    {
        hash = g * hash * +((int)word[i]); // create hash function
    }

    return hash;
}

/*
Finds if the pattern exists inside the text
Receives an array of the words in the text and returns if the pattern exists (true/false)

complexity
    time: O(m), m being all chars in the text
    extra space: O(n), n being all the words in the text
*/
bool patternExists(vector<string> &textWords)
{

    unordered_set<double> hash;
    double pattern = toHash(textWords[0]);

    // get hash value for each word in text. First word is the pattern
    for (int i = 1; i < textWords.size(); i++)
    {
        double convertion = toHash(textWords[i]);

        // check if hash value of word exists
        if(convertion == pattern) return true;

        hash.insert(convertion);
    }

    
    if (hash.find(toHash(textWords[0])) != hash.end())
        return true;

    return false;
}

// kmp

/*
Creates List with Preffix and Suffix matches
Receives a string and creates a list with preffix-suffix matches

complexity
        time: O(m), m being the size of the string
        space: O(m), m being the size of the string
*/
vector<int> ListPreffixSuffix(string &str)
{

    vector<int> lps(str.size());

    int prev = 0;

    //traverse the string
    for (int i = 1; i < str.size(); i++)
    {

        // match between suffix and preffix
        if (str[i] == str[prev])
        {
            lps[i] = prev + 1;  //insert match value
            prev++;
        }
        // no match
        else
        {

            // prev is 0 = 0 matches
            if (prev == 0)
            {
                lps[i] = 0;
            }
            else
            { // return to previous match
                prev = lps[prev - 1];
                i--; // decrease i to check the char with the new value
            }
        }
    }

    return lps;
}

/*
Traverses each line in the text and prints where pattern is found
Receives the lines of text and the pattern we are looking for

complexity
    time: O(n+m), n being all the chars in the text and m being the size of pattern
    extra space: O(m), m being the size of the pattern
*/
void searchPattern(vector<string> &text, string &pattern)
{

    // prefix-suffix pattern list
    vector<int> lps = ListPreffixSuffix(pattern);

    // check text, line by line
    for (int line = 0; line < text.size(); line++)
    { 

        int prev = 0;

        // traverse all characters in the line
        for (int i = 0; i < text[line].size(); i++)
        {

            // match
            if (text[line][i] == pattern[prev])
            {
                prev++;
            }
            // no match
            else
            {

                if (prev != 0)
                { // if we are not at first index
                    prev = lps[prev - 1];
                    i--; // check char with new char
                }
            }

            // check if we have found the pattern
            if (prev == pattern.size())
            {
                cout << line << " " << i - prev + 2 << " " << i + 1 << endl;
                prev = 0;
            }
        }
    }
}

/*
Finds if a pettern exists in a text and displays where it appears on the text

complexity
    time: O(m+n), n being all chars in the text and m being the chars on pattern
    extra space: O(k), k being the words in the text
*/
int main()
{
    // declare variables
    string pattern;           // pattern
    vector<string> text;      // text lines
    vector<string> textWords; // text words

    string aux;    // auxiliary string

    // Get Text lines
    cin >> pattern; // pattern to find

    while (getline(cin, aux))
    {
        istringstream iss(aux);
        text.push_back(aux);
    }


    // Get Text words
    textWords.push_back(pattern);

    for(int i = 0; i < text.size(); i++){
        aux = "";
        for(int j = 0; j < text[i].size(); j++){
            if(text[i][j] == ' '){
                textWords.push_back(aux);
                aux = "";
            }else{
                aux += text[i][j];
            }
        }
    }

    // If pattern exists
    if (patternExists(textWords))
    {
        // search all appearances of pattern in the text
        searchPattern(text, pattern);
    }

    return 0;
}
