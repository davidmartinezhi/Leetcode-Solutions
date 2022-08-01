#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        /*
        info
        
            input: array "intervals" where each interval has [start, end]
            output: minimum number of intervals you need to remove to make the rest of
                    the intervals non-overlapping
            
            constraints:
                array length is between 1 and 100,000
                intervals size is always 2
                
                start is always samller than end
                start and end have values between -50,000 and 50,000
                
        example
            
            intervals = [[1,2],[2,3],[3,4],[1,3]]
            -> 1
            
            intervals = [[1,2],[1,2],[1,2]]
            -> 2
            
            intervals = [[1,3], [2,4], [3,6]]
            -> 1
            
        brute force

            sort to get starts in ascending order O(n log n)

            travel the list O(n) and fins merging intervals
            
            return intervals size - count
            
        optimize:
            bcr: O(n log n) because we need to sort
            memory is constant right now
            
            could it be in O(n)?
        
        test
            array of size 1
            
            
            
        */
        
        //brute force
        
        //check for size 1
        if(intervals.size() == 1) return 0;
        
        sort(intervals.begin(), intervals.end());   //O(n log n) time
        vector<int> merge; //O(1) extra space
        int i = 0;
        int count = 0;
        
        while(i < intervals.size()-1){ //O(n) time
            merge = intervals[i];
            
            while(i < intervals.size() - 1 && merge[1] > intervals[i+1][0]){
                merge[0] = min(merge[0], intervals[i+1][0]);
                merge[1] = min(merge[1], intervals[i+1][1]);
                i++;
            }
            count++;
            i++;
        }
        
        while(i < intervals.size()){
            count++;
            i++;
        }
        
        return intervals.size() - count;
    }
};

/*
minutes: 45+

complexity:
    time: O(n log n)
    extra space: O(1)

Notes:
    La respuesta fue hacer lo que hice ayer y anitier.
    Era recorrer de misma manera e identificar donde había overlapping.
    Pero ahora poniendome creativo y sacar las idferencias entre el original y sin overlaps

    La clave es saber identificar overlaps en intervalos

*/