#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        /*
        info
            input: int "n" representing the number of times we'll count and say
            output: string with the n number counted and said
            constrints: n is between 1 and 30
        
        example
        
            n = 1
            -> "1"
            
            n = 2
            -> "11"
            
            n = 3
            -> "21"
            
            n = 4
            -> "1211"
        
        brute force
            iterate the whole number and have aux counter
            send that string to recursive call
            
            decrease n until it hits 0
            
            complexity:
                time O(n*m) n being n and m, being the size of each new number to count
                space O(n) n being the calls to stack
                extra space: O(1)
        
        optimize
            best case running time O(n*m)
        
        walkthrough
            recursive call and counting
        
        test
            n = 1
            n = 30
        */
        
        string result = "1";
        return countAndSayCall(n, result);
    }
    
    string countAndSayCall(int & n, string & res){
        
        //base case
        if(n == 1) return res;
        
        /*
        1
        
        11
        
        21
        
        1211
        
        */
        
        //count
        string aux = "";
        char number = res[0];
        int count = 0;
        
        for(int i = 0; i < res.size(); i++){
            if(number == res[i]){
                count++;
            }else{
                aux = aux + to_string(count) + number;
                number = res[i];
                count = 1;
            }
        }
        
        res = aux + to_string(count) + number;
        n = n-1;
        
        return countAndSayCall(n, res);
        
    }
};