/**
 * @file Character.h
 * @author Nicholas Ebers (nae5np@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

class Character{
protected:
    int choice_;
    int exhaustion_;
public:
    Character(); //default constructor
    virtual std::string get_dialogue(int choice); //get dialogue for each character
    virtual std::string get_descrip(); //gets description of each character
    virtual std::string search(); //searches each character
    
};


#endif