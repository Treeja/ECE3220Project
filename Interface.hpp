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

/**
 * @brief Declares operations common to all supported strategies
 * 
 */
class Strategy
{
    public:
        virtual ~Strategy() {}
        virtual std::string decision(){return "Called base strategy";}; 
};

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
};

class Move : public Strategy{

};

class Interact : public Strategy{

};


class Inventory : public Strategy{

};






#endif