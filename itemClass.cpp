#include "itemClass.h"
Item::Item(string n, int p)
{
    name = n;
    price = p;
}
string Item::getName()
{
    return name;
}
int Item::getPrice()
{
    return price;
}