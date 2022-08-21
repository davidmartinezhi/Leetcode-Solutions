/*
David Gerardo Martínez Hidrogo - A01235692
Humberto Ricardo Rodriguez Ruán - A01197898
*/
#include <iostream>
#include <vector>

using namespace std;


//complexity: time: O(n)
void merge(vector<double> & list, vector<double> & aux, int  left, int right){

    //declare variables
    int middle = (left+right)/2;
    int i = left, k = left, j = middle+1;

    //merge
    while(i <= middle && j <= right){

        //left value is smaller
        if(list[i] > list[j]){
            aux[k] = list[i];
            k++;
            i++;
        }else{
        //right value is smaller
            aux[k] = list[j];
            k++;
            j++;
        } 
    }

    //add remaining values
    while(i <= middle) aux[k++] = list[i++];
    while(j <= right) aux[k++] = list[j++];

    //update the original list on the given indexes
    for(int z = left; z <= right; z++){
        list[z] = aux[z];
    }
}

//complexity: time: O(n log n)
void mergeSort(vector<double> & list, vector<double> & aux, int left, int right){

    //base case
    if(left < right){

        int middle = (left+right)/2;

        //recursive calls. left and right side of list.
        //complexity: O( log n)
        mergeSort(list, aux, left, middle);
        mergeSort(list, aux, middle+1, right);
        
        //return merge of both sides. O(n)
        merge(list, aux, left, right);        
    }

    return;
}

int main()
{
    //initialize variables
    int n;
    cin >> n;
    vector<double> aux(n);
    vector<double> list;

    //adds numbers to the list
    while(n > 0){
        double auxN;
        cin >> auxN;
        list.push_back(auxN);
        aux.push_back(auxN);
        n--;
    }

    //calls mergesort on the list
    mergeSort(list, aux, 0, list.size()-1);
    
    //print results
    for(int i = 0; i < list.size(); i++){
        cout << list[i] << " ";
    }
    cout << endl;


    return 0;
}
