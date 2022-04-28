/**
 * @file Peter.cpp
 * @author Nicholas Ebers (nae5np@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Peter.h"
#include <iostream>

/*
How do you know Gary? 
Where were you before the lights went out? 
What is your involvement with the research?
Did you hear or see anything worth noting? 
Who do you think killed Gary?
*/


Peter::Peter() : Character(){}

//Dialogue for Peter, Max 3 questions controlled by exhaustion variable
std::string Peter::get_dialogue(int choice){
    if(exhaustion_ < 3){  
        switch (choice)
        {
        case 1:
            exhaustion_ += 1;
            return "I don't he's just one of those fancy pants proffessors. They all think they are better than us working class folk. I'm just the janitor here, cleaning up all their messes\n";
            break;
        case 2:
            exhaustion_ += 1;
            return "I was over in the test area, cleaning up another one of their spills\n";
            break;
        case 3:
            exhaustion_ += 1;
            return "Ya think I do research? Ha! Well lets see I am an expert in putting this mop in the bucket and cleaning up after all these people\n";
            break;
        case 4:
            exhaustion_ += 1;
            return "All I seen was another mess to clean up. Who's gonna clean all this up. Probably me\n";
            break;
        case 5:
            exhaustion_ += 1;
            return "I don't really know these people outside of cleaning up after them but there's something about the lady in the suit. I overheard her talking to herself about needing to find a way to cut the funding\n";
            break;
        
        default:
            return "Look I clearly don't know anything, would you go bug someone else\n";
            break;
        }
    }
    else{
        return "Someones gotta start cleaning this up. See ya later\n";
    }
}

//Gets Character Description
std::string Peter::get_descrip(){
    return "Place Holder";
}