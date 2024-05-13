//
// Created by adoma on 5/13/2024.
//

#ifndef OOPUZD_VECTORCLASS_H
#define OOPUZD_VECTORCLASS_H

template<typename T>
class Vector{
private:
    int size;
    int capacity;
    T* elements;

public:
    Vector();
    Vector(int n, const T& value);   //+
    Vector(const Vector &rhs);       //+

    ~Vector();                //+

    int Size();               //+
    int Capacity();           //+
    bool isEmpty();           //+

    void PushBack(T &object); //+
    void PopBack();           //+
    void Clear();             //+
    void Resize(int n);       //+
    void Reserve(int n);      //+
    void Swap(Vector &rhs);   //+
    void ShrinkToFit();       //+
    void Erase(int index);    //+
    void Insert(int index, T &object);  //+
    void Assign(int n, const T& value); //+

};


#endif //OOPUZD_VECTORCLASS_H
