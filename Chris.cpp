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
std::string Chris::get_dialogue(int choice){
    switch (choice)
    {
    case 1:
        exhaustion_ += 1;
        std::cout<<exhaustion_<<std::endl;
        return "Chris: Answer 1";
        break;
    case 2:
        exhaustion_ += 1;
        std::cout<<exhaustion_<<std::endl;
        return "Chris: Answer 2";
        break;
    case 3:
        exhaustion_ += 1;
        std::cout<<exhaustion_<<std::endl;
        return "Chris: Answer 3";

        break;
    
    default:
        return "No answer for your dumb questions sir";
        break;
    }
}