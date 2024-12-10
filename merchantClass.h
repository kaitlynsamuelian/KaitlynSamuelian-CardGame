#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "itemClass.h"
#include "playerClass.h"

using namespace std;

class Merchant
{
private:
    string name;              // Fancy merchant name
    string merchantFile;      // File name for loading ASCII art
    vector<Item> listOfItems; // Vector of items the merchant is selling
    string message;           // Unique message for the merchant

public:
    Merchant();
    Merchant(string, string, vector<Item>, string);
    void displayMerchant(Player &player); // take Player reference
    bool isEncountered();
    vector<Item> getItems();
    void merchantArt();
};
