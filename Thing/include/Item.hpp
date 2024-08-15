#pragma once
#include <string>

class Item
{
private:
    std::string _itemName;
    std::string _itemDescription;

public:
    Item(std::string itemName, std::string itemDescription);
    ~Item() = default;
    std::string& GetItemName();
    std::string& GetItemDescription();
};