/**
 * @file Interface.hpp
 * @author Sam Bealmer (sjbhyf@umsystem.edu)
 * @brief Main user interface for deciding where to go, what to do, etc.
 * @version 0.1
 * @date 2022-04-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#include <string>
#include <map>
#include <iterator>
#include <iostream>
#include <stdio.h>
#include "Interface.hpp"

/**
 * @brief Declares operations common to all supported strategies
 * 
 */
MainMenu::MainMenu(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
MainMenu::~MainMenu(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void MainMenu::PrintQuestions(){
    for (int i = 1; i < questions.size()+1; i++)
    {
        std::cout << questions.at(i) << std::endl;
    }
}

Interact::Interact(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
Interact::~Interact(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void Interact::PrintQuestions(){
    for (int i = 1; i < questions.size()+1; i++)
    {
        std::cout << questions.at(i) << std::endl;
    }
}

Interact_NPC::Interact_NPC(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
Interact_NPC::~Interact_NPC(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void Interact_NPC::PrintQuestions(){
    for (int i = 1; i < questions.size()+1; i++)
    {
        std::cout << questions.at(i) << std::endl;
    }
}

Interact_Object::Interact_Object(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
Interact_Object::~Interact_Object(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void Interact_Object::PrintQuestions(){
    for (int i = 1; i < questions.size()+1; i++)
    {
        std::cout << questions.at(i) << std::endl;
    }
}

Inventory::Inventory(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
Inventory::~Inventory(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void Inventory::PrintQuestions(){
    for (int i = 1; i < questions.size()+1; i++)
    {
        std::cout << questions.at(i) << std::endl;
    }
}

DeclareKiller::DeclareKiller(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
DeclareKiller::~DeclareKiller(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void DeclareKiller::PrintQuestions(){
    for (int i = 1; i < questions.size()+1; i++)
    {
        std::cout << questions.at(i) << std::endl;
    }
}
