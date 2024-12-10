
#include "merchantClass.h"
#include "gameLogic.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

Merchant getRandomMerchant()
{
    vector<Merchant> merchants;

    vector<Item> johnItems;
    johnItems.push_back(Item("Pack of Gum", 5));
    johnItems.push_back(Item("Lemonade", 10));
    johnItems.push_back(Item("Hamburger", 15));
    johnItems.push_back(Item("Energy drink", 20));
    merchants.push_back(Merchant("John", "MJ.txt", johnItems, "Welcome! I have 4 items for you to chose from. What would you like to buy?"));

    vector<Item> bobItems;
    bobItems.push_back(Item("Pack of Gum", 5));
    bobItems.push_back(Item("Lemonade", 10));
    bobItems.push_back(Item("Hamburger", 15));
    merchants.push_back(Merchant("Bob", "MB.txt", bobItems, "Greetings! Take a look at my items and tell me what you would like."));

    vector<Item> danItems;
    danItems.push_back(Item("Pack of Gum", 5));
    danItems.push_back(Item("Lemonade", 10));
    merchants.push_back(Merchant("Dan", "MD.txt", danItems, "Hello there! Check out my items and please purchase!"));

    vector<Item> alexItems;
    alexItems.push_back(Item("Pack of Gum", 5));
    merchants.push_back(Merchant("Alex", "MA.txt", alexItems, "Hi! Here is the one item I can offer you."));

    Merchant encounteredMerchant;
    bool merchantFound = false;

    // Ensure a merchant is always encountered by using while loop
    while (!merchantFound)
    {
        double randomPercent = static_cast<double>(rand()) / RAND_MAX;

        if (randomPercent < 0.1)
        {
            encounteredMerchant = merchants[0]; // John, 10% chance
            merchantFound = true;
        }
        else if (randomPercent < 0.2)
        {
            encounteredMerchant = merchants[1]; // Bob, 20% chance
            merchantFound = true;
        }
        else if (randomPercent < 0.3)
        {
            encounteredMerchant = merchants[2]; // Dan, 30% chance
            merchantFound = true;
        }
        else if (randomPercent < 0.4)
        {
            encounteredMerchant = merchants[3]; // Alex, 40% chance, 100% chance overall
            merchantFound = true;
        }
    }

    return encounteredMerchant;
}
void displayMenu()
{
    int choice;
    const int minBet = 5;
    // SET THE MINIUM BET TO BE 5
    Player player1;
    // CREATE A PLAYER OBJECT

    do
    {
        cout << "Kaitlyn's Card Game Menu" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. Instructions/Information" << endl;
        cout << "3. Go to Merchant" << endl;
        cout << "4. Previous Game summary" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            ThreeCardPokerGame game(minBet, true, player1);
            game.playRankBasedGame();
            player1.displayCurrentBalanceAndItems();
            break;
        }
        case 2:
        {
            cout << "Welcome to a modified, family friendly version of Poker!";
            cout << " This game is simple but fun! Here is a rundown of how to play." << endl;
            cout << "You will start off with an inital balance of $100 (yay!)" << endl;
            cout << "The main goal of the game is to get as many cards of the same rank as possible." << endl;
            cout << "You will be playing against a dealer, and whoever has more cards of the same rank will win." << endl;
            cout << "What happens if you tie:" << endl;
            cout << "   -If you each have one pair (2 cards of the same rank, 1 card of different rank)," << endl;
            cout << "   -the count displayed will be 2 for both you and the dealer." << endl;
            cout << "   -You will get one try to drop the different card and hopefully end up with 3 cards" << endl;
            cout << "   -of the same rank. If after this, you still only have 2 cards of the rank, the winner" << endl;
            cout << "   -will be determined based on whoevers pair is of the highest rank" << endl;
            cout << "" << endl;
            cout << "   -if you each have no pairs, the count displayed for both you and the dealer will say 1." << endl;
            cout << "   -you will have up to 3 tries to hopefully get a pair and beat the dealer. If you dont," << endl;
            cout << "   -the winner will be calculated by whoevers hand adds up to the most points." << endl;
            cout << "       - A two card would be worth 2, a three card 3 and so on." << endl;
            cout << "       - Ace is worth 11, jack is worth 12, queen is worth 13, and king is worth 14." << endl;
            cout << "" << endl;
            cout << "Betting:" << endl;
            cout << "   -there is a minimum bet of 5 dollars. " << endl;
            cout << "   -each time you play you will have to make 2 bets: ANTE and PLAY" << endl;
            cout << "   -the ANTE bet will be made first, then you will see your hand." << endl;
            cout << "   -if you wish to keep playing, you will enter y for yes and the play bet will be made." << endl;
            cout << "   -NOTE : the play bet will automatically match the ANTE bet" << endl;
            cout << "   -NOTE: the more you bet the more you win!" << endl;
            cout << "     -NOTE: If you have less money then $5 when you start a game," << endl;
            cout << "            you will need to exit the game, recompile and play again." << endl;
            cout << "            (remember the complie line is in the read me file!)" << endl;
            cout << "" << endl;
            cout << "Merchant: " << endl;
            cout << "   -There are 4 merchants, each with different items.";
            cout << "   -One only has 4 items, one has 3, and so on." << endl;
            cout << "   -Each time you select the option go to merchant, you will get one by random!" << endl;
            cout << "    -To purchase an item, type the number in the order you see them" << endl;
            cout << "          -For Example:(If merchant has 4 items) Type 1 for gum, 2 for lemonade, 3 for hamburger or 4 for energy drink." << endl;
            cout << "" << endl;
            cout << "Game summary:" << endl;
            cout << "     -If you wish to place your balance and items owned in a file enter 4";
            cout << " on main menu to do so " << endl;
            cout << "     -You can then open that file  and view them by following directions on the screen." << endl;
            cout << "" << endl;
            bool doneReading = true;
            while (doneReading)
            {
                int instructionsChoice;
                cout << "" << endl;
                cout << "ONCE YOU ARE DONE READING TYPE 1 TO RETURN TO MAIN MENU" << endl;
                cin >> instructionsChoice;
                if (instructionsChoice == 1)
                {
                    doneReading = false;
                    break;
                }
                else
                {
                    cout << "Error. please Enter 1 to go back to main menu." << endl;
                }
            }
            break;
        }
        case 3:
        {
            player1.displayCurrentBalanceAndItems();
            Merchant merchant = getRandomMerchant();
            merchant.displayMerchant(player1);
            break;
        }
        case 4:
        {
            player1.createSummaryFile();
            cout << "Your previous game stats are now being held in a file" << endl;
            int summaryFileChoice;
            cout << "If you wish to see them, Enter 1" << endl;
            cin >> summaryFileChoice;
            if (summaryFileChoice == 1)
            {
                player1.displaySummaryFile();
                int fileChoice;
                do
                {
                    cout << "Once your done reading the file, type 1 to return to main menu" << endl;
                    cin >> fileChoice;
                    if (fileChoice == 1)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Error: please try again" << endl;
                    }
                } while (fileChoice != 1);
            }
            break;
        }
        case 5:
        {
            cout << "Exiting the game. Goodbye!" << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
}

int main()
{
    // srand(static_cast<unsigned int>(time(0)));  // Seed
    displayMenu();
    return 0;
}

