

#ifndef ASSIGNMENT3_PERSON_H
#define ASSIGNMENT3_PERSON_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Person {
private:

    string _firstName, _lastName, _idNumber;
    vector<string> _usedId; //A vector that will store ID numbers, will be used later to check whether an ID number
                           // already exists in a database

public:

    Person(string firsName, string lastName, string id); //Copy constructor
    bool doesIdExist(string id);  //A method that checks if an ID number already exists in a database
    virtual void printDetails() = 0;
    virtual bool excellent() = 0;
    virtual ~Person();  //Destructor
    /* GETTER/SETTER */
    string getName();
};


#endif //ASSIGNMENT3_PERSON_H

