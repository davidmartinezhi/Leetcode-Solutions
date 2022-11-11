#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;



int minDifferenceRectangle(vector<int> & A){

   //check that we have 4 numbers
    if(A.size() < 4) return -1;

    //declare variables
    unordered_map<int, int> ht; // hashtable
    bool firstPar = false; //first pair
    bool secondPar = false; //second pair flag

    //vector of pairs
    vector<int> pairs;

    //traverse A
    for(int i = 0; i < A.size(); i++){

        //update frequency to number
        ht[A[i]]++;

        //check if we have 4 sides of the same length
        if(ht[A[i]] == 4) return 0;

        //Add pair if found
        if(ht[A[i]] == 2) pairs.push_back(A[i]);

        //check if 2 pairs exist
        if(ht[A[i]] == 2 && !firstPar) firstPar = true;
        else if(ht[A[i]] == 2 && !secondPar) secondPar = true;
    }

    //check if rectangle can be made, if two pairs exist
    if(!secondPar) return -1;

    //check multiple pairs
    //dp table
    //min difference value
    vector< vector<int> > dp(pairs.size() + 1, vector<int>(pairs.size() + 1, INT_MAX));
    int minDiff = INT_MAX;

    for(int i = 0; i <= pairs.size(); i++){
        for(int j = 0; j <= pairs.size(); j++){

            
            //if we are not at indexes 0
            if( i != 0 && j != 0){
                //if we are not comparing the same number
                if(i != j){
                    //get difference
                    minDiff = min(minDiff, abs(pairs[i-1] - pairs[j-1]));
                }  
            }
        }
    }

    //return mminDIFF
    return minDiff;
}

int main()
{
    //input
    int aux[] = { 911, 1, 3, 1000, 1000, 2, 2, 999, 1000, 911 };
    vector<int> A;

    for(int i = 0; i < 10; i++){
        A.push_back(aux[i]);
    }

    cout << minDifferenceRectangle(A) << endl;
    return 0;
}
