#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include "PazymiaiDeque.h"
#include <fstream>
#include <sstream>
#include "chrono"

#include "common.h"

using namespace std;
void fileReadingDeque(std::deque<studentasD>& grupeDeque, const std::string& failas, double& laikasSkaitymas, int& fakePazymiai, double& laikasSkaiciavimas) {
    ifstream fin;
    int kausas;
    do {
        fin.open(failas);
        if (!fin.is_open()) {
            cerr << "Error: nepavyko atidaryti failo!!!\nIveskite failo pavadinima is naujo!!!\n" << endl;
            cin >> ;
        }
    } while (!fin.is_open());

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "---------------------------------------------------------" << std::endl;
    std::string line;
    std::istringstream iss;
    std::string grade = "";
    getline(fin, line); // nereikalingas line'as pasalinamas
    while (getline(fin, line)) {
        iss.str(line);
        studentasD laikinasD;
        iss >> laikinasD.vardas >> laikinasD.pavarde;
        while (iss >> grade) {
            try {
                int gradeValue = std::stoi(grade);
                if (gradeValue >= 0 && gradeValue <= 10) {
                    laikinasD.pazymiai.push_back(gradeValue);
                }
            }
            catch (const std::exception& e) {
                fakePazymiai++;
            }
        }
        laikinasD.egzaminas = laikinasD.pazymiai.back();
        laikinasD.pazymiai.pop_back();
        grupeDeque.push_back(laikinasL);
        iss.clear();
    }
    fin.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    laikasSkaitymas = duration.count();

    auto skStart = std::chrono::high_resolution_clock::now();

    generalVidurkisCalculateDeque(grupeDeque);
    generalMedianaCalculateDeque(grupeDeque);

    auto skEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> skDuration = skEnd - skStart;
    laikasSkaiciavimas = skDuration.count();
}