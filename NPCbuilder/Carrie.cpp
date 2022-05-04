/**
 * @file Carrie.cpp
 * @author Nicholas Ebers (nae5np@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Carrie.h"
#include <iostream>
Carrie::Carrie() : Character(){}

//Dialogue Choices for Carrie, three questions max can be answered by her. Exhasution variable prevents more
std::string Carrie::get_dialogue(int choice){
    if(exhaustion_>3)
        exhaustion_ = 0;
    
    if(exhaustion_ < 3){  
        switch (choice)
        {
        case 1:
            exhaustion_+= 1;
            return "Well you see. Gary is my advisor. He has me doing all of the work around here. I write code for him. I fill out excel sheets. I cook dinner. I do the laundry...\n";
            break;
        case 2:
            exhaustion_+= 1;
            return "I was over in the office area. Writing notes for Gary as well as making a pot of coffee while finishing off the other pot.\n";
            break;
        case 3:
            exhaustion_ += 1;
            return "I am a PhD student researching under Gary. We are preparing to write a paper. 'Giant Death Lasers and the Ability to Cause Death' riviting topic if you ask me.\n";
            break;
        case 4:
            exhaustion_ += 1;
            return "Ya know, I think I might have saw Chris tampering with the coffee in the test area earlier.......OH NO!!! IM DRINKING THAT COFFEE AM I GOING TO DIE?!?!?!\n";
            break;
        case 5:
            exhaustion_ += 1;
            return "Ohhhh I shouldn't be saying this but...Henry has been kind of angry with Gary lately. I think Henry believes he should be the main author on the paper, I don't think he'd kill him over it though...maybe just mess with his results.\n";
            break;
        
        default:
            return "You silly billy that's not a question! Try again!\n";
            break;
        }
    }
    else{
        return "I have got to get back to work. Gary would want someone to finish his research, I don't have time for your questions...unless you can get me some more coffee...\n";
    }
}


//returns description of Carrie
std::string Carrie::get_descrip(){
    return "You see that Carrie is wearing a battered lab coat with three pens sitting in the pocket, one of them leaking. Her lab goggles are sitting crooked on her forhead. She has a coffee cup in her hand and she can't seem to sit still and is clearly out of breath. You notice that her fingers are slighlty bloody, with bandages.\n";

}

std::string Carrie::search(){
    return "You search Carrie and find a broken pen, a bottle of adderall, and a bunch of random electrical components like resistors and capacitors.\n";
}