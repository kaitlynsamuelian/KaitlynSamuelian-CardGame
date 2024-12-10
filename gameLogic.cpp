#include "gameLogic.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
Player ThreeCardPokerGame::getPlayer()
{
    return player;
}

Card ThreeCardPokerGame::dealNewCard()
{
    Card dealtCard = deck.back();
    deck.pop_back();
    return dealtCard;
}
ThreeCardPokerGame::ThreeCardPokerGame(int minBet, bool rankBased, Player &p)
    : player(p) // reference to player
{
    minimumBet = minBet;
    initializeDeck(rankBased);
    shuffleDeck();
}

void ThreeCardPokerGame::playRankBasedGame()

{
    bool playAgain = true;
    while (playAgain)
    {
        if (player.getCurrentBalance() <= 5)
        {
            cout << "Game over." << endl;
            cout << "You need more money to play, you will next to exit the game, recompile and play again." << endl;
            break;
        }
        else
        {
            player.displayCurrentBalanceAndItems();
            cout << "The minimum bet for this table is $" << minimumBet << "." << endl;
            int anteBet, playBet;

            cout << "Please place your ANTE bet (minimum $" << minimumBet << "): $";
            cin >> anteBet;

            if (anteBet < minimumBet)
            {
                cout << "Your ANTE bet must be at least $" << minimumBet << ". Please try again." << endl;
                continue;
            }
            if (anteBet > player.getCurrentBalance())
            {
                cout << "You ANTE bet must be less then or equal to your current balance. Please try again" << endl;
                continue;
            }

            player.setCurrentBalance(-anteBet);
            player.displayCurrentBalanceAndItems();
            player.clearHand();
            initializeDeck(true); // Limit deck to Hearts suit for rank-based game
            shuffleDeck();
            dealCards();

            cout << "Player's Hand:" << endl;
            player.displayHand();

            char choice;
            cout << "Do you want to continue playing and place your PLAY bet? (y/n): ";
            cin >> choice;

            if (choice == 'y' || choice == 'Y')
            {
                playBet = anteBet;
                cout << "You placed $" << playBet << " on the PLAY betting area." << endl;
                player.setCurrentBalance(-playBet);
                player.displayCurrentBalanceAndItems();

                cout << "Dealer's Hand:" << endl;
                dealer.displayHand();

                int playerRankCount = player.calculateRankCount();
                int dealerRankCount = dealer.calculateRankCount();
                cout << "Final Player rank count: " << playerRankCount << endl;
                cout << "Final Dealer rank count: " << dealerRankCount << endl;

                if (playerRankCount > dealerRankCount)
                {
                    cout << "Player wins!" << endl;
                    player.setCurrentBalance(2 * (anteBet + playBet));
                    player.displayCurrentBalanceAndItems();
                }
                else if (dealerRankCount > playerRankCount)
                {
                    cout << "Dealer wins!" << endl;
                }
                else
                {
                    cout << "It's a tie!" << endl;
                    cout << "Player gets to pick one card to drop." << endl;
                    int dropIndex;
                    bool isTie = false;
                    int playerschances = 0;

                    do
                    {
                        do
                        {
                            cout << "Enter the card to drop (1 for first card, 2 for second card, or 3 for third card): ";
                            cin >> dropIndex;
                        } while (dropIndex < 1 || dropIndex > 3);
                        dropIndex--;

                        player.replaceCard(dropIndex, deck);
                        cout << "Player's new hand:" << endl;
                        player.displayHand();
                        int playerRankCount2 = player.calculateRankCount();
                        int dealerRankCount2 = dealer.calculateRankCount();
                        cout << "Final Player rank count: " << playerRankCount2 << endl;
                        cout << "Final Dealer rank count: " << dealerRankCount2 << endl;
                        if (playerRankCount2 > dealerRankCount2)
                        {
                            cout << "Player wins!" << endl;
                            player.setCurrentBalance(2 * (anteBet + playBet));
                            player.displayCurrentBalanceAndItems();
                            isTie = true;
                            break;
                        }
                        else if (dealerRankCount2 > playerRankCount2)
                        {
                            cout << "Dealer wins!" << endl;
                            isTie = true;
                            break;
                        }
                        else if (dealerRankCount2 == playerRankCount2)
                        {
                            if (dealerRankCount2 == 1 && playerRankCount2 == 1)
                            {
                                playerschances++;
                                // if(playerschances==3){

                                // }
                                if (playerschances == 3)
                                {
                                    cout << "You have done this 3 times. The winner will be calculated based on whoever has the highest ranked cards in total" << endl;
                                    int playersHandTotal = player.getHandTotalValue();
                                    int dealersHandTotal = dealer.getHandTotalValue();
                                    cout << "Players hand total value is:" << playersHandTotal << endl;
                                    cout << "Dealers hand total value is: " << dealersHandTotal << endl;
                                    if (dealersHandTotal > playersHandTotal)
                                    {
                                        cout << "Dealer Wins!" << endl;
                                        isTie = true;
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Player wins!" << endl;
                                        player.setCurrentBalance(2 * (anteBet + playBet));
                                        player.displayCurrentBalanceAndItems();
                                        isTie = true;
                                        break;
                                    }
                                }
                                else
                                {
                                    cout << "Oh no its still a tie, pick a new card to drop.";
                                    isTie = false;
                                    continue;
                                }
                            }
                            else
                            {
                                int highestRankedCardPlayer = player.calculateHighestRank();
                                int highestRankedCardDealer = dealer.calculateHighestRankedCard();
                                cout << "Players highest ranked card is: " << highestRankedCardPlayer << endl;
                                cout << "Dealers highest ranked card is: " << highestRankedCardDealer << endl;
                                if (highestRankedCardPlayer > highestRankedCardDealer)
                                {
                                    cout << "Player wins!" << endl;
                                    player.setCurrentBalance(2 * (anteBet + playBet));
                                    player.displayCurrentBalanceAndItems();
                                    isTie = true;
                                    break;
                                }
                                else if (highestRankedCardPlayer < highestRankedCardDealer)
                                {
                                    cout << "Dealer wins!" << endl;
                                    isTie = true;
                                    break;
                                }
                            }
                        }
                    } while (isTie == false && playerschances < 3);
                }
            }
            else
            {
                cout << "You chose to fold. The game is over." << endl;
            }

            int option;
            cout << "Enter 1 to play again or 2 to go back to the main menu: ";
            cin >> option;

            switch (option)
            {
            case 1:
                playAgain = true;
                player.clearHand();
                dealer.clearHand();
                break;
            case 2:
                playAgain = false;
                cout << "Returning to the main menu..." << endl;
                break;
            default:
                cout << "Invalid option. Returning to the main menu..." << endl;
                playAgain = false;
                break;
            }
        }
    }
}

void ThreeCardPokerGame::initializeDeck(bool rankBased)
{
    string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "A", "J", "Q", "K"};
    string suits[] = {"C", "D", "H", "S"};

    if (rankBased == true)
    {
        for (int i = 0; i < 13; i++) // Loop through ranks
        {
            deck.push_back(Card(ranks[i], "H"));
        }
    }
    else if (rankBased == false)
    {
        for (int i = 0; i < 4; i++) // Loop through ranks
        {
            for (int j = 0; j < 4; j++) // Loop through suits
            {
                deck.push_back(Card(ranks[i], suits[j]));
            }
        }
    }
}
void ThreeCardPokerGame::shuffleDeck()
{
    srand(static_cast<unsigned>(time(0))); // Seed
    // use a for loop to go thro all the cards in the deck
    // the last element's index is deck.size() - 1, so start there
    //  then go down the deck through each card until i = 1
    //  which performs the final swap between the second and first elements.
    //  use a temp variable to keep data correctly because have to swap both elements
    //  example:
    // if deck[i] = A and deck[j] = B
    //  assign a temp variable to hold value A
    //  then assign B (deckat J) to deck at i
    //  then assign the temp variable (A) to deck at j
    for (int i = static_cast<int>(deck.size()) - 1; i > 0; i--)
    {
        int j = rand() % (i + 1); // Generate a random index from 0 to i
        // Swap elements, use a temp variable to (temportily)hold the the value of deck[i]
        Card temp = deck[i];
        deck[i] = deck[j]; //  Assign the value of deck[j] to deck[i], so now value of deck i is
        // whatever value deck j held
        deck[j] = temp; // assign the value of temp , which holds the orignal value of deck i to deck j
    }
}

void ThreeCardPokerGame::dealCards()
{
    for (int i = 0; i < 3; i++)
    {
        player.addToHand(deck[i]);
        dealer.addToHand(deck[i + 3]);
    }
}
