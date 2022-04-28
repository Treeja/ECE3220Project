/**
 * @file Interface.hpp
 * @author Sam Bealmer (sjbhyf@umsystem.edu)
 * @brief Main user interface for deciding where to go, what to do, etc.
 * @version 0.1
 * @date 2022-04-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>
#include <map>
#include <iterator>
#include <iostream>
#include <stdio.h>

/**
 * @brief Declares operations common to all supported strategies
 * 
 */
class Strategy
{
    public:
        virtual ~Strategy() {}
        virtual void PrintQuestions(){
            for (int i = 1; i < 5; i++)
            {
                std::cout << questions.at(i) << std::endl;
            }
        }
    protected:
        std::map<int,std::string> questions = {
            {1, "(1) Base Class Question"},
            {2, "(2) Base Class Question"},
            {3, "(3) Base Class Question"},
            {4, "(4) Base Class Question"},
            {5, "(5) Base Class Question"}
        };
};
/**
 * @brief Keeps track of what strategy we are currently using
 * 
 */
class Context
{
    private:
        Strategy *strategy_;
    public:
        Context(Strategy *strategy = nullptr) : strategy_(strategy){}
        ~Context(){delete this->strategy_;}
        void set_strategy(Strategy *strategy){
            delete this->strategy_;
            this->strategy_ = strategy;
        }
        Strategy* getStrategy(){
            return strategy_;
        }
};

class MainMenu : public Strategy{
    protected:
        std::map<int, std::string> questions = {
            {1, "(1) Move"},
            {2, "(2) Interact"},
            {3, "(3) Inventory"},
            {4, "(4) Declare Killer"},
            {5, "(5) Exit game"}
        };
    public:
        // Make sure this works calling the base function, as this function shouldn't change for any of the classes but still needs to be available
        void PrintQuestions();
};

class Move : public Strategy{

};

class Interact : public Strategy{
    protected:
        std::map<int, std::string> questions = {
            {1, "(1) Object"},
            {2, "(2) NPC"},
            {3, "(3) Go Back"}
        };
    public:
        void PrintQuestions();

};
class Interact_Object : public Strategy{
    protected:
        std::map<int, std::string> questions = {
            {1, "(1) Inspect Object"}
        };
    public:
        void PrintQuestions();
};
class Interact_NPC : public Strategy{
    protected:
        std::map<int, std::string> questions = {
            {1, "(1) Description"},
            {2, "(2) Question"},
            {3, "(3) Search [Permission Needed]"}
        };
    public:
        void PrintQuestions();
};
class Interact_Hol : public Strategy{

};
class Inventory : public Strategy{
    protected:
        std::map<int, std::string> questions = {
            {1, "(1) View Notes"}
        };
    public:
        void PrintQuestions();
};
class Inventory_ViewNotes : public Strategy{

};

class DeclareKiller : public Strategy{
    protected:
        std::map<int, std::string> questions = {
            {1, "Are you sure you want to declare the killer?"}
        };
    public:
        void PrintQuestions();
};
class MenuBack : public Strategy{

};


#endif