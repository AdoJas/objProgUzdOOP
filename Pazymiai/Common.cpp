#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>"
#include "PazymiaiArrays.h"
#include <fstream>
#include <sstream>
#include "chrono"

void addToArray(int*& arr, int& size, int value) {
    size++;
    int* tmp = new int[size];
    for (int i = 0; i < size - 1; i++) {
        tmp[i] = arr[i];
    }
    tmp[size - 1] = value;
    delete[] arr;
    arr = tmp;
}

void addToArray(studentasA*& arr, int& size, studentasA value) {
    size++;
    studentasA* tmp = new studentasA[size];
    for (int i = 0; i < size - 1; i++) {
        tmp[i] = arr[i];
    }
    tmp[size - 1] = value;
    delete[] arr;
    arr = tmp;
}
void meniu(string& pasirinkimas) {
    bool validInput = false;
    do {
        cout << "Meniu:\n"
            << "1 - Studentu duomenu ivedimas ranka\n"
            << "2 - Ivestiems studentams generuojami pazymiai\n"
            << "3 - Generuojami pazymiai ir vardai/pavardes ivedus studentu skaiciu\n"
            << "4 - Skaityti duomenis is failo\n"
            << "5 - Studentu duomenu generavimas, rasymas i faila, failo nuskaitymas\n"
            << "6 - Studentu rusiavimas is failu pasirenkant konteinerio tipa\n"
            << "7 - Baigti darba\n"
            << "--------------------------------------------------\n"
            << "Pasirinkite norima opcija: ";

        try {
            cin >> pasirinkimas;
            int option = stoi(pasirinkimas);
            if (option >= 1 && option <= 7) {
                validInput = true;
            }
            else {
                cout << "Neteisinga ivestis. Pasirinkite skaiciu nuo 1 iki 7.\n";
            }
        }
        catch (const std::exception& e) {
            cout << "Neteisinga ivestis. Pasirinkite skaiciu nuo 1 iki 7.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (!validInput);
}
void meniuKonteineriams(string& pasirinkimas) {
    bool validInput = false;
    do {
        cout << "Meniu:\n"
            << "1 - Studentu duomenu ivedimas ranka\n"
            << "2 - Ivestiems studentams generuojami pazymiai\n"
            << "3 - Generuojami pazymiai ir vardai/pavardes ivedus studentu skaiciu\n"
            << "4 - Skaityti duomenis is failo\n"
            << "5 - Studentu duomenu generavimas, rasymas i faila, failo nuskaitymas\n"
            << "6 - Baigti pasirinkima\n"
            << "--------------------------------------------------\n"
            << "Pasirinkite norima opcija: ";

        try {
            cin >> pasirinkimas;
            int option = stoi(pasirinkimas);
            if (option >= 1 && option <= 6) {
                validInput = true;
            }
            else {
                cout << "Neteisinga ivestis. Pasirinkite skaiciu nuo 1 iki 6.\n";
            }
        }
        catch (const std::exception& e) {
            cout << "Neteisinga ivestis. Pasirinkite skaiciu nuo 1 iki 6.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (!validInput);
}
void meniuKonteineriai(string& pasirinkimas) {
    bool validInput = false;
    do {
        cout << "Pasirinkite konteineri:\n"
            << "1 - Vector\n"
            << "2 - List\n"
            << "3 - Deque\n"
            << ("--------------------------------------------------\n")
            << "Pasirinkite norima konteineri: ";
        try {
            cin >> pasirinkimas;
            int option = stoi(pasirinkimas);
            if (option >= 1 && option <= 3) {
                validInput = true;
            }
            else {
                cout << "Neteisinga ivestis. Pasirinkite skaiciu nuo 1 iki 7.\n";
            }
        }
        catch (const std::exception& e) {
            cout << "Neteisinga ivestis. Pasirinkite skaiciu nuo 1 iki 3.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        printf("--------------------------------------------------\n");
    } while (!validInput);
}
void sortChoice(string& choice) {
    bool validInput = false;
    do {
        printf("Pasirinkite norima rusiavimo buda: \n");
        printf("1- Rusiuoti pagal varda\n");
        printf("2- Rusiuoti pagal pavarde\n");
        printf("3- Rusiuoti pagal vidurki\n");
        printf("4- Rusiuoti pagal mediana\n");
        cout << "Pasirinkimas: ";
        try {
            cin >> choice;
            int option = stoi(choice);
            if (option >= 1 && option <= 4) {
                validInput = true;
            }
            else {
                cout << "Neteisinga ivestis. Pasirinkite skaiciu nuo 1 iki 4.\n";
            }
        }
        catch (const std::exception& e) {
            cout << "Neteisinga ivestis. Pasirinkite skaiciu nuo 1 iki 3.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        printf("--------------------------------------------------\n");
        
    } while (!validInput);
}
void pasirinkimasVidMed(string& vidMed) {
    do {
        cout << "Jei norite isvedimo vidurkio pavidalu, rasykite 1\n" <<
            "Jei norite isvedimo medianos pavidalu, rasykite 2: ";
        cin >> vidMed;
        printf("--------------------------------------------------\n");
    } while (vidMed != "1" && vidMed != "2");
}
void pasirinkimasIvedimas(string& ivedimas) {
    do {
        cout << "1 - Jei norite rusiuoti i du naujus konteinerius" << endl;
        cout << "2 - Jei norite rusiuoti i viena nauja konteineri" << endl;
        std::cin >> ivedimas;
    } while (ivedimas != "1" && ivedimas != "2");
}
void failoGeneravimasIsvedimas(int iteracija) {
    ofstream fout("KursiokaiGen" + to_string(iteracija + 1) + ".txt");
    stringstream bufferis;
    int laikinas = 0;
    auto start = std::chrono::high_resolution_clock::now();
    bufferis << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(10);

    for (int i = 0; i < 10; i++) {
        bufferis << left << setw(5) << "ND" + to_string(i + 1);
    }
    bufferis << left << setw(5) << "Egz." << endl;

    for (int i = 1; i <= pow(10, 3 + iteracija); i++) {
        bufferis << left << setw(20) << "Vardas" + to_string(i) << left << setw(20) << "Pavarde" + to_string(i) << left << setw(10);
        for (int x = 0; x < rand() % 10 + 1; x++) {
            bufferis << left << setw(5) << rand() % 10 + 1;
            laikinas++;
        }
        for (int z = laikinas; z < 10; z++) { // Corrected loop counter and condition
            bufferis << left << setw(5) << " ";
        }
        bufferis << left << setw(5) << rand() % 10 + 1 << endl;

        laikinas = 0; // Resetting laikinas
    }
    fout << bufferis.str();
    bufferis.str(""); // Clearing the stringstream
    bufferis.clear(); // Clearing any error flags
    fout.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << pow(10, iteracija + 3) << " studentu" << endl;
    cout << "Studentu generavimas ir rasymas i faila uztruko: " << duration.count() << " sek." << endl;
}
void pazymiuFailoGeneravimas() {
    for (int i = 0; i < 5; i++) {
        failoGeneravimasIsvedimas(i);
        cout << "Duomenys isvesti i faila!!!!" << endl;
        cout << "--------------------------------------------------" << endl;
    }
}