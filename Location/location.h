/**
 * @file location.h
 * @author Gavin Stoddard (gjsfp3@umsystem.edu) Revised by Sam Bealmer (sjbhyf@umsystem.edu)
 * @brief Revised version of Gavin's dll, this one should have all the same functions, but without all the segfaults
 * @version 1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#ifndef LOCATION_H
#define LOCATION_H

struct Node{
    int pos_;
    std::string areaName_;
    std::string areaDescription_;
    struct Node* next;
    struct Node* prev;
};

class LocationManager{
    protected:
        struct Node* head = NULL;
        int currentPosition = 1;
    public:
        LocationManager();
        ~LocationManager();
        Node* getHead();
        int getCurrentPos();
        void createList();
        void printList(struct Node* head);
        struct Node* findNode(struct Node* head, int n);
        void insert_end(struct Node** head, int pos, std::string areaName, std::string areaDescription);
};

#endif

