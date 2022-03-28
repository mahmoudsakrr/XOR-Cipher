/*
Program Name: XOR Cipher Generator
Program Purpose: This program encrypts and decrypts messages using xor cipher
Version: 1.0
Last Modification Date: 18/3/2022
Author: Mahmoud Hosam Sakr
ID: 20210368
Group: A
Institution: FCAI - CU
Presented to: Dr. Mohamed El Ramly
Teaching Assistant: ----
*/

#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

void encrypt();
void decrypt();                             // Function prototyping
void operate();
void ExitOrNah();

string scrtKey;
string mess;                                //declaring the message and the secret key to use them freely throughout the program

int main()
{
    
    cout << "Welcome to the XOR Cipher Generator\n";
    while (true)                            // main loop
    operate();
}

void operate()
{   
    cout << "Please choose the operation you'd like to perform\n";
    cout << "1- Encryption\n2-Decryption\n3-Exit\n";
    int op;
    cin >> op;                              // entering the index of the operation and
    switch (op)                             // executing the corresponding function
    {
        case 1: 
            encrypt();
            ExitOrNah();                    // encrypting the message then asking if the user wants to quit
            break;
        case 2:
            decrypt();
            ExitOrNah();                    // decrypting the message then asking if the user wants to quit
            break;
        case 3:
            exit(0);                        // quitting the program
            break;
        default:
            cout << "Invalid Operation Index.\nPlease enter a valid operation index\n";
            cin >> op;                      // checking for invalid indexes
            break;
    }
}


void encrypt()
{
    cout << "Please enter the secret key\n";
    cin.ignore();
    getline(cin, scrtKey);

    while (scrtKey.size() > 1)              // checking for invalid secret keys (the secret key is a single character)
    {
        cout << "Invalid Key. Please enter a single character\n";
        getline(cin, scrtKey);
    }

    cout << "Please enter the message you'd like to encrypt\n";
    getline(cin, mess);                     // getting the message from the user

    cout << "The ciphered message in hexadecimal: ";
    for (int i = 0; i < mess.size(); i++)
    {
        mess.at(i) = mess.at(i) ^ scrtKey.at(0);       // XORing each character in the message with the secret key
        cout << hex << setw(2) << setfill('0') << int(mess.at(i)) << " ";       // displaying the cipher in hex
    }
    cout << "\nThe ciphered message: ";
    cout << endl << mess << endl;           // displaying the cipher in normal text

}


void decrypt()
{
    cout << "Please enter the secret key\n";
    cin.ignore();
    getline(cin, scrtKey);

    while (scrtKey.size() > 1)              // checking for invalid secret keys (the secret key is a single character)
    {
        cout << "Invalid Key. Please enter a single character\n";
        getline(cin, scrtKey);
    }

    cout << "Please enter the message you'd like to decrypt\n";
    getline(cin, mess);                     // getting the message from the user

    for (int i = 0; i < mess.size(); i++)
    {
        mess.at(i) = mess.at(i) ^ scrtKey.at(0);       // XORing each character in the message with the secret key
    }

    cout << endl << mess << endl;           // displaying the deciphered message in normal text
    cout << "Is this the desired message?\n";    // checking if the deciphered message is the desired message
    string enq;
    getline(cin, enq);

    for (int i = 0; i < enq.size(); i++)
    {
        enq.at(i) = tolower(enq.at(i));
    }
    if (enq != "yes")
    {
        cout << "Please enter your message in hexadecimal format\n";          // if it is not the desired message the user enters the message in hex
        getline(cin, mess);                                                         // as hex characters are shown even for unreadable characters
        for (int i = 0; i < mess.size(); i += 2)
        {
            string hxs = mess.substr(i, 2);
            stringstream x(hxs);
            int hxi = 0;
            x >> hex >> hxi;
            cout << (char)(hxi ^ (int)scrtKey.at(0));                                  // XORing with the secret key and displaying the character
        }
        cout << endl;
    }

}

void ExitOrNah()
{
    cout << "Do you want to quit?\n";
    string ans;
    getline(cin, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        ans.at(i) = tolower(ans.at(i));
    }
    if (ans == "yes")
    {
    cout << "Thanks for using the XOR Cipher Generator!\n";
    exit(0);
    }
    else
    cout << endl;
}