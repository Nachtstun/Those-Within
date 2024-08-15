#pragma once

class Choice; // forward declaration - literally the same as declaring a type normally, just without the braces or other info

class ChoiceArray
{
private:
    Choice* _backingArray;

public:
    explicit ChoiceArray(Choice* backingArray);
    ~ChoiceArray();

    Choice& GetChoice(size_t index);
};