#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <utility>
#include <vector>
#include <numeric>
#include "studentas.h"
using namespace std;


void ivedimas(vector<studentasV>& grupeVector, int n);
void ivedimasNoSize(vector<studentasV>& grupeVector);
void ivedimasCaseTwo(vector<studentasV>& grupeVector);
void fileReading(vector<studentasV>& grupeVector, const string& failas, double & laikasSkaitymas, int& fakePazymiai, double& laikasSkaiciavimas);

void generateRandomGrades(studentasV &stud);
void generateRandomNames(studentasV &stud);

void generalVidurkisCalculate(vector<studentasV>& grupeVector);
void generalMedianaCalculate(vector<studentasV>& grupeVector);

void isvedimas(vector<studentasV> grupeVector, double laikasSkaitymas, double laikasSkaiciavimas, double laikasRusiavimas, int fakePazymiai, int iteracija);

void readNumbersV(studentasV& stud, int maxItems);

void laikoIsvedimas(double laikasSkaitymas, double laikasSkaiciavimas, double laikasRusiavimas);
void studentuGeneravimas(vector<studentasV>& grupeVector, studentasV& stud, int kiekis);
void pazymiuFailoGeneravimas();
void sortInput(string& choice, vector<studentasV>& grupeVector);
void failoNuskaitymasRusiavimas(vector<studentasV>& grupeVector, vector<studentasV>& grupeBad, vector<studentasV>& grupeGood, int i, string vidMed, string ivedimasKonteineris, string choice);
void isvedimasFailai(vector<studentasV>& grupeVector, vector<studentasV>& grupeBad, int i, string& vidMed, string& choice);
void pasirinkimasVidMed(string& vidMed);
void vektoriaiMain(string vidMed, string choice, vector<studentasV>& grupeVector, vector<studentasV>& grupeBad, vector<studentasV>& grupeGood, string ivedimas);
void vectorPartition(string vidMed, vector<studentasV>& grupeVector, vector<studentasV>& grupeGood, vector<studentasV>& grupeBad);
void vectorPartition2(string vidMed, vector<studentasV>& grupeVector, vector<studentasV>& grupeBad);