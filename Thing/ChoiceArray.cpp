#include "include/ChoiceArray.hpp"
#include "include/Choice.hpp"


ChoiceArray::ChoiceArray(Choice* backingArray)
{
    _backingArray = backingArray;
}

ChoiceArray::~ChoiceArray()
{
    delete[] _backingArray;
}

Choice& ChoiceArray::GetChoice(size_t index)
{
    return _backingArray[index]; // just passing the indexer along
}