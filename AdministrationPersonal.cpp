

#include "AdministrationPersonal.h"

AdministrationPersonal::AdministrationPersonal(string firstName,string lastName,string id,int administrationYears,string LocationNum):
        Worker(firstName,lastName,id,administrationYears)
{ /* Copy constructor */
    _LocationOffice=LocationNum;
}

AdministrationPersonal::~AdministrationPersonal(){
/* Destructor */
}

