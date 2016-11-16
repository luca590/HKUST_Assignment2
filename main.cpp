//
//  main.cpp
//  Assignment2
//
//  Created by Lucas Gaylord on 10/23/16.
//  Copyright (c) 2016 Lucas Gaylord. All rights reserved.
//








#include <iostream>
#include "Multiset.h"

using namespace std;

//the following static variable is added for grading the memory leak test case, see also the Node.h we provided from the marking scheme page
//int Node::deleteCount;

int main()
{
    /*
     
     Test case 1 expected output:
     [11,22,33]
     
     Test case 2 expected output:
     [1,5,11,22,33,33,44,50,100]
     
     Test case 3 expected output:
     []
     
     Test case 4 expected output:
     [1]
     
     Test case 5 expected output:
     [22,33]
     
     Test case 6 expected output:
     [11,33]
     
     Test case 7 expected output:
     [11,22]
     
     Test case 8 expected output:
     [11,22,33]
     
     Test case 9 expected output:
     []
     
     Test case 10 expected output:
     6
     
     Test case 11 expected output:
     3
     
     Test case 12 expected output:
     3
     
     Test case 13 expected output:
     2
     
     Test case 14 expected output:
     [1,1,2,3,3,3]
     
     Test case 15 expected output:
     [1]
     
     Test case 16 expected output:
     [1,2,2,3,3,3,4,5,5]
     
     Test case 17 expected output:
     [1,2,2,3][2,3,3,3,4,5,5][]
     
     Test case 18 expected output:
     [2,3,3]
     
     Test case 19 expected output:
     [][][]
     
     Test case 20 expected output:
     [1,2,3,4]
     
     Test case 21 expected output:
     [1,2,2,2,3,3,3,3,3,4,5,5]
     
     Test case 22 expected output:
     [1,2,2,3,3][2,3,3,3,4,5,5][]
     
     Test case 23 expected output:
     [1,3]
     
     Test case 24 expected output:
     [1,2]
     
     Test case 25 expected output:
     [1,2,2,3,3][][]
     
     Test case 26 expected output:
     11
     
     Test case 27 expected output:
     00
     
     Test case 28 expected output:
     00
     
     Test case 29 expected output:
     010
     
     Test case 30 expected output:
     1
     
     Test case 31 expected output:
     0
     
     Test case 32 expected output:
     1
     
     Test case 33 expected output:
     01
     
     Test case 34 expected output:
     01
     
     Test case 35 expected output:
     101
     
     Test case 36 expected output:
     10
     
     Test case 37 expected output:
     10
     
     Test case 38 expected output:
     011
     
     Test case 39 expected output:
     [1,1,2,3,3,3]
     
     Test case 40 expected output:
     [1]
     
     Test case 41 expected output:
     You have passed the test case of memory leak! (no score penalty)
     
     */
    
    
    
    int testCase = 16; //change this number to test different test cases
    
    
    
    if(testCase == 1) //+= simple
    {
        Multiset set1;
        set1 += 11;
        set1 += 22;
        set1 += 33;
        cout << endl << set1 << endl;
    }
    else if(testCase == 2) //+= advanced
    {
        Multiset set1;
        set1 += 11;
        set1 += 33;
        set1 += 22;
        set1 += 44;
        set1 += 1;
        set1 += 100;
        set1 += 50;
        set1 += 5;
        set1 += 33;
        cout << endl << set1 << endl;
    }
    else if(testCase == 3) //empty set
    {
        Multiset set1;
        cout << endl << set1 << endl;
    }
    else if(testCase == 4) //one-element set
    {
        Multiset set1;
        set1 += 1;
        cout << endl << set1 << endl;
    }
    
    if(testCase == 5) //+= and -= first
    {
        Multiset set1;
        set1 += 11;
        set1 += 22;
        set1 += 33;
        set1 -= 11;
        cout << endl << set1 << endl;
    }
    else if(testCase == 6) //+= and -= middle
    {
        Multiset set1;
        set1 += 11;
        set1 += 22;
        set1 += 33;
        set1 -= 22;
        cout << endl << set1 << endl;
    }
    else if(testCase == 7) //+= and -= last
    {
        Multiset set1;
        set1 += 11;
        set1 += 22;
        set1 += 33;
        set1 -= 33;
        cout << endl << set1 << endl;
    }
    else if(testCase == 8) //+= and -= non-existent
    {
        Multiset set1;
        set1 += 11;
        set1 += 22;
        set1 += 33;
        set1 -= 44;
        cout << endl << set1 << endl;
    }
    else if(testCase == 9) //+= and -= everything
    {
        Multiset set1;
        set1 += 11;
        set1 += 22;
        set1 += 33;
        set1 -= 11;
        set1 -= 22;
        set1 -= 33;
        cout << endl << set1 << endl;
    }
    
    if(testCase == 10) //cardinality
    {
        Multiset set1("112333");
        cout << endl << set1.cardinality() << endl;
    }
    else if(testCase == 11) //uniqueElementsCount
    {
        Multiset set1("112333");
        cout << endl << set1.uniqueElementsCount() << endl;
    }
    else if(testCase == 12) //itemCount 1
    {
        Multiset set1("112333");
        cout << endl << set1.itemCount(3) << endl;
    }
    else if(testCase == 13) //itemCount 2
    {
        Multiset set1("112333");
        cout << endl << set1.itemCount(1) << endl;
    }
    
    if(testCase == 14) //copy constructor
    {
        Multiset set1("112333");
        Multiset set2(set1);
        cout << endl << set2 << endl;
    }
    else if(testCase == 15) //copy constructor: deep copy
    {
        Multiset set1("1");
        Multiset set2(set1);
        set1 += 22; //to test deep copying; set2 should not be affected
        cout << endl << set2 << endl;
    }
    
    if(testCase == 16) // union
    {
        Multiset set4a("1223");
        Multiset set4b("2333455");
        cout << endl << (set4a | set4b) << endl;
    }
    else if(testCase == 17)// union empty
    {
        Multiset set4a("1223");
        Multiset set4b("2333455");
        Multiset empty("");
        cout << endl << (set4a | empty) << (empty | set4b) <<  (empty | empty) << endl;
    }
    
    if(testCase == 18) // intersection
    {
        Multiset set4a("12233");
        Multiset set4b("2333455");
        cout << endl << (set4a & set4b) << endl;
    }
    else if(testCase == 19)// intersection empty
    {
        Multiset set4a("12233");
        Multiset set4b("2333455");
        Multiset empty("");
        cout << endl << (set4a & empty) << (empty & set4b) <<  (empty & empty) << endl;
    }
    
    if(testCase == 20) // + simple
    {
        Multiset set4a("123");
        Multiset set4b("4");
        cout << endl << (set4a + set4b) << endl;
    }
    else if(testCase == 21) // + advanced
    {
        Multiset set4a("12233");
        Multiset set4b("2333455");
        cout << endl << (set4a + set4b) << endl;
    }
    else if(testCase == 22)// + empty
    {
        Multiset set4a("12233");
        Multiset set4b("2333455");
        Multiset empty("");
        cout << endl << (set4a + empty) << (empty + set4b) <<  (empty + empty) << endl;
    }
    
    if(testCase == 23) // - simple
    {
        Multiset set4a("123");
        Multiset set4b("2");
        cout << endl << (set4a - set4b) << endl;
    }
    else if(testCase == 24) // - advanced
    {
        Multiset set4a("12233");
        Multiset set4b("2333455");
        cout << endl << (set4a - set4b) << endl;
    }
    else if(testCase == 25)// - empty
    {
        Multiset set4a("12233");
        Multiset set4b("2333455");
        Multiset empty("");
        cout << endl << (set4a - empty) << (empty - set4b) << (empty - empty) << endl;
    }
    
    if(testCase == 26) // == 1
    {
        Multiset set4a("123");
        Multiset set4b("123");
        cout << endl << (set4a == set4b) << (set4b == set4a) << endl;
    }
    else if(testCase == 27)// == 2
    {
        Multiset set4a("123");
        Multiset set4b("1234");
        Multiset empty("");
        cout << endl << (set4a == set4b) << (set4b == set4a) << endl;
    }
    else if(testCase == 28)// == 3
    {
        Multiset set4a("123");
        Multiset set4b("1123");
        cout << endl << (set4a == set4b) << (set4b == set4a) << endl;
    }
    else if(testCase == 29)// == empty
    {
        Multiset set4a("123");
        Multiset empty("");
        cout << endl << (set4a == empty) << (empty == empty) << (empty == set4a) << endl;
    }
    
    if(testCase == 30) // isUniqueSet 1
    {
        Multiset set4a("123");
        cout << endl << set4a.isUniqueSet() << endl;
    }
    else if(testCase == 31) // isUniqueSet 2
    {
        Multiset set4a("1233");
        cout << endl << set4a.isUniqueSet() << endl;
    }
    else if(testCase == 32) // isUniqueSet empty
    {
        Multiset set4a("");
        cout << endl << set4a.isUniqueSet() << endl;
    }
    
    if(testCase == 33) // isSupersetOf 1
    {
        Multiset set4a("123");
        Multiset set4b("1234");
        cout << endl << set4a.isSupersetOf(set4b) << set4b.isSupersetOf(set4a) << endl;
    }
    else if(testCase == 34) // isSupersetOf 2
    {
        Multiset set4a("123");
        Multiset set4b("1223");
        cout << endl << set4a.isSupersetOf(set4b) << set4b.isSupersetOf(set4a) << endl;
    }
    else if(testCase == 35) // isSupersetOf empty
    {
        Multiset set4a("123");
        Multiset set4b("");
        cout << endl << set4a.isSupersetOf(set4b) << set4b.isSupersetOf(set4a) << set4b.isSupersetOf(set4b) << endl;
    }
    
    if(testCase == 36) // isSubsetOf 1
    {
        Multiset set4a("123");
        Multiset set4b("1234");
        cout << endl << set4a.isSubsetOf(set4b) << set4b.isSubsetOf(set4a) << endl;
    }
    else if(testCase == 37) // isSubsetOf 2
    {
        Multiset set4a("123");
        Multiset set4b("1223");
        cout << endl << set4a.isSubsetOf(set4b) << set4b.isSubsetOf(set4a) << endl;
    }
    else if(testCase == 38) // isSubsetOf empty
    {
        Multiset set4a("123");
        Multiset set4b("");
        cout << endl << set4a.isSubsetOf(set4b) << set4b.isSubsetOf(set4a) << set4b.isSubsetOf(set4b) << endl;
    }
    
    if(testCase == 39) // =
    {
        Multiset set1("112333");
        Multiset set2("");
        set2 = set1;
        cout << endl << set2 << endl;
    }
    else if(testCase == 40) // = : deep copy
    {
        Multiset set1("1");
        Multiset set2("");
        set2 = set1;
        set1 += 22; //to test deep copying; set2 should not be affected
        cout << endl << set2 << endl;
    }
    
    /*if(testCase == 41) //memory leak test
    {
        Multiset* set1 = new Multiset("123");
        delete set1;
        if(Node::deleteCount<3)
            cout << endl << "Expected Node::deleteCount should be at least 3 as there are 3 nodes in the multiset, but yours is " << Node::deleteCount << "; score penalty is -10" << endl;
        else
            cout << endl << "You have passed the test case of memory leak! (no score penalty)" << endl;
    }*/
    
    
    return 0;
}

























/*
#include <iostream>
#include <cmath>
#include "Multiset.h"

using namespace std;

int main()
{
    Multiset* set3;
    
    cout << endl << "=== set1 ===" << endl;
    cout << "add 11, 22, 33 ..." << endl;
    Multiset set1;
    cout << set1 << endl;
    set1 += 11;
    cout << set1 << endl;
    set1 += 22;
    cout << set1 << endl;
    set1 += 33;
    cout << set1 << endl;
    
    cout << "set1's cardinality = " << set1.cardinality() << endl;
    cout << "set1's uniqueElementsCount = " << set1.uniqueElementsCount() << endl;
    cout << "set1's isUniqueSet = " << set1.isUniqueSet() << endl;
    
    cout << endl << "=== set2 ===" << endl;
    cout << "add 33, 11, 1, 100, 1, 11, 11, 100 ... remove 11 ..." << endl;
    Multiset set2;
    cout << set2 << endl;
    set2 += 33;
    cout << set2 << endl;
    set2 += 11;
    cout << set2 << endl;
    set2 += 1;
    cout << set2 << endl;
    set2 += 100;
    cout << set2 << endl;
    set2 += 1;
    cout << set2 << endl;
    set2 += 11;
    cout << set2 << endl;
    set2 += 11;
    cout << set2 << endl;
    set2 += 100;
    cout << set2 << endl;
    set2 -= 11;
    cout << set2 << endl;
    
    cout << "set2's cardinality = " << set2.cardinality() << endl;
    cout << "set2's uniqueElementsCount = " << set2.uniqueElementsCount() << endl;
    cout << "set2's isUniqueSet = " << set2.isUniqueSet() << endl;
    cout << "set2's itemCount(11) = " << set2.itemCount(11) << endl;
    cout << "set2's itemCount(22) = " << set2.itemCount(22) << endl;
    cout << "set2's itemCount(33) = " << set2.itemCount(33) << endl;
    
    cout << endl << "=== set3 (copied from set1) ===" << endl;
    set3 = new Multiset(set1);
    cout << *set3 << endl;
    
    cout << endl << "=== updated set2 (=set3) ===" << endl;
    set2 = *set3;
    cout << set2 << endl;
    
    cout << endl << "=== set4 ===" << endl;
    Multiset set4a;
    Multiset set4b;
    set4a +=  2;
    set4a +=  4;
    set4a +=  4;
    set4a +=  6;
    set4b += 4;
    set4b += 6;
    set4b += 6;
    set4b += 6;
    set4b += 8;
    set4b += 10;
    set4b += 10;
    Multiset set4 = set4a | set4b;
    cout << set4a << " | " << set4b << " = " << set4 << endl;
    cout << set4 << " & " << set4a << " = " << (set4 & set4a) << endl;
    cout << set4 << " & " << set4b << " = " << (set4 & set4b) << endl;
    cout << set4 << " - " << set4a << " = " <<  set4 - set4a << endl;
    cout << set4a << " - " << set4b << " = " << set4a - set4b << endl;
    cout << set4a << " + " << set4b << " = " << set4a + set4b << endl;
    cout << set4 << " + " << set4b << " = " << set4 + set4b << endl;
    
    cout << "Testing == ..." << endl;
    cout << (set4 == set4) << " " << (set4 == set4a) << " " << (set4 == set4b) << " " << (set4 == (set4b | set4a)) << endl;
  /*  cout << set4 << endl;
    cout << (set4b | set4a) << endl;
    cout << set4b << endl;
    cout << set4a << endl;
    
    cout << "Testing isSupersetOf ..." << endl;
    cout << set4.isSupersetOf(set4) << " " << set4.isSupersetOf(set4a) << " " << set4.isSupersetOf(set4b) << endl;
    cout << set4a.isSupersetOf(set4) << " " << set4a.isSupersetOf(set4a) << " " << set4a.isSupersetOf(set4b) << endl;
    cout << set4b.isSupersetOf(set4) << " " << set4b.isSupersetOf(set4a) << " " << set4b.isSupersetOf(set4b) << endl;
    
    cout << "Testing isSubsetOf ..." << endl;
    cout << set4.isSubsetOf(set4) << " " << set4.isSubsetOf(set4a) << " " << set4.isSubsetOf(set4b) << endl;
    cout << set4a.isSubsetOf(set4) << " " << set4a.isSubsetOf(set4a) << " " << set4a.isSubsetOf(set4b) << endl;
    cout << set4b.isSubsetOf(set4) << " " << set4b.isSubsetOf(set4a) << " " << set4b.isSubsetOf(set4b) << endl;
    
    
    delete set3;
     
     
    
    return 0;
}*/
