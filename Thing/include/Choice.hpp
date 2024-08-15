#pragma once
#include <string>

class ChoiceArray;

class Choice
{
public:
    using FuncSig = void(*)();
    
private:
    ChoiceArray* _optionArray;
    size_t _arrayLength;
    std::string _choiceText;
    std::string _responseText;
    FuncSig _customActionFnPtr;

public:
    Choice() = default;
    Choice(ChoiceArray* optionArray, size_t arrayLength, std::string choiceText, std::string responseText, FuncSig customActionFnPtr = nullptr); // constructor method
    ~Choice() = default; // destructor
    Choice& GetChoice(size_t index);
    std::string& GetChoiceText();
    std::string& GetResponseText();
    FuncSig GetCustomActionFnPtr();
    size_t GetArrayLength();
};

