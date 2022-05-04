/**
 * @file objects.h
 * @author Gavin Stoddard (gjsfp3@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <string.h>

class Object{ 
    private: 
        // initialize this with the corresponding object string associated with each object.
        std::map<int, std::vector<std::string>> office = {
            {1, {"Carrie's Notebook", "Notebook is filled with good quailty data from death laser."}},
            {2, {"Rough Draft", "Newest rough draft according to date. Has very little sign of Gary's work."}},
            {3, {"Pen", "Slightly bloody, running low on ink."}}
        };
       
        std::map<int, std::vector<std::string>> breakR = {
            {1, {"Caffeinated Coffee", "Is now cooled and filled with decaffeinated coffee."}},
            {2, {"Microwave", "Has food in it that has recently been warmed up."}},
        };

        std::map<int, std::vector<std::string>> test = {
            {1, {"Chris's Notebook", "Contains line after line of 'Writing this to look busy'."}},
            {2, {"Death Laser", "Cooling pops can be heard as if it was recently fired. Also appears to be some cut wires on the side."}},
            {3, {"Decaffeinated Coffee", "Half empty and cooled off by this point"}}
        };

        std::map<int, std::vector<std::string>> component = {
            {1, {"Mop Bucket", "Dirty water with a tint of red"}},
            {2, {"Circuits", "You notice one circuit had blown components. (Maybe from where Gary burnt his fingers after shorting a circuit?)"}},
            {3, {"Wrench", "Squeaky clean. Little damp."}}
        };

        /*
        Test Area: Chris notes, decafe coff, Gary RIP, Note in G pocket,  
        Component Storage: Chris, Peter, Mop Bucket, 
        Break Area: Carrie, cafe coff, Sally,
        Office Area: Carries notes, Henry, Rough Draft, 
        */
    public:
        void get_object_Off(){
            for(int i=1; i<office.size()+1; i++){
                std::cout << i << ") " << office.at(i).front() << std::endl;
            }
        }

        void get_object_breakR(){
            for(int i=1; i<breakR.size()+1; i++){
                std::cout << i << ") " << breakR.at(i).front() << std::endl;
            }
        }

        void get_object_test(){
            for(int i=1; i<test.size()+1; i++){
                std::cout << i << ") " << test.at(i).front() << std::endl;
            }
        }

        void get_object_com(){
            for(int i=1; i<component.size()+1; i++){
                std::cout << i << ") " << component.at(i).front() << std::endl;
            }
        }

        void get_description_Off(int object){
            std::map<int, std::vector<std::string>>::iterator iter;
            iter = office.find(object);
            std::cout << (iter->second).at(1) << std::endl;
        }

        void get_description_Break(int object){
            std::map<int, std::vector<std::string>>::iterator iter;
            iter = breakR.find(object);
            std::cout << (iter->second).at(1) << std::endl;
        }

        void get_description_Test(int object){
            std::map<int, std::vector<std::string>>::iterator iter;
            iter = test.find(object);
            std::cout << (iter->second).at(1) << std::endl;
        }

        void get_description_Com(int object){
            std::map<int, std::vector<std::string>>::iterator iter;
            iter = component.find(object);
            std::cout << (iter->second).at(1) << std::endl;
        }
};

#endif