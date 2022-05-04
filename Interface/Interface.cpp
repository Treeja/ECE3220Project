/**
 * @file Interface.hpp
 * @author Sam Bealmer (sjbhyf@umsystem.edu)
 * @brief Declarations for Strategy Design for User Interface
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
MainMenu::MainMenu(){}
MainMenu::~MainMenu(){}
void MainMenu::PrintQuestions(){
    for (int i = 1; i < questions.size()+1; i++)
    {
        std::cout << questions.at(i) << std::endl;
    }
}

Move::Move(){}
Move::~Move(){}
void Move::PrintQuestions(){
    for (int i = 1; i < questions.size()+1; i++)
    {
        std::cout << questions.at(i) << std::endl;
    }
    return;
}

Interact::Interact(){}
Interact::~Interact(){}
void Interact::PrintQuestions(){
    for (int i = 1; i < questions.size()+1; i++)
    {
        std::cout << questions.at(i) << std::endl;
    }
}

Interact_NPC::Interact_NPC(){}
Interact_NPC::~Interact_NPC(){}
void Interact_NPC::PrintQuestions(){
    for (int i = 1; i < questions.size()+1; i++)
    {
        std::cout << questions.at(i) << std::endl;
    }
}

Interact_Object::Interact_Object(){}
Interact_Object::~Interact_Object(){}
void Interact_Object::PrintQuestions(){
    for (int i = 1; i < questions.size()+1; i++)
    {
        std::cout << questions.at(i) << std::endl;
    }
}

DeclareKiller::DeclareKiller(){}
DeclareKiller::~DeclareKiller(){}
void DeclareKiller::PrintQuestions(){
    for (int i = 1; i < questions.size()+1; i++)
    {
        std::cout << questions.at(i) << std::endl;
    }
}
