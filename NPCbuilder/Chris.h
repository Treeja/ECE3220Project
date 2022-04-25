/**
 * @file Chris.h
 * @author Nicholas Ebers (nae5np@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CHRIS_H
#define CHRIS_H

#include "Character.h"
#include <string>
#include <sstream>

class Chris : public Character{
private:
    int exhaustion_; 
public:
    Chris();
    std::string get_dialogue(int choice) override;

};

#endif