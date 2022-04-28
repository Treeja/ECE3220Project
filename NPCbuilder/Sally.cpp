/**
 * @file Sally.cpp
 * @author Nicholas Ebers (nae5np@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Sally.h"
#include <iostream>


Sally::Sally() : Character(){}

/*
How do you know Gary? 
Where were you before the lights went out? 
What is your involvement with the research?
Did you hear or see anything worth noting? 
Who do you think killed Gary?
*/

//Dialogue Options for Sally, Max 3 controlled by exhaustion variable
std::string Sally::get_dialogue(int choice){
    if(exhaustion_ < 3){  
        switch (choice)
        {
        case 1:
            exhaustion_ += 1;
            return "He is mearly my subordinant, he and everyone else in this lab. We own them, Laser Corp that is.\n";
            break;
        case 2:
            exhaustion_ += 1;
            return "I was over in the office area getting ready trying to figure out how to tell Henry and Gary that we were cutting the funding to this project.\n";
            break;
        case 3:
            exhaustion_ += 1;
            return "I'm the money around here. I am a representative of the giant laser super company Laser Corp. I was actually here to figure out how we can cut their funding, but it looks like someone has done it for me. I only have to pay one researcher now.\n";
            break;
        case 4:
            exhaustion_ += 1;
            return "I heard a loud thump and oddly enough some splashing. Could of just been in my head though it was very exciting after all.\n";
            break;
        case 5:
            exhaustion_ += 1;
            return "Do you expect me to have some in depth psychological evaluation of each one of these people. Well I do...but I'd have to call Laser Corp to get it. For now though I have no clue.\n";
            break;
        
        default:
            return "I'm sorry what did you say?\n";
            break;
        }
    }
    else{
        return "Time is money and I'm not sure you have the money to afford my time\n";
    }
}

//Gets Character Description
std::string Sally::get_descrip(){
    return "Sally is in a very nice, probably expensive suit. Her hair is pulled back and she look mean. He fists are curled up so tight that her knuckles are white. She has a note in her pocket with the word NOTICE visible.\n";
}

std::string Sally::get_descrip(){
    return "On Sally you find a note from her employer with details regarding the defunding of the lab. It looks as if they will be stripping down the lab and selling it to Russia\n"
}