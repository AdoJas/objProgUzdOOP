#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "PazymiaiArrays.h"
#include "Common.h"

using namespace std;

void ivedimas(int n, int x, studentasA grupe[]) {

    for (int i = 0; i < n; i++) {
        cout << "Iveskite " << i + 1 << " mokinio varda: ";
        cin >> grupe[i].vardas;
        cout << "Iveskite " << i + 1 << " mokinio pavarde: ";
        cin >> grupe[i].pavarde;
        grupe[i].pazymiai = new int[x];
        cout << "Iveskite mokinio pazymius: ";
        float suma = 0.0;
        for (int j = 0; j < x; j++) {
            cin >> grupe[i].pazymiai[j];
            suma += grupe[i].pazymiai[j];
        }

        cout << "Iveskite " << i + 1 << " mokinio egzamino rezultata: ";
        cin >> grupe[i].egzaminas;
        grupe[i].pazVid = ((suma / x) * 0.4) + (grupe[i].egzaminas * 0.6);
    }
      
}
void ivedimas(studentasA*& grupe, int& kiekis) {
    char testi = 't';
    int pazLaikinas;
    int pazKiekis = 0;
    char c;
    do{
        studentasA stud = studentasA();
        cout << "Iveskite " << kiekis + 1 << " mokinio varda: ";
        cin >>stud.vardas;
        cout << "Iveskite " << kiekis + 1 << " mokinio pavarde: ";
        cin >> stud.pavarde;
        cout << "Iveskite mokinio pazymius, jei norite baigti ivedima, iveskite 0: ";
        stud.pazymiai = new int[pazKiekis];
        do {
            cin >> pazLaikinas;
            if (pazLaikinas != 0) {
                addToArray(stud.pazymiai, pazKiekis, pazLaikinas);
            }
        } while (pazLaikinas != 0);
        cout << "Iveskite " << kiekis + 1 << "mokinio egzamino rezultata: ";
        cin >> stud.egzaminas;
        stud.pazymiuKiekis = pazKiekis;
        addToArray(grupe, kiekis, stud);
        cout << "vardas: " << grupe[kiekis - 1].vardas << endl;
        cout << "Jei norite testi, iveskite t, jei nenorite testi, iveskite n" << endl;
        cin >> testi;
    } while (testi == 't');
}
void medianaSkaiciavimas(int n, int x, studentasA grupe[]) {
    int i, j;
    int laikinas = round(x * 1.0 / 2);
    for (int z = 0; z < n; z++) {

        for (i = 0; i < x - 1; i++) {
            for (j = 0; j < x - i - 1; j++) {
                if (grupe[z].pazymiai[j] > grupe[z].pazymiai[j + 1]) {
                    swap(&grupe[z].pazymiai[j], &grupe[z].pazymiai[j + 1]);
                }
            }
        }
        if (x % 2 == 0) {
            grupe[z].mediana = (grupe[z].pazymiai[laikinas] + grupe[z].pazymiai[laikinas - 1]) / 2;
        }
        else {
            grupe[z].mediana = grupe[z].pazymiai[laikinas - 1];
        }
    }
}
void medianaSkaiciavimas(int n, studentasA *&grupe) {
    int i, j;
    int laikinas;
    for (int z = 0; z < n; z++) {

        for (i = 0; i < grupe[z].pazymiuKiekis - 1; i++) {
            for (j = 0; j < grupe[z].pazymiuKiekis - i - 1; j++) {
                if (grupe[z].pazymiai[j] > grupe[z].pazymiai[j + 1]) {
                    swap(&grupe[z].pazymiai[j], &grupe[z].pazymiai[j + 1]);
                }
            }
        }
        laikinas = round(grupe[z].pazymiuKiekis * 1.0 / 2);
        if (grupe[z].pazymiuKiekis % 2 == 0) {
            grupe[z].mediana = (grupe[z].pazymiai[laikinas] + grupe[z].pazymiai[laikinas - 1]) / 2;
        }
        else {
            grupe[z].mediana = grupe[z].pazymiai[laikinas - 1];
        }
    }
}
void isvedimas(int n, studentasA grupe[]) {
    string vidMed;
    cout << "Jei norite vidurkio, rasykite 1, jei norite medianos, rasykite 2" << endl;
    cin >> vidMed;
    if (vidMed == "1") {
        cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Vid.)" << endl;
        cout << "--------------------------------------" << endl;

        for (int i = 0; i < n; i++) {
            cout << left << setw(20) << grupe[i].vardas << left << setw(20) << grupe[i].pavarde << left << setw(20) << setprecision(3) << grupe[i].pazVid << endl;
        }

    }
    else if (vidMed == "2") {
        cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Med.)" << endl;
        cout << "--------------------------------------" << endl;

        for (int i = 0; i < n; i++) {
            cout << left << setw(20) << grupe[i].vardas << left << setw(20) << grupe[i].pavarde << left << setw(20) << setprecision(3) << grupe[i].mediana << endl;
        }
    }
}