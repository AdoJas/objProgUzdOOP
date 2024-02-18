#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;
struct studentasA {
    string vardas;
    string pavarde;
    int* pazymiai;
    int pazymiuKiekis = 0;
    float egzaminas = 0.0;
    float getMediana();
    float getVidurkis();
};

void ivedimas(int n, int & x, studentasA grupe[]);
void ivedimas(studentasA*& grupe, int& kiekis);
void isvedimas(int n, studentasA grupe[]);
void ivedimasCaseTwo(studentasA*& grupe, int& kiekis);
void generateRandomGrades(studentasA &stud);
void generateRandomNames(studentasA& stud);
void readNumbers(int*& arr, int& size, int maxItems);