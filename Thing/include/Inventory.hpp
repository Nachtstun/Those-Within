#pragma once
#include <string>
#include "Item.hpp"

class Inventory
{
private:
    Item* _itemArray;
    size_t _arrayLength;

public:
    Inventory(Item* itemArray, size_t arrayLength);
    ~Inventory();
    Item& GetItem(size_t index);
    size_t GetArrayLength();
};
