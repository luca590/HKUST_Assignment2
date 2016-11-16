//
//  Multiset.cpp
//  Assignment2
//
//  Created by Lucas Gaylord on 10/23/16.
//  Copyright (c) 2016 Lucas Gaylord. All rights reserved.
//

//SUBMIT THIS
//MAKE SURE THE SPELLING OF THE FILENAME IS EXACTLY Multiset.cpp

#include "Multiset.h"

Multiset :: Multiset() {
	head = NULL;
	} //default constructor
Multiset :: Multiset(const Multiset& another) {
   // cout << "in copy constructor" << endl;
		operator=(another);
	} //copy constructor; deep copy is require
Multiset :: ~Multiset() {
    if(head) { //Called for deleting as memory goes out of scope
        
        //clearSet
        
        Node* ptr = head;
        Node* temp;
        
        // cout << "ptr is: " << ptr << endl;
        
        while(ptr) {
            temp = ptr;
            //   cout << "temp is: " << temp -> getValue() << endl;
            ptr = ptr -> getNext(); //reset pointer before deleting temp, otherwise cannot call getNext()
            delete temp;
        }
        
        if(head)
            head = NULL;
        //cout << "END OF CLEAR SET FUNCTION\n\n\n\n" << endl;
    }
    
    

	head = NULL;
	} //destructor; all dynamically allocated memory should be released here

//void Multiset :: clearSet()

int Multiset :: cardinality() const {
	int sum = 0;
	Node* ptr = head;
	while (ptr) {
	sum += ptr -> getCount();
	ptr = ptr -> getNext();
		}
    return sum;
	} //return the cardinality of the whole set, i.e., the sum of all counts of all items

int Multiset :: uniqueElementsCount() const {
	int count = 0;
	Node* ptr = head;

	while (ptr) {
        ++count;
	ptr = ptr -> getNext();
		}
    return count;
	} //return the number of unique elements in the set

int Multiset :: itemCount(int item) const {
	Node* ptr = head;

	while(ptr) {
	if (ptr -> getValue() == item)
	return ptr -> getCount();

	ptr = ptr -> getNext();
	} //return the count of the specified integer item in the set
    
    return 0;
}

Multiset& Multiset :: operator+=(const int& item) {
 //   cout << "in the += function, item is: " << item << endl;
    
    if(!head) {
       // cout << "head is NULL" << endl;
        head = new Node(item, 1, NULL);
        return *this;
    }

    int count = 1;
    int uniq = uniqueElementsCount();
	Node* ptr = head;
    
	if(itemCount(item) != 0)
		while(ptr) {
//cout << "in the while loop, ptr is: "<< ptr << endl;
			if(ptr -> getValue() == item) {
			ptr -> incrementCount();
			return *this;
            }
			ptr = ptr -> getNext();
        }
    
    else {
 //   cout << "item does not exist and value is: " << item << endl;

	//if the item does not already exist
    count = 0;
	Node* prev_ptr = head;
	while(count < uniq && ptr -> getValue() < item) {
	prev_ptr = ptr;
	ptr = ptr -> getNext();
	++count;
		}
//cout << "after 2nd while and count is: " << count << " and uniqe elements is: " << uniq << endl;
	
        if(count == 0)      //If at the beginning of the list
            head = new Node(item, 1, prev_ptr);
        else if(count < uniq) //add in the middle
            prev_ptr -> setNext(new Node(item, 1, ptr));
        else if (count >= uniq) // add at the end
            prev_ptr -> setNext(new Node(item, 1, NULL));
        //else
           // cout << "There's a problem with if state in +=..." << endl;
    }
    
    return *this;
	
} //add an item (an integer value) to the set; do "return *this;" at the end
    
Multiset& Multiset :: operator-=(const int& item) {
    //cout << "Entered -= function" << endl;
	Node* ptr = head;
	Node* prev_ptr = head;
    
	if(itemCount(item) != 0) {
     //   cout << "Assuming item " << item << " exists!" << endl;
		while(ptr) {
			if(ptr -> getValue() == item && ptr -> getCount() > 1) {
			ptr -> decrementCount();
			return *this;
			}
            
			else 
				if (ptr -> getValue() == item && ptr -> getCount() <= 1) {
                   // cout << "Count is <= 1, therefore deleting item " << item << endl;
                    
                if(ptr == head)
                    head = ptr -> getNext();
                else
				prev_ptr -> setNext(ptr -> getNext());
                    
				delete ptr;
				return *this;
					}
			prev_ptr = ptr;
			ptr = ptr -> getNext();
			}	
		}
    
   // else
     //   cerr << "ERROR you cannot subtract " << item << endl;
	return *this;
	} //remove an item (an integer value) from the set; do "return *this;" at the end
    
Multiset Multiset :: operator+(const Multiset& another) const {
	Multiset A(another);
	Node* ptr = head;
	while(ptr) {
        for (int i = 0; i < ptr -> getCount(); i++)
                A += ptr -> getValue();
	ptr = ptr -> getNext();
		}
    return A;
} //return the resulting set of adding all items from another set to this set (this set should not be altered in this function)

Multiset Multiset :: operator-(const Multiset& another) const {
 //   cout << "entered operator-" << endl;
	Multiset A;
    
	Node* ptr = head; 
	while(ptr) {
        for (int i = 0; i < ptr -> getCount(); i++)
            A += ptr -> getValue();
            ptr = ptr -> getNext();
	}
  //  cout << "Added values from us to A" << endl;
    
	ptr = another.head;
	while(ptr) {
 //   cout << "Subtracting value: " << ptr -> getValue() << endl;
        for (int i = 0; i < ptr -> getCount(); i++)
            A -= ptr -> getValue();
	ptr = ptr -> getNext();
		}
  //  cout << "Subtracted values from A. A's head is: " << A.head << endl;
    return A;
} //return the resulting set of subtracting all items in another set from this set (this set should not be altered in this function)
    
Multiset Multiset :: operator|(const Multiset& another) const {
    //cout << "\n\n\n\n\n\n\n\nin the | function" << endl;
Multiset A(another);
	Node* ptr = head;
	while(ptr) {
        if(!(another.itemCount(ptr -> getValue()) != 0)) //if the value in me does not exist in A
            for (int i = 0; i < ptr -> getCount(); i++)
            A += ptr -> getValue();	// add to A
        
		else {		//assuming the value exists, find who's count is bigger
            //cout << "assuming value: " << ptr -> getValue() << " does exist." << endl;
            int a = A.itemCount(ptr -> getValue()); //cout << "for value: " << ptr -> getValue() << " count is: " << a << endl;
			int b = ptr -> getCount();              //cout << "for value: " << ptr -> getValue() << " count is: " << b << endl;
			if (b > a)	//if the count not in A is bigger, add it to A
				for(int i = 0; i < b - a; i++)
					A += ptr -> getValue();
            }
        ptr = ptr -> getNext();
		}
   // cout << "FINISHED WITH THE | FUNCTION\n\n\n\n\n\n" << endl;
    return A;
	} //return the union of this set and another set (this set should not be altered in this function)
    
Multiset Multiset :: operator&(const Multiset& another) const {
	Multiset A;
	Node* ptr = head;
	while(ptr) {
        if(another.itemCount(ptr -> getValue()) != 0 && itemCount(ptr -> getValue()) != 0) {
            
            int a = another.itemCount(ptr -> getValue()); //cout << "for value: " << ptr -> getValue() << " count is: " << a << endl;
            int b = ptr -> getCount();           //  cout << "for value: " << ptr -> getValue() << " count is: " << b << endl;
            if (b < a)	//find which ever count is samller and add it to A. Should not already exist in A, because A is empty
                for(int i = 0; i < b; i++)
                A += ptr -> getValue();
            else if (a <= b)
                for(int i = 0; i < a; i++)
                    A += ptr -> getValue();
            }
        
            ptr = ptr -> getNext();
        }
    return A;
	} //return the intersection of this set and another set (this set should not be altered in this function)
    
Multiset& Multiset :: operator=(const Multiset& another) {
if(this == &another)
return *this;
    
    //clearSet
    { //Called for deleting as memory goes out of scope
        Node* ptrx = head;
        Node* tempx;
        
        // cout << "ptr is: " << ptr << endl;
        
        while(ptrx) {
            tempx = ptrx;
            //   cout << "temp is: " << temp -> getValue() << endl;
            ptrx = ptrx -> getNext(); //reset pointer before deleting temp, otherwise cannot call getNext()
            delete tempx;
        }
        
        if(head)
            head = NULL;
        //cout << "END OF CLEAR SET FUNCTION\n\n\n\n" << endl;
    }

    
    
	Node* ptr = another.head;
    head = new Node(ptr -> getValue(), ptr -> getCount(), NULL);
	Node* this_ptr = head;	//should start with head
    ptr = ptr -> getNext();
    
        while(ptr) {
        this_ptr -> setNext(new Node(ptr -> getValue(), ptr -> getCount(), NULL));
            //cout << "in == this_ptr is: " << this_ptr << endl;
        this_ptr = this_ptr -> getNext();
        ptr = ptr -> getNext(); //needs to be at the bottom so when it goes out of range, while does not execute
        }

return *this;

	} //replace all the items in this set with the ones in the another set; deep copy is required; do "return *this;" at the end; you can assume self-assignment, e.g. multisetX = multisetX, won't happen
    
bool Multiset :: operator==(const Multiset& another) const {
	if(cardinality() != another.cardinality()) return false; //if sets are not the same size, return false
	
	Node* ptr = head; 
	while(ptr) {
		if(!(another.itemCount(ptr -> getValue()) != 0 && itemCount(ptr -> getValue()) == another.itemCount(ptr -> getValue())))
            return false;
		//if the value of our Node exists in the other multiset, and their counts are the same, for all values in our multiset (given the same size), the multisets are equal
		ptr = ptr -> getNext();
		}	
	return true;
	} //check if two sets are equal, i.e., two sets have the same items and the same item count for each item

bool Multiset :: isSupersetOf(const Multiset& another) const {
	if(cardinality() < another.cardinality()) return false; //if sets are not the same size, return false

	Node* ptr = another.head;
	while(ptr) {
        if(!(itemCount(ptr -> getValue()) != 0 && itemCount(ptr -> getValue()) >= ptr -> getCount()))
            return false;
        ptr = ptr -> getNext();
		}
	return true;
	} //return true if and only if this set is a superset of another set; return false otherwise

bool Multiset :: isSubsetOf(const Multiset& another) const { //is there an element in another for every element in *this?
	if(cardinality() > another.cardinality()) return false; //if sets are not the same size, return false

	Node* ptr = head;
	while(ptr) {
		if(!(another.itemCount(ptr -> getValue()) != 0 && ptr -> getCount() <= another.itemCount(ptr -> getValue())))
        return false;
        ptr = ptr -> getNext();
		}
	return true;
	} //return true if and only if this set is a subset of another set; return false otherwise

bool Multiset :: isUniqueSet() const {
	if(head == NULL) return true;	//empty sets are unique

	Node* ptr = head;
	while(ptr) {
		if(ptr -> getCount() != 1) return false;
	ptr = ptr -> getNext();
		}
    return true;
	} //return true if and only if this set is a unique set, i.e., all item counts are exactly 1; an empty set is considered as a unique set as well
