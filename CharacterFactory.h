/**
 * @file CharacterFactor.h
 * @author Nicholas Ebers (nae5np@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CHARACTERFACTORY_H
#define CHARACTERFACTORY_H

#include "Gary.h"
#include "Chris.h"

class CharacterFactory{
public:
    Gary* createGary();
    Chris* createChris();

    void DeleteCharacter(Character* character);
};

#endif