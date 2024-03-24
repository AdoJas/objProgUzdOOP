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
#include <deque>

using namespace std;

struct studentasD {
    string vardas;
    string pavarde;
    deque<int> pazymiai;
    float pazVid = 0.0;
    float egzaminas = 0.0;
    float mediana = 0.0;
    float pazSuma = 0.0;
};
void generalMedianaCalculateDeque(std::deque<studentasD>& grupeDeque);
void generalVidurkisCalculateDeque(deque<studentasD>& grupeDeque);
void fileReadingDeque(std::deque<studentasD>& grupeDeque, std::string failas);
void dequePartition(string vidMed, deque<studentasD>& grupeDeque, deque<studentasD>& grupeDequeBad, deque<studentasD>& grupeDequeGood);
void dequePartition2(string vidMed, deque<studentasD>& grupeDeque, deque<studentasD>& grupeDequeBad);
void failoNuskaitymasRusiavimasDeque(deque<studentasD>& grupeDeque, deque<studentasD>& grupeDequeBad, deque<studentasD>& grupeDequeGood, int i, string vidMed, int& ivedimas, string choice);
void failoIsvedimasDeque(deque<studentasD>& grupeDeque, deque<studentasD>& grupeDequeBad, deque<studentasD>& grupeDequeGood, int i, string vidMed, int& ivedimas, string choice);
void sortInputDeque(string& choice, deque<studentasD>& grupeDeque);
void dequeMain(string vidMed, string choice, deque<studentasD>& grupeDeque, deque<studentasD>& grupeDequeBad, deque<studentasD>& grupeDequeGood, int ivedimas);