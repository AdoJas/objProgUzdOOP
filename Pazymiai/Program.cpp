#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <ctime>
#include "PazymiaiVectors.h"
#include "PazymiaiArrays.h"
#include "PazymiaiList.h"
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
    int fakePazymiai;
    int choice = 0;
do{
    meniu(pasirinkimas);
    pasirinkimas = 0;
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
        vektoriaiMain(vidMed, choice, grupeVector, grupeBad, grupeGood);
        break;
    }
    case 6: {
        meniuKonteineriai(pasirinkimas);
        switch (pasirinkimas) {
        case 1: {
            vektoriaiMain(vidMed, choice, grupeVector, grupeBad, grupeGood);
        }
        case 2: {

        }

        }


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
