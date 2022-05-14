/* Assignment: 3
Author: Roey Salah,
 ID: 206115438
Author: Priel Hoffman,
 ID: 318277308
*/

#include "Manager.h"

Manager::Manager(string firstName,string lastName,string id,int academicYears,int administrationYears,vector<string> coursesList,string LocationNum) :
        Person(firstName, lastName, id),
        Worker(firstName, lastName, id, academicYears),
        Teacher(firstName, lastName, id, academicYears, coursesList),
        AdministrationPersonal(firstName,lastName,id,administrationYears,LocationNum)
{ /* Copy constructor */

}
Manager* Manager::newSchoolManager(string firstName, string lastName, string id, int academicYears, int administrationYears
        , vector<string>coursesList, string LocationNum)
{ /* A static method of a manager class that aims to make sure there is no more than one manager. If there is already a
    manager, a massage will be printed that the school can not have more than one manager */
    if(SchoolManager == nullptr){  //If there is no manager, we will call the copy constructor method
        SchoolManager=(new Manager(firstName,lastName,id,academicYears,administrationYears,coursesList,LocationNum));
    }
    else { //If there is already a manager for the school
        cout<<"Sorry,The school can have only one manager!"<<endl;
    }
    return SchoolManager;
}

void Manager::deleteManager(){
    /* A method that delete the manager from memory */
    if(SchoolManager!= nullptr){
        delete SchoolManager;
    }
}
double Manager::mountSalary(){
    /* A method that returns the manager's monthly salary according to a two-value calculation of his seniority (teaching seniority and administrative seniority).
       If the manager also serves as a teacher he will be rewarded as a teacher and to this will be added a administrative
       supplement that will be calculated according to the next formula: z will be the number of years of administrative
       seniority 500 * z + 2 * basis, if not also serving as a teacher will receive solely the administrative supplement. */
    int salary;
    int getYears=AdministrationPersonal::_academicYears;
    int TeacherSalary;
    salary=(basis*2)+(getYears*500);
    if(_numberOfCourses>0){  //A principal will also be a teacher in the school if the number of subjects he teaches is greater than zero
        TeacherSalary= Teacher::mountSalary();
        salary+=TeacherSalary;
    }
    return salary;
}

void Manager::printDetails(){
    /* This method prints the details of the manager, his salary, his administrative seniority and if he also serves as
       a teacher, the details of the class (including his pupils), years of teaching seniority, etc. */
    cout << "Name of the School Manager:" << this->AdministrationPersonal::getName() << endl;
    cout << "Monthly salary:" << mountSalary() << endl;
    cout << "Management Years as a Manager:" << AdministrationPersonal::_academicYears << endl;
    if(_numberOfCourses>0) {
        cout<<AdministrationPersonal::getName()<<"Is also a teacher"<<endl;
        cout<<"Academic Years as a lecturer:"<<Teacher::_academicYears<<endl;
        cout<<"This Manager Is Teaching the following Courses:"<<endl;
        printAllCourses();
    }
    if (this->excellent())  //A call for a method that checks whether the manager excels. If the returned value is that
        // the manager does excel (true)
    {
        cout << "This School Manager is Outstanding!" << endl;
    }
    else { //If the returned value is that the manager does not excel (false)
        cout << "This School Manager is Not Outstanding!" << endl;
    }
    cout<<"*********************************************************************************"<<endl;

}

bool Manager::excellent(){
    /* This is a Boolean method checks whether the manager is outstanding. True will be returned if the years of
       seniority greater than three. Otherwise, a false will be returned */
    if((this->AdministrationPersonal::_academicYears)>3){
        return true;
    }
    return false;
}




Manager* Manager:: SchoolManager= nullptr;

Manager::~Manager(){
    /* Destructor */
}
