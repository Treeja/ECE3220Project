/**
 * @file Henry.h
 * @author Nicholas Ebers (nae5np@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef HENRY_H
#define HENRY_H

#include "Character.h"
#include <string>
#include <sstream>

class Henry : public Character{
private:
    int exhaustion_ =0; 
public:
    Henry();
    std::string get_dialogue(int choice) override;
    std::string get_descrip() override;
    std::string search() override;

};

#endif