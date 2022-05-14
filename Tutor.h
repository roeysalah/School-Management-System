

#ifndef ASSIGNMENT3_TUTOR_H
#define ASSIGNMENT3_TUTOR_H
#include "Teacher.h"
#include "Class.h"

class Class;

class Tutor: public Teacher{
protected:
    Class *teacher;   //Pointer to the class the tutor is teaching

public:
    Tutor(string firstName,string lastName,string id,int academicYears,vector<string>coursesList,Class*teacherClass);  //Copy constructor
    virtual double mountSalary();   //A method that returns the tutor's monthly salary
    virtual bool excellent();  //A Boolean method that checks whether the tutor is an outstanding tutor
    virtual void printDetails();  //A method that prints all the details of the tutor
    virtual ~Tutor();  //Destructor

    Class*getTeacherClass();

};


#endif //ASSIGNMENT3_TUTOR_H
