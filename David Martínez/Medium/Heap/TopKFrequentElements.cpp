#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
        info
            input: integer array "nums" and int "k"
            output: "k" most frequent elements
            
            answer may be returned in any order
            
            constraints:
                array size is between 1 and 10,000
                k is in range 1 and n, n being the unique elements in the array
                it's guaranteed that the answer is unique
        
        example
            [1,1,1,2,2,3] k = 2
            -> [1,2]
            
            [
            1: 3,
            2: 2,
            3: 1
            ]
            
            [1] k = 1
            -> [1]
            
        brute force
            use hashmap to map numbers and their frequency
            traverse the hasmap k times, looking for the number with max frequency
            
            complexity
                time: O(n + k*k)
                extra space: O(k)
                
        optimize
            best case running time: O(n)
            
            use max heap for frequencies
            
            traverse to map in hashtable numbers and their freq O(n)
            traverse to map hashtable of frequencies and their numbers adj list O(n)
            add frequencies to the priority queue   (O(n))
            
            while k is dif from 0 O(k)
                get the top element and add number
            
            
        
        test
            
                
            
        */
        
        /*
        //declare variables
        unordered_map<int,int> numFreq;
        unordered_map<int,vector<int>> freqNum;
        priority_queue<int> topFreq;
        vector<int> ans;
        
        //traverse to fill numFreq O(n)
        for(int i = 0; i < nums.size(); i++){
            numFreq[nums[i]]++;
        }
        
        //traverse to fill freqNum and topFreq O(n)
        for(auto n : numFreq){
            freqNum[n.second].push_back(n.first);
            if(freqNum[n.second].size() == 1) topFreq.push(n.second);
            
        }
        
        //get k elements O(k)
        while(k > 0){
            int aux = topFreq.top();
            topFreq.pop();
            
            for(int i = 0; i < freqNum[aux].size(); i++){
                if(k > 0){
                    ans.push_back(freqNum[aux][i]);
                    k--;
                }else{
                    break;
                } 
            }
        }
        
        return ans;
        */
        
        //simplifying answer
        
        //declare variables
        unordered_map<int, int> numFreq;
        priority_queue<pair<int,int>> topFreq;
        vector<int> ans;
        
        //traverse original vector to fill info in numFreq
        for(int i = 0; i < nums.size(); i++){
            numFreq[nums[i]]++;
        }
        
        //traverse numFreq to fill priority queue
        for(auto n : numFreq){
            topFreq.push(make_pair(n.second,n.first));
            
            if(topFreq.size() > numFreq.size() - k){
                ans.push_back(topFreq.top().second);
                topFreq.pop();                
            }
        }
        
        return ans;
    }
};

/*

time: 45 minutes because at first I didn't understood the problem well
      resolving the problem, aprox 25-30 minutes

complexity:
    time: O(2n) = O(n)
    extra space: O(n)

Make sure to understand the problem correctly, it's okay to try to go faster
But a key element is understanding the problem well, I noticed that in info and examples
I saw them supperficially without thinking much about them.
*/