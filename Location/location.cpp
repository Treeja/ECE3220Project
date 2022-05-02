/**
 * @file location.cpp
 * @author Gavin Stoddard (gjsfp3@umsystem.edu) Revision by Sam Bealmer (sjbhyf@umsystem.edu)
 * @brief 
 * @version 2
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "location.h"
/**
 * @brief Construct a new Location Manager:: Location Manager object
 * In reality, makes an empty list.
 * 
 */
LocationManager::LocationManager(){}
/**
 * @brief Destroy the Location Manager:: Location Manager object
 * 
 */
LocationManager::~LocationManager(){
    Node* temp = new Node();
    while(head != NULL){
        temp = head;
        head = head->next;
        delete(temp);
    }
}

/**
 * @brief Returns a pointer to the node searched for in the list
 * 
 * @param head Reference to the head node [Usually done through getHead()]
 * @param n nth position of node searching for
 * @return struct Node* 
 */
struct Node* LocationManager::findNode(Node* head, int n){
    Node *node = head;
    while(node != nullptr){
        if(node->pos_ == n){
            currentPosition = node->pos_;
            return node;
        }
        node = node->next;
    }
    //std::cerr << "No such location available!\n";
    return nullptr;
}

/**
 * @brief Returns head
 * 
 * @return Node* 
 */
Node* LocationManager::getHead(){
    return head;
}

/**
 * @brief Returns current position
 * 
 * @return int 
 */
int LocationManager::getCurrentPos(){
    return currentPosition;
}

/**
 * @brief Inserts a node at the end of the dll
 * 
 * @param head Reference to the head. Can be double ref because this is only really used internally
 * @param pos int position value of new node
 * @param areaName Data
 * @param areaDescription Data 
 */
void LocationManager::insert_end(Node** head, int pos, std::string areaName, std::string areaDescription){
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

/**
 * @brief Prints the list, starting at pointer to given node [Usually the head]
 * 
 * @param head Node to start printing list at
 */
void LocationManager::printList(Node* head){
    Node* last = head;
    while (last != NULL){
        std::cout << "\nPosition: " << last->pos_ << "\nareaName: " << last->areaName_ << "\nareaDesc: " << last->areaDescription_ << "\n^v";
        last = last->next;
    }
    if(head == NULL)
        std::cout << "NULL";
}

/**
 * @brief Creates the linked list
 * NOTE: This can probably be moved into the constructor, but I'm leaving it here in case I ever need to recreate the list for some reason.
 */
void LocationManager::createList(){
    insert_end(&head,1,"Office Area","You see nothing but cubicals. Henry is sitting at his cubical working.\nA few desks down you see a desk with a notebook on it.");
    insert_end(&head,2,"Break Area","Filled with coffee cups and food wrapers. The is acouple of microwaves and a coffee maker with a pot of coffee.\nYou see Carrie pouring another cup of coffee while talking to Sally.");
    insert_end(&head,3,"Test Area","Gary's body lies next to a puddle of water. You can hear the death laser shutting down.\nNext to the laser there are abunch of circuits next to testing equipment.");
    insert_end(&head,4,"Component Storage","You see Chris and Peter standing at different sides of the room.\nThere is a lot of water splashed around the room.");
}