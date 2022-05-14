/* Assignment: 3
Author: Roey Salah,
 ID: 206115438
Author: Priel Hoffman,
 ID: 318277308
*/

#ifndef ASSIGNMENT3_CPP_SCHOOL_H
#define ASSIGNMENT3_CPP_SCHOOL_H

#include "Person.h"
#include "Layer.h"
#include "Worker.h"
#include "VecAnalyser.h"
#include "Secretary.h"
#include "Tutor.h"
#include "Manager.h"

class School {
private:
    Layer _listOfLayers[NUMBEROFLAYERS];  //An array of pointers to at most the six existing layers in the school
    vector<Pupil*> _pupilsInTheSchool;  //A vector that contains pointers to all pupils in the school
    vector<Worker*> _workersInTheSchool;  //A vector that contains pointers to all school workers
    vector<string> _usedId;  //A vector that contains all the ID numbers of all the people in the school

    static School* bestSchool;
    School();  //Constructor

    //setters for menu
    char setLayer();
    int setClassNumber();
    string setFirstName();
    string setLastName();
    string setId();
    vector<int>setGrades();
    vector<string>setCourses();
    int setAcademicYears();
    int setAdminYears();
    string setLocationOffice();

    //checkers
    bool checkIfStringValid(string strForCheck);
    bool checkIfNumberValid(string strForCheck);
    bool doesIdExist(string id);


public:
    void menu();  //A method that prints the menu for school management
    virtual ~School();  //Destructor
    static School*buildNewSchool();  //A static method that will allow the creation of a single object at any time of the school type
    void removeSchool(School* removeSchool);  //A method that deletes school objects from memory
};

#endif //ASSIGNMENT3_CPP_SCHOOL_H
