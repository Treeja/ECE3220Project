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
    int choice = -1;
    std::cout << "Choice: ";
    std::cin >> choice;  
    // if((choice < 0) || (choice > 9)){
    //     std::cout << "Wrong input; Try again!\n";
    //     choice = -1;
    //     choice = getInput();
    // }
    return choice;
}
/**
 * @brief Menu for moving the player
 * 
 * @param context 
 */

//Wraps written prose
void wrap(std::string const &input, size_t width, std::ostream &os, size_t indent = 0) {
    std::istringstream in(input);

    os << std::string(indent, ' ');
    size_t current = indent;
    std::string word;

    while (in >> word) {
        if (current + word.size() > width) {
            os << "\n" << std::string(indent, ' ');
            current = indent;
        }
        os << word << ' ';
        current += word.size() + 1;
    }
}

void MoveMenu(Context *context, LocationManager *locManager){
    int choice = 0;
    context->set_strategy(new Move);
    Node* tmp = nullptr;
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
                Clear();
                return;
            default:
                std::cout << "Wrong Choice!\n";
                
        }
        tmp = nullptr;
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
                            std::cout << "\nObjects in Office Area\n";
                            obj->get_object_Off();
                            pick = obj->pickObj(4);
                            obj->get_description_Off(pick);
                            break;
                        case 2:
                            std::cout << "\nObjects in Break Area\n";
                            obj->get_object_breakR();
                            pick = obj->pickObj(3);
                            obj->get_description_Break(pick);
                            break;
                        case 3:
                            std::cout << "\nObjects in Test Area\n";
                            obj->get_object_test();
                            pick = obj->pickObj(4);
                            obj->get_description_Test(pick);
                            break;
                        case 4:
                            std::cout << "\nObjects in Component Storage\n";
                            obj->get_object_com();
                            pick = obj->pickObj(3);
                            obj->get_description_Com(pick);
                            break;
                        case 5:
                            break;
                        default:
                            break;
                        }
                    case 2:
                        break;
                    default:
                        break;
                    }
                delete(obj);
                obj = nullptr;
                } while (choice != 2);
                Clear();
                break;
            case 2:
                context->set_strategy(new Interact_NPC);
                do
                {
                    std::cout << "\n[Interact NPC Menu]\n";
                    std::cout << "Who would you like to interact with?\n";
                    for (int i = 1; i < availableCharacters.size()+1; i++){
                        std::cout << "(" << i << ") " << availableCharacters.at(i).first << std::endl;
                    }
                    std::cout <<"(" << availableCharacters.size()+1 << ") Go Back\n";
                    int ChosenNPC = getInput();
                    if(ChosenNPC == availableCharacters.size()+1){
                        Clear();
                        return;
                    }
                    if(ChosenNPC == availableCharacters.size()+2)
                        std::cout << "Wrong input!\n";
                    std::cout << "What would you like to do?\n";
                    context->PrintQuestions();
                    NPCchoice = getInput();
                    switch (NPCchoice){
                    case 1:
                        std::cout<<"\n\n";
                        //std::cout << availableCharacters.at(ChosenNPC).second->get_descrip();
                        wrap(availableCharacters.at(ChosenNPC).second->get_descrip() ,100, std::cout, 0);
                        std::cout<<"\n\n";
                        break;
                    case 2:
                        std::cout << "What would you like to ask?\n";
                        std::cout << "(1) How do you know Gary?" << std::endl;
                        std::cout << "(2) Where were you before the lights went out?" << std::endl;
                        std::cout << "(3) What is your involvement with the research?" << std::endl;
                        std::cout << "(4) Did you hear or see anything worth noting?" << std::endl;
                        std::cout << "(5) Who do you think killed Gary?" << std::endl;
                        questionChoice = getInput();
                        std::cout<<"\n\n";
                        //std::cout << availableCharacters.at(ChosenNPC).second->get_dialogue(questionChoice);
                        wrap(availableCharacters.at(ChosenNPC).second->get_dialogue(questionChoice) ,100, std::cout, 0);
                        std::cout<<"\n\n";
                        break;
                    case 3:
                        //std::cout << availableCharacters.at(ChosenNPC).second->search();
                        std::cout<<"\n\n";
                        wrap(availableCharacters.at(ChosenNPC).second->search(),100, std::cout, 0);
                        std::cout<<"\n\n";
                        break;
                    case 4:
                        Clear();
                        return;
                    default:
                        std::cout << "Wrong Choice!\n";
                        break;
                    }
                } while (NPCchoice != 4);
                break;
            case 3:
                Clear();
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
    Clear();
    std::string in = "You gather everyone into the test area. Gary is still lying there the blood pool is even bigger than it was before\n\n You look around and don't see Peter amoung the group, you quietly inform everyone that you believe Peter is the killer. Just as you do this you hear the Death Laser power on and rotate toward you and the others.\n\n Peter has a menacing look on his face and his finger is on the trigger of the Death Laser. He exclaims 'Well, well you figured it out. I never thought anyone would expect the lowly janitor. I am tired of cleaning up after you reckless slobs. Gary was the worst, coffee spills on the floor, componets all over the desks, exposed wires always left open. I didn't think anyone would think twice about him 'accidently' shocking himself, so I cut the wires he was working on when he wasn't looking. That didn't work though it just gave him a little shock and caused the lights to go out. While he was on the ground I hit him with a wrench and did my best to clean up any blood in the area and the wrench then ran over the the component storage before the emergency lights kicked on.'\n\n 'I can't have any witnesses...'\n\n'You all have to die!'\n\n As Peter pulled the trigger the lights kicked back on. The police entered the room. You immediatly hear a gunshot and see Peter laying on the ground...he's dead\n\n";

    wrap(in,100, std::cout, 0);

    std::cout<<"\n\nThank you for playing!\n\n"<<std::endl;

    return;
}

void endgameWrong(std::string character){

    Clear();
    std::string gender;
    std::string gender2;
    if(character == "Carrie" || character == "Sally"){
        gender = "her";
        gender2 = "her";
    }
    else{
        gender = "him";
        gender2 = "his";
    }
    std::string in = "You gather everyone in the test area, point at " + character + " and exclaim '" + character +" did it.' The group quickly looks at " + character + " and grabs " +gender+  ". " +character+ " wrestles the group screaming 'It wasn't me it wasn't me!' As " +character+ " fights for " +gender2+ " life the lights quickly flash on and the police enter the room. They quickly detain " +character+ " and lead " +gender+ " away, patting you on the back saying job well done. " +character+ " is going to be in prison for a long long time. As the commotion dies down the police interview everyone, everyone's story matches up and it is a closed case. You are one of the last to leave the building, other than Peter who is cleaning up. As you are leaving you see Peter clutching a wrentch and hear him lightly say 'That was all to easy'.....\n\n";
    wrap(in,100, std::cout, 0);

    std::cout<<"\nThank you for playing!\n";


    return;

}

bool DeclareKillerMenu(Context *context){
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
            goto end;
        }
        else{
            std::string characters[6] = {"Carrie", "Chris", "Gary", "Henry", "Peter", "Sally"};
            endgameWrong(characters[killerChoice-1]);
            goto end;
        }
        
    } else if (choice == 2){
        return false;
    } else {
        std::cout << "Wrong Choice, try again later!";
        return false;
    }
end:
    return true;
}

void Introduction(){
    std::cout << "Welcome to our murder mystery 'Who Killed Gary GPA' by Sam Bealmer, Nick Ebers, and Gavin Stoddard.\n\n";
    std::string prose = "As a recent graduates from Universty of Missouri College of Journalism I went to the most famous lab on campus to interview the researchers in the lab. The lab was working on a breakthrough invention of a death laser. When walking into lab I meet the employees who work under the great Gary GPA. First I met the undergraduate research student Chris Capstone, PhD Student Carrie Circuits, and the Co-author Henry Honors Project. Continuing my tour around the lab I meet a Janitor named Peter Power Electronics who was complaning about always having to clean up after all these lazy researchers. I then ran into Gray GPA who abrutly stopped a heated argument with a financer of the project named Sally Software. He then kindly greeted me and helped me finish the tour. We finished the tour by him showing me the newly finished death laser. He then told me to make myself at home and he would catch up with me for a full interview in a couple of minutes. I made my way back to the Office Area when the lights shut off. I stood in complete darkness for about 30 minutes until the back power finally kicked in and the emergy lights were the only things lighting up the room. I then heard a scream from the testing area and there was Carrie and on the ground was Gary GPA dead on the floor. Everyone came running in and I proceeded to call the police. The police informed me to make everyone leave the crime area but to not leave the lab until they get there for questioning. As we waiting for the police I saw an opportnity to be the first reporter on a breaking story. Making my way back to the office area once again I decided I was going to crack this case before the police got the scene!\n";
    wrap(prose,100, std::cout, 0);
    std::cout << "\n********INSTRUCTIONS********" << std::endl;
    std::string inst = "In this game you will be able to move around from area to area talking to the people in each area and check out some of the objects to see if you are able to figure out who killed Gary GPA. When moving to different areas you will want to pick the interact option to talk suspects or to look at an object. Make sure you do your best work and pick the correct killer! Have fun!";
    wrap(inst,100, std::cout, 0);
    std::cout << std::endl;
}

void MainMenuMenu(Context *context, Character* charList[]){
    int userChoice = 0;
    Object objects;
    LocationManager *locManager = new LocationManager();
    bool killCorrect = false;
    do
    {
        context->set_strategy(new MainMenu);
        std::cout << "What would you like to do?\n";
        context->PrintQuestions();
        userChoice = getInput();
        switch(userChoice){
            case 1:
                Clear();
                MoveMenu(context, locManager);
                // Gavin's functions.
                break;
            case 2:
                Clear();
                InteractMenu(context, locManager, charList); // The questions for NPCs depend on where you are
                break;
            case 3:
                Clear();
                killCorrect = DeclareKillerMenu(context);
                if(killCorrect){
                    userChoice = 4;
                    break;
                }
                break;
            case 4:
                Clear();
                std::cout << "Goodbye!\n";
                break;
            case 5:
                Introduction();
                break;
            default:
                std::cout << "You can't do that!\n";
                break;
        }
    } while (userChoice != 4);
    delete(locManager);
    locManager = nullptr;
}

#endif
