#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        /*
            info
                input: array of n strings "strs", all the same length
                output: number of columns to delete

                Details:
                    putting words on top of each other
                    letters must be arranged in lexicographical order
                    if not, delete that column

                constraints:
                    * array size is in range 1 and 100
                    * array strings can have length between 1 and 1,000
                    * strings consist of lowercase english letters

            example
                strs = ["cba","daf","ghi"]
                "cba"
                "daf"
                "ghi"

                -> 1, column on index 1 is not sorted

                strs = ["a","b"]
                "a"
                "b"

                -> 0

                strs = ["zyx","wvu","tsr"]
                "zyx"
                "wvu"
                "tsr"

                -> 3

            brute force
                for each column, traverse every row O(n*m) runtime
                    create a string with those letters O(n+m) memory
                    create aux sorted string O(n+m) memory and O((n+m) log (n+m)) runtime
                    if they don't match, add 1 to columns to delete

                complexity:
                    runtime: O((n*m)*((n+m) log (n+m)))
                    extra space: O(n+m)

            optimize
                best conceibable runtime: O(n*m)

                for each column, traverse every row
                    have int to know the current value position of col letter in rows
                    if row is smaller, add to col to delete and advance

                complexity:
                    runtime: O(n*m)
                    extra space: O(1)

            test
                * no columns to delete
                * all columns to delete
                * columns to delete exist
        */

        /*
        strs = [
            "a",
            "b",
            ]

            col = 0
            row = 0

            letterIdx = -1

            colsToDelete = 0

        */

        //declare variables
        int colsToDelete = 0;
        int n = strs.size(); //size rows
        int m = strs[0].size(); //size columns

        //for each column
        for(int col = 0; col < m; col++){

            //integer helper variable
            int lowerLetterIdx = -1;

            //for each row
            for(int row = 0; row < n; row++){

                //get letter
                int letterIdx = strs[row][col] - 'a';

                //cout << strs[row][col] << " idx: " << strs[row][col] - 'a' << endl;

                //if it's not in sorted order
                if(lowerLetterIdx > letterIdx){
                    
                    //add to columns to delete
                    colsToDelete++;
                    break;                    
                }

                //update letter Idx
                lowerLetterIdx = letterIdx;

            }
        }

        //return
        return colsToDelete;
    }
};