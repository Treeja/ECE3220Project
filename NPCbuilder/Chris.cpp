/**
 * @file Chris.cpp
 * @author Nicholas Ebers (nae5np@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Chris.h"
#include <iostream>
Chris::Chris() : Character(){}

//Dialogue for Chris. Can as a max of 3 questions tracked by exhaustion variable
std::string Chris::get_dialogue(int choice){
    if(exhaustion_ < 3){  
        switch (choice)
        {
        case 1:
            exhaustion_ += 1;
            return "I was in his class Introduction to Death Laser Design. I was lucky enough to work in this lab with him. Its super top secret! Were about to make the biggest death laser on Earth....ope maybe I shouldn't have said that.\n";
            break;
        case 2:
            exhaustion_ += 1;
            return "I was just by the test area writing in my notebook, lots of data we need to keep track of! Oh! and I also switched out the coffee over here with decaf, Carrie is going to die next if we don't watch her coffee intake.\n";
            break;
        case 3:
            exhaustion_ += 1;
            return "I'm a undergraduate research assistant in the lab, probably because I'm the smartest kid in the class.\n";
            break;
        case 4:
            exhaustion_ += 1;
            return "To be completely honest, I did see Gary messing with some wires over here, maybe he just shocked himself. Could explain why the lights went off.\n";
            break;
        case 5:
            exhaustion_ += 1;
            return "If I had to pick anyone it would be that PhD student Carrie. She is absolutly off her rocker, she drinks 30 cups of coffee a day and never stops working. She has a screw loose if you ask me. Did you see all the Band-Aids on her hand from the blisters she developed writing so much?\n";
            break;
        
        default:
            return "Was that even English? Try again..\n";
            break;
        }
    }
    else{
        return "Okay you've bugged me long enough I need to keep writing in my notebook\n";
    }
}

//Gets Character Description
std::string Chris::get_descrip(){
    return "Chris looks young, probably not 21 yet. He has a proud stance to him, you notice that he really only breaths through his mouth. He is the only one in the lab wearing shorts and open toed shoes.\n";
}

std::string Chris::search(){
    return "On Chris' person you find; a fake ID and a note with specific details regading the death laser (he most likely shouldn't be writting this stuff down for security reasons).\n";
}