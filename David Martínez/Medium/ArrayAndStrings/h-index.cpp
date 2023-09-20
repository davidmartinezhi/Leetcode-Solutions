#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        /*
        info
            input:
                * int array "citations", where citation[i] is number of citations
                  a researcher has received on the ith paper

            output:
                * researchers h-index

                h-index is the max value of h, such that the given researcher
                has published at least h papers that have each been cited h times

            constraints:
                * what range of sizes can the array have? [1, 5k]
                * what range of values can citation[i] have? [0, 1k]

        example
            citations = [3,0,6,1,5]
            -> 3

            curr = 3
            found = 3
            h = 3
            n = 5

            citations = [1,3,1]
            -> 1

            curr = 1
            found = 3
            h = 1
            n = 3



        brute force
            if found equal or more times than current and greater than h
                h equals current

            complexity
                runtime: O(n^2)
                extra space: O(1)

        optimize
            best conceivable runtime: O(n)

            bottleneck is traversing twice
            
            citations = [3,0,6,1,5]
            
            maybe get number and how many numbers are greater than that number
            maybe have and array  with max value size

            citations = [3,0,6,1,5]
            citationsSorted = [0,1,3,5,6]
                                 i = 1
                                 remaining = n-i = 5-1 = 4
                                 4 papers have 1 or more citations

                                   i=2
                                   remaining = n-i = 5-2 = 3
                                   3 papers have 3 or more citations

            citations = [7,8,9]
                         i = 0
                         remaining = n-i = 3-0 = 3
                         so number must be equal or greater than remaining


            complexity
                runtime: O(n log n)
                extra space: O(1)

        test
            * h index is 1, even if we have more citations
            * h index is 0
            * h index is greater than 1, but more than one h-index exist

            hotspot:
                check h indez with single number and its greater than 1
        */

        //get size
        int n = citations.size();

        //check size
        if(n == 1){
            if(citations[0] == 0) return 0;
            else return 1;
        }

        //declare h index
        int hIdx = 0;

        //sort array
        sort(citations.begin(), citations.end());

        //traverse array
        for(int i = 0; i < n; i++){

            //get remaining numbers
            int remainingNums = n-i;

            //check current number is greater or equal to remainingNums
            if(citations[i] >= remainingNums){
                hIdx = max(hIdx, remainingNums);
            }
        }

        return hIdx;
    }
};