#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:

        vector<vector<int>> pares;
        vector<int> array;

        Solution(vector<vector<int>> pares, vector<int> array){
            this->pares = pares;
            this->array = array;
        }

        vector<int> pablo1(vector<vector<int>> & n, vector<int>  & m){
            //runtime: O(n)
            //Space: O(1)

            //actual sum
            vector<int> sums;

            //Precompute the original array
            for(int i = 1; i < m.size(); i++){
                m[i] += m[i-1];
            }

            //Get the value from the pairs index
            for(int i = 0; i < n.size(); i++){
                int sum;
                if(n[i][0] == 0){
                    //If the first index is 0, return the sum at the next index
                    sum = m[n[i][1]];

                }
                else{
                    //If the first index is not the first one, we substract the element before first index
                    // from the element in the secon index
                    sum = m[n[i][1]] - m[n[i][0] - 1];
                }

                sums.push_back(sum);
            }

            return sums;
        }
};

int main()
{


    vector<vector<int>> pruebas = {{2,3},{0,4},{1,4},{3,4}};
    vector<int> arrayOriginal = {4,27,8,100,9};
    Solution prueba(pruebas, arrayOriginal);
    vector<int> result = prueba.pablo1(prueba.pares, prueba.array);

    cout << endl;

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }

    cout << endl;
    return 0;
}
/*
Notas:

    Tarde alrededor de 1 hora
    Lo que he notado sobre dynamic programming es que haces un setup de los datos, para poder sacar más info
    sobre el precompute que ya hiciste
*/