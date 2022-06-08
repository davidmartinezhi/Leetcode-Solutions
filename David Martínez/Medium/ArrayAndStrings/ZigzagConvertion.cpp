#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        /*
        info
            input: string
                
            output: string converted
            constraints:
                string length is between 1 and 1,000
                string consists of lowercase english letters points and commas
                number of rows is between 1 and 1,000
            
        example
            
            s = "PAYPALISHIRING"
            
            [P  A  H    N
             A PL SI  I G
             Y  I   R   
            ]
            
            output: PAHNAPLSIIGYIR
            
            S = "PAYPALISHIRING"
            [
            [P, I,N]
            [A, L,S,I,G]
            [Y, A,H,R]
            [P,I]
            ]
            
        brute force
            create matrix and traverse the original string
            with a pointer appending each character in a zigzag pattern in the matrix
            time: O(n)
            space: O(n)
            
        optimize
            there should be a way of using just O(1) extra space in memory
            BCR: O(n) we must traverse the string at least once
            I'll do brute force first
        
        walkthrough
            create vector with empty strings inside
            create pointer which will be used to append the characters into each string
            traverse the string
            add character to string at pointer position and move the pointer position
            when pointer position is at last index, it must substract until it reaches the first position
            
        implement
        
        test
            special case:
                1 row
        */
        
        if(numRows == 1) return s;
        
        //variables
        string result = "";
        vector<string> rowStrings(numRows, "");
        int stringIdx = 0;
        string rowDirection = "down";
        
        //traverse the original string
        for(int i = 0; i < s.size(); i++){
            
            rowStrings[stringIdx] += s[i]; //add the char to its corresponding place
            
            //Change direction of pointer in extremes
            if(rowDirection == "down"){
                if(stringIdx == numRows-1){
                    rowDirection = "up";
                }
            }
            
            if(rowDirection == "up"){
                if(stringIdx == 0){
                    rowDirection = "down";
                }
            }
            
            //Move pointer
            if(rowDirection == "down"){
                stringIdx++;
            }
            else{
                stringIdx--;
            }
        }
        
        //Concatenate resulting strings
        for(int i = 0; i < rowStrings.size();i++){
            result += rowStrings[i];
        }
        
        return result;
    }
};

/*
notas:
    terminado en 28 minutos
    Se puede optimizar la memoria para no utilizar el vector y ser O(1) extra space
*/

int main(){

    Solution solution;
    string test = "PAYPALISHIRING";

    string result = solution.convert(test, 4);

    cout << result << endl;

    return 0;
}