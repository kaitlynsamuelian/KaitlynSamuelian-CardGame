#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include <vector>
#include "cardClass.h"
#include "itemClass.h"

class Player
{
private:
    vector<Card> currentHand;
    int currentBalance;
    vector<Item> purchasedItems;
    int handTotalValue;

public:
    Player();
    void addToHand(Card);
    void displayCard(Card);
    void displayHand();
    vector<Card> getHand();
    int calculateRankCount();
    void replaceCard(int, vector<Card> deck);
    void clearHand();
    int getCurrentBalance();
    void setCurrentBalance(int);
    void displayCurrentBalanceAndItems();
    vector<Item> getCurrentItems();
    void addItem(Item &item);
    void createSummaryFile();
    void displaySummaryFile();
    int calculateHighestRank();
    int getHandTotalValue();
};

#endif
