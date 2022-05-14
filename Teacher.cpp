/* Assignment: 3
Author: Roey Salah,
 ID: 206115438
Author: Priel Hoffman,
 ID: 318277308
*/

#include "Teacher.h"
#include "Worker.h"



Teacher::Teacher(string firstName, string lastName, string id, int academicYears, vector<string>coursesList)
        : Person(firstName, lastName, id),
          Worker(firstName, lastName, id, academicYears)
{ /* Copy constructor */
    listOfCourses = coursesList;
    _numberOfCourses = listOfCourses.size();
}

void Teacher ::printDetails() {
    /* A method that prints all the details of the teacher, including the subjects he teaches, his salary and the other
       personal details of the teacher */
    cout << "Name of the Teacher:" << this->getName() << endl;
    cout << "Monthly salary:" << mountSalary() << endl;
    cout << "Academic Years as a lecturer:" << this->getAcademicYears() << endl;
    cout<<"This Teacher Is Teaching the following Courses:"<<endl;
    printAllCourses();
    if (this->excellent()){  //A call for a method that checks whether the teacher excels. If the returned value is that
        // the teacher does excel (true)
        cout << "This Teacher is Outstanding!" << endl;
    }
    else{ //If the returned value is that the teacher does not excel (false)
        cout << "This Teacher is Not Outstanding!" << endl;
    }
}

void Teacher ::printAllCourses(){
    /* This method prints the names of the subjects that the teacher teaches */
    if (!listOfCourses.empty()){
        for (int i = 0; i < listOfCourses.size(); i++) {
            cout<<"Course "<<i+1<<":"<<listOfCourses[i]<<endl;
        }
    }
    else{
        cout<<"This teacher does not teach any subject!"<<endl;
    }
}


bool Teacher ::excellent(){
    /* This method returns true if the teacher is outstanding, meaning the teacher teaches at least 5 subjects.
       Otherwise, it will returns false */
    if(this->_numberOfCourses>=5){
        return true;
    }
    return false;
}

double Teacher ::mountSalary(){
    /* This method returns the teacher's monthly salary according to the following calculation.
       We denote by x the number of subjects taught by the teacher and by y the years of seniority of
       the teacher. His monthly salary will then be: basis*(1+x/10)+300*y */
    double salary;
    salary = basis * (1 +(double (this->_numberOfCourses) / 10)) + (300 * _academicYears);
    return salary;
}

Teacher::~Teacher(){
    /* Destructor */
}