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
void fileReading(vector<studentasV>& grupeVector, string failas, double & laikasSkaitymas, int& fakePazymiai, double& laikasSkaiciavimas);

void generateRandomGrades(studentasV &stud);
void generateRandomNames(studentasV &stud);

void generalVidurkisCalculate(vector<studentasV>& grupeVector);
void generalMedianaCalculate(vector<studentasV>& grupeVector);

void isvedimas(vector<studentasV> grupeVector, double laikasSkaitymas, double laikasSkaiciavimas, double laikasRusiavimas, int fakePazymiai, int iteracija);

void readNumbersV(studentasV& stud, int maxItems);

void laikoIsvedimas(double laikasSkaitymas, double laikasSkaiciavimas, double laikasRusiavimas);
void studentuGeneravimas(vector<studentasV>& grupeVector, studentasV& stud, int kiekis);
void pazymiuFailoGeneravimas(vector<studentasV>& grupeVector);
void failoGeneravimasIsvedimas(int iteracija);
void sortInput(string& choice, vector<studentasV>& grupeVector, double& laikasRusiavimas);
void failoNuskaitymasRusiavimas(vector<studentasV>& grupeVector, vector<studentasV>& grupeBad, vector<studentasV>& grupeGood, double& laikasSkaitymas, double& laikasSkaiciavimas, int i, string vidMed);
void isvedimasFailai(vector<studentasV> grupeVector, vector<studentasV> grupeBad, int i, string& vidMed, string& choice);
void pasirinkimasVidMed(string& vidMed);
void vektoriaiMain(string vidMed, string choice, vector<studentasV>& grupeVector, vector<studentasV>& grupeBad, vector<studentasV>& grupeGood);