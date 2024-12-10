#ifndef ITEMCLASS_H
#define ITEMCLASS_H
#include <iostream>
using namespace std;
class Item
{
private:
    string name;
    int price;

public:
    Item(string, int);
    string getName();
    int getPrice();
};
#endif