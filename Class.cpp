/* Assignment: 3
Author: Roey Salah,
 ID: 206115438
Author: Priel Hoffman,
 ID: 318277308
*/

#include "Class.h"

Class::Class(char layer,int numOfClass,vector<Pupil*> pupilsInClass,int numOfPupils,Tutor *ptrOfTutor){
    /* Copy constructor */
    _layer=layer;
    _numOfClass=numOfClass;
    _pupilsList=pupilsInClass;
    numOfPupils=numOfPupils;
    _ptrOfTutor=ptrOfTutor;
}

Class::Class(char layer ,int numOfClass){
    /* Default constructor */
    _layer=layer;
    _numOfClass=numOfClass;
    _ptrOfTutor= nullptr;
    _numOfPupils=0;
}

Tutor* Class::getTutor(){
    return _ptrOfTutor;
}

void  Class::setClassName(char name){
    _layer=name;
}

void  Class::setTutor(Tutor* tutor){
    _ptrOfTutor=tutor;
}

void  Class::setNumOfClass(int num){
    _numOfClass=num;
}

void Class:: addPupilToClass(Pupil* pupilToAdd){
    /* This method receives a pointer to pupil and adds it to a pupils vector */
    _pupilsList.push_back(pupilToAdd);
    _numOfPupils++; //Increases the number of pupils in a class by one
}

Pupil* Class::operator[](int index){
    /* This method receives a positive integer and returns the pupil who is in this index in the pupils vector */
    while(index<0 || index>=_numOfPupils){
        cout<<"Invalid index,please try again!"<<endl;
    }
    return _pupilsList.at(index);
}

double Class ::averageGrade(){
    /* The method calculates the grade average of the class */
    int average=0;
    if(_pupilsList.size()){
        for(int i=0;i<_pupilsList.size();i++){
            average+= _pupilsList[i]->averageGrades();  //We will summarize each time a grade from the grade list of the
            // pupils in the class
        }
    }
    average/=_pupilsList.size(); //To calculate an average we divide the sum of the scores by the number of scores
    return average;
}


void Class :: printExcellentPupils(){
    /* This method prints the details of the outstanding pupils of the class */
    bool flag= true;
    for(int i=0;i<_pupilsList.size();i++){
        if(_pupilsList[i]->excellent()){
            cout<<"Excellent Pupil details:"<<endl;
            _pupilsList[i]->printDetails();
            flag= false;
        }
    }
    if(flag) {
        cout<<"This class have no Excellent Pupil!"<<endl;
    }
}


void Class ::printPupils(){
    /* This method prints the details of all pupils studying in the class */
    if(_numOfPupils==0){  //If the class is empty
        cout<<"This class have no pupils"<<endl;
    }
    else {
        cout << "The Details of this class:" << endl;
        cout << "Layer:" <<  _layer << endl;
        cout << "Class number:" << _numOfClass << endl;
        cout << "Number of Pupils in this class:" << _numOfPupils << endl;
        cout << "Average grade of this class:" << averageGrade() << endl;
        cout << "Pupils Details in this class: " << endl;
        for(int i=0;i<_pupilsList.size();i++){
            _pupilsList[i]->printDetails();
        }
        cout<<"*********************************************************************************"<<endl;
    }
}

bool Class ::excellentClass(){
    /* This method checks whether the class excels. An outstanding class is a class in which at least 50 percent of the
       pupils is outstanding. If the class excels, true will be returned. Otherwise false will be returned */
    double pupilexcel = 0;
    if (_numOfPupils > 0){
        for(int i=0;i<_pupilsList.size();i++){
            if(_pupilsList[i]->excellent()){
                pupilexcel++;
            }
        }
        if(pupilexcel>=((double)(0.5*_numOfPupils))) {
            return true;
        }
    }
    return false;
}

Class::~Class(){
/* Destructor */
}