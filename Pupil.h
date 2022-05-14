/* Assignment: 3
Author: Roey Salah,
 ID: 206115438
Author: Priel Hoffman,
 ID: 318277308
*/

#ifndef ASSIGNMENT3_PUPIL_H
#define ASSIGNMENT3_PUPIL_H
#include "Person.h"
#include "vector"

class Pupil: public Person{
private:

    vector<int>grades;  //A vector of grades for the pupil in all the subjects that the pupil is studying
    int _numberOfClass;  //The name of the layer in which the pupil is studying (value will be 'a'-'f')
    char _layer;  //Pupil's class number (1-3)

public:

    Pupil(string firstName, string lastName, string id, char layer, int classNumber, vector<int>pupilGrades); //Copy constructor
    virtual bool excellent();  //A Boolean method that will return whether the pupil excels
    virtual void printDetails();  //A method that prints all the pupil's details
    int averageGrades();  //A method that will return the pupil's grade average
    virtual ~Pupil();  //Destructor
    /* GETTER/SETTER */
    int getClassNumber();
};


#endif //ASSIGNMENT3_PUPIL_H
