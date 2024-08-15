#include "include/ItemArray.hpp"
#include "include/Item.hpp"


ItemArray::ItemArray(Item* backingArray)
{
    _backingArray = backingArray;
}

ItemArray::~ItemArray()
{
    delete[] _backingArray;
}

Item& ItemArray::GetItem(size_t index)
{
    return _backingArray[index]; // just passing the indexer along
}