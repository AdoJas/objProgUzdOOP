#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;

struct studentasV {
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    float pazVid = 0.0;
    float egzaminas = 0.0;
    float mediana = 0.0;
    float pazSuma = 0.0;
};
void ivedimas(vector<studentasV>& grupeVector, int n);
void ivedimasNoSize(vector<studentasV>& grupeVector);
void ivedimasCaseTwo(vector<studentasV>& grupeVector);
void generateRandomGrades(studentasV &stud);
void generateRandomNames(studentasV &stud);
void medianaSkaiciavimasV(vector<studentasV>& grupeVector);
void isvedimas(vector<studentasV> grupeVector);
void vidurkis(vector<studentasV>& grupeVector);