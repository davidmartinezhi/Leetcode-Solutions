/*
Act2.2
Creates a Suffix array and displays it in alphabetical order.
David Gerardo Martínez Hidrogo - A01235692 
Humberto Ricardo Rodriguez Ruán - A01197898

Last Modified: Oct 3. 20:07:00
*/

#include <iostream>
#include <algorithm>
#include <vector>
 using namespace std;


/*
Create Suffix Array.
Receives String input and generates de Suffix Array of that string

Complexity
    time: O(n^2 log n). O(n log n) for sorting and O(n) for comparison between strings while sorting
    extra space: O(n). It just uses the space needed to create the suffix array
*/
 vector<pair<string, int> > createSuffixArray(string & str){

    //suffix array initialization
    vector<pair<string, int> > suffixArray(str.size()); 

    //fill suffix array. time: O(n^2)
    for(int i = 0; i < str.size(); i++){
        suffixArray[i].first = str.substr(i, str.size() - i);
        suffixArray[i].second = i;
    }

    //sort suffix array. time: O(n^2 log n)
    sort(suffixArray.begin(), suffixArray.end());

    return suffixArray;
 }

 int main()
 {
    
    //declare variables
    string str; //input
    cin >> str;

    //create suffix array
    vector<pair<string,int> > suffixArray = createSuffixArray(str);

    //Display suffix array values
    for(int i = 0; i < str.size(); i++){
        cout << suffixArray[i].first << " ";
    }
    cout << endl;

    
    //Display suffix array indexes
    for(int i = 0; i < str.size(); i++){
        cout << suffixArray[i].second << " ";
    }
    cout << endl;
    
    
    return 0;
 }
 