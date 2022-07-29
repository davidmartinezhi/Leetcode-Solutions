#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        /*
            info
                input: array of non-overlapping intervals "i" and new interval
                
                    each interval contains start and end of that interval
                    intervals is sorted in ascending order by intervals[0] 
                
                    insert new interval into intervals
                    such that intervals is still sorted in ascending order by start[i] and
                    intervals has no overlapping intervals
                    
                ouput: intervals after the insertion
                
                constraints:
                    intervals has length between 0 and 10,000
                    each index has only 2 values, start and end
                    start and end are between 0 and 100,000
                    start is lesser or equal than end
                    intervals is sorted by ascending order of starts
            
            example
            
            
                [[1,3],[6,9]] newInterval = [2,5]
                output = [[1,5],[4,9]]
                
                starts: [1,6]
                ends: [5,9]
                
                
                start: 1 compare with 2
                smallest is 1
                end: 3 compare with 5
                    5 is greater, insert
                    [[1,5],[6,9]]
                    
                    compare 5 with 6
                    if smaller, break
                    
                    else merge first start with second end
                    
                [4,8]
                intervals = [[1,2],[3,4],[6,7],[8,10],[12,16]]
                newInterval = [4,8]
                
                starts = [1,3,4,8,12]
                ends =   [2,4,8,10,16]
                
                -> [[1,2],[3,10],[12,16]]
                
                
            brute force
                create array with sorted in ascending order numbers
                from start every number greater or equal, gets crossed
                and also lesser or equal than end
            
                leave the last number
                if size reamaining is pair
                start creating new result vector
                
                runtime: O(n log n) sort
                extra space: O(n + newInterval)
                
            optimize
                bcr: O(n)
                merge, to avoid sorting
                
                DS brainstorm:
                    matrix?
                    
            test:
                intervals with gaps 1->5 6->9 with new between 1 and 5
                intervals without gaps 1->5 6->9 with new between 1 and 9
                
        */
        

        /*
        
        //first try: brute force
        //declare variables
        vector<vector<int>> result;
        vector<int> auxIntervals;
        vector<int> merge;

        //empty intervals
        if(intervals.size() == 0){
            result.push_back(newInterval);
            return result;
        }
        
        //fill aux vectors
        for(int k = 0; k < intervals.size(); k++){
            for(int h = 0; h < 2; h++){
                auxIntervals.push_back(intervals[k][h]);
            }
        }
        
        int i = 0;
        int j = 0;
        int size = 0;
        
        while(i < auxIntervals.size() && j < 2){
            
            if(auxIntervals[i] == newInterval[j]){
                merge.push_back(auxIntervals[i]);
                while(i < auxIntervals.size() && auxIntervals[i] == merge[merge.size()-1]){
                    i++;
                }
                while(j < 2 && newInterval[j] == merge[merge.size()-1]){
                    j++;
                }
            }else if(auxIntervals[i] < newInterval[j]){
                merge.push_back(auxIntervals[i]);
                i++;
            }else{
                merge.push_back(newInterval[j]);
                j++;
            }
            
            size++;
            
        }
        
        while(i < auxIntervals.size()){
            merge.push_back(auxIntervals[i]);
            i++;  
            size++;
        }
        
        while(j < 2){
            merge.push_back(newInterval[j]);
            j++;
            size++;
        }
        
        for(int k = 0; k < merge.size(); k++){
            if(merge[k] >= newInterval[0] && merge[k] < newInterval[1]){
                merge[k] = -1;
                i = k;
                size--;
            }
        }
        
        if(size % 2 != 0 && i+1 < merge.size() && merge[i+1] == newInterval[1]){
            merge[i+1] = -1;
        }

        
        vector<int> auxResult;
        
        for(int k = 0; k < merge.size(); k++){
            
            if(merge[k] != -1){
                auxResult.push_back(merge[k]);
            }

            if(auxResult.size() == 2){
                result.push_back(auxResult);
                auxResult = {};
            } 
        }        

        return result;
        */
        
        //optimal solution
        //O(n) time
        //O(1) extra space
        
        //declare variables
        vector<vector<int>> result;
        vector<int> mergeI = newInterval;
        int i = 0;
        int n = intervals.size();
        
        //fill result befor merge
        while(i < n && intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }
        
        //merge
        while(i < n && intervals[i][0] <= newInterval[1]){
            mergeI[0] = min(intervals[i][0], mergeI[0]);
            mergeI[1] = max(intervals[i][1], mergeI[1]);
            i++;
        }
        
        //add merge
        result.push_back(mergeI);
        
        //fill result after merge
        while(i < n){
            result.push_back(intervals[i]);
            i++;
        }
        
        //return
        return result;

        }
};

/*
Notas:
    Tiempo: 45+ minutes
    Complexity:
        time: O(n)
        extra space: O(1)

    Es mi primer problema sobre intervalos.
    Estuve en lo correcto en que debía de implementar memoization para comparar variables

    Pero por falta de experiencia con este tipo de problemas no pude decifrarlo antes de los 45 minutos
    La respuesto no se ve muy compleja pero esta muy simple y elegante.

    Debo practicar más problemas de intervalos

*/