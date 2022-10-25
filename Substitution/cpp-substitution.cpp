#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include<algorithm>

using namespace std;

int main()
{

    string substitute = "";
    int stringSize = 0;
    bool check = false;

    do
    {
        cout << "Enter word without dupliate letters: "; cin >> substitute;
        stringSize = substitute.size();

        cin.ignore();

        check = false;
        for (int i = 0; i < stringSize; i++)
        {
            for (int j = i + 1; j < stringSize; j++)
            {
                if (substitute[i] == substitute[j] && substitute[i] != '0') check = true;
            }
        }
    } while (check == true);

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string cipherAlphabet = "abcdefghijklmnopqrstuvwxyz";
    char subArray[26];
    char cipherArray[26];

    for (int i = 0; i < stringSize; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (substitute[i] == alphabet[j]) cipherAlphabet.erase(remove(cipherAlphabet.begin(), cipherAlphabet.end(), substitute[i]), cipherAlphabet.end());
        }
    }

    cipherAlphabet = substitute + cipherAlphabet;
    cout << cipherAlphabet << endl;

    string cipherText = "";
    cout << "Enter cipher text: "; getline(cin, cipherText);
    int cipherSize = cipherText.size();

    string encryptedText = "";
    
    for (int i = 0; i < cipherSize; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (cipherText[i] == ' ')
            {
                encryptedText = encryptedText + ' '; 
                break;
            }

            if (cipherText[i] == alphabet[j]) encryptedText = encryptedText + cipherAlphabet[j];
        }
    }

    cout << "Encrypted text: " << encryptedText << endl;


}
