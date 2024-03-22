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
#include <string>
#include "filesystem"

using namespace std;

//namespace fs = std::filesystem;
enum class KonteinerioTipas {Nera, Vector, List, Deque};
enum class Veiksmas { GenerateFilesAndSort, SortExistingStudents, Nera};

KonteinerioTipas getKonteinerioTipas() {
    int choice;
    do {
        cout << "Pasirinkite konteineri: \n"
            << "1 - vektorius\n"
            << "2 - list\n"
            << "3 - deque\n";
        try {
            cin >> choice;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Neteisinga ivestis - turi buti sveikasis skaicius (1 arba 2 arba 3): " << e.what() << std::endl;
        }
    }while (choice != 1 && choice != 2 || choice != 3);

    switch (choice) {

    case 1:
        return KonteinerioTipas::Vector;
        break;
    case 2:
        return KonteinerioTipas::List;
        break;
    case 3:
        return KonteinerioTipas::Deque;
        break;
    default:
        return KonteinerioTipas::Nera;
        break;
    }
}

Veiksmas getVeiksmas() {
    int choice;
    do {
        cout << "Pasirinkite norima funkcija: \n"
            << "1 - Studentu failu generavimas ir darbas su jais\n"
            << "2 - Turimu failu nuskaitymas ir darbas su jais\n";
        try {
            cin >> choice;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Neteisinga ivestis - turi buti sveikasis skaicius (1 arba 2): " << e.what() << std::endl;
        }
    } while (choice != 1 && choice != 2);
    switch (choice) {

    case 1:
        return Veiksmas::GenerateFilesAndSort;
        break;
    case 2:
        return Veiksmas::SortExistingStudents;
        break;
    default:
        return Veiksmas::Nera;
        break;
    }

}
void runProgram() {
    /*for (int i = 0; i < 5; i++) {
        failoGeneravimasIsvedimas(i);
    }*/
    bool exitProgram = false;

    while (!exitProgram) {
        
        KonteinerioTipas containerChoice = getKonteinerioTipas();
        if (containerChoice == KonteinerioTipas::Nera) {
            continue;
        }

        Veiksmas actionChoice = getVeiksmas();
        if (actionChoice == Veiksmas::Nera) {
            continue;
        }

        //performAction

        bool validInput = false;
        cout << "Ar norite testi?? (1 - Taip/ 2 - Ne)";

        string userChoice = " ";
        try {
            cin >> userChoice;
            int option = stoi(userChoice);
            if (option >= 1 && option <= 4) {
                validInput = true;
            }
            else {
                cout << "Neteisinga ivestis. Pasirinkite skaiciu nuo 1 iki 4.\n";
            }
        }catch (const std::exception& e) {
            cout << "Neteisinga ivestis. Pasirinkite skaiciu nuo 1 iki 3.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    printf("--------------------------------------------------\n");
        
        if (userChoice == "2") {
            exitProgram = true;
        }
    }
}


//
//void generalVidurkisCalculate(KonteinerioTipas& grupeContainer) {
//    for (auto& student : grupeContainer) {
//        if (student.pazymiai.empty()) {
//            student.pazVid = student.egzaminas * 0.6;
//        }
//        else {
//            double suma = std::accumulate(student.pazymiai.begin(), student.pazymiai.end(), 0.0);
//            student.pazVid = suma / student.pazymiai.size() * 0.4 + student.egzaminas * 0.6;
//        }
//    }
//}
//
//void generalMedianaCalculate(KonteinerioTipas& grupeContainer) {
//
//    for (auto& studentas : grupeContainer) {
//        std::sort(studentas.pazymiai.begin(), studentas.pazymiai.end());
//
//        size_t size = studentas.pazymiai.size();
//        if (size < 2) studentas.mediana = -1;
//        if (size % 2 == 0) {
//            studentas.mediana = (studentas.pazymiai[size / 2 - 1] + studentas.pazymiai[size / 2]) / 2.0 * 0.4 + studentas.egzaminas * 0.6;
//        }
//        else {
//            studentas.mediana = studentas.pazymiai[size / 2] * 0.4 + studentas.egzaminas * 0.6;
//        }
//    }
//}
//
//void turimiFailai() {
//    vector<string> failai;
//
//    cout << "Turimi studentu failai: \n";
//    int fileIndex = 1;
//    for (const auto& paieska : std::filesystem::directory_iterator(".")) {
//        string filename = paieska.path().filename().string();
//        if (filename.find("studentai") != string::npos && filename.find(".txt") != string::npos) {
//            failai .push_back(filename);
//            cout << fileIndex++ << ". " << filename << "\n";
//        }
//    }
//
//}
