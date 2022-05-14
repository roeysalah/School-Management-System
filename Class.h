

#ifndef ASSIGNMENT3_CPP_CLASS_H
#define ASSIGNMENT3_CPP_CLASS_H
#include "Pupil.h"
#include "Tutor.h"
#include "vector"
#define NUMOFCLASSES 3
#define NUMBEROFLAYERS 6

class Tutor;
class Class {

private:
    char _layer;  //Layer name (single character ‘a’ - ‘f')
    int _numOfClass;  //Class number (3-1)
    vector<Pupil*> _pupilsList;  //Vector pointers to pupils studying in the class
    int _numOfPupils;  //The amount of pupils in the class
    Tutor *_ptrOfTutor;  //Pointer to the class tutor

public:
    /* constructors */
    Class(char layer, int numOfClass, vector<Pupil*> pupilsInClass, int numOfPupils, Tutor* ptrOfTutor);  //Copy constructor
    Class(char layer = '0', int numOfClass = 0);  //Default constructor

    /* methods */
    void addPupilToClass(Pupil* pupilToAdd);  //A method that receives pointer to pupil and adds him to the vector of pupils
    Pupil* operator[](int index);  //A method that accepts a positive integer and returns the pupil located in this
    // index in the pupil vector
    void printExcellentPupils();  //A method that prints outstanding pupils
    bool excellentClass();  //A method that tests whether the class excels
    void printPupils();  //A method that prints the pupil's details
    double averageGrade();  //A method that calculates the grade point average of the class

    //getters
    Tutor* getTutor();

    //setters
    void setClassName(char name);
    void setTutor(Tutor* tutor);
    void setNumOfClass(int num);

    virtual ~Class(); //Destructor
};

#endif //ASSIGNMENT3_CPP_CLASS_H
