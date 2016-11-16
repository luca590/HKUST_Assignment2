//
//  Node.h
//  Assignment2
//
//  Created by Lucas Gaylord on 10/23/16.
//  Copyright (c) 2016 Lucas Gaylord. All rights reserved.
//

//DO NOT SUBMIT
//DO NOT MODIFY

#ifndef NODE_H_
#define NODE_H_

class Node
{
public:
   // Node(); //other default constructor **************** ASK DESMOND ******************
    Node(int _value, int _count, Node* _next); //default constructor
    Node(const Node& another); //copy constructor
    
    int getValue() const; //return the value of the integer that this node stores
    int getCount() const; //return the number of copies of the integer this node stores
    Node* getNext() const; //return the next pointer
    
    void incrementCount(); //increase the number of copies of the integer that this node stores by 1
    void decrementCount(); //decrease the number of copies of the integer that this node stores by 1
    void setNext(Node* _next); //set the next pointer
    
    bool operator==(const Node& another) const; //return true if and only if another node stores the same value and count as this node; return false otherwise
    bool operator!=(const Node& another) const; //return false if and only if another node stores the same value and count as this node; return true otherwise
    
private:
    int value; //the value of the integer that this node stores
    int count; //the number of copies of the integer that this node stores
    Node* next; //pointer pointing to the next node; points to NULL if it is the end of the linked list
};

#endif /* NODE_H_ */