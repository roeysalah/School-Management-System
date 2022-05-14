/* Assignment: 3
Author: Roey Salah,
 ID: 206115438
Author: Priel Hoffman,
 ID: 318277308
*/

#ifndef ASSIGNMENT3_WORKER_H
#define ASSIGNMENT3_WORKER_H
#include "Person.h"
#include "vector"

class Worker: virtual public Person{
protected:

    int _academicYears;  //Years of seniority of the employee in the school
    static int basis;  //A static variable that will be initialized to about 25. This variable will be used to calculate
    // workers salaries

public:

    Worker(string firstName, string lastName, string id, int academicYears);  //Copy constructor
    int getAcademicYears();
    virtual bool excellent() = 0;  //A method that checks whether the worker excels
    virtual double mountSalary() = 0;  //A method that returns the worker's monthly salary
    virtual void printDetails() = 0;  //A method that prints worker details
    virtual ~Worker();  //Destructor
    virtual int compareValue();
};
#endif //ASSIGNMENT3_WORKER_H

