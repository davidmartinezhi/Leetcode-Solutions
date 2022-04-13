#include <iostream>
using namespace std;

double gauss(double n){
    double aux = (n+1)/2;
    return  aux * n;
}

int main()
{
    cout << endl;
    cout << " Gauss: " << gauss(8) << endl;
    cout << endl;
    return 0;
}
