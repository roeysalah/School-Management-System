/* Assignment: 3
Author: Roey Salah,
 ID: 206115438
Author: Priel Hoffman,
 ID: 318277308
*/

#ifndef ASSIGNMENT3_MANAGER_H
#define ASSIGNMENT3_MANAGER_H

#include "Teacher.h"
#include "AdministrationPersonal.h"
#include <iostream>


class Manager :virtual public Teacher, virtual public AdministrationPersonal{
private:
    static Manager* SchoolManager;
    Manager(string firstName, string lastName, string id, int seniorityYears, int administrationYears
            , vector<string>coursesList, string LocationNum);  //Copy constructor
public:
    static Manager* newSchoolManager(string firstName, string lastName, string id, int academicYears,
                                     int administrationYears, vector<string>coursesList, string LocationNum); //A static method of the class that makes sure there is no more than one manager
    static void deleteManager();  //A method that deletes a manager from memory
    virtual double mountSalary();  //A method that returns the manager's monthly salary
    virtual void printDetails();  //A method that prints the details of the manager
    virtual bool excellent();  //A Boolean method that checks whether the manager is outstanding
    virtual ~Manager();  //Destructor
};


#endif //ASSIGNMENT3_MANAGER_H
