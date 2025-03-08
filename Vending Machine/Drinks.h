#ifndef DRINK_H
#define DRINK_H
#include <string>
using namespace std;
class Drink
{
public:
    Drink();
    Drink(string Nam, double pricey);

    // PRINT FUNCTIONS
    void print() const
    {
        cout << "Product Name: " << NameOfDrink << ", Price" << price << " Quantity: " << DrinkInventory;
    }
    void printQuantity() const
    {

        cout << "Product Name: " << NameOfDrink << " ---- " << "Quantity: " << DrinkInventory;
    }

    // GETTER FUNCTIONS
    string getName()
    {

        return NameOfDrink;
    }

    int getQuantity()
    {
        return DrinkInventory;
    }

    double getPrice() const
    {
        return price;
    }

    // FUNCTIONAL FUNCTIONS
    void addQuantity(int quan)
    {
        DrinkInventory += quan;
    }

    // SETTER FUNCTIONS
    void setName(string nam)
    {
        NameOfDrink = nam;
    }

    void setPrice(int pri)
    {

        price = pri;
    }

    void setQuantity(int quantt)
    {
        quantt = DrinkInventory;
    }

private:
    string NameOfDrink;
    string DrinkID;
    int DrinkInventory;
    double price;
    double tax;
    double finalPrice;
};

#endif