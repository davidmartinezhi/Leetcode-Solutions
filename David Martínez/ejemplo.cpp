#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
bool repitedNumbers1(vector<int> nums)
{
    vector<int> nums = {4, 5, 6, 2, 1, 10, -4};

    // Sort
    sort(nums.begin(), nums.end()); // Runtime: O(n log n)

    // Busco numeros repetidos
    for (int i = 1; i < nums.size(); i++)
    { // Runtime: O(n)
        if (nums[i] == nums[i - 1])
        {
            return true;
        }
    }

    // Si no encuentra ningún numero repetido
    return false;

    // Runtime: O(n log n)
    // Memory: O(1), no usa variables extras
}

bool repitedNumbers2(vector<int> nums)
{
    vector<int> nums = {4, 5, 6, 2, 1, 10, -4};

    // Recorro cada elemento de la lista
    for (int i = 0; i < nums.size(); i++)
    { // Runtime: O(n)

        // Para ese elemento, checo el resto de la lista
        for (int j = 0; j < nums.size(); j++)
        { // Runtime: O(n)

            // Checo si se repite el número
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }

    // Si no encuentra ningún numero repetido
    return false;

    // Runtime: O(n^2)
    // Memory: O(1)
}

bool repitedNumbers3(vector<int> nums)
{
    vector<int> nums = {4, 5, 6, 2, 1, 10, -4};

    // Hashtable
    unordered_map<int, int> numsHashTable;

    // Recorro el vector nums
    for (int i = 0; i < nums.size(); i++)
    {

        // Agrego el dato a nums y le sumo uno a su contador
        numsHashTable[nums[i]]++;

        // Si tiene 2 datos, significa que se repiten
        if (numsHashTable[nums[i]] == 2)
        {
            return true;
        }
    }

    return false;

    // Runtime: O(n)
    // Memory: O(n), usas espacio extra para guardar todos los datos de nums
}

bool repitedNumbers4(vector<int> nums)
{
    vector<int> nums = {4, 5, 6, 2, 1, 10, -4, 2, 2};

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            for(int k = j; k < nums.size(); k++) {
                if (nums[j] == nums[i] && nums[i] == nums[k])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool repitedNumbers5(vector<int> nums)
{
    vector<int> nums = {4, 5, 6, 2, 1, 10, -4};

    // Hashtable
    unordered_map<int, int> numsHashTable;

    // Recorro el vector nums
    for (int i = 0; i < nums.size(); i++)
    {

        // Agrego el dato a nums y le sumo uno a su contador
        numsHashTable[nums[i]]++;

        // Si tiene 2 datos, significa que se repiten
        if (numsHashTable[nums[i]] == 3)
        {
            return true;
        }
    }

    return false;

    // Runtime: O(n)
    // Memory: O(n), usas espacio extra para guardar todos los datos de nums
}
*/

int recursividadCuenta(int n){

    //Caso Base
    if(n == 1){
        return 1; //1*1
    }

    //Regreso cuenta pasada
    return n*n + recursividadCuenta(n-1);
}

int main()
{

    cout << recursividadCuenta(3) << endl;

}

