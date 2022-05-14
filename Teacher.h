

#ifndef ASSIGNMENT3_TEACHER_H
#define ASSIGNMENT3_TEACHER_H
#include "Worker.h"


class Teacher: virtual public Worker{
private:
    vector<string>listOfCourses;  //Vector with the names of all the subjects the teacher teaches
protected:
    int _numberOfCourses;  //The amount of subjects that the teacher teaches
    void printAllCourses();  //A method that prints all the subjects taught by the teacher

public:
    Teacher(string firstName, string lastName, string id, int academicYears, vector<string>coursesList);  //Copy constructor
    virtual void printDetails();  //A method that prints all the teacher's details
    virtual double mountSalary();  //A method that returns the teacher's monthly salary
    virtual bool excellent();  //A Boolean method that checks whether the teacher is an outstanding teacher
    virtual ~Teacher();  //Destructor
};


#endif //ASSIGNMENT3_TEACHER_H
