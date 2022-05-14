/* Assignment: 3
Author: Roey Salah,
 ID: 206115438
Author: Priel Hoffman,
 ID: 318277308
*/

#include "School.h"

School* School ::buildNewSchool(){
    /* This method creates a school. It can only create one school */
    if(bestSchool== nullptr){
        bestSchool = new School();
    }
    else {  //If school is already exits
        cout<<"Sorry,only one school can be establish!"<<endl;
    }
    return bestSchool;
}

void School ::removeSchool(School* removeSchool){
    /* This method, once the user exited from the menu, will delete from memory the pupils vector, the workers vector,
     * the layers and the classes */
    int i,j;
    for (i=0;i<_pupilsInTheSchool.size();i++){
        delete _pupilsInTheSchool.at(i);
    }
    for(j=0;j<_workersInTheSchool.size();j++){
        delete _workersInTheSchool.at(j);
    }
    delete removeSchool;
    removeSchool= nullptr;
}


School::School() {
    /* This method creates six layers and then for each layer creates a three classes */
    for (int i = 0; i < NUMBEROFLAYERS; i++) {  //For each layer
        int numOfClass=0;
        _listOfLayers[i].setLayerName(i + 'a');
        for(int j=0;j<NUMOFCLASSES;j++){  //Create 3 classes
            this->_listOfLayers[i][j]->setNumOfClass(numOfClass+j+1);
        }
    }
}

char School::setLayer(){
    /* The method will ask the user to enter a layer name from a to f and return the inserted layer name */
    char layer;
    cout<<"Please enter layer: ";
    cin>>layer;
    cin.clear();
    while(layer<'a' || layer>'f')
    {
        cout<<"Layer must be between a-f. Please try again: ";
        cin>>layer;
        cin.clear();
    }
    return layer;
}

int School::setClassNumber(){
    /* The method will ask the user to enter a class name from 1 to 3 and return the entered class name */
    int numOfClass;
    cout<<"Please enter number of a class: ";
    cin>>numOfClass;
    cin.clear();
    while (numOfClass<1 || numOfClass>3){
        cout<<"Number of class must be between 1-3. Please try again: ";
        cin>>numOfClass;
        cin.clear();
    }
    return numOfClass;
}

string School::setFirstName(){
    /* The method will ask the user for a first name and it will return the first name it received from the user */
    string firstName;
    cout<<"Please enter first name: ";
    cin>>firstName;
    cin.clear();
    while(!checkIfStringValid(firstName)){
        cout<<"First name must be a string, please try again: ";
        cin>>firstName;
        cin.clear();
    }
    return firstName;
}

string School::setLastName(){
    /* The method will ask the user for a last name and it will return the last name it received from the user */
    string lastName;
    cout<<"Please enter last name: ";
    cin>>lastName;
    cin.clear();
    while(!checkIfStringValid(lastName)){
        cout<<"First name must be a string, please try again: ";
        cin>>lastName;
        cin.clear();
    }
    return lastName;
}

bool School::doesIdExist(string id){
    /* This method receives an ID number and returns true if the ID card appears in the ID vector of all the people in
     * the school. Otherwise, return false */
    bool found = false;
    for (int i = 0; i < _usedId.size() && !found; i++) {
        if (id == _usedId[i]) {
            found = true;
        }
    }
    return found;
}

string School::setId(){
    /* The method will ask the user for an ID number and it will return the ID number it received from the user */
    string id;
    cout<<"Please enter id number: ";
    cin>>id;
    cin.clear();
    while (!checkIfNumberValid(id)){
        cout<<"ID must be numbers, please try again: ";
        cin>>id;
        cin.clear();
    }
    if (doesIdExist(id)==true)
    {
        cout<<"Id is already exits in database.\n";
        id="0";
    }
    if (id!="0")
        _usedId.push_back(id);
    return id;
}

vector<int>School::setGrades(){
    /* The method will ask the user to enter the pupil's grades one after the other and it will return vectors within
       which the grades it received from the user */
    vector<int> grades;
    int grade,num=1;
    bool flag= false;
    do {
        cout<<"Please enter your grades,For exit press -1. "<<endl;
        cout<<"Grade "<<num<<":";
        cin>>grade;
        cin.clear();
        if(grade==-1){
            flag= true;
        }
        else
        {
            while((grade<0 || grade>100)  && grade!=-1 ){
                cout<<"Grade must be between 0-100. Please try again: ";
                cin>>grade;
                cin.clear();
            }
            grades.push_back(grade);
            num++;
        }
    }while(!flag);
    return grades;

}
vector<string>School::setCourses(){
    /* The method will ask the user to enter the subjects that the teacher teaches one after the other and it will return
       a vector of subjects within which the subjects received from the user */
    vector<string> courses;
    string courseName;
    bool exit= false;
    int num=0;
    do {
        cout<<"Please enter your courses at least one course!,For exit press -1. "<<endl;
        cout<<"course "<<num+1<<":";
        cin>>courseName;
        cin.clear();
        if(courseName=="-1" && num>0){
            exit= true;
        }
        else
        {
            courses.push_back(courseName);
            num++;
        }
    }while(!exit);
    return courses;
}

int School:: setAcademicYears(){
    /* The method will ask the user to enter a number of years of teaching seniority and it will return the number of
       years of teaching seniority it received from the user */
    int academicYears;
    cout<<"Please Enter Academic Years:";
    cin>>academicYears;
    cin.clear();
    while(isdigit(academicYears)){
        cout<<"Academic Years Must be number,please try again:";
        cin>>academicYears;
        cin.clear();
    }
    return academicYears;
}


int School:: setAdminYears(){
    /* The method will ask the user to enter several years of administrative seniority and it will return the number of
       years of administrative seniority it received from the user */
    int adminYears;
    cout<<"Please Enter administration Years:";
    cin>>adminYears;
    cin.clear();
    while(isdigit(adminYears)){
        cout<<"administration Years Must be number,please try again:";
        cin>>adminYears;
        cin.clear();
    }
    return adminYears;
}


bool School :: checkIfStringValid(string strForCheck){
    /* A method that accepts a string and checks whether the string contains only letters. The method will return true
       if the string is valid, otherwise it will return flase */
    int i=0;
    bool flag= true;
    while(i<(int)strForCheck.length()&& flag){
        if((strForCheck[i]<'a' || strForCheck[i]>'z') && (strForCheck[i]<'A' || strForCheck[i]>'Z'))
            flag=false;
        i++;
    }
    if(flag){return true;}
    return false;
}

string School::setLocationOffice(){
    /* The method asks the user to enter a number that indicates the location of the office and return the number that
       indicates the location of the office */
    string office;
    cout<<"Please enter Office number: ";
    cin>>office;
    cin.clear();
    while (!checkIfNumberValid(office)){
        cout<<"The name of the Office must be numbers,please try again!";
        cin>>office;
        cin.clear();
    }
    return office;

}

bool School:: checkIfNumberValid(string strForCheck){
    /* The method gets a string and checks if the string contains only numbers. It will return true if the string
       contains only numbers, otherwise it will return false */
    int i=0;
    bool flag= true;
    while(i<(int)strForCheck.length()&& flag){
        if(strForCheck[i]<'0' || strForCheck[i]>'9')
            flag=false;
        i++;
    }
    if(flag){return true;}
    return false;
}



void School::menu() {
    int answer;
    Manager * newManger;
    bool flag= false;
    do {
        cout << "Greetings People This is The best School !" << endl;
        cout << "Please choose one of the following options:\n "
                "==========================================================\n"
                "1) Add Pupil.\n"
                "2) Add Teacher.\n"
                "3) Add Tutor.\n"
                "4) Add Manager.\n"
                "5) Add Secretary.\n"
                "6) Print person details.\n"
                "7) Print outstanding people.\n"
                "8) Print tutor's class.\n"
                "9) Highest paid worker.\n"
                "10) Exit\n"
                "==========================================================" << endl;
        cin >> answer;
        cin.clear();
        switch (answer){
            case 1:
            {
                cout<<"Adding new Pupil!"<<endl;
                string firstName=setFirstName(), lastName=setLastName(),id=setId();
                if (id=="0")
                    break;
                char layer=setLayer();
                int numOfClass=setClassNumber();
                vector<int> grades=setGrades();
                Pupil *newPupil=new Pupil (firstName,lastName,id,layer,numOfClass,grades);
                _pupilsInTheSchool.push_back(newPupil);
                _listOfLayers[layer-'a'].addPupil(newPupil);
                break;
            }
            case 2:
            {
                cout<<"Adding new teacher!"<<endl;
                string firstName=setFirstName(), lastName=setLastName(), id=setId();
                if (id=="0")
                    break;
                int academicYears;
                academicYears=setAcademicYears();
                vector<string>courses=setCourses();
                Teacher*newTeacher=new Teacher(firstName,lastName,id,academicYears,courses);
                _workersInTheSchool.push_back(newTeacher);
                break;
            }

            case 3:
            {
                cout<<"Adding new Tutor!"<<endl;
                string firstName=setFirstName(), lastName=setLastName(), id=setId();
                if (id=="0")
                    break;
                vector<string>courses=setCourses();
                int academicYears;
                academicYears=setAcademicYears();
                cout<<"Please enter the Tutoring class details:"<<endl;
                char layer=setLayer();
                int numOfClass=setClassNumber();
                while(((_listOfLayers[layer-'a'][numOfClass-1])->getTutor())!= nullptr)
                {
                    cout<<"This class already has a Tutor choose another class please."<<endl;
                    cout<<"Please enter the Tutoring class details:"<<endl;
                    layer=setLayer();
                    numOfClass=setClassNumber();
                }
                Tutor*newTutor=new Tutor(firstName,lastName,id,academicYears,courses,_listOfLayers[layer-'a'][numOfClass-1]);
                _listOfLayers[layer-'a'][numOfClass-1]->setTutor(newTutor);
                _workersInTheSchool.push_back(newTutor);
                break;
            }

            case 4:
            {
                if(flag){
                    cout<<"Sorry,school can have only one Manager !!"<<endl;
                    break;
                }
                cout<<"Adding new Manager!"<<endl;
                string firstName=setFirstName(), lastName=setLastName(), id=setId(),LocationOffice=setLocationOffice();
                if (id=="0")
                    break;
                int academicYears=setAcademicYears();
                int adminYears=setAdminYears();
                vector<string>courses;
                char answer;
                cout<<"This Manager is also a lecturer ? please answer y/n :"<<endl;
                cin>>answer;
                cin.clear();
                if(answer=='y')
                {
                    courses=setCourses();
                }
                Manager *newMangertemp=Manager::newSchoolManager(firstName,lastName,id,academicYears,adminYears,courses,LocationOffice);
                newManger=newMangertemp;
                _workersInTheSchool.push_back(newManger);
                flag= true;
                break;
            }
            case 5:
            {
                cout<<"Adding new Secretary!"<<endl;
                string firstName=setFirstName(), lastName=setLastName(), id=setId(),LocationOffice=setLocationOffice();
                if (id=="0")
                    break;
                int adminYears=setAdminYears();
                int childrens;
                cout<<"Please Enter the number of children this Secretary have:";
                cin>>childrens;
                cin.clear();
                while(isdigit(childrens)){
                    cout<<"Sorry,Number of children must be a number please try again!"<<endl;
                    cin>>childrens;
                    cin.clear();
                }
                Secretary*newSecretary=new Secretary(firstName,lastName,id,adminYears,LocationOffice,childrens);
                _workersInTheSchool.push_back(newSecretary);
                break;
            }
            case 6:
            {
                VecAnalyser<Worker> wVa(_workersInTheSchool);
                VecAnalyser<Pupil> pVa(_pupilsInTheSchool);

                if (_workersInTheSchool.size() + _pupilsInTheSchool.size() == 0) {
                    cout << "The school is empty" << endl;
                }
                else {
                    cout << "Workers: " << endl;
                    wVa.printAll();
                    cout << "Pupils: " << endl;
                    pVa.printAll();
                }
                break;
            }
            case 7:
            {
                VecAnalyser<Worker> wVa(_workersInTheSchool);
                VecAnalyser<Pupil> pVa(_pupilsInTheSchool);
                if (_workersInTheSchool.size() + _pupilsInTheSchool.size() == 0) {
                    cout << "The school is empty" << endl;
                }
                else {
                    cout << "Workers: " << endl;
                    wVa.printOutstending();
                    cout << "Pupils: " << endl;
                    pVa.printOutstending();
                }
                break;
            }
            case 8:
            {
                string id=setId();
                for(int i=0;i<_workersInTheSchool.size();i++){
                    if(_workersInTheSchool[i]->doesIdExist(id)){
                        while (typeid(_workersInTheSchool[i])!=typeid(Tutor*)) {
                            cout << "Tutor found at school !! Please try again: " << endl;
                            id=setId();
                        }
                            Tutor* temp =dynamic_cast<Tutor*>(_workersInTheSchool[i]);
                            Class* toPrint=temp->getTeacherClass();
                            toPrint->printPupils();
                            toPrint->printExcellentPupils();

                        }
                        else
                        {
                            cout<<"This is not a Tutor!"<<endl;
                        }

                }
                break;
            }
            case 9:
            {
                VecAnalyser<Worker> wVa(_workersInTheSchool);
                wVa.printMax();
                break;
            }
            case 10:
                cout << "Goodbye" << endl;
                delete newManger;
                removeSchool(bestSchool);
                break;

            default:
                cout << "Bad choice! Please try again." << endl;
        }
    }while (answer != 10);
}

School::~School() {
/* Destructor */
}

School* School:: bestSchool= nullptr;