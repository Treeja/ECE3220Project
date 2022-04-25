/**
 * @file location.h
 * @author Gavin Stoddard (gjsfp3@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string.h>
#ifndef LOCATION_H
#define LOCATION_H

class Location
{
    protected:
    //Location* head = NULL;
    int node_ = 1;
    public:
        //Location();
        std::string area;
        Location* next; // Pointer to next node in DLL
        Location* prev; // Pointer to previous node in DLL
        void append(Location** head_ref, std::string newArea);
        void printList(Location* node);
        Location* move(Location* head_ref, int num);
        Location* start(Location* head_ref); 
        int nextPoint(Location* head_ref);

};


#endif