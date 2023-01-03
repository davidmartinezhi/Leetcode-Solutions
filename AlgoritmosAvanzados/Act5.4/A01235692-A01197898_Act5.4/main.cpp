/*
Act5.2
Implement backtracking algorithm with bitmasking to determine the number
of combinations that can be achieved in the problem: type of hats in a group of people.

There are 100 different types of hats/caps and each has an ID from 1 to 100. In addition, 
there are n people each one have a variable collection of hats/caps. On a certain date all 
these people decide to go to a party wearing a hat/cap, but in order to look unique they 
have decided that none of them will wear the same hat/cap.

They have been asked to find the total number of different arrangements or ways in which 
none of them will wear the same type of hat/cap.

INPUT:
The first line contains the value of n, followed by n lines containing the 
hat/cap collections of each person.

OUTPUT:
Total number of different arrangements, followed by each arrangement containing 
the ids of the hat/cap for each person.

CONSTRAINTS:
Each collection contains any number ranging from 1 to 100.

David Gerardo Martinez Hidrogo - A01235692 
Humberto Ricardo Rodriguez Ruan - A01197898

Created: Nov 27, 2022 10:33pm    Last Modification: Nov 28, 2022 12:48am
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

/*
Convert number
Input: string number
Output: integer number

Complexity
    Time: O(n)
    space: O(1)
*/
int stringToInt(string & n){

    //Get string number
    int num = 0;

    //Transform to integer
    for(int i = 0; i < n.size(); i++){
        //get number
        num = (num * 10) + (n[i] - '0');
    }

    return num;

}

/*
Find all possible arrangements without repeating hats
Input: Hashtables to save collections, collections count, collections of each person, bitmask, current arrangement of hats and i for current hat collection
Output: void

Complexity
    Time: O(number of collections * largest collection)
    Extra Space: O(1), recursively O(collections size log collections size)
*/
void findArrangements(unordered_map<int, vector<int> > &ht, int &count, vector<vector<int> > & collections, vector<int> & bitmask, vector<int> & arrangement, int i){


    //get collections size
    int n = collections.size();

    //return if we are at the end of collections
    if(i == n) return;

    vector<int> collection = collections[i];

    //traverse collection
    for(int j = 0; j < collection.size(); j++){

        //get hat
        int hat = collection[j];

        //Bit can be added, hat is not currently in the arrangement
        if(bitmask[hat] == 0){

            //mark bitmask
            bitmask[hat] = 1;

            //add hat to arrangement
            arrangement.push_back(hat);

            //check if arrangement has been found
            if(arrangement.size() == n){
                
                //update count and add arrangement to ht
                vector<int> aux;
                count++;

                for(int j = 0; j < arrangement.size(); j++){
                    aux.push_back(arrangement[j]);
                }

                ht[count] = aux;


            }else{

                //check next collection
                findArrangements(ht, count, collections, bitmask, arrangement, i+1);

            }

            //remove found value and update bitmask
            arrangement.pop_back();
            bitmask[hat] = 0;            
        }
    }

    return;

}

/*
Find all possible arrangements without repeating hats
Input: Hashtables to save collections, collections count, collections of each person, bitmask, current arrangement of hats and i for current hat collection
Output: void

Complexity
    Time: O(number of collections * largest collection)
    Extra Space: O(possible arrangements * collections size)
*/
void possibleCollections(vector<vector<int> > & collections){
    
    //Declare variables
    vector<int> bitmask(100, 0);
    vector<int> arrangement(0);
    unordered_map<int, vector<int> > ht; //save found arrangements
    int count = 0; //number of arrangements found
    int i = 0;

    findArrangements(ht, count, collections, bitmask, arrangement, i);

    //print answer
    cout << count << endl;

    //print possible arrangements
    i = 0;

    for(int i = 1; i <= count; i++){
        for(int j = 0; j < ht[i].size(); j++){
            cout << ht[i][j] << " ";
        }
        cout << endl;
    }
}


/*
Find all possible arrangements without repeating hats
Input: Hashtables to save collections, collections count, collections of each person, bitmask, current arrangement of hats and i for current hat collection
Output: void

Complexity
    Time: O(number of collections * largest collection)
    Extra Space: O(possible arrangements * collections size)
*/
int main(){

    //Declare variables
    int n; //number con collections
    vector<vector<int> > collections; //collections
    
    string collectionString;

    //get input
    bool first = false;

    //receive line as string
    while(getline(cin, collectionString)){ 

        //receive line as string
        istringstream iss(collectionString);
        //cout << collectionString << endl;

        //Declare current collection
        vector<int> collection; 
        string aux = "";

        if(first){
            //traverse collection as string
            for(int i = 0; i <= collectionString.size(); i++){
                
                //End of hat id
                if(collectionString[i] == ' ' || i  == collectionString.size()){
                    collection.push_back(stringToInt(aux)); //add hat as an integer
                    aux = ""; //reset aux string for hat id
                }else{
                    aux += collectionString[i]; //add number
                }
            }
            collections.push_back(collection);
        }else{
            first = true;
        }
    }

    possibleCollections(collections);


    return 0;
}
