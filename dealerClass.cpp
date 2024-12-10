#include "dealerClass.h"
#include <iostream>
#include <fstream>
using namespace std;

void Dealer::addToHand(Card newCard)
{
    currentHand.push_back(newCard);
}

void Dealer::displayCard(Card currentCard)
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

void Dealer::displayHand()
{
    for (size_t i = 0; i < currentHand.size(); i++)
    {
        displayCard(currentHand[i]);
    }
}

vector<Card> Dealer::getHand()
{
    return currentHand;
}

int Dealer::calculateRankCount()
{
    int dealerRankCount = 0;

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

        if (count > dealerRankCount)
        {
            dealerRankCount = count;
        }
    }

    return dealerRankCount;
}

void Dealer::clearHand()
{
    currentHand.clear();
}

int Dealer::calculateHighestRankedCard()
{
    int dealerRankCount = 0;
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

        if (count > dealerRankCount)
        {
            dealerRankCount = count;
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

int Dealer::getHandTotalValue()
{
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
