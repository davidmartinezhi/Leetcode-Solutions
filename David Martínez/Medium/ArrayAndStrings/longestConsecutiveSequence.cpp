#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
        input
            info:
                - unsorted array of integers "nums"

            output:
                - length of longest consecutive elements sequence

            constraints:
                - what sizes of array can i expect? [0, 100000]
                - what int values can i have in nums? [-10^9, 10^9]
                - must run in O(n) complexity

        example
            nums = [100,4,200,1,3,2]
            -> 4

            nums = [0,3,7,2,5,8,4,6,0,1]
            -> 9

        brute force
            sorting the array and travering for longest consecutive elements. complexity: O(n log n)
            adding all elements to a min heap and popping elements. complexity: O(n log n)

        optimize
            best conceivable runtime: O(n)
            have big array of size of all possible values
                add values appearances
            traverse big array

            traverse to get minimum value and max value
            create array with min value size
            create array with max value size

            traverse negative array backwards
            traverse positive array normally

            Complexity: 
                runtime: O(max(maxValue, minValue*-1))
                extra space: O(max(maxValue, minValue*-1))

        test
            - extremes, array contains -10^9 and 10^9
            - array of only negatives
            - array of only positives
        */

    /*
        //declare variables
        int n = nums.size();
        int maxPositive = 0;
        int minNegative = 0;
        int longestConsecutive = 0;

        //traverse array to get max and min values
        for(int num : nums){
            if(num > 0) maxPositive = max(maxPositive, num);
            if(num < 0) minNegative = min(minNegative, num);
        }

        //create arrays
        vector<bool> negatives((minNegative*-1)+1);
        vector<bool> positives(maxPositive+1);

        //fill arrays
        for(int num : nums){
            if(num >= 0) positives[num] = true;
            if(num <= 0) negatives[num*-1] = true;
        }

        int currentConsecutive = 0;

        //traverse negatives
        for(int i = negatives.size()-1; i >= 0; i--){

            if(negatives[i]){
                currentConsecutive++;
            }else{
                currentConsecutive = 0;
            }

            longestConsecutive = max(currentConsecutive, longestConsecutive);
            
        }

        if(currentConsecutive > 0) currentConsecutive--;

        //traverse positives
        for(int i = 0; i < positives.size(); i++){
            if(positives[i]){
                currentConsecutive++;
            }else{
                currentConsecutive = 0;
            }
            longestConsecutive = max(currentConsecutive, longestConsecutive);
        }

        return longestConsecutive;
        */

        //declare variables
        unordered_set<int> numsInArray;
        int longestCS = 0;
        int currentCS;

        //insert values into unordered set
        for(int num : nums){
            numsInArray.insert(num);
        }

        //for each number
        for(int num : nums){

            int aux = num;
            currentCS = 1;


            //if number is the first element of a sequence
            if(numsInArray.find(aux-1) == numsInArray.end()){

                //while the next element exists, increase sequence and move to next value
                while(numsInArray.find(aux+currentCS) != numsInArray.end()){
                    currentCS++;
                }

                //set longest consecutive sequence
                longestCS = max(longestCS,currentCS);

            }

        }

        return longestCS;
    }
};

/*
time: 30 min

complexity
    runtime: O(n)
    extra space: O(n)

De inicio saque un buen approach que no era optimo pero se acercaba a una respuesta lineal

Pero el approach no comentado es el ideal ya que solo comienza a contar la secuencia si es que el
elemento es el inicio de la secuencia.

*/