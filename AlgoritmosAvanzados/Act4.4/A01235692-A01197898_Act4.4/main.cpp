/*
Act4.4
Using the Randomized Algorithms technique, 
build a program in C++ that implements the 
Randomized Binary Search Algorithm to determine 
if an integer in a set of integers, using the 
Las Vegas Randomized Algorithm method.

INPUT: 
The program receives an integer S to be searched 
in the set of integers Q described in the next line.


OUTPUT:    
The output of the program will indicate in which index 
is the number to be searched, with the format: 
"The element is at the index: i", i will be the value of the index. 
If the data is not found, the message: "The element is not in the array" will be indicated.

David Gerardo Martinez Hidrogo - A01235692 
Humberto Ricardo Rodriguez Ruan - A01197898

Created: Nov 18, 2022 11:06pm    Last Modification: Nov 15, 2022 4:09pm
*/

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

/*
Generates a random number between start and end

Input: integer start and integer end
Output: random number between start and end

Complexity:
    Time: O(1)
    Complexity: O(1)
*/
int getRandom(int & start, int & end){

    if(start == end) return start;
    
    //using current time as the seed for the random number generator
    srand(time(NULL));
    return (rand() % end) + start;
}


/*
Returns index of value we are searching for
Input: vector with numbers, number we are searching for, and range where 
        the number could be found
Output: index where the number we are looking for is found

Complexity:
    Time: O(log n)
    Extra Space: O(log n)
*/
int binarySearchRecursively(vector<int> & nums, int & searching, int start, int end){

    //check if the operation can be made
    if(end >= start){

        //get random middle number
        int randomMid = getRandom(start, end);

        //check if value has been found
        if( nums[randomMid] == searching ){
            return randomMid;
        }
        //check if it's at left side
        else if( searching < nums[randomMid]){
            return binarySearchRecursively(nums, searching, start, randomMid-1);
        }
        //check if it's at the right side
        else{
            return binarySearchRecursively(nums, searching, randomMid+1, end);
        }
    }

    //return that it has not been found
    return -1;

}

/*
Returns index of value we are searching for
Input: vector with numbers, number we are searching for, and range where 
        the number could be found
Output: index where the number we are looking for is found

Complexity:
    Time: O(log n)
    Extra Space: O(1)
*/
int binarySearch(vector<int> & nums, int & searching){

    if(nums.size() == 1){
        return (nums[0] == searching) ? 0 : -1;
    }

    int start = 0;
    int end = nums.size();

    while(start <= end){

        //get random middle number
        int randomMid = getRandom(start, end);

        //check if value has been found
        if( nums[randomMid] == searching ){
            return randomMid;
        }
        //check if it's at left side
        else if( nums[randomMid] < searching ){
            start = randomMid + 1;
        }
        //check if it's at the right side
        else{
            end = randomMid - 1;
        }
    }

    //return that it has not been found
    return -1;

}


/*

Returns index of value we are seaching for

INPUT: 
The program receives an integer S to be searched 
in the set of integers Q described in the next line.


OUTPUT:    
The output of the program will indicate in which index 
is the number to be searched, with the format: 
"The element is at the index: i", i will be the value of the index. 
If the data is not found, the message: "The element is not in the array" will be indicated.


COMPLEXITY:
    Time: O(n)
    Extra space: O(n)
*/
int main()
{
    
    //declare variables
    int search;
    vector<int> nums;
    int idx, aux;

    //get input
    cin >> search;

    while(cin >> aux){
        nums.push_back(aux);
    }

    idx = binarySearch(nums, search);

    if(idx == -1){
        cout << "Element is not in the array" << endl;
    }else{
        cout << "Element is at index: " << idx << endl;
    }

    return 0;
}
