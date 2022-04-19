/**
 * @file CharacterFactory.cpp
 * @author Nicholas Ebers (nae5np@umsystem.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "CharacterFactory.h"

Gary* CharacterFactory::createGary(){
    return (new Gary());
}

void CharacterFactory::DeleteCharacter(Character* character){
    delete character;
}
