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
void MoveMenu(Context *context, LocationManager *locManager){
    int choice = 0;
    context->set_strategy(new Move);
    Node* tmp = new Node();
    do
    {
        std::cout << "\n[Move Menu]\n";
        std::cout << "Where would you like to move to?\n";
        context->PrintQuestions();
        choice = getInput();
        if(choice == locManager->getCurrentPos()){
            std::cout << "You are currently there!\n";
            return;
        }
        switch(choice){
            case 1:
                std::cout << std::endl;//"[Office Area] Chosen!\n";
                tmp = locManager->findNode(locManager->getHead(),choice);
                std::cout << "You are in the " << tmp->areaName_ << ". " << tmp->areaDescription_ << std::endl << std::endl;
                return;
            case 2:
                std::cout << std::endl;//"[Break Area] Chosen!\n";
                tmp = locManager->findNode(locManager->getHead(),choice);
                std::cout << "You are in the " << tmp->areaName_ << ". " << tmp->areaDescription_ << std::endl << std::endl;
                return;
            case 3:
                std::cout << std::endl;//"[Test Area] Chosen!\n";
                tmp = locManager->findNode(locManager->getHead(),choice);
                std::cout << "You are in the " << tmp->areaName_ << ". " << tmp->areaDescription_ << std::endl << std::endl;
                return;
            case 4:
                std::cout << std::endl;//"[Component Area] Chosen!\n";
                tmp = locManager->findNode(locManager->getHead(),choice);
                std::cout << "You are in the " << tmp->areaName_ << ". " << tmp->areaDescription_ << std::endl << std::endl;
                return;
            case 5:
                std::cout << "[Go Back] Chosen!\n";
                return;
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
void InteractMenu(Context *context, LocationManager *locManager, Character* charList[]){
    int choice = 0;
    do
    { 
        context->set_strategy(new Interact);
        DialogueDecision *dia = new DialogueDecision();
        CharacterFactory chaFac;
        std::map<int, Character*> acceptableChars;
        // This should create characters based on where you currently are, but idk if this is the best way to do it.
        /**
         * The other way we could do it is to create a vector or an array somewhere that keeps track of pointers to the already created charcters,
         * and pass that into the function so that we aren't dealing with deleting and re-creating the characters every time we go into this menu.
         * We would also only allow the player to interact with the characters at the current location just by locking the questions behind a switch/case
         * kind of like seen below. (maps are fun, but maps are expensive)
         * 
         * If we did it like the second option, we would create the list/characters all the way back in init probably, and pass it all the way through
         * That way you can question, leave, move, enter, questions again and the exhaustion would stay tracked.
         * 
         * Fuck, thats what i'm gonna have to do isn't it. Damnit.
         * 
         */
        switch (locManager->getCurrentPos())
        {
        case 1: // Office
            /**
             * Characters at this location:
             * 
             */
            acceptableChars = {
                {1, charList[1]},
                {2, charList[2]},
                {3, charList[3]},
                {4, charList[4]},
                {5, charList[5]},
                {6, charList[6]}
            };
            break;
        case 2: // Break
            /**
             * Characters at this location:
             * 
             */
            acceptableChars = {
                {1, charList[1]},
                {2, charList[2]},
                {3, charList[3]},
                {4, charList[4]},
                {5, charList[5]},
                {6, charList[6]}
            };
            break;
        case 3: // Test
            /**
             * Characters at this location:
             * 
             */
            acceptableChars = {
                {1, charList[1]},
                {2, charList[2]},
                {3, charList[3]},
                {4, charList[4]},
                {5, charList[5]},
                {6, charList[6]}
            };
            break;
        case 4: // Component
            /**
             * Characters at this location:
             * 
             */
            acceptableChars = {
                {1, charList[1]},
                {2, charList[2]},
                {3, charList[3]},
                {4, charList[4]},
                {5, charList[5]},
                {6, charList[6]}
            };
            break;
        
        default:
            break;
        }
        int NPCchoice = 0;
        int questionChoice = 0;
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
                    std::cout << "What would you like to do?\n";

                    context->PrintQuestions();
                    NPCchoice = getInput();
                    switch (NPCchoice)
                    {
                    case 1:
                        std::cout << "[Description] Chosen!\n";
                        break;
                    case 2:
                        std::cout << "[Question] Chosen!\n";
                        std::cout << "What would you like to ask?\n";
                        dia->printQuestions();
                        questionChoice = getInput();
                        // PASS TO NICK FUNCTION
                        break;
                    case 3:
                        std::cout << "[Search] Chosen!\n";
                        break;
                    case 4:
                        std::cout << "[Go Back] Chosen!\n";
                        break;
                    default:
                        std::cout << "Wrong Choice!\n";
                        break;
                    }
                } while (NPCchoice != 4);
                break;
            case 3:
                std::cout << "[Go Back] Chosen!\n";
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
    Object objects;
    LocationManager *locManager = new LocationManager();
    
    locManager->createList();
    do
    {
        context->set_strategy(new MainMenu);
        std::cout << "CurrentLocation: " << locManager->getCurrentPos() << std::endl;
        std::cout << "What would you like to do?\n";
        context->PrintQuestions();
        userChoice = getInput();
        switch(userChoice){
            case 1:
                std::cout << "[Move] Chosen!\n";
                MoveMenu(context, locManager);
                // Gavin's functions.
                break;
            case 2:
                std::cout << "[Interact] Chosen!\n";
                InteractMenu(context, locManager, charList); // The questions for NPCs depend on where you are
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
    delete(locManager);
}

#endif
