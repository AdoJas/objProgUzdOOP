#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <cctype>
#include "PazymiaiArrays.h"
#include "Common.h"
#include "cmath"


using namespace std;
float studentasA::getMediana() {
    if (pazymiuKiekis < 2) return -1;

    int i, j;
    int laikinas = round(pazymiuKiekis * 1.0 / 2);
    float med;
 
    for (i = 0; i < pazymiuKiekis - 1; i++) {
        for (j = 0; j < pazymiuKiekis - i - 1; j++) {
            if (pazymiai[j] > pazymiai[j + 1]) {
                swap(pazymiai[j], pazymiai[j + 1]);
            }
        }
    }
    if (pazymiuKiekis % 2 == 0) {
        med = (pazymiai[laikinas] + pazymiai[laikinas - 1]) * 1.0 / 2;
    }
    else {
        med = pazymiai[laikinas - 1];
    }
    
    return med * 0.4 + egzaminas * 0.6;
}
float studentasA::getVidurkis() {
    float laikinas = 0;;
        laikinas = 0;
        for (int x = 0; x < pazymiuKiekis; x++) {
            laikinas += pazymiai[x];
        }
        return (pazymiuKiekis != 0) ? (laikinas * 1.0 / pazymiuKiekis * 0.4) + (egzaminas * 0.6) : (egzaminas * 0.6);
}
void ivestiStudenta(int studentoNr, int pazKiekis, studentasA& stud) {
    int kiekis = 0;
    cout << "Iveskite " << studentoNr << " mokinio varda: ";
    cin >> stud.vardas;
    cout << "Iveskite " << studentoNr << " mokinio pavarde: ";
    cin >> stud.pavarde;
    stud.pazymiai = new int[0];
    cout << "Iveskite mokinio pazymius: ";

    float suma = 0.0;
    readNumbers(stud.pazymiai, kiekis, pazKiekis);
    stud.pazymiuKiekis = kiekis;
    cout << "Iveskite " << studentoNr << " mokinio egzamino rezultata: ";
    cin >> stud.egzaminas;
}
void ivedimas(int n, int & x, studentasA grupe[]) {
    int kiekis = 0;
    cout << "Kiek namu darbu pazymiu turi kiekvienas mokinys?" << endl;
    cin >> x;
    for (int i = 0; i < n; i++) {
        ivestiStudenta(i + 1, x, grupe[i]);
    }
}
void ivedimas(studentasA*& grupe, int& kiekis) {
    char testi = 't';
    int pazLaikinas = 0;
    do{
        int pazKiekis = 0;
        studentasA stud = studentasA();
        ivestiStudenta(kiekis + 1, pazKiekis, stud);
        addToArray(grupe, kiekis, stud);
        cout << "Jei norite testi, iveskite t, jei nenorite testi, iveskite n" << endl;
        cin >> testi;
    } while (testi == 't');
}
void ivedimasCaseTwo(studentasA*& grupe, int& kiekis) {
    char testi = 't';
    do {
        int pazKiekis = 0;
        studentasA stud = studentasA();
        cout << "Iveskite " << kiekis + 1 << " mokinio varda: ";
        cin >> stud.vardas;
        cout << "Iveskite " << kiekis + 1 << " mokinio pavarde: ";
        cin >> stud.pavarde;
        stud.pazymiai = new int[pazKiekis];
        generateRandomGrades(stud);
        addToArray(grupe, kiekis, stud);
        cout << "---------------------------------------------------------" << endl;
        cout << "Jei norite testi, iveskite t, jei nenorite testi, iveskite n" << endl;
        cin >> testi;

    }while (tolower(testi) == 't');
    cout << "---------------------------------------------------------" << endl;
}
void isvedimas(int n, studentasA grupe[]) {
    string vidMed;
    do {
        cout << "Jei norite vidurkio, rasykite 1, jei norite medianos, rasykite 2" << endl;
        cin >> vidMed;
    } while (vidMed != "1" && vidMed != "2");
    
    if (vidMed == "1") {
        cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Vid.)" << endl;
        cout << "---------------------------------------------------------" << endl;

        for (int i = 0; i < n; i++) {
            cout << left << setw(20) << grupe[i].vardas << left << setw(20) << grupe[i].pavarde << left << setw(20) << setprecision(3) << grupe[i].getVidurkis() << endl;
        }

    }
    else if (vidMed == "2") {
        cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Med.)" << endl;
        cout << "---------------------------------------------------------" << endl;

        for (int i = 0; i < n; i++) {
            cout << left << setw(20) << grupe[i].vardas << left << setw(20) << grupe[i].pavarde << left << setw(20) << setprecision(3) << grupe[i].getMediana() << endl;
        }
    }
}
void generateRandomGrades(studentasA &stud) {
    stud.pazymiuKiekis = rand() % 10 + 1;
    stud.pazymiai = new int[stud.pazymiuKiekis];
    for (int i = 0; i < stud.pazymiuKiekis; i++) {
        stud.pazymiai[i] = rand() % 10 + 1;
    }
    stud.egzaminas = rand() % 10 + 1;
}
void generateRandomNames(studentasA& stud) {
    const char* vardas[] = { "Bronius", "Juozas", "Rimas", "Tomas", "Matas", "Markas", "Ignas", "Kristupas", "Joris", "Arnas" };
    const char* pavarde[] = { "Broniauskas", "Juozevicius", "Rimauskas", "Tomavicius", "Matkevicius", "Markevicius", "Igniauskas", "Kristevicius", "Jorevicius", "Arniavicius" };
    int vardasIndex = rand() % 10;
    int pavardeIndex = rand() % 10;
    stud.vardas = vardas[vardasIndex];
    stud.pavarde = pavarde[pavardeIndex];
}
void readNumbers(int*& arr, int& size, int maxItems = 0) {
    string s;
    bool testi = true;
    int notNumbers = 0;
    int badValues = 0;
    if (maxItems > 0) {
        cout << "Iveskite " << maxItems << " pazymius. Noredami baigti ivedima spauskite 0." << endl;
        cout << "---------------------------------------------------------" << endl;
    }
    else {
        cout << "Iveskite pazymius. Noredami baigti ivedima spauskite 0." << endl;
        cout << "---------------------------------------------------------" << endl;
    }
    while (testi) {
        while (s != "0" ) {
            cin >> s;
            try {
                int value = std::stoi(s);
                badValues += value >= 0 && value <= 10 ? 0 : 1;
                if ((size < maxItems || maxItems == 0) && value > 0 && value < 11) {
                    addToArray(arr, size, value);
                }
            }
            catch (...) {
                notNumbers++;
            }
        }
        testi = maxItems > 0 && size < maxItems;
        if (testi) {
            if (notNumbers > 0)
                cout << "Ivestu neteisingu pazymiu skaicius: " << notNumbers << endl;
            if (badValues)
                cout << "Ivestu pazymiu, kurie nera intervale [1,10], skaicius: " << badValues << endl;
            cout << "Trukstamu pazymiu skaicius: " << maxItems - size << ". Teskite ivedima" << endl;
            s = "";
            notNumbers = badValues = 0;
        }
    }
}
