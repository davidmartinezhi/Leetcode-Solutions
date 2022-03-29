#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:

        vector<int> pablo1(vector<vector<int>> & n, vector<int>  & m){

            //actual sum
            vector<int> sums;

            //Precompute the original array
            for(int i = 1; i < m.size(); i++){
                m[i] += m[i-1];
            }

            //Get the value from the pairs index
            for(int i = 0; i < n.size(); i++){
                int sum;
                if(n[i][0] == 0){
                    //If the first index is 0, return the sum at the next index
                    sum = m[n[i][1]];

                }
                else{
                    //If the first index is not the first one, we substract the element before first index
                    // from the element in the secon index
                    sum = m[n[i][1]] - m[n[i][0] - 1];
                }

                sums.push_back(sum);
            }

            return sums;
        }
};