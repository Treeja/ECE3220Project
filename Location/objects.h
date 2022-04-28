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
        std::vector<std::string> object = {"Chris's Notebook", "Carrie's Notebook", "Death Laser", "Decafe Coff", "Note", "Mop Bucket", "Cafe Coff", "Rough Draft"};
        /*
        Test Area: Chris notes, decafe coff, Gary RIP, Note in G pocket,  
        Component Storage: Chris, Peter, Mop Bucket, 
        Break Area: Carrie, cafe coff, Sally,
        Office Area: Carries notes, Henry, Rough Draft, 
        */
        std::vector<std::string> description = {"Its a death laser", "To fix things", "issa knife", "To write", "Clean"}; // initialize this with the corresponding object string associated with each object.
        std::map<std::string,std::string> description_map; // This stores a look up table for the each morse code character
    public:
        void generate_object_map(){
            for(int i=0; i<=object.size(); i++){
                description_map[object[i]] = description[i];
            }
        }

        void get_description(std::string text){
            std::map<std::string, std::string>::iterator iter;
            iter = description_map.find(text);
            if(text == iter->first){
                std::cout << iter->second << std::endl;
            }
        }
};

#endif