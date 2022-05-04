/**
 * @file MenuFunctions.hpp
 * @author Sam Bealmer (sjbhyf@umsystem.edu)
 * @brief Functions for navigating through the main menu
 * @version 0.1
 * @date 2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H
#include "../Dialogue/dialogue.hpp"
#include "../Interface/Interface.hpp"
#include "../Location/location.h"
#include "../Location/objects.h"
#include "../NPCbuilder/CharacterFactory.h"
#include <iostream>

/**
 * @brief Get the Input object
 * 
 * @return int 
 */
int getInput(){
    int choice;
    std::cout << "Choice: ";
    std::cin >> choice;
    return choice;
}
/**
 * @brief Menu for moving the player
 * 
 * @param context 
 */
void MoveMenu(Context *context, Location* head){
    int choice = 0;
    context->set_strategy(new Move);
    // Location* head = nullptr;
    // head = head->start(head);
    do
    {
        std::cout << "\n[Move Menu]\n";
        std::cout << "Where would you like to move to?\n";
        context->PrintQuestions();
        choice = getInput();
        switch(choice){
            case 1:
                std::cout << "[Office Area] Chosen!\n";
                head = head->move(head,1);
                head->description(head);
                return;
                break;
            case 2:
                std::cout << "[Break Area] Chosen!\n";
                head = head->move(head,2);
                head->description(head);
                return;
                break;
            case 3:
                std::cout << "[Test Area] Chosen!\n";
                head = head->move(head,3);
                head->description(head);
                return;
                break;
            case 4:
                std::cout << "[Component Area] Chosen!\n";
                head = head->move(head,4);
                head->description(head);
                return;
                break;
            case 5:
                std::cout << "[Go Back] Chosen!\n";
                return;
                break;
            default:
                std::cout << "Wrong Choice!\n";
                break;
        }
    } while (choice != 5);
    return;
}
/**
 * @brief Main interacting menu
 * 
 * @param context 
 */
void InteractMenu(Context *context, Character* charList[], Location* head){
    int choice = 0; // Main interat menu user choice
    do
    { 
        context->set_strategy(new Interact);
        DialogueDecision *dia = new DialogueDecision();
        int pos = head->getNode();
        std::map<int, std::pair<std::string, Character*>> availableCharacters = {};
        // This switch decides what NPCs will be available depending on the location
        switch (pos)
        {
        case 1: // Office
            availableCharacters.clear();
            availableCharacters[1] = std::make_pair("Carrie", charList[0]);
            availableCharacters[2] = std::make_pair("Chris", charList[1]);
            availableCharacters[3] = std::make_pair("Gary", charList[2]);
            availableCharacters[4] = std::make_pair("Henry", charList[3]);
            availableCharacters[5] = std::make_pair("Peter", charList[4]);
            availableCharacters[6] = std::make_pair("Sally", charList[5]);
            break;
        case 2: // Break
            availableCharacters.clear();
            availableCharacters[1] = std::make_pair("Carrie", charList[0]);
            availableCharacters[2] = std::make_pair("Chris", charList[1]);
            availableCharacters[3] = std::make_pair("Gary", charList[2]);
            availableCharacters[4] = std::make_pair("Henry", charList[3]);
            availableCharacters[5] = std::make_pair("Peter", charList[4]);
            availableCharacters[6] = std::make_pair("Sally", charList[5]);
            break;
        case 3: // Test
            availableCharacters.clear();
            availableCharacters[1] = std::make_pair("Carrie", charList[0]);
            availableCharacters[2] = std::make_pair("Chris", charList[1]);
            availableCharacters[3] = std::make_pair("Gary", charList[2]);
            availableCharacters[4] = std::make_pair("Henry", charList[3]);
            availableCharacters[5] = std::make_pair("Peter", charList[4]);
            availableCharacters[6] = std::make_pair("Sally", charList[5]);
            break;
        case 4: // Component
            availableCharacters.clear();
            availableCharacters[1] = std::make_pair("Carrie", charList[0]);
            availableCharacters[2] = std::make_pair("Chris", charList[1]);
            availableCharacters[3] = std::make_pair("Gary", charList[2]);
            availableCharacters[4] = std::make_pair("Henry", charList[3]);
            availableCharacters[5] = std::make_pair("Peter", charList[4]);
            availableCharacters[6] = std::make_pair("Sally", charList[5]);
            break;
        default: // ERROR
            availableCharacters.clear();
            break;
        }
        int NPCchoice = 0; // The user choice for what to do in NPC land
        int questionChoice = 0; // user choice for what question to ask NPC
        std::cout << "\n[Interact Menu]\n";
        std::cout << "What would you like to do?\n";
        context->PrintQuestions();
        choice = getInput();
        switch(choice){
            case 1:
                std::cout << "[Object] Chosen!\n";
                context->set_strategy(new Interact_Object);
                do
                {
                    std::cout << "\n[Interact Object Menu]\n";
                    std::cout << "What would you like to do?\n";
                    context->PrintQuestions();
                    choice = getInput();
                    switch (choice)
                    {
                    case 1:
                        std::cout << "[Inspect Object] Chosen!\n";
                        break;
                    case 2:
                        std::cout << "[Go Back] Chosen!\n";
                        break;
                    default:
                        break;
                    }
                } while (choice != 2);
                break;
            case 2:
                std::cout << "[NPC] Chosen!\n";
                context->set_strategy(new Interact_NPC);
                do
                {
                    std::cout << "\n[Interact NPC Menu]\n";
                    std::cout << "Who would you like to interact with?\n";
                    for (int i = 1; i < availableCharacters.size()+1; i++){
                        std::cout << "(" << i << ") " << availableCharacters.at(i).first << std::endl;
                    }
                    int ChosenNPC = getInput();
                    std::cout << "What would you like to do?\n";
                    context->PrintQuestions();
                    NPCchoice = getInput();
                    switch (NPCchoice)
                    {
                    case 1:
                        std::cout << "[Description] Chosen!\n";
                        std::cout << availableCharacters.at(ChosenNPC).second->get_descrip();
                        break;
                    case 2:
                        std::cout << "[Question] Chosen!\n";
                        std::cout << "What would you like to ask?\n";
                        dia->printQuestions();
                        questionChoice = getInput();
                        std::cout << availableCharacters.at(ChosenNPC).second->get_dialogue(questionChoice);
                        break;
                    case 3:
                        std::cout << "[Search] Chosen!\n";
                        std::cout << availableCharacters.at(ChosenNPC).second->search();
                        break;
                    case 4:
                        std::cout << "[Go Back] Chosen!\n";
                    default:
                        std::cout << "Wrong Choice!\n";
                        break;
                    }
                } while (NPCchoice != 4);
                break;
            case 3:
                std::cout << "[Go Back] Chosen!\n";
                return;
                break;
            default:
                std::cout << "Wrong input!\n";
                break;
        }
        
    } while (choice != 3);
    return;
}

/**
 * @brief Menu for Inventory
 * 
 * @param context 
 */
void InventoryMenu(Context *context){
    int choice = 0;
    context->set_strategy(new Inventory);
    do
    {
        std::cout << "\n[Inventory Menu]\n";
        std::cout << "What would you like to do?\n";
        context->PrintQuestions();
        choice = getInput();
        switch (choice)
        {
        case 1:
            std::cout << "[View Notes] Chosen!\n";
            break;
        case 2:
            std::cout << "[Go Back] Chosen!\n";
        default:
            std::cout << "Wrong Input!\n";
            break;
        }
    } while (choice != 2);
    return;
}

void DeclareKillerMenu(Context *context){
    context->set_strategy(new DeclareKiller);
    context->PrintQuestions();
    std::cout <<"(1) Yes\n(2) No\n";
    int choice = getInput();
    if(choice == 1){
        std::cout << "Kill! Kill! Kill!\n";
        return;
    } else if (choice == 2){
        std::cout << "No Kill! No Kill! No Kill!\n";
        return;
    } else {
        std::cout << "Wrong Choice, try again later!";
        return;
    }
}


void MainMenuMenu(Context *context, Character* charList[]){
    int userChoice = 0;
    Location* head = nullptr;
    Object objects;
    do
    {
        head = head->start(head);
        context->set_strategy(new MainMenu);
        std::cout << "What would you like to do?\n";
        context->PrintQuestions();
        userChoice = getInput();
        switch(userChoice){
            case 1:
                std::cout << "[Move] Chosen!\n";
                MoveMenu(context, head);
                // Gavin's functions.
                break;
            case 2:
                std::cout << "[Interact] Chosen!\n";
                InteractMenu(context, charList, head);
                break;
            case 3:
                std::cout << "[Inventory] Chosen!\n";
                InventoryMenu(context);
                break;
            case 4:
                std::cout << "[Declare Killer] Chosen!\n";
                DeclareKillerMenu(context);
                break;
            case 5:
                std::cout << "[Exit Game] Chosen! Goodbye!\n";
                break;
            default:
                std::cout << "You can't do that!\n";
                break;
        }
        
    } while (userChoice != 5);
}

#endif
