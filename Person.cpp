/* Assignment: 3
Author: Roey Salah,
 ID: 206115438
Author: Priel Hoffman,
 ID: 318277308
*/

#include "Person.h"

Person::Person(string firsName,string lastName,string id){
    /* Copy constructor */
    _firstName=firsName;
    _lastName=lastName;
    _idNumber=id;
    _usedId.push_back(id);
}

bool Person::doesIdExist(string id){
    /* This method receive an ID number and returns a Boolean value if the ID number already exists in the database.
       The goal is to avoid a situation of adding the same people to the database. */
    bool found = false;
    for (int i = 0; i < _usedId.size() && !found; i++) {
        if (id == _usedId[i]) {
            found = true;
        }
    }
    return found;
}

string Person:: getName(){
    return _firstName +" "+_lastName;
}

Person::~Person(){
    /* Destructor */
}