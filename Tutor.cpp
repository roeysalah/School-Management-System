
#include "Tutor.h"

Tutor::Tutor(string firstName, string lastName, string id, int academicYears, vector<string>coursesList, Class* teacherClass) :
        Person(firstName, lastName, id),
        Worker(firstName, lastName, id, academicYears),
        Teacher(firstName,lastName,id,academicYears,coursesList)
{ /* Copy constructor */
    this->teacher=teacherClass;
}

Class* Tutor::getTeacherClass(){
    return this->teacher;
}

double Tutor::mountSalary(){
    /* This method returns the tutor's monthly salary. The salary will be about 1000 NIS more
       from a teacher who teaches the same amount of subjects and has the same seniority. */
    return (Teacher::mountSalary() + 1000);
}

void Tutor::printDetails(){
    /* The method prints all the details of the tutor, including the subjects he is teaching,
       his salary, the class he is educating (all the details of his pupils and the rest
       of class details) and other personal details of the tutor. */
    cout << "Name of the Tutor:" << this->getName() << endl;
    cout << "Monthly salary:" << mountSalary() << endl;
    cout << "Academic Years as a School Educator:" << this->_academicYears << endl;
    cout<<"This Tutor Is Teaching the following Courses:"<<endl;
    printAllCourses();
    if(this->excellent()){  //A call for a method that checks whether the tutor excels. If the returned value is that
        // the tutor does excel (true)
        cout<<"This Tutor is Outstanding"<<endl;
    }
    else { //If the returned value is that the tutor does not excel (false)
        cout<<"This Tutor is  Not Outstanding"<<endl;
    }
    teacher->printPupils();
    cout<<"*********************************************************************************"<<endl;

}

bool Tutor:: excellent(){
    /* This method checks whether the tutor is an outstanding tutor and returns a Boolean value - true will be returned
     * if the number of pupils that are outstanding in the tutor's class is at least 50% of all the tutor in his class.
     * Otherwise, false will be returned */
    if(teacher == nullptr){
        cout << "This tutor does not teach any subject!" << endl;
        return false;
    }
    else {
        return(this->teacher->excellentClass());
    }
}

Tutor::~Tutor(){
/* Destructor */
}