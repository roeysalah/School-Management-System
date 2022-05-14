

#include "Layer.h"

Layer::Layer(){
}

Layer::Layer(char nameOfLayer){
    /* A method that creates a layer by adding 3 classes to each of the six layers */
    _nameOfLayer=nameOfLayer;
    for (int i = 0; i < NUMOFCLASSES; i++)
    {
        _classesOfLayer[i].setNumOfClass(i+1);
    }
}

void Layer::setLayerName(char nameOfLayer){
    /* The method gives each layer a name from a to f */
    _nameOfLayer=nameOfLayer;
    for(int i=0;i<NUMOFCLASSES;i++)
    {
        _classesOfLayer[i].setClassName(nameOfLayer);
    }
}

void Layer::addPupil(Pupil* newPupil) {
    /* The method gets a pointer to pupil and adds it to the class */
    _classesOfLayer[newPupil->getClassNumber() - 1].addPupilToClass(newPupil);
}

Class* Layer:: operator[](int index){
    /* The method receives a number and returns the class that is indexed by the number obtained in the class array of
       the layer */
    while(index<0 || index>2)
        cout<<"Invalid index! Please try again"<<endl;
    return (&_classesOfLayer[index]);
}
Layer::~Layer() {
    /* Destructor */
}