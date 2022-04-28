/**
 * @file Sally.h
 * @author Nicholas Ebers (nae5np@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SALLY_H
#define SALLY_H

#include "Character.h"
#include <string>
#include <sstream>

class Sally : public Character{
private:
    int exhaustion_; 
public:
    Sally();
    std::string get_dialogue(int choice) override;
    std::string get_descrip() override;
    std::string search() override;

};

#endif