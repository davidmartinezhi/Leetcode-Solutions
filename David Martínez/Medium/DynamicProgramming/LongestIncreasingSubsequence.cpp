#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        //declare aux vector for dp
        vector<int> aux(nums.size(), 1);
        
        //declare varibale for longest subsequence
        int longest = 1;
        
        //traverse the array
        for(int i = 1; i < nums.size(); i++){
            
            //traverse from first index to i
            for(int j = 0; j < i; j++){
                
                //if the front index is bigger, and it has a shortest or equal subsequence count
                if(nums[i] > nums[j] && aux[i] <= aux[j]){
                    aux[i] = aux[j] + 1;    //add the subsequence of the smaller number and add 1
                    
                    longest = max(longest, aux[i]); //save the number of longest subsequence
                }
            }
        }
        
        //return longest subsequence
        return longest;
    }
};