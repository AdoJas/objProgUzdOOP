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
    float pazVid = 0;
    float egzaminas = 0;
    float mediana = 0;
};

void ivedimas(int n, int x, studentasA grupe[]);
void ivedimas(studentasA*& grupe, int& kiekis);
void medianaSkaiciavimas(int n, int x, studentasA grupe[]);
void medianaSkaiciavimas(int n, studentasA *&grupe);
void isvedimas(int n, studentasA grupe[]);
void vidurkis(int n, studentasA *grupe);