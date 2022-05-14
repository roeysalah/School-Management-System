/* Assignment: 3
Author: Roey Salah,
 ID: 206115438
Author: Priel Hoffman,
 ID: 318277308
*/

#include "Secretary.h"


Secretary::Secretary(string firstName,string lastName,string id,int administrationYears,string LocationNum,int NumOfChildren)
        :Person(firstName, lastName,id),
         Worker(firstName, lastName, id, administrationYears),
         AdministrationPersonal(firstName,lastName,id,administrationYears,LocationNum)
{  /* Copy constructor */
    _numberOfChildren=NumOfChildren;
}

void Secretary::printDetails(){
    /* This method prints all the details of the secretary */
    cout << "Name of the Secretary:" << this->getName() << endl;
    cout << "Monthly salary:" << mountSalary() << endl;
    cout << "Academic Years as a Secretary:" << this->getAcademicYears() << endl;
    cout << "The Secretary have " << _numberOfChildren << " Children learning in this school" << endl;
    if (this->excellent()) { //A call for a method that checks whether the secretary excels. If the returned value is that
        // the secretary does excel (true)
        cout << "This Secretary is Outstanding!" << endl;
    }
    else { //If the returned value is that the secretary does not excel (false)
        cout << "This Secretary is Not Outstanding!" << endl;
    }
    cout<<"*********************************************************************************"<<endl;
}

double Secretary ::mountSalary(){
    /* This method returns the monthly salary of the secretary to be calculated according to the following formula:
       200 * x + basis ,where x denotes the number of the secretary's children attending school */
    int salary;
    salary= (_numberOfChildren * 200) + basis;
    return salary;
}

bool Secretary:: excellent(){
    /* A Boolean method that checks whether the secretary is outstanding. An outstanding secretary is one whose number
      of years of seniority is greater than ten. */
    if(AdministrationPersonal::_academicYears>10){
        return true;
    }
    return false;
}

Secretary::~Secretary(){
/* Destructor */
}