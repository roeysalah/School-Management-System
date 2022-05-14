/* Assignment: 3
Author: Roey Salah,
 ID: 206115438
Author: Priel Hoffman,
 ID: 318277308
*/

#include "Pupil.h"


Pupil::Pupil(string firstName, string lastName, string id, char layer, int classNumber, vector<int>pupilGrades)
        :Person(firstName, lastName, id)
{   /* Copy constructor */
    _numberOfClass=classNumber;
    _layer=layer;
    grades=pupilGrades;
}

int Pupil ::getClassNumber(){
    return _numberOfClass;
}

int Pupil::averageGrades(){
    /* This method returns the average of the pupil's grades */
    int score=0;
    if(!grades.empty()){
        for(int i = 0;i<grades.size();i++){
            score+=grades[i];  //We will sum in the variable the grades in the pupil's grades vector
        }
        score/=grades.size();  //Divide the sum of the scores by the number of scores that appear in the vector to
        // calculate the average of the scores
    }
    return score;
}

void Pupil::printDetails(){
    /* This method prints the pupil's details, including his grades and his grades average and whether he excels or not */
    cout<<"Name of the Pupil:"<<this->getName()<<endl;
    cout << "The Grades of The pupil is:" << endl;
    for (int i = 0; i < grades.size(); i++) {
        cout << " Course " << i + 1 << ":" << grades[i] << endl;
    }
    cout << "The Average Grade of the pupil is:" << this->averageGrades() << endl;
    if(this->excellent()){  //A call for a method that checks whether the pupil excels. If the returned value is that
        // the pupil does excel (true)
        cout << "This Pupil is Outstanding!" << endl;
    }
    else{  //If the returned value is that the pupil does not excel (false)
        cout << "This Pupil is Not Outstanding!" << endl;
    }
    cout<<"*********************************************************************************"<<endl;

}

bool Pupil ::excellent(){
    /* A method that checks whether the pupil is outstanding. In order to be outstanding, his average grades must be
       greater than 85, and there must be no subject in which he received a grade lower than 65 */
    bool flag = true;  //We will initialize the variable so that the pupil does excel
    int pupilGrade=0;

    if(!grades.empty()){
        for (int i = 0; i < grades.size() && flag; i++) {
            if (grades[i] < 65) {
                flag = false;  //The pupil does not meet the requirements so he does not excel
            }
            pupilGrade+=grades[i];
        }
        pupilGrade /= grades.size();
    }
    else{
        return false;  //If the pupil does not have any grades so he does not excel
    }
    if (pupilGrade <= 85)
        flag=false;   //The pupil does not meet the requirements so he does not excel
    return flag;
}

Pupil::~Pupil(){
}