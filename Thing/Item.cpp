#include "include/Item.hpp"

Item::Item(std::string itemName, std::string itemDescription)
{
    _itemName = itemName;
    _itemDescription = itemDescription;
}

std::string& Item::GetItemName()
{
    return _itemName;
}

std::string& Item::GetItemDescription()
{
    return _itemDescription;
}