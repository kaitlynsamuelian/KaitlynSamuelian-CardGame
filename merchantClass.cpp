#include "merchantClass.h"
Merchant::Merchant()
{
    name = "no name";
    merchantFile = "no file";
    listOfItems = vector<Item>();
    message = "no message";
}
Merchant::Merchant(string n, string file, vector<Item> items, string msg)
{
    name = n;
    merchantFile = file;
    listOfItems = items;
    message = msg;
}
void Merchant::displayMerchant(Player &player)
{
    bool correctChoice = false;
    merchantArt();
    cout << "Hello, my name is " << name << "!" << endl;
    cout << message << "\n";
    cout << "The items I have are:" << endl;
    for (int i = 0; i < listOfItems.size(); i++)
    {
        cout << "- " << listOfItems[i].getName() << " (Price: " << listOfItems[i].getPrice() << ")" << endl;
    }
    do
    {
        int choice;
        cout << "What item would you like to buy(Type the line number your item is on)? If you dont wish to buy anything, select 0 to return to the main menu." << endl;
        cin >> choice;

        // Check if the input is valid
        if (choice < 0 || choice > listOfItems.size())
        {
            cout << "Invalid choice. Please try again." << endl;
            correctChoice = false;
            continue;
        }

        if (choice == 0)
        {
            cout << "Exiting merchant menu." << endl;
            correctChoice = true;
            break;
        }

        // if the item is purchased
        Item selectedItem = listOfItems[choice - 1];
        if (player.getCurrentBalance() >= selectedItem.getPrice())
        {
            player.setCurrentBalance(-selectedItem.getPrice());
            player.addItem(selectedItem); // Add item to player's inventory
            cout << "You have purchased " << selectedItem.getName() << " for $" << selectedItem.getPrice() << "." << endl;
            player.displayCurrentBalanceAndItems();
            bool validBuyAgainChoice = true;
            do
            {
                int buyAgainChoice;
                cout << "Enter 1 to buy more items or enter 2 to return to main menu." << endl;
                cin >> buyAgainChoice;
                if (buyAgainChoice != 1 && buyAgainChoice != 2)
                {
                    cout << "Please enter a valid Choice" << endl;
                    validBuyAgainChoice = false;
                    continue;
                }
                else
                {
                    validBuyAgainChoice = true;
                    switch (buyAgainChoice)
                    {
                    case 1:
                        correctChoice = false;
                        break;
                    case 2:
                        cout << "Exiting merchant menu." << endl;
                        correctChoice = true;
                        break;
                    default:
                        cout << "please enter a valid choice" << endl;
                        break;
                    }
                }
            } while (validBuyAgainChoice == false);
        }
        else
        {
            cout << "You do not have enough balance to buy this item. Either buy a different item or return to the main menu." << endl;
            correctChoice = false;
        }
    } while (correctChoice == false);
}

vector<Item> Merchant::getItems()
{
    return listOfItems;
}

void Merchant::merchantArt()
{
    ifstream artFile(merchantFile);

    if (artFile.is_open())
    {
        string line;
        while (getline(artFile, line))
        {
            cout << line << endl;
        }
        artFile.close();
    }
    else
    {
        cout << "Error: Unable to open file " << merchantFile << endl;
    }
}
