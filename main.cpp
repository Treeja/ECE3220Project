/**
 * @file main.cpp
 * @author Sam Bealmer  (sjbhyf@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Interface/MenuFunctions.hpp"
#include "Location/location.h"
#include <iostream>


int main(int argc, char** argv){
    // INIT
    
    // MAIN
    std::cout << "Welcome to our game!\n";
    Context *context = new Context(new MainMenu);
    CharacterFactory charFac;
    Character* charList[6];
    charList[0] = charFac.createCarrie();
    charList[1] = charFac.createChris();
    charList[2] = charFac.createGary();
    charList[3] = charFac.createHenry();
    charList[4] = charFac.createPeter();
    charList[5] = charFac.createSally();
    Introduction();
    MainMenuMenu(context, charList);
    delete(context);
    context = nullptr;
    charFac.DeleteCharacter(charList[0]);
    charFac.DeleteCharacter(charList[1]);
    charFac.DeleteCharacter(charList[2]);
    charFac.DeleteCharacter(charList[3]);
    charFac.DeleteCharacter(charList[4]);
    charFac.DeleteCharacter(charList[5]);
    return EXIT_SUCCESS;
}