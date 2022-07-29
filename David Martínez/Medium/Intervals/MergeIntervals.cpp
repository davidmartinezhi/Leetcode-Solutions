#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        vector<vector<int>> merge(vector<vector<int>> & intervals){
        /*
        info
            input: array "intervals"
                each interval contains [start, end]
                merge all overlapping intervals
                
            output: array of the non-overlapping intervals that covers all intervals in input
            
            constraints:
                array size between 1 and 10,000
                start is always smaller or equal to end
                start and end are between 0 and 10,000 in value
                
        example
            [[1,3],[2,6],[8,10],[15,18]]
            -> [[1,6],[8,10],[15,18]]
            
            [[1,4], [4,5]]
            -> [1,5]
            
        brute force
            traverse the list and use memoization
            time: O(n)
            extra space: O(1)
            
        optimize
            bcr: O(n)
            this is the optimal solution
            
        walkthrough
            traverse entire list
            check if interval1[1] is greater or equal than interval2[0]
                in that case set a merge interval with mins and max
                when codition is not met add merge interval to result
            else add
            
        test
            special cases:
                empty array
                overlapping exists
                overlapping doesn't exist
                    
                
        */
        
        //[[1,4], [4,5]]
        //[[1,3],[2,6],[8,10],[15,18]]
        
        //sort in ascending order all starts, time O(n log n)
        sort(intervals.begin(), intervals.end());
        
        //declare variables
        vector<vector<int>> result; //[]
        vector<int> mergeI; //[1,3]
        int i = 0, n = intervals.size();
        
        //traverse the array    time O(n)
        while(i < n-1){
            
            mergeI = intervals[i];
            
            //overlap exists
            while(i < n - 1 && mergeI[1] >= intervals[i+1][0]){
                mergeI[0] = min(intervals[i+1][0], mergeI[0]);
                mergeI[1] = max(intervals[i+1][1], mergeI[1]);
                i++;
            }  
                
            result.push_back(mergeI);
                
            i++;
        }
        
        //add remaining intervals
        while(i < n){
            result.push_back(intervals[i]);  
            i++;            
        }
        //return result
        return result;
                    
        }
};

/*

finished in: 34 minutes

complexity
    time: O(n log n)
    extra space: O(1)

Notes
    Terminado rapido, una vez que ya vi como trabajar con intervalos en INSERT INTERVAL
    se me hizo muy sencillo implementar una solución. Me tarde un poco en hotspots de lógica
    debería de anotar esos hot spots en test.

    Aún así muy buena solución.

    Debo checar si hay una manera de solucionarlo sin el sort, aunque no creo que sea posible
    si se quiere saber los overlapse

*/