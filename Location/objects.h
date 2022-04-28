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
        std::vector<std::string> Office_Obj = {"Carrie's Notebook", "Rough Draft", "Pen"};
        std::vector<std::string> Office_Des = {"Carrie's Notebook des", "Rough Draft des", "Pen des"};

        std::vector<std::string> Break_Obj = {"Caffeinated Coffee" };
        std::vector<std::string> Break_Des = {"Caffeinated Coffee des" };

        std::vector<std::string> Test_Obj = {"Chris's Notebook", "Death Laser", "Decaffeinated Coffee"};
        std::vector<std::string> Test_Des = {"Chris's Notebook des", "Death Laser des", "Decaffeinated Coffee des"};

        std::vector<std::string> Component_Obj = {"Mop Bucket" };
        std::vector<std::string> Component_Des = {"Mop Bucket des" };

        /*
        Test Area: Chris notes, decafe coff, Gary RIP, Note in G pocket,  
        Component Storage: Chris, Peter, Mop Bucket, 
        Break Area: Carrie, cafe coff, Sally,
        Office Area: Carries notes, Henry, Rough Draft, 
        */
        std::map<std::string,std::string> Office_map;
        std::map<std::string,std::string> Break_map;
        std::map<std::string,std::string> Test_map;
        std::map<std::string,std::string> Component_map; // This stores a look up table for the each morse code character
    public:
        void generate_object_map(int area){
            if(area == 1){
                for(int i=0; i<=Office_Obj.size(); i++){
                    Office_map[Office_Obj[i]] = Office_Des[i];
                }
            }
            if(area == 2){
                for(int i=0; i<=Break_Obj.size(); i++){
                    Break_map[Break_Obj[i]] = Break_Des[i];
                }
            }
            if(area == 3){
                for(int i=0; i<=Test_Obj.size(); i++){
                    Test_map[Test_Obj[i]] = Test_Des[i];
                }
            }
            if(area == 4){
                for(int i=0; i<=Component_Obj.size(); i++){
                    Component_map[Component_Obj[i]] = Component_Des[i];
                }
            }
        }

        void get_description_Off(std::string text){
            std::map<std::string, std::string>::iterator iter;
            iter = Office_map.find(text);
            if(text == iter->first){
                std::cout << iter->second << std::endl;
            }
        }

        void get_description_Break(std::string text){
            std::map<std::string, std::string>::iterator iter;
            iter = Break_map.find(text);
            if(text == iter->first){
                std::cout << iter->second << std::endl;
            }
        }

        void get_description_Test(std::string text){
            std::map<std::string, std::string>::iterator iter;
            iter = Test_map.find(text);
            if(text == iter->first){
                std::cout << iter->second << std::endl;
            }
        }

        void get_description_Compon(std::string text){
            std::map<std::string, std::string>::iterator iter;
            iter = Component_map.find(text);
            if(text == iter->first){
                std::cout << iter->second << std::endl;
            }
        }
};

#endif