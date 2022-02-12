#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*
            input: 2 integer arrays sorted in non-decreasing order and n,m representing the size of
                each array
            
            nums1 has (n+m) size 
            nums1 size = m
            nums2 size = n
            
            After the function, all elements in order for nums1 and nums2, should be in 
           single array. stored in nums1
           
          m and n, have length size in range 0 and 200
          
          n+m have a length between 1 and 200
          
          example
          
          [1,4,5,0,0,0] 3 [2,5,6] 3
          
          [1,2,4,5,5,6]
          
          Brute force
            nums1 size
            m = nums1.size() - n;
          
            O(m)
            m to the end
                add the values from nums2 in nums 1
            
             sort    O(m+n log m+n)
        
                runtime: O(m+n log m+n)
                
        Optimize
            
           Until m
            
            compare fisrt element of nums1 and nums 2
            
          [1,4,5,0,0,0] 3 [2,5,6] 3
          
          [1,2,4,5,5,6]   
          
          
          [4,5,6,0,0,0] 3 [1,2,3] 3
          
          [1,2,3,4,5,6]
                
        
        Test:
            m = 1 and n = 0
            m=0 and n = 1
            
        */
        
        //Brute force. Salio en menos de 20 minutos
        
        //Traverse n
        for(int i = 0; i < n; i++){
            
            nums1[i+m] = nums2[i];
            
        }
        
        sort(nums1.begin(), nums1.end());
    }
};