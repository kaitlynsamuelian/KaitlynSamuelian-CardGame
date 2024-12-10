#ifndef DEALERCLASS_H
#define DEALERCLASS_H

#include <vector>
#include "cardClass.h"

class Dealer
{
private:
    vector<Card> currentHand;
    int handTotalValue;

public:
    void addToHand(Card);
    void displayCard(Card);
    void displayHand();
    vector<Card> getHand();
    int calculateRankCount();
    void clearHand();
    int calculateHighestRankedCard();
    int getHandTotalValue();
};

#endif
