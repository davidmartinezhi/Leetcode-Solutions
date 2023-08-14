#include <iostream>
#include <vector>

using namespace std;

struct Node{
    char c;
    int end;
    vector<Node*> child; //size of alphabet

    Node(): c(0), end(0), child(vector<Node*>(26, nullptr)){};
    Node(int val): c(val), end(0), child(vector<Node*>(26, nullptr)){};
};

class WordDictionary {

    Node* root;


    void trie_insert(string s){

        //declare variables
        int index;
        int i = 0;

        //get root
        Node* curr = root;

        //traverse string
        while(s[i]){
            index = s[i] - 'a'; //index position

            //check if the current node has a child in that index
            //NO CHILD
            if(!curr->child[index]){ //create one
                curr->child[index] = new Node(s[i]);
            }

            //move to the child
            curr = curr->child[index];

            i++;
        }

        curr->end++;
    }

    bool trie_search(string s, Node* curr, int pos, int n){

        //check if pos is a dot
        if(s[pos] == '.'){
            
            bool res = false;

            Node* current = curr;

            //traverse the alphabet
            for(int i = 0; i < 26; i++){

                //if we are at the last character and it exists
                if(pos == n-1 && curr->child[i]){
                    current = curr->child[i];
                    res = res || current->end > 0 ? true : false;
                }

                else if(curr->child[i] && trie_search(s, curr->child[i], pos+1, n)) return true;

            }

            return res;

        }

        //not a dot
        else if(curr->child[s[pos]-'a']){ //if node at char exists

            //if we are at last char
            if(pos == n-1){
                curr = curr->child[s[pos]-'a'];
                return curr->end > 0 ? true : false;
            }
            
            return trie_search(s, curr->child[s[pos]-'a'], pos+1, n);

        }

        return false;

    }

public:
    WordDictionary() {
        root = new Node('/');
    }
    
    void addWord(string word) {
        trie_insert(word);
    }


    
    bool search(string word) {
        return trie_search(word, root, 0, word.size());
    }
};
