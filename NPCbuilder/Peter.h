/**
 * @file Peter.h
 * @author Nicholas Ebers (you@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PETER_H
#define PETER_H

#include "Character.h"
#include <string>
#include <sstream>

class Peter : public Character{
private:
    int exhaustion_; 
public:
    Peter();
    std::string get_dialogue(int choice) override;

};

#endif