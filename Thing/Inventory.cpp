#include "include/Inventory.hpp"
#include <stdexcept>

Inventory::Inventory(Item* itemArray, size_t arrayLength)
{
    _itemArray = itemArray;
    _arrayLength = arrayLength;
}

Inventory::~Inventory()
{
    delete[] _itemArray;
}

Item& Inventory::GetItem(size_t index)
{
    if (index >= _arrayLength || index < 0)
    {
        throw std::out_of_range("Index was outside the bounds of the array.");
    }

    return _itemArray[index];
}

size_t Inventory::GetArrayLength()
{
    return _arrayLength;
}