#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include "PazymiaiVectors.h"
#include <fstream>


using namespace std;
float studentasV::getMediana() {
    if (pazymiai.size() < 2) return -1;
    int laikinas = round(pazymiai.size() * 1.0 / 2);
    float med;
    sort(pazymiai.begin(), pazymiai.end());
    if (pazymiai.size() % 2 == 0) {
        med = (pazymiai[laikinas] + pazymiai[laikinas - 1]) * 1.0 / 2;
    }
    else {
        med = pazymiai[laikinas - 1];
    }
    return med * 0.4 + egzaminas * 0.6;
}
float studentasV::getVidurkis() {
    if (pazymiai.empty()) return egzaminas * 0.6;
    return accumulate(pazymiai.begin(), pazymiai.end(), 0) * 1.0 / pazymiai.size() * 0.4 + egzaminas * 0.6;
}

void ivedimasV(vector<studentasV>& grupeVector, studentasV& stud, int studentoNr, int pazymiuKiekis) {
    string s;
    cout << "Iveskite " << studentoNr + 1 << " mokinio varda: ";
    cin >> stud.vardas;
    cout << "Iveskite " << studentoNr + 1 << " mokinio pavarde: ";
    cin >> stud.pavarde;
    cout << "Iveskite mokinio pazymius: ";
    readNumbersV(stud, pazymiuKiekis);
    cout << "Iveskite " << studentoNr + 1 << " mokinio egzamino rezultata: ";
    do {
        cin >> s;
    } while (stoi(s) == true);
        stud.egzaminas = stoi(s);
    grupeVector.push_back(stud);
    cout << grupeVector.size() << " ";
    //stud.pazymiai.clear();
}
void ivedimas(vector<studentasV>& grupeVector, int n) {
    int x = 0;
    cout << "Kiek namu darbu pazymiu turi kiekvienas mokinys?" << endl;
    cin >> x;
    studentasV laikinasV;
    for (int i = 0; i < n; i++) {
        ivedimasV(grupeVector, laikinasV, i, x);
    }
}
void ivedimasNoSize(vector<studentasV>& grupeVector) {
    char testi = 't';
    do {
        studentasV laikinasV;
        ivedimasV(grupeVector, laikinasV, grupeVector.size(), 0);
        cout << "Jei norite testi, iveskite t, jei nenorite testi, iveskite n ";
        cin >> testi;
    } while (testi == 't' || testi == 'T');
}
void ivedimasCaseTwo(vector<studentasV>& grupeVector) {
    char testi = 't';
    int laikinas = 0;
    studentasV laikinasV;
    do {
        cout << "Iveskite " << grupeVector.size() + 1 << " mokinio varda: ";
        cin >> laikinasV.vardas;
        cout << "Iveskite " << grupeVector.size() + 1 << " mokinio pavarde: ";
        cin >> laikinasV.pavarde;
        generateRandomGrades(laikinasV);
        grupeVector.push_back(laikinasV);
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
void isvedimas(vector<studentasV> grupeVector, string& outputFileName) {
    string vidMed;
    do {
        cout << "Jei norite vidurkio, rasykite 1, jei norite medianos, rasykite 2" << endl;
        cin >> vidMed;
    } while (vidMed != "1" && vidMed != "2");

    if (vidMed == "1") {
        cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Vid.)" << endl;
        cout << "--------------------------------------------------" << endl;

        for (int i = 0; i < grupeVector.size(); i++) {
            cout << left << setw(20) << grupeVector[i].vardas << left << setw(20) << grupeVector[i].pavarde << left << setw(20) << setprecision(3) << grupeVector[i].getVidurkis() << endl;
        }

    }
    else if (vidMed == "2") {
        cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------" << endl;

        for (int i = 0; i < grupeVector.size(); i++) {
            cout << left << setw(20) << grupeVector[i].vardas << left << setw(20) << grupeVector[i].pavarde << left << setw(20) << setprecision(3) << grupeVector[i].getMediana() << endl;
        }
    }
}
void readNumbersV(studentasV &stud, int maxItems = 0) {
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
        while (s != "0") {
            cin >> s;
            try {
                int value = std::stoi(s);
                badValues += value >= 0 && value <= 10 ? 0 : 1;
                if ((stud.pazymiai.size() < maxItems || maxItems == 0) && value > 0 && value < 11) {
                    stud.pazymiai.push_back(stoi(s));
                }
            }
            catch (...) {
                notNumbers++;
            }
        }
        testi = maxItems > 0 && stud.pazymiai.size() < maxItems;
        if (testi) {
            if (notNumbers > 0)
                cout << "Ivestu neteisingu pazymiu skaicius: " << notNumbers << endl;
            if (badValues)
                cout << "Ivestu pazymiu, kurie nera intervale [1,10], skaicius: " << badValues << endl;
            cout << "Trukstamu pazymiu skaicius: " << maxItems - stud.pazymiai.size() << ". Teskite ivedima" << endl;
            s = "";
            notNumbers = badValues = 0;
        }
    }
}
void sortInput(int& choice){
    do{
        printf("Pasirinkite norima rusiavimo buda:\n");
        printf("1- Rusiuoti pagal varda\n ");
        printf("2- Rusiuoti pagal pavarde\n ");
        printf("3- Rusiuoti pagal vidurki\n ");
        printf("4- Rusiuoti pagal mediana\n ");
        cin >> choice;
    }while(choice > 4 || choice < 1);
}