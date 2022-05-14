/* Assignment: 3
Author: Roey Salah,
 ID: 206115438
Author: Priel Hoffman,
 ID: 318277308
*/

#include "Worker.h"

int Worker::basis=25;

Worker::Worker(string firstName,string lastName,string id,int academicYears):Person(firstName,lastName,id){
    /* Copy constructor */
    _academicYears=academicYears;
}

int Worker::compareValue(){
    return (this->mountSalary());
}

int Worker ::getAcademicYears(){
    return _academicYears;
}

Worker::~Worker(){
/* Destructor */
}