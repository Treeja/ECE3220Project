/**
 * @file dialogue.hpp
 * @author Sam Bealmer (sjbhyf@umsystem.com)
 * @brief The dialogue cpp/hpp pair are responsible for sending an int based on the question asked.
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DIALOGUE_H
#define DIALOGUE_H
#include <string>
#include <vector>

class DialogueDecision {
    public:
        DialogueDecision();
        ~DialogueDecision();
        std::string getQuestion(int qNumber);
        void printQuestions();
                
    private:
        std::vector<std::string> questions;
};


#endif