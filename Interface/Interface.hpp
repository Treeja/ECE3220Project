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
        Context(Strategy* const s ) : strategy_(s){}
        ~Context(){delete this->strategy_;}
        void set_strategy(Strategy *strategy){
            delete this->strategy_;
            this->strategy_ = strategy;
        }
        void PrintQuestions(){
            strategy_->PrintQuestions();
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
        MainMenu();
        ~MainMenu() override;
        void PrintQuestions() override;
};

class Move : public Strategy{
    protected:
        std::map<int,std::string> questions = {
            {1, "(1) Office Area"},
            {2, "(2) Break Area"},
            {3, "(3) Test Area"},
            {4, "(4) Component Storage"},
            {5, "(5) Go Back"}
        };
    public:
        Move();
        ~Move() override;
        void PrintQuestions() override;
};

class Interact : public Strategy{
    protected:
        std::map<int, std::string> questions = {
            {1, "(1) Object"},
            {2, "(2) NPC"},
            {3, "(3) Go Back"}
        };
    public:
        Interact();
        ~Interact() override;
        void PrintQuestions() override;

};
class Interact_Object : public Strategy{
    protected:
        std::map<int, std::string> questions = {
            {1, "(1) Inspect Object"},
            {2, "(2) Go Back"}
        };
    public:
        Interact_Object();
        ~Interact_Object() override;
        void PrintQuestions() override;
};
class Interact_NPC : public Strategy{
    protected:
        std::map<int, std::string> questions = {
            {1, "(1) Description"},
            {2, "(2) Question"},
            {3, "(3) Search [Permission Needed]"},
            {4, "(4) Go Back"}
        };
    public:
        Interact_NPC();
        ~Interact_NPC() override;
        void PrintQuestions() override;
};
class Interact_Hol : public Strategy{
    public:
        Interact_Hol();
        ~Interact_Hol() override;
        void PrintQuestions() override;
};
class Inventory : public Strategy{
    protected:
        std::map<int, std::string> questions = {
            {1, "(1) View Notes"},
            {2, "(2) Go Back"}
        };
    public:
        Inventory();
        ~Inventory() override;
        void PrintQuestions() override;
};

class DeclareKiller : public Strategy{
    protected:
        std::map<int, std::string> questions = {
            {1, "Are you sure you want to declare the killer?"}
        };
    public:
        DeclareKiller();
        ~DeclareKiller() override;
        void PrintQuestions() override;
};


#endif