#include <limits>
#include "common.h"
#include "PazymiaiArrays.h"
#include <fstream>

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
void meniu(int& pasirinkimas){
    do {
        cout << "Meniu:\n"
            << "1 - Studentu duomenu ivedimas ranka\n"
            << "2 - Ivestiems studentams generuojami pazymiai\n"
            << "3 - Generuojami pazymiai ir vardai/pavardes ivedus studentu skaiciu\n"
            << "4 - Skaityti duomenis is failo\n"
            << "5 - Studentu duomenu generavimas, rasymas i faila, failo nuskaitymas\n"
            << "6 - Studentu rusiavimas is failu pasirenkant konteinerio tipa\n"
            << "7 - Baigti darba\n"
            << ("--------------------------------------------------\n")
            << "Pasirinkite norima opcija: ";
        cin >> pasirinkimas;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        printf("--------------------------------------------------\n");
    } while (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3 && pasirinkimas != 4 && pasirinkimas != 5 && pasirinkimas != 6 && pasirinkimas != 7);
}
void meniuKonteineriai(int& pasirinkimas) {
    do {
        cout << "Pasirinkite konteineri:\n"
            << "1 - Vector\n"
            << "2 - List\n"
            << "3 - Deque\n"
            << ("--------------------------------------------------\n")
            << "Pasirinkite norima konteineri: ";
        cin >> pasirinkimas;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        printf("--------------------------------------------------\n");
    } while (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3);
}
void sortChoice(int& choice) {
    do {
        printf("Pasirinkite norima rusiavimo buda: \n");
        printf("1- Rusiuoti pagal varda\n");
        printf("2- Rusiuoti pagal pavarde\n");
        printf("3- Rusiuoti pagal vidurki\n");
        printf("4- Rusiuoti pagal mediana\n");
        cout << "Pasirinkimas: ";
        cin >> choice;
    } while (choice > 4 || choice < 1);
}
void pasirinkimasVidMed(string& vidMed) {
    do {
        cout << "Jei norite isvedimo vidurkio pavidalu, rasykite 1\n" <<
            "Jei norite isvedimo medianos pavidalu, rasykite 2: ";
        cin >> vidMed;
    } while (vidMed != "1" && vidMed != "2");
}
void generateFiles(int iteracija, int kiekis) {
    ofstream fout("KursiokaiGen" + to_string(iteracija + 1) + ".txt");
    fout << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 0; i < 10; ++i)
    {
        fout << setw(5) << "ND" + to_string(i + 1);
    }
    fout << setw(5) << "Egz." << endl;

    for (int i = 1; i <= kiekis; i++)
    {
        fout << left << setw(20) << "Vardas" + to_string(i)
            << setw(20) << "Pavarde" + to_string(i);
        for (int j = 0; j < 15; j++)
        {
            fout << setw(5) << (rand() % 10 + 1);
        }
        fout << setw(5) << (rand() % 10 + 1);
        fout << endl;
    }
}