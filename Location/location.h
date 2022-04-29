/**
 * @file location.h
 * @author Gavin Stoddard (gjsfp3@umsystem.edu) Revised by Sam Bealmer (sjbhyf@umsystem.edu)
 * @brief 
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
        int currentPosition = -1;
    public:
        void createList(){
            insert_end(&head,1,"Office Area","You see nothing but cubicals. Henry is sitting at his cubical working.\nA few desk down you see a desk with a notebook on it.");
            insert_end(&head,2,"Break Area","Filled with coffee cups and food wrapers. The is acouple of microwaves and a coffee maker with a pot of coffee.\nYou see Carrie pouring another cup of coffee while talking to Sally.");
            insert_end(&head,3,"Test Area","Gary's body lies next to a puddle of water. You can hear the death laser shutting down.\nNext to the laser there are abunch of circuits next to testing equipment.");
            insert_end(&head,4,"Component Storage","You see Chris and Peter standing at different sides of the room.\nThere is alot of water splashed around the room.");
        };
        struct Node* findNode(struct Node** head, int n){
            Node *node = *head;
            while(node != nullptr){
                if(node->pos_ == n){
                    return node;
                }
                node = node->next;
            }
            std::cerr << "No such location available!\n";
            return nullptr;
        };
};

void insert_end(struct Node** head, int pos, std::string areaName, std::string areaDescription){
    struct Node* newNode = new Node;
    struct Node* last = *head;
    newNode->pos_ = pos;
    newNode->areaName_ = areaName;
    newNode->areaDescription_ = areaDescription;
    newNode->next = NULL;
    if (*head == NULL){
        newNode->prev= NULL;
        *head = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    newNode->prev = last;
    return;
}

void printList(struct Node* node){
    struct Node* last;
    while (node != NULL){
        std::cout << "\nPosition: " << node->pos_ << "\nareaName: " << node->areaName_ << "\nareaDesc: " << node->areaDescription_ << "\n^v";
        last = node;
        node = node->next;
    }
    if(node == NULL)
        std::cout << "NULL";
}
#endif

