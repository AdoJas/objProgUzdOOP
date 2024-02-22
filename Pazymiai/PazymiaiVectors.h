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
    float getMediana();
    float getVidurkis();
    float pazSuma = 0.0;
};
void ivedimas(vector<studentasV>& grupeVector, int n);
void ivedimasNoSize(vector<studentasV>& grupeVector);
void ivedimasCaseTwo(vector<studentasV>& grupeVector);
void fileReading(vector<studentasV>& grupeVector, const string& failas, double & laikasSkaitymas);

void generateRandomGrades(studentasV &stud);
void generateRandomNames(studentasV &stud);

void generalVidurkisCalculate(vector<studentasV>& grupeVector);
void generalMedianaCalculate(vector<studentasV>& grupeVector);

void isvedimas(vector<studentasV> grupeVector, double laikasSkaitymas);

void readNumbersV(studentasV& stud, int maxItems);

void sortInput(int& choice, vector<studentasV>& grupeVector, double& laikasSkaitymas);