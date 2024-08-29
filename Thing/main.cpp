#include <iostream>
#include <string>
#include "include/Choice.hpp"
#include "include/Inventory.hpp"
#include "include/ChoiceArray.hpp"
#include "include/ItemArray.hpp"

// Objective: Finish the tutorial dialogue and figure out how to make a generic set of dialogue tree nodes
// for exploring and interacting with the world (And your inventory, of course).


//Choice::FuncSig bla = &DoThing; // pointer to DoThing that you can invoke
//bla(); // invoking DoThing
Item* itemArray = new Item[3] {
    Item("Thermal Paste", "A tube of some sort of soft grey solids. It is made to cool certain parts of your pc next to you.\n"),
    Item("Canned Air", "An aluminum can of pressurized air. It makes a funny noise when you spray it.\n"),
    Item("Molex Connectors", "Some sort of wiring. It seems like you'd use it to chain some parts together.\n")
};

int playerChoiceValue = 0;

Inventory myInventory(itemArray, 3); // this line - direct initialisation
Choice* endOfGameChoicePtr = nullptr;
Choice* ptrToDelete = nullptr;
Choice* currentChoice = nullptr;
ChoiceArray* inventoryItemsArray = nullptr;

void DeleteCurrentChoice()
{
    delete ptrToDelete;
    currentChoice = endOfGameChoicePtr;
}

void ListAllItems()
{
    Choice* itemChoices = new Choice[myInventory.GetArrayLength()];

    for (size_t i = 0; i < myInventory.GetArrayLength(); i++)
    {
        itemChoices[i] = Choice(nullptr, 0, myInventory.GetItem(i).GetItemName(), myInventory.GetItem(i).GetItemDescription(), &DeleteCurrentChoice);
    }
    
    inventoryItemsArray = new ChoiceArray(itemChoices);

    currentChoice = new Choice(inventoryItemsArray, myInventory.GetArrayLength(), "", "Inventory:", nullptr, true);
    ptrToDelete = currentChoice;
    //size_t i = 0;

    //do
    //{
    //    std::cout << "Please select which item you would like to view the description of:\n";
    //    std::cin >> i;
    //    i--;
    //} 
    //while (i < 0 || i >= myInventory.GetArrayLength());

    //std::cout << myInventory.GetItem(i).GetItemDescription() << "\n";
}
 
int main()
{
    // Hacky as hell, we should probably find a better way to do this
    Choice* endOfGameChoice = new Choice[1] {
        Choice(nullptr, 0, "Hey you reached the end of the game get fucked lmao", "")
    };

    endOfGameChoicePtr = endOfGameChoice;

    ChoiceArray endOfGameChoiceArray(endOfGameChoice);

    Choice* tutorialTwo = new Choice[1] {
        Choice(nullptr, 0, "List inventory items.", "", &ListAllItems)
    };

    ChoiceArray tutorialTwoWrapper(tutorialTwo);

    Choice* tutorial = new Choice[1] {
        Choice(&tutorialTwoWrapper, 1, "I see.", "You should take a look at your inventory. Press the slay button, girl, you'll get it.")
    };

    ChoiceArray tutorialArrayWrapper(tutorial);

    Choice* optionsTwo = new Choice[2] {
        Choice(&tutorialArrayWrapper, 1, "Why am I here?", "You need to help your components with some underlying issues."),
        Choice(&tutorialArrayWrapper, 1, "marco", "You'll need to take a look")
    };

    ChoiceArray optionsTwoArrayWrapper(optionsTwo);

    Choice* options = new Choice[2] {
        Choice(&optionsTwoArrayWrapper, 2, "Where am I?", "That's a bit of a silly question, isn't it? You already know where you are, right?"),
        Choice(&optionsTwoArrayWrapper, 2, "Who are you?", "That's cruel of you...I thought you knew me better, considering I greet you daily. No matter, I will reintroduce myself.\nI am your operating system. Your consciousness has been transported into your own machine.")
    };
    

    ChoiceArray optionsArrayWrapper(options);
    Choice myChoice(&optionsArrayWrapper, 2, "", "You hear a voice.\nWelcome. We've been expecting you.");

    int menuInput = 0;
    std::cout << "Those Within\n\n";
    bool validInputGiven = false;

    while (!validInputGiven)
    {
        std::cout << "1. Start Game 2. Options 3. Exit\n";
        std::cin >> menuInput;
        switch (menuInput)
        {
            case 1:
            {
                validInputGiven = true;
                //game starts here

                currentChoice = &myChoice;
                std::cout << currentChoice->GetResponseText() << "\n";

                while (currentChoice->GetArrayLength() != 0)
                {
                    // there is still game to be played
                    
                    for (size_t i = 0; i < currentChoice->GetArrayLength(); i++)
                    {
                        std::cout << i + 1 << ". " << currentChoice->GetChoice(i).GetChoiceText() << " ";
                    }

                    std::cout << "\n";

                    bool validPlayerChoiceChosen = false;
                    std::cin >> playerChoiceValue;
                    playerChoiceValue--;

                    
                    if (playerChoiceValue >= 0 && playerChoiceValue < currentChoice->GetArrayLength())
                    {
                        currentChoice = &currentChoice->GetChoice(playerChoiceValue);
                        std::cout << currentChoice->GetResponseText() << "\n";
                        if (currentChoice->GetCustomActionFnPtr() != nullptr)
                        {
                            Choice::FuncSig fnPtr = currentChoice->GetCustomActionFnPtr();
                            fnPtr();
                        }
                    }
                    else
                    {
                        std::cout << "I am not programmed to understand what any of what you said means. It's a miracle I'm even talking to you. Please help me understand by picking something that I am programmed to understand.\n";
                    }
                }

                std::cout << currentChoice->GetChoiceText() << "\n"; // TODO: This is calling the wrong thing. I Think I put the text in the wrong place but also its nearly 3 AM. sue me.

                break;
            }
            
            case 2:
            {
                //wow, legally required options!
                break;
            }
            
            case 3:
            {
                //why do you hate my game????
                break;
            }

            default:
            {
                std::cout << "That is not a valid option. Please select a valid option.\n";
                break;
            }
        }
    }

    return 0;
}