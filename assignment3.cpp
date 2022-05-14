
/* Assignment: 3
Author: Roey Salah,
 */

#include <iostream>
#include "Pupil.h"
#include "Person.h"
#include "Tutor.h"
#include "Manager.h"
#include "Secretary.h"
#include "School.h"
#include "VecAnalyser.h"

#include <list>



#include <iostream>
int main() {
    School *game=School::buildNewSchool();
    game->menu();
}
