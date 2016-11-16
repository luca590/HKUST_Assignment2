//
//  Node.cpp
//  Assignment2
//
//  Created by Lucas Gaylord on 10/23/16.
//  Copyright (c) 2016 Lucas Gaylord. All rights reserved.
//

//SUBMIT THIS
//MAKE SURE THE SPELLING OF THE FILENAME IS EXACTLY Node.cpp

#include "Node.h"
#include <iostream>

using namespace std;
/*
Node::Node() {
    value = 0;
    count = 0;
    next = 0;
}*/

Node :: Node(int _value, int _count, Node* _next) {
   // cout << "in Node parameter constructor" << endl;
value = _value;
count = _count;
next = _next;
	} //default constructor

Node :: Node(const Node& another) {
value = another.value;
count = another.count;
next = another.next;
	} //copy constructor
    
int Node ::  getValue() const {
	return value;
	} //return the value of the integer that this node stores

int Node ::  getCount() const {
	return count;
	} //return the number of copies of the integer this node stores
Node* Node :: getNext() const {
//cout << "in getNext. Next is: " << next << endl;
    return next;
        
	} //return the next pointer
    
void Node ::  incrementCount() {
	++count;
	} //increase the number of copies of the integer that this node stores by 1

void Node ::  decrementCount() {
	--count;
	} //decrease the number of copies of the integer that this node stores by 1

void Node ::  setNext(Node* _next) {
	next = _next;
	} //set the next pointer
    
bool Node ::  operator==(const Node& another) const {
	return (another.value == value & another.count == count) ? true : false;
	} //return true if and only if another node stores the same value and count as this node; return false otherwise

bool Node ::  operator!=(const Node& another) const {
    return(!(*this == another));
	} //return false if and only if another node stores the same value and count as this node; return true otherwise
