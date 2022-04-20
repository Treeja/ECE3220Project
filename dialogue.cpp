/**
 * @file dialogue.cpp
 * @author Sam Bealmer (sjbhyf@umsystem.edu)
 * @brief The dialogue cpp/hpp pair are responsible for sending an int based on the question asked.
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "dialogue.hpp"
#include <iostream>

DialogueDecision::DialogueDecision(){
    questions.push_back("(1) How do you know gary?");
    questions.push_back("(2) Where were you before the lights went out?");
    questions.push_back("(3) What is your involvement with the research?");
    questions.push_back("(4) What's your favorite color?");
    questions.push_back("(5) How many 'I's are there in 'Mississippi'");
}

DialogueDecision::~DialogueDecision(){
    while(!questions.empty()){
        questions.pop_back();
    }
}

std::string DialogueDecision::getQuestion(int qNumber){
    return questions[qNumber];
}

void DialogueDecision::printQuestions(){
    for(std::string i : questions){
        std::cout << i << std::endl;
    }
}