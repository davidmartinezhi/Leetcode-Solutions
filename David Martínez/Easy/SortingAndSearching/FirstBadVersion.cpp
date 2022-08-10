#include <iostream>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        /*
        info
            input: n which represents the number of versions 
                use isBadVersion API to detect bad versions
            
                implement function to find first bad version
                minimize the calls to the API
            
            output: number of bad version
            constraints:
                Bad version is between 1 and INT_MAX
            
        Brute force
            Look for versions from 1 to n
            
            complexity:
                time O(n)
                space O(1)
            
        Optimize
            Use binary search to look for range in bad version
            complexity O(log n)
            space O(1) iterativo, log n recursivo
            
        walkthrough
            create bst function with 1 as default start n as end
            Use right end as pivot
            if g b b, move end to middle
            if g g b, move start to middle + 1
            
        test
            
                last version is bad one
                first version is bad one
                version in the middle is bad
                odd number of numbers
                even number of numbers
            
        
        */

       //versión iterativa

       /*
        int start = 1;
        int end = n;
        
        while(start < end){
            int middle = ((end-start)/2) + start;
            bool m; 
            
            m = isBadVersion(middle);
            
            //if middle if good version
            if(!m){
                start = middle+1;
            }else{
                end = middle;
            }
        }

        
        return start;
       */
        
        return bst(1, n);
        
    }
    
    int bst(int start, int end){
        
        //base case
        if(start < end){
            int middle = ((end-start)/2) + start;
            bool m;
            m = isBadVersion(middle);
            
            //if middle if good version
            if(!m){
                return bst(middle+1, end);
            }else{
                return bst(start, middle);
            }
        }
        
        return start;

        
    }

    //Esta función es solo para que no marque error en vscode, en leetcode no ponerlo
    bool isBadVersion(int n){
        return true;
    }
};