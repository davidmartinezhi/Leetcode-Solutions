#include <iostream>
#include <vector>
using namespace std;


struct Node{
    char c;
    int ends;
    vector<Node*> childs;
    string word;

    Node(): c('0'), ends(0), childs(vector<Node*>(26,nullptr)), word(""){}
    Node(char val): c(val), ends(0), childs(vector<Node*>(26,nullptr)), word(""){}
};

class Solution {
    Node* root;

    void trie_insert(string s){

        int i = 0; //string curr char
        Node* curr = root; //pointer to root

        while(s[i]){    //while we have not reach the end of the string

            int index = s[i] - 'a'; //get the position of alphabet 

            //if node does not exist with the current char, create it
            if(curr->childs[index] == nullptr) curr->childs[index] = new Node(s[i]); 

            //move to that node
            curr = curr->childs[index];
            i++; //update char we are seeing in the string
        }

        curr->ends++;   //mark word ends
        curr->word = s; //mark word
    }

    void solve(vector<vector<char>> & board, vector<string> & found, int & rows, int &cols, int i, int j, Node* curr){


        //base cases
        if(i < 0 || i >= rows || j < 0 || j >= cols) return; //check if we are in bounds

        //get index of char
        int index = board[i][j] - 'a';
        if(board[i][j] == '$' || curr->childs[index] == nullptr) return; //trie does not have char or cell is already visited
        

        //move to new word
        curr = curr->childs[index];

        //checar si hemos encontrado la palabra, la agregamos y removemos el ends
        if(curr->ends > 0){
            found.push_back(curr->word);
            curr->ends--;
        }

        //body
        char c = board[i][j]; //store current value
        board[i][j] = '$'; //change value temporarily

        //check body
        solve(board, found, rows, cols, i-1, j, curr); //top
        solve(board, found, rows, cols, i+1, j, curr); //down
        solve(board, found, rows, cols, i, j-1, curr); //left
        solve(board, found, rows, cols, i, j+1, curr); //right

        //Return value on board
        board[i][j] = c;
    }

public:
    Solution(){
        root = new Node('/');
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        //declare variables
        vector<string> found;
        int rows = board.size();
        int cols = board[0].size();

        //insert all words in tree
        for(string word : words){
            trie_insert(word);
        }

        //search words
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                solve(board, found, rows, cols, i, j, root);
            }
        }

        return found;
    }
};

/*
time: 45+

Complexity
    runtime: O(((n*m)*(n*m))+array size)

Solución inicial que hice estuvo dentro del tiempo, pero era backtracking sin la implementación de trie
Trie ayuda a reducir la complejidad bastante porque sino es O(nm*nm*array size) y esa complejidad es muy alta para el time limit que tenía

Pero si es miuy util utilizar trie también. Para mejorar la complejidad bastante.


*/