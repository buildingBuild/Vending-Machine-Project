// Created by Eneojo Solomon Unwuchola
// © 2025 Eneojo Solomon Unwuchola. All rights reserved.
// Unauthorized copying of this file, via any medium, is strictly prohibited.

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Drinks.h"
using namespace std;

int main()
{

    string machineDisplay = "A1 A2 A3 A4 A5\n"
                            "B1 B2 B3 B4 B5\n"
                            "C1 C2 C3 C4 C5\n"
                            "D1 D2 D3 D4 D5\n"
                            "E1 E2 E3 E4 E5\n";
    string input;
    /// its assumed the user can see it
    /// its assumed the vending machine is fully populated
    while (true)
    {
        cout << "\nUser Select a Drink option\n";
        cout << machineDisplay << "\n";
        cout << "Select: ";
        cin >> input;

        if (input.length() == 2 && machineDisplay.find(input) != string::npos)
        {
            cout << "Selection Found!\n";
            cout << "\n";
            break; // Exit loop when input is valid
        }
        else
        {
            cout << "Selection not Found\n";
        }
    }

    /// Vars for reading in information
    string line;
    string idDrink;
    string itemName;
    double price;
    int quantity;
    bool found = false;
    /// User Selection in information
    char userInput;

    ifstream BringFs("storage.txt");
    if (!BringFs.is_open())
    {
        cout << "Error using Vending Machine" << endl;
        return 1;
    }
    else
    {

        cout << "Vending Process Started" << "\n";
        cout << "-----------------------" << "\n";
        while (BringFs >> idDrink)
        {
            if (idDrink == input)
            {
                BringFs >> itemName >> price >> quantity;
                found = true;
                break;
            }
            else
            {
                continue;
            }
        }
        if (!found)
        {
            cout << "Drink is not available!\n"; // populate the vending machine location in storageVending.cpp
            cout << "--Possible error fixes--\n";
            cout << "Must Populate the vending Machine location at " << input << "and save information \n";
            cout << "\n";
            return 0;
        }
    }

    if (quantity > 0)
    {

        cout << "Cost: $" << price << "\n";
        cout << "Drink Name: " << itemName << "\n";
        cout << "Would you like to Purchase(Y/N): ";
        cin >> userInput;
        userInput = toupper(userInput);
        cout << "\n";
        if (userInput == 'Y')
        {
            cout << "PURCHASED..... " << itemName << " Drink" << endl;
            cout << "ENJOY!\n";
            cout << "\n";
            quantity -= 1; // would love to add this feature but would be hard for user due to more files needed
            return 0;
        }
        else
        {
            exit(0);
        }
    }

    BringFs.close();

    return 0;
}
