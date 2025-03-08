// Created by Eneojo Solomon Unwuchola
// © 2025 Eneojo Solomon Unwuchola. All rights reserved.
// Unauthorized copying of this file, via any medium, is strictly prohibited.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>
#include "Drinks.h"
using namespace std;
string MakeID()
{
    srand(time(0));
    char rLetter = "ABCDE"[rand() % 5];
    int randNum = rand() % (5 - 1 + 1) + 1;

    string convertNum = to_string(randNum);
    string convertChar(1, rLetter);
    string DrinkID = convertChar + convertNum;
    return DrinkID;
}

Drink::Drink(string Nam, double pricey)
{
    NameOfDrink = Nam;
    price = pricey;
    DrinkInventory = 5;
}

Drink::Drink()
{
    NameOfDrink = "not exist";
    price = -1;
    DrinkInventory = -1;
}

int main()
{

    map<string, Drink> ClassMap;
    srand(time(0));
    int input;
    char userLastCont = 'Y';
    do
    {
        string UserSelection = "\n-----------------------------------------------------------------\n"
                               "| SELECT NUMERICAL OPTION                                       |\n"
                               "| 1. POPULATE IN VENDING MACHINE INVENTORY                      |\n"
                               "| 2. RESTOCK DRINK IN VENDING MACHINE INVENTORY                 |\n"
                               "| 3. EDIT PRODUCT OF SPECIFIC INVENTORY SPACE                   |\n"
                               "| 4. REFILL ALL INVENTORY                                       |\n"
                               "| 5. DISPLAY ALL INVENTORY                                      |\n"
                               "| 6. SAVE & QUIT [INVENTORY/INFORMATION SAVED TO VENDING MACINE]|\n"
                               "----------------------------------------------------------------|\n";
        cout << UserSelection;
        cin >> input;

        while (input < 1 || input > 6)
        {
            cout << "WRONG SELECTION";
            cout << UserSelection;
            cin >> input;
        }

        // vars for case 1
        double DrinkPrice;
        string DrinkName;
        string DrinkId;
        char userContin;
        int count = 0;

        // vars for case 2
        int drinkAmount;

        // vars for case 3
        double changedDrinkPrice;
        string changedDrinkName;
        int changedDrinkAmount;

        // vars for case 4
        int increaseby;

        // vars for case 5

        // vars for case 6
        ofstream PutFs("drinks.txt");
        ofstream PlaceFs("storage.txt");
        map<string, Drink>::iterator it;
        switch (input)
        {

            /*
               A1,A2,A3,A4,A5
               B1,B2,B3,B4,B5
               C1,C2,C3,C4,C5
               D1,D2,D3,D4,D5
               E1,E2,E3,E4,E5
           */

        case 1:
            cout << "\n";
            cout << "-----------------------------\n";
            cout << "POPULATING VENDING MACHINE" << endl;
            cout << endl;

            for (int i = 0; i < 25 - ClassMap.size(); i++)
            {
                cout << "Enter Product Name(leave no space in name): ";
                cin.ignore();
                getline(cin, DrinkName);
                cout << "Enter Drink Price: $";
                cin >> DrinkPrice;
                do
                {
                    DrinkId = MakeID();
                } while (ClassMap.find(DrinkId) != ClassMap.end());
                ClassMap[DrinkId] = Drink(DrinkName, DrinkPrice);
                cout << DrinkId << endl;
                cout << "------------" << endl;
                count++;
                if (count % 3 == 0)
                {
                    cout << "Would you like to continue adding drinks to the vending machine? (Y/N)\n";
                    cin >> userContin;
                    toupper(userContin);
                    if (userContin == 'Y')
                    {
                        continue;
                    }
                    else
                    {
                        cout << "Product Adding Ended\n";
                        break;
                    }
                }
            }

            cout << "-----------------------------\n";
            break;

        case 2:
            cout << "\n";
            cout << "-----------------------------\n";
            cout << "Enter Drink ID to restock: ";
            cin >> DrinkId;
            if (ClassMap.find(DrinkId) != ClassMap.end())
            {
                cout << "Drink Found: " << ClassMap[DrinkId].getName() << endl;
                cout << "Drink Inventory Amount: " << ClassMap[DrinkId].getQuantity() << endl;
                cout << "Adding how many?: ";
                cin >> drinkAmount;
                ClassMap[DrinkId].addQuantity(drinkAmount);
                cout << "New Drink Inventory Amount: " << ClassMap[DrinkId].getQuantity() << endl;
                cout << "-----------------------------\n";
                cout << endl;
            }
            else
            {
                cout << "Drink not found" << endl;
                cout << "Check capitalization and for right ID" << endl;
                cout << "Also check if vending machine has been populated" << endl;
                cout << "-----------------------------\n";
            }
            break;

        case 3:
            cout << "-----------------------------\n";
            cout << "EDIT PRODUCT OF DRINK INVENTORY\n";
            cout << "Enter Drink ID for editing: ";
            cin >> DrinkId;
            cout << "\n";
            if (ClassMap.find(DrinkId) != ClassMap.end())
            {
                cout << "Displaying Drink Information\n";
                cout << "Drink Name:  " << ClassMap[DrinkId].getName() << "\n";
                cout << "Drink Price: $" << ClassMap[DrinkId].getPrice() << "\n";
                cout << "Drink Quantity: " << ClassMap[DrinkId].getQuantity() << "\n";
                cout << "\n";

                cout << "Enter New Drink Name: ";
                cin.ignore();
                getline(cin, changedDrinkName);
                cout << "Enter New Drink Price: $";
                cin >> changedDrinkPrice;
                cout << "Enter New Drink Quantity: ";
                cin >> changedDrinkAmount;
                cout << "\n";

                ClassMap[DrinkId].setName(changedDrinkName);
                ClassMap[DrinkId].setPrice(changedDrinkPrice);
                ClassMap[DrinkId].setQuantity(changedDrinkAmount);

                cout << "Displaying New Drink Information\n";
                cout << "Drink Name:  " << ClassMap[DrinkId].getName() << "\n";
                cout << "Drink Price: $" << ClassMap[DrinkId].getPrice() << "\n";
                cout << "Drink Quantity: " << ClassMap[DrinkId].getQuantity() << "\n";
                cout << "\n";
            }
            else
            {
                cout << "Drink not found" << endl;
                cout << "Check capitalization and for correct ID" << endl;
                cout << "Also check if vending machine has been populated" << endl;
                cout << "-----------------------------\n";
            }
            break;

        case 4:
            cout << "-----------------------------\n";
            cout << "INCREASE ALL DRINK QUANTITIES BY: ";
            cin >> increaseby;

            for (map<string, Drink>::iterator it = ClassMap.begin(); it != ClassMap.end(); ++it)
            {
                it->second.addQuantity(increaseby);
                cout << "Drink ID: " << it->first << " - New Quantity: " << it->second.getQuantity() << endl;
            }
            cout << "-----------------------------\n";
            break;

        case 5:

            cout << "-----------------------------\n";
            cout << "ALL PRODUCTS IN VENDING MACHINE\n";

            if (ClassMap.empty())
            {
                cout << "No Drink Products available\n";
                cout << "Populate the vending machine\n";
            }
            else
            {
                map<string, Drink>::iterator it;
                for (it = ClassMap.begin(); it != ClassMap.end(); ++it)
                {
                    cout << "-----------------------------\n";
                    cout << "Drink ID: " << it->first << "\n";
                    cout << "Drink Name: " << it->second.getName() << "\n";
                    cout << "Drink Price: $" << it->second.getPrice() << "\n";
                    cout << "Drink Quantity: " << it->second.getQuantity() << "\n";
                    cout << "-----------------------------\n";
                }
            }

            break;

        case 6:

            if (PutFs.is_open() && PlaceFs.is_open())
            {
                cout << "\n";
                cout << "Success opening files, saving information" << endl;
                for (it = ClassMap.begin(); it != ClassMap.end(); ++it)
                {
                    PutFs << "-----------------------------\n";

                    PutFs << "Drink ID: " << it->first << "\n";
                    PutFs << "Drink Name: " << it->second.getName() << "\n";
                    PutFs << "Drink Price: $" << it->second.getPrice() << "\n";
                    PutFs << "Drink Quantity: " << it->second.getQuantity() << "\n";
                    PutFs << "-----------------------------\n";
                }

                for (it = ClassMap.begin(); it != ClassMap.end(); ++it)
                {

                    PlaceFs << it->first << " " << it->second.getName() << " " << it->second.getPrice() << " " << it->second.getQuantity() << "\n";
                }
                cout << "Information saved to drinks.txt file and storage.txt\n";
                // drinks.txt file is for the vending.cpp
                // storage.txt file is for the admins to properly see information
                PutFs.close();
            }
            else
            {
                cout << "Unable to open file for writng" << endl;
                cout << "Try again" << endl;
            }
            return 0;
            break;
        default:
            cout << "ERROR ERROR ERROR" << endl;
            return 1;
            break;
        }

        cout << "Continue to main menu selection(Y/N): ";
        cin >> userLastCont;
        userLastCont = toupper(userLastCont);
    } while (userLastCont == 'Y');

    cout << "Thanks for using the program by Eneojo Solomon Unwuchola\n";
    cout << "To access the vending machine use the vending.cpp file\n";

    return 0;
}