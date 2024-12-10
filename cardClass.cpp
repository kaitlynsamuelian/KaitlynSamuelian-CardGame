#include "cardClass.h"
Card::Card()
{
    rank = "";
    suit = "";
    fileName = "";
}

Card::Card(string r, string s)
{
    rank = r;
    suit = s;
    fileName = rank + suit + ".txt";
}

string Card::getRank()
{
    return rank;
}

string Card::getSuit()
{
    return suit;
}

string Card::getFileName()
{
    return fileName;
}

void Card::setRank(string r)
{
    rank = r;
    fileName = rank + suit + ".txt";
}

void Card::setSuit(string s)
{
    suit = s;
    fileName = rank + suit + ".txt";
}
