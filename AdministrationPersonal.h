

#ifndef ASSIGNMENT3_ADMINISTRATIONPERSONAL_H
#define ASSIGNMENT3_ADMINISTRATIONPERSONAL_H
#include "Worker.h"

class AdministrationPersonal : virtual public Worker{
private:

    string _LocationOffice;  //A number that describes the location of the administrative staff member office

public:

    AdministrationPersonal(string firstName, string lastName, string id, int administrationYears, string LocationNum);  //Copy constructor
    virtual ~AdministrationPersonal();  //Destructor
    virtual double mountSalary()=0;  //A method that returns the administrative staff member's monthly salary
    virtual void printDetails()=0;  //A method that prints all the details of the administrative staff member
    virtual bool excellent()=0;  //A Boolean method that checks whether an administrative staff member is outstanding
};


#endif //ASSIGNMENT3_ADMINISTRATIONPERSONAL_H
