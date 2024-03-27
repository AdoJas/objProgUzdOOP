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

void fileReadingDeque(std::deque<studentasD>& grupeDeque, std::string failas) {
    std::ifstream fin;
    do {
        fin.open(failas);
        if (!fin.is_open()) {
            std::cerr << "Error: nepavyko atidaryti failo!!!\nIveskite failo pavadinima is naujo!!!\n" << std::endl;
            std::cin >> failas;
        }
    } while (!fin.is_open());
    auto start = std::chrono::high_resolution_clock::now();
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

    std::cout << "DEQUE - Failu nuskaitymas uztruko: " << duration.count() << std::endl;

    auto skStart = std::chrono::high_resolution_clock::now();

    generalVidurkisCalculateDeque(grupeDeque);
    generalMedianaCalculateDeque(grupeDeque);

    auto skEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> skDuration = skEnd - skStart;
    //std::cout << "Vidurkiu ir medianu apskaiciavimas su DEQUE uztruko: " << skDuration.count() << std::endl;
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
void dequePartition(string vidMed, deque<studentasD>& grupeDeque, deque<studentasD>& grupeDequeBad, deque<studentasD>& grupeDequeGood) {
    if (vidMed == "1") {
        auto it = std::partition(grupeDeque.begin(), grupeDeque.end(), [](const studentasD& student) {
            return student.pazVid >= 5;
            });

        grupeDequeGood.insert(grupeDequeGood.end(), grupeDeque.begin(), it);
        grupeDequeBad.insert(grupeDequeBad.end(), it, grupeDeque.end());
    }
    else {
        auto it = std::partition(grupeDeque.begin(), grupeDeque.end(), [](const studentasD& student) {
            return student.mediana >= 5;
            });

        grupeDequeGood.insert(grupeDequeGood.end(), grupeDeque.begin(), it);
        grupeDequeBad.insert(grupeDequeBad.end(), it, grupeDeque.end());
    }
}
void dequePartition2(string vidMed, deque<studentasD>& grupeDeque, deque<studentasD>& grupeDequeBad) {
    if (vidMed == "1") {
        auto it = std::partition(grupeDeque.begin(), grupeDeque.end(), [](const studentasD& student) {
            return student.pazVid >= 5;
            });
        grupeDequeBad.insert(grupeDequeBad.end(), it, grupeDeque.end());
        grupeDeque.erase(it, grupeDeque.end());
    }
    else {
        auto it = std::partition(grupeDeque.begin(), grupeDeque.end(), [](const studentasD& student) {
            return student.mediana >= 5;
            });
        grupeDequeBad.insert(grupeDequeBad.end(), it, grupeDeque.end());
        grupeDeque.erase(it, grupeDeque.end());
    }
}
void failoNuskaitymasRusiavimasDeque(deque<studentasD>& grupeDeque, deque<studentasD>& grupeDequeBad, deque<studentasD>& grupeDequeGood, int i, string vidMed, int& ivedimas, string choice) {
    int fakePazymiai;
    fileReadingDeque(grupeDeque, "KursiokaiGen" + to_string(i + 1) + ".txt");

    auto start1 = std::chrono::high_resolution_clock::now();
    sortInputDeque(choice, grupeDeque);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;
    cout << "DEQUE - studentu konteinerio rusiavimas truko: " << duration1.count() << endl;
    /*do {
        cout << "1 - Jei norite rusiuoti i du naujus konteinerius" << endl;
        cout << "2 - Jei norite rusiuoti i viena nauja konteineri" << endl;
        std::cin >> ivedimas;
    } while (ivedimas != 1 && ivedimas != 2);*/

    auto start = std::chrono::high_resolution_clock::now();
    if (ivedimas == 1) {
        dequePartition(vidMed, grupeDeque, grupeDequeBad, grupeDequeGood);
    }
    else {
        dequePartition2(vidMed, grupeDeque, grupeDequeBad);
    }
    dequePartition(vidMed, grupeDeque, grupeDequeBad, grupeDequeGood);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    /*std::cout << "Studentu nuskaitymas is failo  " << laikasSkaitymas << " sek." << std::endl;
    std::cout << "Studentu duomenu apskaiciavimas truko:  " << laikasSkaiciavimas << " sek." << std::endl;*/
    cout << "DEQUE - Studentu rusiavimas i du konteinerius truko:  " << duration.count() << " sek." << endl;
}
void failoIsvedimasDeque(deque<studentasD>& grupeDeque, deque<studentasD>& grupeDequeBad, deque<studentasD>& grupeDequeGood, int i, string vidMed, int& ivedimas, string choice) {
    ofstream fout;
    fout.open("KursiokaiGood" + to_string(i + 1) + ".txt");

    ofstream foutB;
    foutB.open("KursiokaiBad" + to_string(i + 1) + ".txt");

    stringstream bufferis;
    stringstream bufferisB;

    auto start1 = std::chrono::high_resolution_clock::now();
    if (vidMed == "1") {
        bufferis << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Vid.)" << endl;
        bufferis << "--------------------------------------------------" << endl;

        for (auto& student : grupeDequeGood) {
            bufferis << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.pazVid << endl;
        }
        fout << bufferis.str();
        bufferis.str("");
        bufferis.clear();
    }
    else if (vidMed == "2") {
        bufferis << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Med.)" << endl;
        bufferis << "--------------------------------------------------" << endl;

        for (auto& student : grupeDequeGood) {
            bufferis << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.mediana << endl;
        }
        fout << bufferis.str();
        bufferis.str("");
        bufferis.clear();
    }

    if (vidMed == "1") {
        bufferisB << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Vid.)" << endl;
        bufferisB << "--------------------------------------------------" << endl;

        for (auto& student : grupeDequeBad) {
            bufferisB << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.pazVid << endl;
        }
        foutB << bufferisB.str();
        bufferisB.str("");
        bufferisB.clear();
    }
    else if (vidMed == "2") {
        bufferisB << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Med.)" << endl;
        bufferisB << "--------------------------------------------------" << endl;

        for (auto& student : grupeDequeBad) {
            bufferisB << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.mediana << endl;
        }
        foutB << bufferisB.str();
        bufferisB.str("");
        bufferisB.clear();
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;
    cout << "Abieju studentu konteineriu(DEQUE) isvedimas truko:  " << duration1.count() << " sek." << endl;
    cout << "--------------------------------------------------" << endl;
}
bool compareByNameDeque(const studentasD& a, const studentasD& b) {
    if (a.vardas.find("Vardas") == 0 && b.vardas.find("Vardas") == 0) {
        int num1 = stoi(a.vardas.substr(6));
        int num2 = stoi(b.vardas.substr(6));
        return num1 > num2;
    }
    else return a.vardas < b.vardas;
}

bool compareBySurnameDeque(const studentasD& a, const studentasD& b) {
    if (a.pavarde.find("Pavarde") == 0 && b.pavarde.find("Pavarde") == 0) {
        int num1 = stoi(a.pavarde.substr(7));
        int num2 = stoi(b.pavarde.substr(7));
        return num1 > num2;
    }
    else return a.pavarde < b.pavarde;
}

bool compareByAverageDeque(const studentasD& a, const studentasD& b) {
    return a.pazVid < b.pazVid;
}

bool compareByMedianaDeque(const studentasD& a, const studentasD& b) {
    return a.mediana < b.mediana;
}

void sortInputDeque(string& choice, deque<studentasD>& grupeDeque) {
    switch (stoi(choice)) {
    case 1:
        sort(grupeDeque.begin(), grupeDeque.end(), compareByNameDeque);
        break;
    case 2:
        sort(grupeDeque.begin(), grupeDeque.end(), compareBySurnameDeque);
        break;
    case 3:
        sort(grupeDeque.begin(), grupeDeque.end(), compareByAverageDeque);
        break;
    case 4:
        sort(grupeDeque.begin(), grupeDeque.end(), compareByMedianaDeque);
        break;
    default:
        cerr << "Klaida: nepavyko surusiuoti failu!\n";
    }
}
void clearDeque(deque<studentasD>& grupeDeque) {
    for (auto& student : grupeDeque) {
        student.pazymiai.clear();
    }
    grupeDeque.clear();
}
void dequeMain(string vidMed, string choice, deque<studentasD>& grupeDeque, deque<studentasD>& grupeDequeBad, deque<studentasD>& grupeDequeGood, int ivedimas) {
    pasirinkimasVidMed(vidMed);
    sortChoice(choice);
    //pazymiuFailoGeneravimas();
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 5; i++) {
        cout << pow(10, i + 3) << " studentu failas" << endl;
        failoNuskaitymasRusiavimasDeque(grupeDeque, grupeDequeBad, grupeDequeGood, i, vidMed, ivedimas, choice);


        auto start = std::chrono::high_resolution_clock::now();
        sortInputDeque(choice, grupeDequeBad);
        sortInputDeque(choice, grupeDequeGood);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        cout << "--------------------------------------------------" << endl;
        //cout << "LIST - Abieju studentu konteineriu rusiavimas pagal pasirinkima :  " << duration.count() << " sek." << endl;
        //failoIsvedimasDeque(grupeDeque, grupeDequeBad, grupeDequeGood, i, vidMed, ivedimas, choice);
        clearDeque(grupeDeque);
        clearDeque(grupeDequeBad);
        clearDeque(grupeDequeGood);
    }

}
