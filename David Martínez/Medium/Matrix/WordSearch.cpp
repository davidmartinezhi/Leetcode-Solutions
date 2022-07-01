#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        /*
        info
            input: matrix m*n grid of characters and string "word"
            output: true if word exists in the grid
            
                sequence must be horizontal or vertical, cells should be used just once
            
            constraints:
                m and n ranges from 1 to 6
                word length ranges from 1 to 15
                they consist only of lower and uppercase english letters
                
        example:
                [
                ["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]
                ]
                
                word = "SEE"
                
        brute force
                DFS through recursivity
                complexity:
                    time: O(m+n + first letter appearances * wordlength)
                    extra space: stack calls O(word size)
                    
        optimize
            I believe my answer is optimal I'll implement
            
        walkthrough
            traverse grid until we fins first char of the word
                then send dfs to each adjacency to find second char and so on
                
            if word is found return true, else false
                
        test
            
            no word in the grid
            word in the grid
            
            hotspots:
        */
        
        //declare variables
        bool ans = false;
        int rows = board.size();
        int cols = board[0].size();
        
        //traverse array and send to dfs search
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                int index = 0;
                if(board[row][col] == word[0]){
                    dfs(board, word, ans, rows, cols, row, col, index);
                    if(ans == true) return true;
                }
            }
        }
        
        //return
        return false;
    }
    
    void dfs(vector<vector<char>> & board, string & word, bool & ans, int &rows, int & cols, int row, int col, int index){
        
        //out of boundaries
        if(row >= rows || row < 0 || col >= cols || col < 0 || board[row][col] != word[index]) return;
        
        //index out of range
        if(index > word.size()-1) return;
        
        //match and checking last element
        if(board[row][col] == word[word.size()-1] && index == word.size()-1) ans = true;
        
        //update element coming, so we don't use repeated chars
        char aux = board[row][col];
        board[row][col] = '0';
        
        //check the rest of elements
        dfs(board, word, ans, rows, cols, row+1, col, index+1); // down
        dfs(board, word, ans, rows, cols, row-1, col, index+1); // top
        dfs(board, word, ans, rows, cols, row, col-1, index+1); // left
        dfs(board, word, ans, rows, cols, row, col+1, index+1); // right  
        
        //on return from dfs, return char to original value
        board[row][col] = aux;
        
    }
};

/*
time: 43 minutes
complexity:
    time: O((n+m) + (appearance of starting char * word))
    extra space: O(word size * variables used on each stack call)

Me siento orgulloso de lo eficiente que resolcí este problema
No me imaginaba aplicando dfs en una matriz para encontrar patrones, pero 
se nota mucho el improvement desde principios del año hasta ahora.

*/