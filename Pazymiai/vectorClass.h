//
// Created by adoma on 5/13/2024.
//

#ifndef OOPUZD_VECTORCLASS_H
#define OOPUZD_VECTORCLASS_H

template<typename T>
class Vector{
private:
    int size;  //Kiek elementu yra vektoriaus viduje
    int capacity; //Kiek elementu gali tilpti
    T* elements; //Masyvas, kuriame saugomi elementai

public:
    Vector(); //Konstruktorius
    Vector(int n, const T& value); //Konstruktorius su n elementu
    Vector(const Vector &rhs); //Copy konstruktorius

    ~Vector();
    int Size(); //Grazina elementu skaiciu
    int Capacity(); //Grazina kiek memory vietos yra isskirta siam vektoriui
    bool isEmpty(); //Ar vektorius yra tuscias

    void PushBack(T &object); //Ideda elementa i vektoriaus gala
    void PopBack(); //Istrina paskutini vektoriaus elementa
    void Clear(); //Istrina visus elementus is vektoriaus
    void Resize(int n); //Pakeicia vektoriaus dydi(size) i n
    void Reserve(int n); //Alokuoja memory vietos vektoriaus elementams
    void Swap(Vector &rhs); //Sukeicia vektoriaus elementus su kitu vektoriumi
    void ShrinkToFit(); //Sumazina memory vietos kieki (capacity) iki vektoriaus dydzio (size)
    void Erase(int index); //Istrina elementa is vektoriaus pagal indeksa (index)
    void Insert(int index, T &object); //Iterpia elementa i vektoriaus vieta pagal indeksa (index)
    void Assign(int n, const T& value); //Pakeicia vektoriaus elementus i n elementu su reiksme (value)
    void operator=(const Vector &rhs); //Priskyrimo operatoriaus overloadas
    T& At(int index); //Grazina elementa pagal indeksa (index)
    T& Front(); //Grazina pirmaji vektoriaus elementa
    T& Back(); //Grazina paskutini vektoriaus elementa
    T* Begin(); //Grazina pointeri i vektoriaus pradzia
    T* End(); //Grazina pointeri i vektoriaus gale
    T* RBegin(); //Grazina pointeri i vektoriaus pradzia is galo
};

#endif //OOPUZD_VECTORCLASS_H
