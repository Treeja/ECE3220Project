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
    MainMenuMenu(context, charList);

    // TEST
    // LocationManager *locationList = new LocationManager();
    // locationList->createList();
    // //locationList->printList(locationList->getHead());
    // Node* temp = locationList->findNode((locationList->getHead()), 4);
    // std::cout << "TempNode: " << temp->pos_ << "\n CurrentLoc: " << locationList->getCurrentPos() << std::endl;
    // temp = locationList->findNode((locationList->getHead()), 2);
    // std::cout << "TempNode: " << temp->pos_ << "\n CurrentLoc: " << locationList->getCurrentPos() << std::endl;
    // temp = locationList->findNode((locationList->getHead()), 3);
    // std::cout << "TempNode: " << temp->pos_ << "\n CurrentLoc: " << locationList->getCurrentPos() << std::endl;
    // temp = locationList->findNode((locationList->getHead()), 1);
    // std::cout << "TempNode: " << temp->pos_ << "\n CurrentLoc: " << locationList->getCurrentPos() << std::endl;
    
    // EXIT
    delete(context);
    for (size_t i = 0; i < 6; i++)
    {
        charFac.DeleteCharacter(charList[i]);
    }
    return EXIT_SUCCESS;
}