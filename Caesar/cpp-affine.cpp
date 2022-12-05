
#include <iostream>
#include <string>
#include<bits/stdc++.h>

using namespace std;

string encryption(string alphabet,int a, int b);
string decryption(string alphabet, int a, int b);

int main()
{
    
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string text = "";

    int a, b = 0;
    cout << "Enter variables for (ax+b)" << endl;
    cout << "a= "; cin >> a; cout << "b= "; cin >> b;   

    int input = -1;
    bool flag = false;

    while (!flag)
    {

        cout << "Would you like to Encrypt(1) or Decrypt(0)?"; cin >> input;

        switch (input)
        {
        case 0:
            text = decryption(alphabet, a, b);
            flag = true;
            break;
        case 1:
            text = encryption(alphabet, a, b);
            flag = true;
            break;
        default:
            cout << "ERROR: Incorrect input, please enter a 1 or 0" << endl;
            flag = false;
            break;
        }

    }

    cout << text << endl;
    
    
}

string encryption(string alphabet, int a, int b)
{

    string plainText = "";
    cout << "Enter Plain Text: ";
    cin >> plainText;

    transform(plainText.begin(), plainText.end(), plainText.begin(), ::tolower);

    string cipherText = "";

    int x = -1;
    int index = -1;

    for (int i = 0; i < plainText.length(); i++)
    {

        x = (int(plainText[i]) - 19) % 26;
        index = ((a * x) + b) % 26;

        cipherText += alphabet[index];

    }

    return cipherText;

}

string decryption(string alphabet, int a, int b)
{

    string cipherText = "";
    cout << "Enter Cipher Text: ";
    cin >> cipherText;

    transform(cipherText.begin(), cipherText.end(), cipherText.begin(), ::tolower);

    string plainText = "";

    int a_inverse = 0;

    for (int i = 0; i < 26; i++)
    {

        if (((a * i) % 26) == 1)
        {
            a_inverse = i;
            break;
        }

    }

    int x = -1;
    int index = -1;


    for (int i = 0; i < cipherText.length(); i++)
    {

        x = (int(cipherText[i]) - 19) % 26;
        index = (((a_inverse * (x - b)) % 26) + 26)%26;

        plainText += alphabet[index];

    }

    return plainText;

}


