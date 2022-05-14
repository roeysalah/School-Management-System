

#ifndef ASSIGNMENT3_CPP_LAYER_H
#define ASSIGNMENT3_CPP_LAYER_H
#include "Class.h"

class Class;
class Layer {
private:
    char _nameOfLayer;
    Class _classesOfLayer[NUMOFCLASSES];  //An array of pointer to for up to three classes that make up the layer
public:
    Layer(); //Default constructor
    Layer(char nameOfLayer);  //Copy constructor
    Class* operator[](int index);  //A method that receives a positive integer (2-0) and returns the class that is in index
    //of the classes array
    void setLayerName(char newName);
    virtual ~Layer();  //Destructor
    void addPupil(Pupil* newPupil);  //A method that receives a pointer to a pupil and adds it to the class
};

#endif //ASSIGNMENT3_CPP_LAYER_H
