#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include "PazymiaiList.h"
#include <fstream>
#include <sstream>
#include "chrono"
#include "common.h"

using namespace std;

void fileReadingList(list<studentasL> grupeList, string failas) {
    ifstream fin;
    do {
        fin.open(failas);
        if (!fin.is_open()) {
            cerr << "Error: nepavyko atidaryti failo!!!\nIveskite failo pavadinima is naujo!!!\n" << endl;
            cin >> failas;
        }
    } while (!fin.is_open());
    auto start = std::chrono::high_resolution_clock::now();
    cout << "---------------------------------------------------------" << endl;
    string line;
    istringstream iss;
    string grade = "";
    getline(fin, line); // nereikalingas line'as pasalinamas
    while (getline(fin, line)) {
        iss.str(line);
        studentasL laikinasL;
        iss >> laikinasL.vardas >> laikinasL.pavarde;
        while (iss >> grade) {
            try {
                if (stoi(grade) >= 0 && stoi(grade) <= 10) {
                    laikinasL.pazymiai.push_back(std::stoi(grade));
                }
            }
            catch (std::exception& e) {
            }
        }
        laikinasL.egzaminas = laikinasL.pazymiai.back();
        laikinasL.pazymiai.pop_back();
        grupeList.push_back(laikinasL);
        iss.clear();
    }
    fin.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    cout << "Failu nuskaitymas su LIST uztruko: " << duration.count();

    auto skStart = std::chrono::high_resolution_clock::now();

    generalVidurkisCalculateList(grupeList);
    generalMedianaCalculateList(grupeList);

    auto skEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> skDuration = skEnd - skStart;
    cout << "Vidurkiu ir medianu apskaiciavimas su LIST uztruko: " << skDuration.count();
}
void generalVidurkisCalculateList(list<studentasL>& grupeList) {
    for (auto& student : grupeList) {
        if (student.pazymiai.empty()) {
            student.pazVid = student.egzaminas * 0.6;
        }
        else {
            double suma = std::accumulate(student.pazymiai.begin(), student.pazymiai.end(), 0.0);
            student.pazVid = suma / student.pazymiai.size() * 0.4 + student.egzaminas * 0.6;
        }
    }
}
void generalMedianaCalculateList(list<studentasL>& grupeList) {
    for (auto& studentas : grupeList) {
        studentas.pazymiai.sort(); 

        size_t size = studentas.pazymiai.size();
        if (size < 1) {
            studentas.mediana = -1;
        }
        else if (size % 2 == 0) {
            auto it1 = studentas.pazymiai.begin();
            advance(it1, size / 2 - 1);
            auto it2 = studentas.pazymiai.begin();
            advance(it2, size / 2);
            studentas.mediana = (*it1 + *it2) / 2.0 * 0.4 + studentas.egzaminas * 0.6;
        }
        else {
            auto it = studentas.pazymiai.begin();
            advance(it, size / 2);
            studentas.mediana = *it * 0.4 + studentas.egzaminas * 0.6;
        }

        studentas.pazSuma = 0;
        for (int pazymys : studentas.pazymiai) {
            studentas.pazSuma += pazymys;
        }

        if (size > 0) {
            studentas.pazVid = studentas.pazSuma / size;
        }
        else {
            studentas.pazVid = 0;
        }
    }
}
void listPartition(string vidMed, list<studentasL>& grupeList, list<studentasL>& grupeListBad, list<studentasL>& grupeListGood) {
    if (vidMed == "1") {
        auto it = std::partition(grupeList.begin(), grupeList.end(), [](const studentasL& student) {
            return student.pazVid >= 5;
            });

        grupeListGood.insert(grupeListGood.end(), grupeList.begin(), it);
        grupeListBad.insert(grupeListBad.end(), it, grupeList.end());
    }
    else {
        auto it = std::partition(grupeList.begin(), grupeList.end(), [](const studentasL& student) {
            return student.mediana >= 5;
            });

        grupeListGood.insert(grupeListGood.end(), grupeList.begin(), it);
        grupeListBad.insert(grupeListBad.end(), it, grupeList.end());
    }
}
void listPartition2(string vidMed, list<studentasL>& grupeList, list<studentasL>& grupeListBad) {
    if (vidMed == "1") {
        auto it = std::partition(grupeList.begin(), grupeList.end(), [](const studentasL& student) {
            return student.pazVid >= 5;
            });

        grupeListBad.insert(grupeListBad.end(), it, grupeList.end());
        grupeList.erase(it, grupeList.end());
    }
    else {
        auto it = std::partition(grupeList.begin(), grupeList.end(), [](const studentasL& student) {
            return student.mediana >= 5;
            });

        grupeListBad.insert(grupeListBad.end(), it, grupeList.end());
        grupeList.erase(it, grupeList.end());

    }
}
void failoNuskaitymasRusiavimasList(list<studentasL>& grupeList, list<studentasL>& grupeListBad, list<studentasL>& grupeListGood, double& laikasSkaitymas, double& laikasSkaiciavimas, int i, string vidMed, int& ivedimas) {
    int fakePazymiai;
    fileReadingList(grupeList, "KursiokaiGen" + to_string(i + 1) + ".txt");
    /*do {
        cout << "1 - Jei norite rusiuoti i du naujus konteinerius" << endl;
        cout << "2 - Jei norite rusiuoti i viena nauja konteineri" << endl;
        std::cin >> ivedimas;
    } while (ivedimas != 1 && ivedimas != 2);*/
    
    auto start = std::chrono::high_resolution_clock::now();
    /*if (ivedimas == 1) {
        listPartition(vidMed, grupeList, grupeListBad, grupeListGood);
    }
    else {
        listPartition2(vidMed, grupeList, grupeListBad);
    }
    */
    listPartition(vidMed, grupeList, grupeListBad, grupeListGood);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    /*std::cout << "Studentu nuskaitymas is failo  " << laikasSkaitymas << " sek." << std::endl;
    std::cout << "Studentu duomenu apskaiciavimas truko:  " << laikasSkaiciavimas << " sek." << std::endl;*/
    std::cout << "Studentu rusiavimas i du konteinerius truko:  " << duration.count() << " sek." << std::endl;
}
void failoIsvedimasList(list<studentasL>& grupeList, list<studentasL>& grupeListBad, list<studentasL>& grupeListGood, double& laikasSkaitymas, double& laikasSkaiciavimas, int i, string vidMed, int& ivedimas) {
    ofstream fout("KursiokaiGood" + to_string(i + 1) + ".txt");
    ofstream foutB("KursiokaiBad" + to_string(i + 1) + ".txt");
    
    stringstream bufferis;
    stringstream bufferisB;

    auto start = std::chrono::high_resolution_clock::now();
    //sortInput(choice, grupeList, laikasSkaitymas);
    //sortInput(choice, grupeListBad, laikasSkaitymas);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << "Abieju studentu konteineriu rusiavimas pagal pasirinkima :  " << duration.count() << " sek." << endl;
    auto start1 = std::chrono::high_resolution_clock::now();
    if (vidMed == "1") {
        bufferis << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Vid.)" << endl;
        bufferis << "--------------------------------------------------" << endl;

        for (auto& student : grupeList) {
            bufferis << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.pazVid << endl;
        }
        fout << bufferis.str();
        bufferis.str("");
        bufferis.clear();
    }
    else if (vidMed == "2") {
        bufferis << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Med.)" << endl;
        bufferis << "--------------------------------------------------" << endl;

        for (auto& student : grupeList) {
            bufferis << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.mediana << endl;
        }
        fout << bufferis.str();
        bufferis.str("");
        bufferis.clear();
    }

    if (vidMed == "1") {
        bufferisB << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Vid.)" << endl;
        bufferisB << "--------------------------------------------------" << endl;

        for (auto& student : grupeListBad) {
            bufferisB << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.pazVid << endl;
        }
        foutB << bufferisB.str();
        bufferisB.str("");
        bufferisB.clear();
    }
    else if (vidMed == "2") {
        bufferisB << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Med.)" << endl;
        bufferisB << "--------------------------------------------------" << endl;

        for (auto& student : grupeListBad) {
            bufferisB << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.mediana << endl;
        }
        foutB << bufferisB.str();
        bufferisB.str("");
        bufferisB.clear();
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;
    cout << "Abieju studentu konteineriu(LIST) isvedimas truko:  " << duration1.count() << " sek." << endl;
}
