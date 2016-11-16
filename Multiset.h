//
//  Multiset.h
//  Assignment2
//
//  Created by Lucas Gaylord on 10/23/16.
//  Copyright (c) 2016 Lucas Gaylord. All rights reserved.
//

//DO NOT SUBMIT
//DO NOT MODIFY

#ifndef MULTISET_H_
#define MULTISET_H_

#include <iostream>
#include "Node.h"
using namespace std;

//refer to the sample output if you do not understand what some of the functions do
class Multiset
{
public:
    
    Multiset(); //default constructor
    Multiset(const Multiset& another); //copy constructor; deep copy is required
    ~Multiset(); //destructor; all dynamically allocated memory should be released here
    
    int cardinality() const; //return the cardinality of the whole set, i.e., the sum of all counts of all items
    int uniqueElementsCount() const; //return the number of unique elements in the set
    int itemCount(int item) const; //return the count of the specified integer item in the set
    
    Multiset& operator+=(const int& item); //add an item (an integer value) to the set; do "return *this;" at the end
    Multiset& operator-=(const int& item); //remove an item (an integer value) from the set; do "return *this;" at the end
    Multiset operator+(const Multiset& another) const; //return the resulting set of adding all items from another set to this set (this set should not be altered in this function)
    Multiset operator-(const Multiset& another) const; //return the resulting set of subtracting all items in another set from this set (this set should not be altered in this function)
    Multiset operator|(const Multiset& another) const; //return the union of this set and another set (this set should not be altered in this function)
    Multiset operator&(const Multiset& another) const; //return the intersection of this set and another set (this set should not be altered in this function)
    Multiset& operator=(const Multiset& another); //replace all the items in this set with the ones in the another set; deep copy is required; do "return *this;" at the end; you can assume self-assignment, e.g. multisetX = multisetX, won't happen
    bool operator==(const Multiset& another) const; //check if two sets are equal, i.e., two sets have the same items and the same item count for each item
    
    bool isSupersetOf(const Multiset& another) const; //return true if and only if this set is a superset of another set; return false otherwise
    bool isSubsetOf(const Multiset& another) const; //return true if and only if this set is a subset of another set; return false otherwise
    bool isUniqueSet() const; //return true if and only if this set is a unique set, i.e., all item counts are exactly 1; an empty set is considered as a unique set as well
 
    
    
    
    Multiset(const char* items)
    {
        head = NULL;
        for(int i=0; i<strlen(items); i++)
        {
            int item = items[i] - '0'; //item is the int item to add to the set with the following code
            
            if(head == NULL) //set is empty
            {
                head = new Node(item, 1, NULL);
            }
            else //set is not empty; head != NULL
            {
                Node* previous = NULL;
                Node* current = head;
                while(current != NULL && item > current->getValue())
                {
                    previous = current;
                    current = current->getNext();
                }
                
                if(current != NULL && item == current->getValue()) //if item exists in the set already
                {
                    current->incrementCount();
                }
                else //new node
                {
                    Node* newNode = new Node(item, 1, NULL);
                    
                    if(previous == NULL) //need to add as the new head
                    {
                        newNode->setNext(head);
                        head = newNode;
                    }
                    else //add it to the middle/end
                    {
                        previous->setNext(newNode);
                        newNode->setNext(current);
                    }
                }
            }
        }
    }
    
    


    
    
    
    
private:
    Node* head; //pointer pointing to the head node of the linked list that represents the whole multiset; points to NULL if and only if the multiset is empty; refer to the assignment description webpage for restrictions
    
    //implementation of operator<< is complete; do NOT modify it; it also does some checking to make sure your linked list implementation follows the requirements
    friend ostream & operator<<(ostream& os, const Multiset& set)
    {
       // cout << "\nprinting..." << endl;
        
        Node* current = set.head;
        os << "[";
        while(current != NULL)
        {
            //verify to enforce that the 0-count node should not be in the set
            if(current->getCount() <= 0)
            {
                os << current->getValue() << "(error: empty node should not be in the set)";
                if(current->getNext() != NULL)
                    os << ",";
            }
            
            //output the set items according to their counts
            for(int i=0; i<current->getCount(); i++)
            {
                os << current->getValue();
                
                //verify to enforce that the consecutive nodes do not have the same value
                if(current->getNext() != NULL)
                {
                    if(current->getNext()->getValue() == current->getValue())
                        os << "(error: consecutive nodes should not have the same value)";
                }
                
                if(current->getNext() != NULL || i != current->getCount()-1)
                    os << ",";
            }
            
            current = current->getNext();
        }
        os << "]";
        
       // cout << "\nDONE PRINTING" << endl;
        
        return os;
    }
};

#endif /* MULTISET_H_ */