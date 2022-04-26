/**
 * @file location.cpp
 * @author Gavin Stoddard (gjsfp3@umsystem.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "location.h"

void Location::append(Location** head_ref, std::string newArea)
{ 
    /*allocate node */
    Location* new_node = new Location();
 
    Location* last = *head_ref; /* used in step 5*/
 
    /*put in the data */
    new_node->area = newArea;
 
    /*This new node is going to be the last node, so
        make next of it as NULL*/
    new_node->next = NULL;
 
    /*If the Linked List is empty, then make the new
        node as head */
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
 
    /*Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
 
    /*Change the next of last node */
    last->next = new_node;
 
    /*Make last node as previous of new node */
    new_node->prev = last;
 
    return;
}

void Location::printList(Location* node)
{
    Location* last;
    std::cout<<"\nTraversal in forward direction \n";
    while (node != NULL)
    {
        std::cout<<"Area: "<<node->area<< std::endl;
        last = node;
        node = node->next;
    }
 
    std::cout<<"\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        std::cout<<" "<<last->area<<" ";
        last = last->prev;
    }
    if(last == NULL)
    {
        std::cout << std::endl;
    }
}

Location* Location::move(Location* head_ref, int num){
    //std::cout << head_ref->area << std::endl;
    //std::cout << "Node Before:" << head_ref->node_ << std::endl;
    node_ = head_ref->node_;

    while(node_ < num){
        head_ref = head_ref->next;
        node_ = node_ + 1;
    }
    head_ref->node_ = node_;
    //std::cout <<  "Node after forward:" << head_ref->node_ << std::endl;

    //std::cout << head_ref->area << std::endl;

    while(node_ > num){
        head_ref = head_ref->prev;
        node_ = node_ - 1;
        //std::cout << node_ << std::endl;
    }
    head_ref->node_ = node_;
    //std::cout <<  "Node after backward:" << head_ref->node_ << std::endl;
    
    return head_ref;
}

Location* Location::start(Location* head_ref){

    head_ref->append(&head_ref, "Office Area");
    head_ref->append(&head_ref, "Break Area");
    head_ref->append(&head_ref, "Test Area");
    head_ref->append(&head_ref, "Component Storage");
    return head_ref;
}

int Location::nextPoint(Location* head_ref){
    int nextMove = -1;
    std::cout << "You are in the " << head_ref->area << ". Where would you like to move next?\n"
    << "Please type in number of place you would like to move.\n" 
    << "1) Office Area\n2) Break Area\n3) Test Area\n4) Component Storage\n";
    
    //User can pick next location only if it is a given option
    while(nextMove <= 0 || nextMove > 4){
        std::cin >> nextMove;
        if(nextMove <= 0 || nextMove > 4){
            std::cout << "ERROR: please pick a given location\n";
        }
    }

    return nextMove;
}