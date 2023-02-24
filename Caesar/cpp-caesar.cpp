

#include <iostream>
#include <string>

#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Do you want to encrpyt(0) or decrypt(1)?" << endl;
    int choice = -1;
    cin >> choice;

    cin.ignore();

    string cipherEncrypt = "";
    int stringSize = 0;
    int shift = 0;

    switch (choice)
    {
    case 0:
        
        //string cipherEncrypt = "";

        cout << "Text to be encrypted: "; getline(cin, cipherEncrypt);
        stringSize = cipherEncrypt.size();

        shift = 0;
        cout << "Shift amount: "; cin >> shift;
        shift = shift % 26;

        for (int i = 0; i < stringSize; i++)
        {
            if (cipherEncrypt[i] == 32)
                cipherEncrypt[i] = cipherEncrypt[i];
            else
                cipherEncrypt[i] = cipherEncrypt[i] + shift;
        }
        cout << "Shifted text: " << cipherEncrypt << endl;
        break;

    case 1:

        string cipherDecrypt = "";
        cout << "Text to be decrypted: "; getline(cin, cipherDecrypt);
        stringSize = cipherDecrypt.size();

        //cin.ignore();

        int answer = -1;
        cout << "Do you know the shift(Y=0/N=1)? "; cin >> answer;

        switch (answer)
        {
        case 0:

            shift = 0;
            cout << "Enter shift amount: "; cin >> shift;
            shift = shift % 26;

            for (int i = stringSize; i >= 0; i--)
            {
                if (cipherDecrypt[i] == 32)
                    cipherDecrypt[i] = cipherDecrypt[i];
                else
                    cipherDecrypt[i] = cipherDecrypt[i] - shift;
            }

            cout << "Shifted text: " << cipherDecrypt << endl;

            break;

        case 1:

            cout << "Choose best answer" << endl;

            shift = 1;

            while (shift <= 26)
            {

                string decryptString = cipherDecrypt;
                string candidate = "";

                int shiftAmount;
                for (int i = 0; i < stringSize; i++)
                {

                    if (decryptString[i] == 32)
                        candidate += decryptString[i];
                    else
                        candidate += ((decryptString[i] - 97 - shift + 26) % 26) + 97;
                }
                cout << "Decryopted cipher: " << candidate << " Shifted amount: " << shift << endl;
                shift++;
            }
            break;

        }
        break;

    }
}

