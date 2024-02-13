#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

struct studentasV {
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    float pazVid = 0;
    float egzaminas = 0;
    float mediana = 0;
};
