/*
David Gerardo Martínez Hidrogo - A01235692
Humberto Ricardo Rodriguez Ruán - A01197898
*/

//complexity: time: O(n)
void merge(vector<int> & list, vector<int> & aux, int  left, int right){

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
void mergeSort(vector<int> & list, vector<int> & aux, int left, int right){

    //base case
    if(left 

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
