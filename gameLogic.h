#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <vector>
#include "cardClass.h"
#include "playerClass.h"
#include "dealerClass.h"

class ThreeCardPokerGame
{
private:
    vector<Card> deck;
    Player &player;
    Dealer dealer;
    int minimumBet;

public:
    ThreeCardPokerGame(int, bool, Player &p);

    void playRankBasedGame();
    void playSuitBasedGame();
    void initializeDeck(bool);
    void shuffleDeck();
    void dealCards();
    Card dealNewCard();
    Player getPlayer();
};

#endif
