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

void fileReadingList(std::deque<studentasD>& grupeDeque, std::string failas) {
    std::ifstream fin;
    do {
        fin.open(failas);
        if (!fin.is_open()) {
            std::cerr << "Error: nepavyko atidaryti failo!!!\nIveskite failo pavadinima is naujo!!!\n" << std::endl;
            std::cin >> failas;
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
                if (std::stoi(grade) >= 0 && std::stoi(grade) <= 10) {
                    laikinasD.pazymiai.push_back(std::stoi(grade));
                }
            }
            catch (std::exception& e) {
            }
        }
        laikinasD.egzaminas = laikinasD.pazymiai.back();
        laikinasD.pazymiai.pop_back();
        grupeDeque.push_back(laikinasD);
        iss.clear();
    }
    fin.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Failu nuskaitymas su DEQUE uztruko: " << duration.count() << std::endl;

    auto skStart = std::chrono::high_resolution_clock::now();

    generalVidurkisCalculateDeque(grupeDeque);
    generalMedianaCalculateDeque(grupeDeque);

    auto skEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> skDuration = skEnd - skStart;
    std::cout << "Vidurkiu ir medianu apskaiciavimas su DEQUE uztruko: " << skDuration.count() << std::endl;
}
void generalVidurkisCalculateDeque(deque<studentasD>& grupeDeque) {
    for (auto& student : grupeDeque) {
        if (student.pazymiai.empty()) {
            student.pazVid = student.egzaminas * 0.6;
        }
        else {
            double suma = std::accumulate(student.pazymiai.begin(), student.pazymiai.end(), 0.0);
            student.pazVid = suma / student.pazymiai.size() * 0.4 + student.egzaminas * 0.6;
        }
    }
}
void generalMedianaCalculateDeque(std::deque<studentasD>& grupeDeque) {
    for (auto& studentas : grupeDeque) {
        std::sort(studentas.pazymiai.begin(), studentas.pazymiai.end());

        size_t size = studentas.pazymiai.size();
        if (size < 1) {
            studentas.mediana = -1;
        }
        else if (size % 2 == 0) {
            auto it1 = studentas.pazymiai.begin() + size / 2 - 1;
            auto it2 = studentas.pazymiai.begin() + size / 2;
            studentas.mediana = (*it1 + *it2) / 2.0 * 0.4 + studentas.egzaminas * 0.6;
        }
        else {
            auto it = studentas.pazymiai.begin() + size / 2;
            studentas.mediana = *it * 0.4 + studentas.egzaminas * 0.6;
        }
    }
}