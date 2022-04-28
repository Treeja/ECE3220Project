/**
 * @file Carrie.h
 * @author Nicholas Ebers (nae5np@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CARRIE_H
#define CARRIE_H

#include "Character.h"
#include <string>
#include <sstream>

class Carrie : public Character{
private:
    int exhaustion_; 
public:
    Carrie();
    std::string get_dialogue(int choice) override;
    std::string get_descrip() override;
    std::string search() override;

};

#endif