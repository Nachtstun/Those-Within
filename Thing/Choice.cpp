#include "include/Choice.hpp"
#include "include/ChoiceArray.hpp"
#include <stdexcept>

Choice::Choice(ChoiceArray* optionArray, size_t arrayLength, std::string choiceText, std::string responseText, FuncSig customActionFnPtr, bool shouldManageOptionArrayLifetime)
{
    _optionArray = optionArray; // pass the pointer along to ourselves for future use
    _arrayLength = arrayLength; // length of the array. We can use this to validate index-based access.
    _choiceText = choiceText;
    _responseText = responseText;
    _customActionFnPtr = customActionFnPtr;
    _shouldManageOptionArrayLifetime = shouldManageOptionArrayLifetime;
}

Choice::~Choice()
{
    if (!_shouldManageOptionArrayLifetime)
    {
        return; // don't do anything
    }

    delete _optionArray; // clean up, or we get a memory leak
}

Choice& Choice::GetChoice(size_t index)
{
    if (index >= _arrayLength || index < 0)
    {
        throw std::out_of_range("Index was outside the bounds of the array."); // THIS IS THE ERROR YOU WILL SEE IF STUFF GOES WRONG HERE, IT NEEDS TO MAKE SENSE TO YOU
    }

    return _optionArray->GetChoice(index);
}

std::string& Choice::GetChoiceText()
{
    return _choiceText;
}

std::string& Choice::GetResponseText()
{
    return _responseText;
}

size_t Choice::GetArrayLength()
{
    return _arrayLength;
}

Choice::FuncSig Choice::GetCustomActionFnPtr()
{
    return _customActionFnPtr;
}