#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <vector>
#include <numeric>
#include <algorithm>
#include "PazymiaiVectors.h"


using namespace std;

void ivedimas(vector<studentasV>& grupeVector, int n) {
    int x = 0;
    int pazymys = 0;
    cout << "Kiek namu darbu pazymiu turi kiekvienas mokinys?" << endl;
    cin >> x;
    studentasV laikinasV;
    for (int i = 0; i < n; i++) {
        cout << "Iveskite " << i + 1 << " mokinio varda: ";
        cin >> laikinasV.vardas;
        cout << "Iveskite " << i + 1 << " mokinio pavarde: ";
        cin >> laikinasV.pavarde;
        cout << "Iveskite mokinio pazymius: ";
        for(int i = 0; i < x; i++){
            cin >> pazymys;
            laikinasV.pazymiai.push_back(pazymys);
        }
        cout << "Iveskite " << i + 1 << " mokinio egzamino rezultata: ";
        cin >> laikinasV.egzaminas;
        laikinasV.pazSuma = accumulate(laikinasV.pazymiai.begin(), laikinasV.pazymiai.end(), 0);
        laikinasV.pazVid = (x != 0) ? ((laikinasV.pazSuma * 1.0 / x) * 0.4) : 0;
        grupeVector.push_back(laikinasV);
    }
}
void ivedimasNoSize(vector<studentasV>& grupeVector) {
    char testi = 't';
    do {
        studentasV laikinasV;
        cout << "Iveskite " << grupeVector.size() + 1 << " mokinio varda: ";
        cin >> laikinasV.vardas;
        cout << "Iveskite " << grupeVector.size() + 1 << " mokinio pavarde: ";
        cin >> laikinasV.pavarde;

        laikinasV.pazymiai.clear(); 
        int pazymys;
        cout << "Iveskite namu darbu pazymius (0 norint baigti): ";
        while (cin >> pazymys && pazymys != 0) {
            laikinasV.pazymiai.push_back(pazymys);
        }
        cout << "Iveskite egzamino rezultata: ";
        cin >> laikinasV.egzaminas;
        grupeVector.push_back(laikinasV);

        cout << "Ar norite ivesti dar viena studenta? (t/n): ";
        cin >> testi;
    } while (testi == 't' || testi == 'T'); // Allow uppercase T as well
}
void ivedimasCaseTwo(vector<studentasV>& grupeVector) {
    char testi = 't';
    int laikinas = 0;
    studentasV laikinasV;
    do {
        cout << "Iveskite " << laikinas + 1 << " mokinio varda: ";
        cin >> laikinasV.vardas;
        cout << "Iveskite " << laikinas + 1 << " mokinio pavarde: ";
        cin >> laikinasV.pavarde;
        generateRandomGrades(laikinasV);
        grupeVector.push_back(laikinasV);
        laikinas++;
        cout << "Jei norite testi, iveskite t, jei nenorite testi, iveskite n" << endl;
        cin >> testi;
    } while (testi == 't');

}
void generateRandomNames(studentasV &stud) {
    const char* vardas[] = { "Bronius", "Juozas", "Rimas", "Tomas", "Matas", "Markas", "Ignas", "Kristupas", "Joris", "Arnas" };
    const char* pavarde[] = { "Broniauskas", "Juozevicius", "Rimauskas", "Tomavicius", "Matkevicius", "Markevicius", "Igniauskas", "Kristevicius", "Jorevicius", "Arniavicius" };
    int vardasIndex = rand() % 10;
    int pavardeIndex = rand() % 10;
    stud.vardas = vardas[vardasIndex];
    stud.pavarde = pavarde[pavardeIndex];

}
void generateRandomGrades(studentasV &stud) {
    stud.pazymiai.resize(rand() % 10 + 1);
    for (int& paz : stud.pazymiai) {
        paz = rand() % 10 + 1;
    }
    stud.egzaminas = rand() % 10 + 1;
}
void vidurkis(vector<studentasV>& grupeVector) {
    for (int i = 0; i < grupeVector.size(); i++) {
        if (grupeVector[i].pazymiai.empty()) {
            grupeVector[i].pazVid = 0;
        }
        else {
            grupeVector[i].pazVid = accumulate(grupeVector[i].pazymiai.begin(), grupeVector[i].pazymiai.end(), 0) * 0.4;
        }
    }
}
void medianaSkaiciavimasV(vector<studentasV>& grupeVector) {
    for (int i = 0; i < grupeVector.size(); i++){
        if (grupeVector[i].pazymiai.empty()) {
            grupeVector[i].mediana = 0;
        }
        else {
            sort(grupeVector[i].pazymiai.begin(), grupeVector[i].pazymiai.end());
            int size = grupeVector[i].pazymiai.size();
            if (size / 2 == 0) {
                grupeVector[i].mediana = ((grupeVector[i].pazymiai[size / 2 - 1]) + grupeVector[i].pazymiai[size / 2] / 2.0) * 0.4;
            }
            else {
                grupeVector[i].mediana = (grupeVector[i].pazymiai[size / 2])* 0.4;
            }
        }
    }
            
}
void isvedimas(vector<studentasV> grupeVector) {
    string vidMed;
    cout << "Jei norite vidurkio, rasykite 1, jei norite medianos, rasykite 2" << endl;
    cin >> vidMed;
    if (vidMed == "1") {
        cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Vid.)" << endl;
        cout << "--------------------------------------------------" << endl;

        for (int i = 0; i < grupeVector.size(); i++) {
            cout << left << setw(20) << grupeVector[i].vardas << left << setw(20) << grupeVector[i].pavarde << left << setw(20) << setprecision(3) << grupeVector[i].pazVid + grupeVector[i].egzaminas * 0.6 << endl;
        }

    }
    else if (vidMed == "2") {
        cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------" << endl;

        for (int i = 0; i < grupeVector.size(); i++) {
            cout << left << setw(20) << grupeVector[i].vardas << left << setw(20) << grupeVector[i].pavarde << left << setw(20) << setprecision(3) << grupeVector[i].mediana + (grupeVector[i].egzaminas * 0.6) << endl;
        }
    }



}