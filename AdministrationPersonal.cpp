/* Assignment: 3
Author: Roey Salah,
 ID: 206115438
Author: Priel Hoffman,
 ID: 318277308
*/

#include "AdministrationPersonal.h"

AdministrationPersonal::AdministrationPersonal(string firstName,string lastName,string id,int administrationYears,string LocationNum):
        Worker(firstName,lastName,id,administrationYears)
{ /* Copy constructor */
    _LocationOffice=LocationNum;
}

AdministrationPersonal::~AdministrationPersonal(){
/* Destructor */
}

