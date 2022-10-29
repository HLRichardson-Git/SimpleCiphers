/*

    Written by: Hunter Richardson
    Last updated: October 29th 2022

    Takes a file of plaintext and encrypts with static key and creates a
    frequency table then outputs to a output file.

*/

#include <iostream>
#include <fstream>
#include <string>

#include <cmath>
#include <cstring>

using namespace std;

int main()
{

    string key = "iltganrcqwjebokuymvhfxpdzs";
    string plainText = "";
    string cipherText = "";

    float plainTextDistribution[26] = { 0 };
    float cipherTextDistribution[26] = { 0 };

    /*
        Open input file
    */
    ifstream inFile("input.txt");
    if (inFile.is_open())
    {
        string temp = "";
        while (getline(inFile, temp))
        {
            plainText = plainText + temp;
        }
        inFile.close();
    }

    /*
        Erase special characters, change uppercase to lowercase,
        populate plain/ cipher text distribution table, and create cipher text.
    */
    for (int i = 0; i < plainText.length(); i++)
    {

        // Erase special characters
        if (plainText[i] < 'A' || plainText[i] > 'Z' &&
            plainText[i] < 'a' || plainText[i] > 'z')
        {
            plainText.erase(i, 1);
            i--;
        }

        // Change uppercase to lowercase
        int c = plainText[i];
        if (isupper(c))
            plainText[i] = tolower(c);

    }

    /*
        Creating the cipher text and populating the distribution tables
    */
    for (int i = 0; i < plainText.length(); i++)
    {
        // Create cipher text
        int charIndex = plainText[i] - 97;
        cipherText += key[charIndex];

    }

    for (int i = 0; i < plainText.length(); i++)
    {
        // Populate plain text distribution table
        int charIndex = plainText[i] - 97;
        plainTextDistribution[charIndex]++;

        // Populate cipher text distribution table
        char cipherCharIndex = cipherText[i] - 97;
        cipherTextDistribution[cipherCharIndex]++;
    }

    /*
        Open and write to output file.
    */
    ofstream outFile;
    outFile.open("output.txt");
    outFile << cipherText;
    outFile.close();


    /*
        Average the distribution table.
    */
    for (int i = 0; i < 26; i++)
    {
        // Calculate percentage
        plainTextDistribution[i] = round((plainTextDistribution[i]
            / plainText.length()) * 100);

        cipherTextDistribution[i] = round((cipherTextDistribution[i]
            / cipherText.length()) * 100);
    }

    /*
        Display the distribution.
    */
    cout << "Plain Text distribution: " << endl;
    for (int i = 0; i < 26; i++)
    {
        char letter = i + 97;
        cout << letter << " : ";
        for (int j = 0; j < plainTextDistribution[i]; j++)
        {
            cout << "[]";
        }
        cout << endl;
    }

    cout << "\nCipher Text distribution: " << endl;
    for (int i = 0; i < 26; i++)
    {
        char letter = i + 97;
        cout << letter << " : ";
        for (int j = 0; j < cipherTextDistribution[i]; j++)
        {
            cout << "[]";
        }
        cout << endl;
    }

}

