/**
 * @file Gary.h
 * @author Nicholas Ebers (nae5np@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GARY_H
#define GARY_H

#include "Character.h"
#include <string>
#include <sstream>

class Gary : public Character{
private:
    int exhaustion_; 
public:
    Gary();
    std::string get_dialogue(int choice) override;

};

#endif