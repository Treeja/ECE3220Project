/**
 * @file Character.cpp
 * @author Nicholas Ebers (nae5np@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Character.h"

Character::Character(){
    choice_ = -1;
}

std::string Character::get_dialogue(int choice){
    return "Base Class Invoked";
}

std::string Character::get_descrip(){
    return "Base Class Invoked";
}

std::string Character::search(){
    return "Base Class Invoked";
}