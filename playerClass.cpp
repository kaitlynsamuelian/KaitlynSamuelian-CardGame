#include "playerClass.h"
#include <iostream>
#include <fstream>

using namespace std;
//initalize players balance as 100 since this is starting balance
Player::Player()
{
    currentBalance = 100;
}
//function to add a new card to players hand
void Player::addToHand(Card newCard)
{
    currentHand.push_back(newCard);
}

//function to display each card
//load in the ascii art for the card
void Player::displayCard(Card currentCard)
{
    string fileName = currentCard.getFileName();
    ifstream cardFile(fileName);

    if (cardFile.is_open())
    {
        string line;
        while (getline(cardFile, line))
        {
            cout << line << endl;
        }
        cardFile.close();
    }
    else
    {
        cout << "Error opening file: " << fileName << endl;
    }
}
//use the display card function to create
// a function to display all three cards in the players hand
void Player::displayHand()
{
    for (size_t i = 0; i < currentHand.size(); i++)
    {
        displayCard(currentHand[i]);
    }
}
//function to get the three cards in the players hand
vector<Card> Player::getHand()
{
    return currentHand;
}

int Player::calculateRankCount()
{
    int playerRankCount = 0;
    int highestRankedCard = 0;

    for (int i = 0; i < currentHand.size(); i++)
    {
        int count = 1;

        for (int j = i + 1; j < currentHand.size(); j++)
        {
            if (currentHand[i].getRank() == currentHand[j].getRank())
            {
                count++;
            }
        }

        if (count > playerRankCount)
        {
            playerRankCount = count;
        }
    }

    return playerRankCount;
}
int Player::calculateHighestRank()
{
    //find the players highest ranked card
    //build off of the rank count function to
    //find the highest rank card in the pair
    //since the player has to have a pair to win
    int playerRankCount = 0;
    int highestRankedCard = 0;

    for (int i = 0; i < currentHand.size(); i++)
    {
        int count = 1;

        for (int j = i + 1; j < currentHand.size(); j++)
        {
            if (currentHand[i].getRank() == currentHand[j].getRank())
            {
                count++;
            }
        }

        if (count > playerRankCount)
        {
            playerRankCount = count;
            if (currentHand[i].getRank() == "2")
            {
                highestRankedCard = 2;
            }
            else if (currentHand[i].getRank() == "3")
            {
                highestRankedCard = 3;
            }
            else if (currentHand[i].getRank() == "4")
            {
                highestRankedCard = 4;
            }
            else if (currentHand[i].getRank() == "5")
            {
                highestRankedCard = 5;
            }
            else if (currentHand[i].getRank() == "6")
            {
                highestRankedCard = 6;
            }
            else if (currentHand[i].getRank() == "7")
            {
                highestRankedCard = 7;
            }
            else if (currentHand[i].getRank() == "8")
            {
                highestRankedCard = 8;
            }
            else if (currentHand[i].getRank() == "9")
            {
                highestRankedCard = 9;
            }
            else if (currentHand[i].getRank() == "10")
            {
                highestRankedCard = 10;
            }
            else if (currentHand[i].getRank() == "A")
            {
                highestRankedCard = 11;
            }
            else if (currentHand[i].getRank() == "J")
            {
                highestRankedCard = 12;
            }
            else if (currentHand[i].getRank() == "Q")
            {
                highestRankedCard = 13;
            }
            else if (currentHand[i].getRank() == "K")
            {
                highestRankedCard = 14;
            }
        }
    }

    return highestRankedCard;
}
int Player::getHandTotalValue()
{
    //create a function to get the players hand total value, based on rank of cards
    //since ranks are strings
    //use if statements to check if the current card is equal to a certain number,
    //then add that number to the total
    handTotalValue = 0;
    for (int i = 0; i < currentHand.size(); i++)
    {
        if (currentHand[i].getRank() == "2")
        {
            handTotalValue += 2;
        }
        else if (currentHand[i].getRank() == "3")
        {
            handTotalValue += 3;
        }
        else if (currentHand[i].getRank() == "4")
        {
            handTotalValue += 4;
        }
        else if (currentHand[i].getRank() == "5")
        {
            handTotalValue += 5;
        }
        else if (currentHand[i].getRank() == "6")
        {
            handTotalValue += 6;
        }
        else if (currentHand[i].getRank() == "7")
        {
            handTotalValue += 7;
        }
        else if (currentHand[i].getRank() == "8")
        {
            handTotalValue += 8;
        }
        else if (currentHand[i].getRank() == "9")
        {
            handTotalValue += 9;
        }
        else if (currentHand[i].getRank() == "10")
        {
            handTotalValue += 10;
        }
        else if (currentHand[i].getRank() == "A")
        {
            handTotalValue += 11;
        }
        else if (currentHand[i].getRank() == "J")
        {
            handTotalValue += 12;
        }
        else if (currentHand[i].getRank() == "Q")
        {
            handTotalValue += 13;
        }
        else if (currentHand[i].getRank() == "K")
        {
            handTotalValue += 14;
        }
    }
    return handTotalValue;
}
//create a function to replace the card (happens if the players pair count is tied with the dealer)
void Player::replaceCard(int cardRemovedIndex, vector<Card> deck)
{
    if (cardRemovedIndex >= 0 && cardRemovedIndex < currentHand.size())
    {
        Card removedCard = currentHand[cardRemovedIndex];

        // Find a new card that is different from the removed card
        Card newCard;
        bool cardFound = false;

        // Loop until we find a card different from the removed card
        while (!cardFound && !deck.empty())
        {
            // Get a card from the deck
            newCard = deck.back(); //use back function to assign the last elemnt of the vector to new card
            deck.pop_back();       // Remove that card from the deck

            // Check new card is different from the removed card
            if (newCard.getRank() != removedCard.getRank() || newCard.getSuit() != removedCard.getSuit())
            {
                cardFound = true; // if new card is different set the bool value to true
            }
            else
            {
                // If the card is the same as the removed card, put it back into the deck at the begging
                //to avoid repeated checks
                deck.insert(deck.begin(), newCard);
            }
        }

        if (cardFound)
        {
            // if the boolean was true, a diff card was found so replace the card being removed in hand
            currentHand[cardRemovedIndex] = newCard;
        }
        else
        {
            // Handle the case where no valid new card was found (deck was empty or no valid card left)
            cout << "No valid card found in the deck to replace the removed card." << endl;
        }
    }
}

//function to clear a hand
void Player::clearHand()
{
    currentHand.clear();
}
//getter function to print the balance
int Player::getCurrentBalance()
{
    return currentBalance;
}
//function to adjust the current balance
void Player::setCurrentBalance(int moneyWon)
{
    currentBalance = currentBalance + moneyWon;
}
//function to display the current balance
void Player::displayCurrentBalanceAndItems()
{
    cout << "Current balance: $" << currentBalance << endl;
    cout << "Purchased items:" << endl;
    if (purchasedItems.empty())
    {
        cout << "0 items purchased" << endl;
    }
    else
    {
        for (int i = 0; i < purchasedItems.size(); i++)
        {
            cout << "- " << purchasedItems[i].getName() << endl;
        }
    }
}
void Player::addItem(Item &item)
{
    purchasedItems.push_back(item);
}

vector<Item> Player::getCurrentItems()
{
    return purchasedItems;
}
void Player::createSummaryFile()
{
    ofstream summaryFile("Summary.txt");

    summaryFile << "Current balance: $" << currentBalance << endl;
    summaryFile << "Purchased items: " << endl;
    if (purchasedItems.empty())
    {
        summaryFile << "No items have been purchased" << endl;
    }
    else
    {
        for (int i = 0; i < purchasedItems.size(); i++)
        {
            summaryFile << "- " << purchasedItems[i].getName() << endl;
        }
    }
    summaryFile.close();
}
void Player::displaySummaryFile()
{
    ifstream inFile("Summary.txt");

    if (!inFile.is_open())
    {
        cout << "Error: Unable to open file " << endl;
        return;
    }

    string line;
    while (getline(inFile, line))
    {
        cout << line << endl;
    }
    inFile.close();
}