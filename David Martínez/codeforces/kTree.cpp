#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution{
    public:
        double kT(int & n, int & k, int & d){

            //declare aux variable
            double result = 0;
            int minimum = min(n,k);
            vector<int> dToMin;
            
            //fill dToMin
            for(int i = d; d <= minimum; i++){
                dToMin.push_back(i);
            }

            //traverse to get numbers for permutation
            for(int i = 0; i < dToMin.size(); i++){
                vector<int> aux;
                int intAux = n - dToMin[i];

                while(intAux > 0){
                    aux.push_back(intAux);
                    intAux--;
                }

                result += pow(2, aux.size());
            }

            return result;
        }
};

int main()
{
    int n = 4, k = 5, d = 2;
    Solution sol;

    cout << " resupuesta: " << sol.kT(n,k,d) << endl;

    return 0;
}

