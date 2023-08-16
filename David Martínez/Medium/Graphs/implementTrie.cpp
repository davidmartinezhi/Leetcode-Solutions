#include <iostream>
#include <vector>

using namespace std;

struct Node{
    char c;
    int ends;
    vector<Node*> childs;

    Node(): c('0'), ends(0), childs(vector<Node*>(26,nullptr)){}
    Node(char val): c(val), ends(0), childs(vector<Node*>(26,nullptr)){}
};

/*
info
    - implement a trie class
        - it must have initializer
        - insert word
        - search word
        - startsWith prefix

        constraints:
            - word length is of size in range [1 and 2000]
            - word and letter consist of only lower case english letters
            - 30,000 calls total will be made to insert, search and startsWith

        insert word
            input: string word
            output: void

            example
                word = hi, hill
                            root: /
                                h
                                i

            brute force
                have root
                    if char at its alphabetical order does not exists, create it
                    move to the child at that index

                complexity
                    runtime: O(n)


        search 
            input: string word
            output: bool true if the word is on the trie, else false

            example

                /
                h
                i ends = 1
                t ends = 1

                if char postion in 0-indexed alphabet does not exists, return false
                if we are at end and ends > 0 return false


        startsWith
            input: string prefix
            output: bool true if previously inserted word containts prefix

            hi
                /
                h
                i ends = 1
                t ends = 1





*/

class Trie {

    Node* root;

public:
    Trie() {
        root = new Node('/'); 
    }
    
    void insert(string word) {
        /*
        hi
        hit

        a, b, c, d, e, f ,g, h, i

                /
                h
                i ends = 1
                t ends = 1
        
        */

        //declare variables
        int i = 0;
        Node* curr = root;

        //traverse string
        while(word[i]){

            //get alphabetical order 0-indexed
            int index = word[i] - 'a';

            //if char at current node childs does not exists, create it
            if(!curr->childs[index])curr->childs[index] = new Node(word[i]);

            curr = curr->childs[index];
            i++;
        }

        curr->ends++;

        
    }
    
    bool search(string word) {

        //declare variables
        int i = 0;
        Node* curr = root;

        //traverse word
        while(word[i]){
            //get alphabetical order 0-indexed
            int index = word[i] - 'a'; 

            //if char at current node childs does not exists, return false
            if(!curr->childs[index])return false;

            //move to next child
            curr = curr->childs[index];
            i++;   
        }

        return curr->ends > 0;
        
    }
    
    bool startsWith(string prefix) {

        /*

        */

        //declare variables
        int i = 0;
        Node* curr = root;

        //traverse word
        while(prefix[i]){

            //get alphabetical order 0-indexed
            int index = prefix[i] - 'a'; 

            //if char at current node childs does not exists, return false
            if(!curr->childs[index])return false;

            //move to next child
            curr = curr->childs[index];
            i++;   
        }

        return true;
    }
};
