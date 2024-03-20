#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cmath>
#include "Common.h"
#include <fstream>
#include <sstream>
#include "chrono"
#include <list>
#include <string>
using namespace std;

struct studentasL {
    string vardas;
    string pavarde;
    list<int> pazymiai;
    float pazVid = 0.0;
    float egzaminas = 0.0;
    float mediana = 0.0;
    float pazSuma = 0.0;
};



void fileReadingList(list<studentasL> grupeList, string failas, double& laikasSkaitymas, int& fakePazymiai, double& laikasSkaiciavimas);
void generalVidurkisCalculateList(list<studentasL>& grupeList);
void generalMedianaCalculateList(list<studentasL>& grupeList);
void failoNuskaitymasRusiavimasList(list<studentasL>& grupeList, list<studentasL>& grupeListBad, list<studentasL>& grupeListGood, double& laikasSkaitymas, double& laikasSkaiciavimas, int i, string vidMed);
void listPartition(string vidMed, list<studentasL>& grupeList, list<studentasL>& grupeListBad, list<studentasL>& grupeListGood);
void listPartition2(string vidMed, list<studentasL>& grupeList, list<studentasL>& grupeListBad);