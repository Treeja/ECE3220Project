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


void Clear(){
    #if defined _WIN32
        system("cls");
        //clrscr(); // including header file : conio.h
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
        //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
    #elif defined (__APPLE__)
        system("clear");
    #endif
}
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
    Clear();
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
    Clear();
    do
    { 
        context->set_strategy(new Interact);
        DialogueDecision *dia = new DialogueDecision();
        int pos = locManager->getCurrentPos();
        std::map<int, std::pair<std::string, Character*>> availableCharacters = {};
        // This switch decides what NPCs will be available depending on the location
        switch (pos)
        {
        case 1: // Office
            availableCharacters.clear();
            availableCharacters[1] = std::make_pair("Henry", charList[3]);
            break;
        case 2: // Break
            availableCharacters.clear();
            availableCharacters[1] = std::make_pair("Carrie", charList[0]);
            availableCharacters[2] = std::make_pair("Sally", charList[5]);
            break;
        case 3: // Test
            availableCharacters.clear();
            availableCharacters[1] = std::make_pair("Gary", charList[2]);
            break;
        case 4: // Component
            availableCharacters.clear();
            availableCharacters[1] = std::make_pair("Chris", charList[1]);
            availableCharacters[2] = std::make_pair("Peter", charList[4]);
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
                Clear();
                context->set_strategy(new Interact_Object);
                do
                {
                    Object* obj = new Object;
                    int pick = 0;
                    std::cout << "\n[Interact Object Menu]\n";
                    std::cout << "What would you like to do?\n";
                    context->PrintQuestions();
                    choice = getInput();
                    switch (choice)
                    {
                    case 1:
                        switch (pos)
                        {
                        case 1:
                            std::cout << "[Description] Chosen!\n\n Objects in Office Area\n";
                            obj->get_object_Off();
                            pick = obj->pickObj(4);
                            obj->get_description_Off(pick);
                            break;
                        case 2:
                            std::cout << "[Description] Chosen!\n\n Objects in Break Area\n";
                            obj->get_object_breakR();
                            pick = obj->pickObj(3);
                            obj->get_description_Break(pick);
                            break;
                        case 3:
                            std::cout << "[Description] Chosen!\n\n Objects in Test Area\n";
                            obj->get_object_test();
                            pick = obj->pickObj(4);
                            obj->get_description_Test(pick);
                            break;
                        case 4:
                            std::cout << "[Description] Chosen!\n\n Objects in Component Storage\n";
                            obj->get_object_com();
                            pick = obj->pickObj(3);
                            obj->get_description_Com(pick);
                            break;
                        case 5:
                            std::cout << "[Go Back] Chosen!\n";
                            break;
                        default:
                            break;
                        }
                    case 2:
                            std::cout << "[Go Back] Chosen!\n";
                            break;
                        default:
                            break;
                    }
                } while (choice != 2);
                break;
            case 2:
                context->set_strategy(new Interact_NPC);
                Clear();
                do
                {
                    std::cout << "\n[Interact NPC Menu]\n";
                    std::cout << "Who would you like to interact with?\n";
                    for (int i = 1; i < availableCharacters.size()+1; i++){
                        std::cout << "(" << i << ") " << availableCharacters.at(i).first << std::endl;
                    }
                    std::cout <<"(" << availableCharacters.size()+1 << ") Go Back\n";
                    int ChosenNPC = getInput();
                    if(ChosenNPC == availableCharacters.size()+1)
                        return;
                    if(ChosenNPC == availableCharacters.size()+2)
                        std::cout << "Wrong input!\n";
                    std::cout << "What would you like to do?\n";
                    context->PrintQuestions();
                    NPCchoice = getInput();
                    switch (NPCchoice){
                    case 1:
                        std::cout << availableCharacters.at(ChosenNPC).second->get_descrip();
                        break;
                    case 2:
                        std::cout << "What would you like to ask?\n";
                        dia->printQuestions();
                        questionChoice = getInput();
                        std::cout << availableCharacters.at(ChosenNPC).second->get_dialogue(questionChoice);
                        break;
                    case 3:
                        std::cout << availableCharacters.at(ChosenNPC).second->search();
                        break;
                    case 4:
                        return;
                    default:
                        std::cout << "Wrong Choice!\n";
                        break;
                    }
                } while (NPCchoice != 4);
                break;
            case 3:
                return;
            default:
                std::cout << "Wrong input!\n";
                break;
        }
        
    } while (choice != 3);
    return;
}

//endgame written prose if you guess the correct killer
void endgameCorrect(){
    std::cout<<"You gather everyone into the test area. Gary is still lying there the blood pool is even bigger than it was before\n\n You look around and don't see Peter amoung the group, you quietly inform everyone that you believe Peter is the killer. Just as you do this you hear the Death Laser power on and rotate toward you and the others.\n\n Peter has a menacing look on his face and his finger in on the trigger of the Death Laser. He exclaims 'Well, well you figured it out. I never thought anyone would expect the lowly janitor. I am tired of cleaning up after you reckless slobs. Gary was the worst, coffee spills on the floor, componets all over the desks, exposed wires always left open. I didn't think anyone would think twice about him 'accidently' shocking himself, so I cut the wires he was working on when he wasn't looking. That didn't work though it just gave him a little shock and caused the lights to go out. While he was on the ground I hit him with my mop and did my best to clean up any blood in the area then ran over the the component storage before the emergency lights kicked on.'\n\n 'I can't have any witnesses...'\n\n'You all have to die!'\n\n As Peter pulled the trigger the lights kicked back on. The police entered the room. You immediatly hear a gunshot and see Peter laying on the ground...he's dead\n\n";

    std::cout<<"Thank you for playing!"<<std::endl;

    exit(0);
}

void endgameWrong(){

    return;

}

void DeclareKillerMenu(Context *context){
    context->set_strategy(new DeclareKiller);
    context->PrintQuestions();
    std::cout <<"(1) Yes\n(2) No\n";
    int choice = getInput();
    if(choice == 1){
        std::cout << "Who would you like to accuse?\n";
        std::cout << "(1) Carrie\n(2) Chris\n(3) Gary\n(4) Henry\n(5) Peter\n(6) Sally\n";
        int killerChoice = getInput();
        if(killerChoice == 5){
            endgameCorrect();
        }
        else{
            endgameWrong();
        }
        
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
        Clear();
        context->set_strategy(new MainMenu);
        std::cout << "What would you like to do?\n";
        context->PrintQuestions();
        userChoice = getInput();
        switch(userChoice){
            case 1:
                MoveMenu(context, locManager);
                // Gavin's functions.
                break;
            case 2:
                InteractMenu(context, locManager, charList); // The questions for NPCs depend on where you are
                break;
            case 3:
                DeclareKillerMenu(context);
                break;
            case 4:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "You can't do that!\n";
                break;
        }
        
    } while (userChoice != 4);
    delete(locManager);
}

#endif
