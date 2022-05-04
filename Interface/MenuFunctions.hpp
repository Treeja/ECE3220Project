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
void MoveMenu(Context *context){
    int choice = 0;
    context->set_strategy(new Move);
    do
    {
        std::cout << "\n[Move Menu]\n";
        std::cout << "Where would you like to move to?\n";
        context->PrintQuestions();
        choice = getInput();
        switch(choice){
            case 1:
                std::cout << "[Office Area] Chosen!\n";

                return;
                break;
            case 2:
                std::cout << "[Break Area] Chosen!\n";
                return;
                break;
            case 3:
                std::cout << "[Test Area] Chosen!\n";
                return;
                break;
            case 4:
                std::cout << "[Component Area] Chosen!\n";
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
void InteractMenu(Context *context){
    int choice = 0;
    do
    { 
        context->set_strategy(new Interact);
        DialogueDecision *dia = new DialogueDecision();
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
        std::cout << "Who would you like to accuse?\n";
        std::cout << "(1) Carrie\n(2) Chris\n(3) Gary\n(4) Henry\n(5) Peter\n(6) Sally\n";
        int killerChoice = getInput();
        if(killerChoice == 6){
            endgameCorrect()
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


void MainMenuMenu(Context *context){
    int userChoice = 0;
    do
    {
        context->set_strategy(new MainMenu);
        std::cout << "What would you like to do?\n";
        context->PrintQuestions();
        userChoice = getInput();
        switch(userChoice){
            case 1:
                std::cout << "[Move] Chosen!\n";
                MoveMenu(context);
                // Gavin's functions.
                break;
            case 2:
                std::cout << "[Interact] Chosen!\n";
                InteractMenu(context);
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

//endgame written prose if you guess the correct killer
void endgameCorrect(){
    std::cout<<"You gather everyone into the test area. Gary is still lying there the blood pool is even bigger than it was before\n\n You look around and don't see Peter amoung the group, you quietly inform everyone that you believe Peter is the killer. Just as you do this you hear the Death Laser power on and rotate toward you and the others.\n\n Peter has a menacing look on his face and his finger in on the trigger of the Death Laser. He exclaims 'Well, well you figured it out. I never thought anyone would expect the lowly janitor. I am tired of cleaning up after you reckless slobs. Gary was the worst, coffee spills on the floor, componets all over the desks, exposed wires always left open. I didn't think anyone would think twice about him 'accidently' shocking himself, so I cut the wires he was working on when he wasn't looking. That didn't work though it just gave him a little shock and caused the lights to go out. While he was on the ground I hit him with my mop and did my best to clean up any blood in the area then ran over the the component storage before the emergency lights kicked on.'\n\n 'I can't have any witnesses...'\n\n'You all have to die!'\n\n As Peter pulled the trigger the lights kicked back on. And the police entered the room. You immediatly hear a gunshot and see Peter laying on the ground...he's dead\n\n";

    std::cout<<"Thank you for playing!"<<std::endl;
}

void endgameWrong(){

}

#endif
