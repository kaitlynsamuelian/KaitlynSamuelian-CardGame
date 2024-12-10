#ifndef CARDCLASS_H
#define CARDCLASS_H

#include <string>
using namespace std;

class Card
{
private:
    string rank;
    string suit;
    string fileName;

public:
    Card();
    Card(string, string);
    string getRank();
    string getSuit();
    string getFileName();
    void setRank(string);
    void setSuit(string);
};

#endif
