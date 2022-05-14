/* Assignment: 3
Author: Roey Salah,
 ID: 206115438
Author: Priel Hoffman,
 ID: 318277308
*/

#include <vector>
#include <iostream>
#include <typeinfo>
#include "Person.h"
#include "Teacher.h"
#include "Manager.h"
#ifndef ASSIGNMENT3_CPP_VECANALYSER_H
#define ASSIGNMENT3_CPP_VECANALYSER_H


template<typename T>
class VecAnalyser {
private:
    vector<T*> _data;

public:
    void printOutstending();

    void printMax() {
        /* A method that prints the vector member with the highest value
        (for pupils - with the highest grades average, for workers - with the highest salary) */
        if(_data.empty()){
            cout<<"There is no person in list!"<<endl;
        }
        T* max = _data[0];
        for (int i = 1; i < _data.size(); i++) {
            if (max->compareValue() < _data[i]->compareValue()) {
                max = _data[i];
            }
        }
        max->printDetails();
    }

    VecAnalyser(vector<T*> vec) {
        _data = vec;
    }

    ~VecAnalyser() {}

    void printElement(int index) {
        /* A method that receives an index and prints the member in that index. */
        if (index < _data.size()) {
            _data[index]->printDetails();
        }
        else {
            cout << "Index is out of range" << endl;
        }
    }

    void printAll() {
        /* A method that prints all the members of the data structure one after the other */
        for (int i = 0; i < _data.size(); i++) {
            printElement(i);
            cout << endl;
        }
    }

    void swap(int indexOne, int indexTwo) {
        /* A method that accepts two indexes and switches between the variables in them */
        if (_data.size() > indexOne && _data.size() > indexTwo)
        {
            T temp = *_data[indexOne];
            *_data[indexOne] = *_data[indexTwo];
            *_data[indexTwo] = temp;
        }
        else if (_data.size() < indexOne && _data.size() < indexTwo)
        {
            cout << "Both indexes are out of range -> " << indexOne << ", " << indexTwo << ". Max: " << _data.size();
        }
        else if (_data.size() < indexOne)
        {
            cout << "Index " << indexOne << " is out of range" << ". Max: " << _data.size();
        }
        else {
            cout << "Index " << indexTwo << " is out of range" << ". Max: " << _data.size();
        }
    }


    T* getElement(int index) {

        if (index < _data.size())
        {
            return _data[index];
        }
        cout << "Index " << index << " is out of range. max: " << _data.size();
        return nullptr;
    }


    bool isManager (int index) {
        /* A method that checks whether an element in a particular index vector is a manager */
        if (typeid(*_data.at(index)).name() == "Manager")
            return true;
        else
            return false;
    }

    void check(){
        Manager m();
        Teacher t();
        _data.push_back(m);
        _data.push_back(t);
        cout<<isManager(0);
    }
};


template <class T>
//This function print all the outStending pupils/workers
void VecAnalyser<T>::printOutstending()
{
    bool flag=false;
    for(int i=0;i<_data.size();i++)
    {
        if (_data[i]->excellent())
        {
            _data[i]->printDetails();
            flag=true;
        }
    }
    if(!flag)//if no one is outstanding
    {
        cout<<"Unbelievable! no one in the entire school is outstanding!! it's the worst school!!:("<<endl;
    }

}


#endif //ASSIGNMENT3_CPP_VECANALYSER_H



