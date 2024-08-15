#pragma once

class Item; // forward declaration - literally the same as declaring a type normally, just without the braces or other info

class ItemArray
{
private:
    Item* _backingArray;

public:
    explicit ItemArray(Item* backingArray);
    ~ItemArray();

    Item& GetItem(size_t index);
};