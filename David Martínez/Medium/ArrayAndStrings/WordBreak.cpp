#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //bottom-up approach
        
        //declare variables
        int n = s.size();   //string size
        bool dp[n+1][n+1];  //dp table
        
        unordered_set<string> myset;    //unordered set
        
        //add dictionary words to unordered set
        for(auto word: wordDict)
            myset.insert(word);
        
        //traverse the dp array and fill values
        for(int length=1;length<=n;++length) //Window Size
        {
            int start = 1;  //declaring starting point of window
            int end = length;   //declaring end point of window
            
            while(end<=n) //Sliding Window moves while end hasn0t reach the end
            {
                string temp = s.substr(start-1,length); //declare substring of indexes in window
                
                //if word exists in dictionary
                if(myset.find(temp)!=myset.end()) 
                    dp[start][end] = true;  //set cell as true
                else
                {
                    
                    bool flag = false;
                    
                    //decrease window all the way to the end
                    for(int i=start;i<end;++i)
                        
                        //if we have found a word in current index and on previous index
                        if(dp[start][i] and dp[i+1][end])
                        {   
                            //set as true that cell
                            flag = true;
                            break;
                        }
                    dp[start][end] = flag;
                }
                
                //move the sliding window
                start += 1;
                end += 1;
            }
        }
        
        //return if sordbreak has been found
        return dp[1][n];
    }
};
