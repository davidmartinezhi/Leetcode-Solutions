#include <iostream>
using namespace std;

double gauss(double n){
    double aux = (n+1)/2;   //De esta manera lo puedo sacar con numeros con punto decimal
    return  aux * n;
}

int gaussInt(int n){
    return n * (n+1) / 2;   //De esta manero lo puedo sacar con enteros
}

int main()
{
    cout << endl;
    cout << " Gauss: " << gaussInt(6) << endl;
    cout << endl;
    return 0;
}
