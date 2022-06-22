#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
        info
            input: integer array "nums" and integer "k"
            output: Kth largest element in the array
            constraints:
                k is in range 1 to 10,000
                nums[i] is between -10,000 and 10,000
            
        example
            [3,2,1,5,6,4], k = 2
            -> 5
            
            [3,2,3,1,2,4,5,5,6], k = 4
            ->4
            
        brute force
            sort the array
            get the kth largest number by substracting k from nums size 
            
            time: O(n log n)
            space: O(1)
        
        optimize:
            best case running time O(n) ?
            
            alternatives:
                use maxHeap
                time: O(n) n traversing the array, log n searching kth largest element
                memory: O(n)
                priority_queue<int> maxHeap;
                
                traverse the list n time in search for the biggest actual number. O(n^2)
        
        test:
            special case:
                K is bigger than nums size. this can't happen
                all numbers are the same
            
        */
        
        //brute force
        //runtime: O(n log n)
        //extra space: O(1)
         /*
        //sort
        sort(nums.begin(), nums.end());
        
        //return kth largest element
        return nums[nums.size() - k];
        */
        
        //optimize
        //Runtime: O(n)
        //extra space: O(n)

        //create priority queue
        priority_queue<int> maxHeap(nums.begin(), nums.end());

        //get kth largest element
        while(k > 1){
            maxHeap.pop();
            k--;
        }
        
        return maxHeap.top();

    }
};

/*
Notas:
    brute force terminado en 15 minutos
    optimized version terminado en 9 minutos
    total: 24 minutos

    Me asombro lo rapido que saque la solución, se supone que el problema es medium
    pero lo sentí como si fuese easy.

*/