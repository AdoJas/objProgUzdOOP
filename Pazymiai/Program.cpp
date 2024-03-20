#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <ctime>
#include "PazymiaiVectors.h"
#include "PazymiaiArrays.h"
#include "Common.h"
#include "cstdlib"
#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include "chrono"
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int n = 0; //studentu skaicius
    int x = 0; //pazymiu skaicius
    int i = 0;
    int pasirinkimas = 0;
    int arrVect = 0;
    int laikinas = 0;
    string failas = " ";
    string vidMed;
    vector<studentasV> grupeVector;
    vector<studentasV> grupeBad;
    vector<studentasV> grupeGood;
    double laikasSkaitymas = 0.0;
    double laikasSkaiciavimas = 0.0;
    double laikasRusiavimas = 0.0;
    int fakePazymiai = 0;
    int choice;
do{
    meniu(pasirinkimas);
    switch (pasirinkimas) {
    case 1: {
        printf("Kiek studentu yra grupeje? (iveskite 0, jei norite ivesti neribota kieki)\n");
        cin >> n;
        if (n == 0) {
            ivedimasNoSize(grupeVector);
        }
        else {
            ivedimas(grupeVector, n);
        }
        generalVidurkisCalculate(grupeVector);
        generalMedianaCalculate(grupeVector);
        isvedimas(grupeVector, laikasSkaitymas, laikasSkaiciavimas, laikasRusiavimas, fakePazymiai, 0);
        break;
    }
    case 2: {
        ivedimasCaseTwo(grupeVector);
        printf("Pazymiai sugeneruoti\n");
        generalVidurkisCalculate(grupeVector);
        generalMedianaCalculate(grupeVector);
        isvedimas(grupeVector, laikasSkaitymas, laikasSkaiciavimas, laikasRusiavimas, fakePazymiai, 0);
        break;
    }
    case 3: {
        printf("Kiek studentu yra grupeje?\n");
        cin >> n;
        for (int z = 0; z < n; z++) {
            studentasV stud = studentasV();
            generateRandomNames(stud);
            generateRandomGrades(stud);
            grupeVector.push_back(stud);
        }
        generalVidurkisCalculate(grupeVector);
        generalMedianaCalculate(grupeVector);
        isvedimas(grupeVector, laikasSkaitymas, laikasSkaiciavimas, laikasRusiavimas, fakePazymiai, 0);
        break;
    }
    case 4: {
        printf("Iveskite failo pavadinima\n");
        cin >> failas;
        fileReading(grupeVector, failas, laikasSkaitymas, fakePazymiai, laikasSkaiciavimas);
        isvedimas(grupeVector, laikasSkaitymas, laikasSkaiciavimas, laikasRusiavimas, fakePazymiai, 0);
        break;
    }
    case 5: {
        pasirinkimasVidMed(vidMed);
        sortChoice(choice);
        //pazymiuFailoGeneravimas(grupeVector);
        auto start = std::chrono::high_resolution_clock::now();
        
        for (int i = 0; i < 5; i++) {
            failoNuskaitymasRusiavimas(grupeVector, grupeBad, grupeGood, laikasSkaitymas, laikasSkaiciavimas, i, vidMed);
            isvedimasFailai(grupeGood, grupeBad, i, vidMed, choice);

            for (int i = 0; i < grupeVector.size(); i++) {
                grupeVector[i].pazymiai.clear();
            }
            grupeVector.clear();

            for (int i = 0; i < grupeBad.size(); i++) {
                grupeBad[i].pazymiai.clear();
            }
            grupeBad.clear();

            for (int i = 0; i < grupeGood.size(); i++) {
                grupeGood[i].pazymiai.clear();
            }
            grupeGood.clear();
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        cout << "VIsos programos veikimo trukme:  " << duration.count() << " sek." << endl;
        break;
    }
    case 6: {



        break;
    }    
    case 7:
        printf("Sekmingai baigete darba!!!\n");
        break;

    default:
        printf("Neteisingai ivesti duomenys\n");
    }
    printf("--------------------------------------------------\n");
    if (pasirinkimas == 6) {
        break;
    }
    for (int i = 0; i < grupeVector.size(); i++) {
        grupeVector[i].pazymiai.clear();
    }
    grupeVector.clear();

}while (pasirinkimas != 7);

    return 0;
}
