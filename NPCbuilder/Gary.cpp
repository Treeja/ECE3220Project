/**
 * @file Gary.cpp
 * @author Nicholas Ebers (nae5np@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Gary.h"
#include <iostream>
Gary::Gary() : Character(){}

std::string Gary::get_dialogue(int choice){
    if(exhaustion_>3)
        exhaustion_ = 0;
        
    return "He's dead, what did you expect from this?\n";
}

//Gets Character Description
std::string Gary::get_descrip(){
    return "Aside from the obvious, that Gary is dead, you notice that there has been some blunt force trauma to the back of his head. Blood looks like it spilt out the back of his head and is now pulled up next to him on the floor. You also notice some blisters on his fingers as if he had burnt them. There is a piece of paper sticking out of his back pocket.\n";
}

std::string Gary::search(){
    return "Inside of Gary's pocket you find a note. It looks like the note has data regarding the laser, oddly though the data is scratched out and new data is in its place with a different handwritting\n";
}