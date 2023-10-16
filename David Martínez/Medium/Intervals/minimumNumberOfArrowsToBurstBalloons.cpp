#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        /*
            info
                input:
                    * array points, with tuple of integer values representing coordinates

                output:
                    * return minimum number of arrows that must be shot to burst all balloons

                constraints:
                    * what range of baloons instances can i expect? [1, 100k]
                    * what range of values can i expect in the coordinates [INT_MIN, INT_MAX]

            example
                points = [[10,16],[2,8],[1,6],[7,12]]
                sorted points = [[1,6],[2,8],[7,12],[10,16]]
                    mins[1,6]
                -> 2

                points = [[1,2],[3,4],[5,6],[7,8]]
                    mins[1,2] 1
                    mins[3,4]
                -> 4

                points = [[1,2],[2,3],[3,4],[4,5]]
                        mins[1,2] 1
                        mins[3,4] 1
                -> 2

                points = [[1,2],[2,4],[3,6],[4,5]]

                I can only have overlap with end and beginning with the same value once

            brute force
                sort the coordinates by the first x value
                get the values of the first interval as curr interval
                if we are in the last position, add 1

                while(currMinInterval end >= currInterval first)
                    move to the next interval
                    move pointer
                
                add 1

                complexity:
                    runtime: O(n log n)
                    extra space: O(1)

            optimize
                bcr: O(n)

            test
                * just one interval
                * two balloons overlap
                * no balloons overlap

                hotspot:
                    * check index starting position
        */


        //get size
        int n = points.size();

        //check if size is of size 1
        if(n == 1) return 1;

        //sort
        sort(points.begin(), points.end());

        //declare variables
        int darts = 1;
        int end = points[0][1];

        /*
            [[1,6],[2,8],[7,12],[10,16]]

            end = 6
            darts = 1

            [1,6]

        */

        //traverse points
        for(int i = 0; i < n; i++){

            //current baloon overlaps
            if(points[i][0] <= end) {
                end = min(end, points[i][1]);
            }
            else {
                darts++;
                end = points[i][1];
            }
        }

        return darts;
    }
};

/*
time: 40 minutes

complexity:
    runtime: O(n log n)
    extra space: O(1)

Notes
    I was able to come up with a solution easy and got the 
    complexity right from the start.  

*/