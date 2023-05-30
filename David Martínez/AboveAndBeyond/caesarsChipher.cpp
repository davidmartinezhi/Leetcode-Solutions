
#include <iostream>
using namespace std;

void caesarsChipher(string text, int shift)
{

    // declare new string
    string chipheredText = "";

    // traverse string
    for (int i = 0; i < text.size(); i++)
    {

        if (isupper(text[i]))
        {
            // get ascii value
            int asciiPosition = text[i] - 'A';

            int movement = (asciiPosition + shift) % 26;

            char newChar = 'A' + movement;

            cout << newChar << endl;

            chipheredText += newChar;
        }
        else
        {
            // get ascii value
            int asciiPosition = text[i] - 'a';

            int movement = (asciiPosition + shift) % 26;

            char newChar = 'a' + movement;

            cout << newChar << endl;

            chipheredText += newChar;
        }
    }

    // return new string
    cout << chipheredText << endl;
}

int main()
{

    // declare variable
    string text;
    int shift;

    cout << "Enter Text: ";
    cin >> text;

    cout << "Enter Shift value: ";
    cin >> shift;

    caesarsChipher(text, shift);
}