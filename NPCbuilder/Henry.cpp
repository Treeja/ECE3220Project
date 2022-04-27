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
std::string Henry::get_dialogue(int choice){
    if(exhaustion_ < 3){  
        switch (choice)
        {
        case 1:
            exhaustion_ += 1;
            return "Answer 1";
            break;
        case 2:
            exhaustion_ += 1;
            return "Answer 2";
            break;
        case 3:
            exhaustion_ += 1;
            return "Answer 3";
            break;
        case 4:
            exhaustion_ += 1;
            return "Answer 4";
            break;
        case 5:
            exhaustion_ += 1;
            return "Answer 5";
            break;
        
        default:
            return "No answer for your dumb questions sir";
            break;
        }
    }
    else{
        return "I don't feel like talking anymore..";
    }
}