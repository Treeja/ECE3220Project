/**
 * @file Henry.cpp
 * @author Nicholas Ebers (nae5np@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Henry.h"
#include <iostream>
Henry::Henry() : Character(){}

/*
How do you know Gary? 
Where were you before the lights went out? 
What is your involvement with the research?
Did you hear or see anything worth noting? 
Who do you think killed Gary?
*/

//Dialogue for Henry, Max 3 options controlled by exhaustion variable
std::string Henry::get_dialogue(int choice){
    if(exhaustion_>3)
        exhaustion_ = 0;
        
    if(exhaustion_ < 3){  
        switch (choice)
        {
        case 1:
            exhaustion_ += 1;
            return "Gary you see, is a collegue of mine. We studied together in graduate school and have been researching together for years. He is a dear old friend of mine. I can't believe someone could have done this.\n";
            break;
        case 2:
            exhaustion_ += 1;
            return "Well I was here in the office area writing a rough draft of...our...paper. We are working on some cutting edge stuff here, I'll send you a copy once I get published.\n";
            break;
        case 3:
            exhaustion_ += 1;
            return "I am a co-researcher in this lab. I don't know why but the university refuses to give me my own lab, but I don't mind researching with Gary I guess...\n";
            break;
        case 4:
            exhaustion_ += 1;
            return "The custodian, whats his name...ah yes Peter...he moved awfully quick when those lights went out. You might talk to him and see what he was doing before the lights went out.\n";
            break;
        case 5:
            exhaustion_ += 1;
            return "I honestly think it was that janitor, Peter right? He just always seems to have a look in his eyes. I think he hates working here.\n";
            break;
        
        default:
            return "Sir, I am a scholar. If you are going to ask me questions I'm going to need you to speak clearly\n";
            break;
        }
    }
    else{
        return "Sir, I need to get back to my research. You've exhausted me.\n";
    }
}

//Gets Character Description
std::string Henry::get_descrip(){
    return "Henry is clean cut, and is wearing a very nice and clean lab coat. The three pins in his lab coat are perfectly aligned. Currently it look that he is writting some sort of academic paper. He looks like he doesn't have time to talk.\n";
}

std::string Henry::search(){
    return "All you can find on Henry is a wallet that contain a picture of Gary and Henry when they were younger. Probably undergrads back then\n";
}