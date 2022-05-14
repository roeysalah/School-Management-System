/* Assignment: 3
Author: Roey Salah,
 ID: 206115438
Author: Priel Hoffman,
 ID: 318277308
*/

#ifndef ASSIGNMENT3_SECRETARY_H
#define ASSIGNMENT3_SECRETARY_H
#include "AdministrationPersonal.h"

class Secretary : public AdministrationPersonal{
private:

    int _numberOfChildren;  //Number of children of the secretary attending school

public:
    Secretary(string firstName, string lastName, string id, int administrationYears, string LocationNum, int NumOfChildren); //Copy constructor
    virtual bool excellent();  //A Boolean method that checks whether the secretary is outstanding
    virtual double mountSalary();  //A method that returns the secretary's monthly salary
    virtual void printDetails();  //A method that prints all the details of the secretary
    virtual ~Secretary();  //Destructor
};


#endif //ASSIGNMENT3_SECRETARY_H
