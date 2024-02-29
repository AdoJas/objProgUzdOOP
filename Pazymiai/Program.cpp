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
    int fakePazymiai = 0;
    double laikasSkaitymas = 0.0;
    double laikasSkaiciavimas = 0.0;
    double laikasRusiavimas = 0.0;
    string failas = " ";
    studentasA* grupe = nullptr;
    vector<studentasV> grupeVector;

do{
    meniu(pasirinkimas);
    switch (pasirinkimas) {
    case 1:
        printf("Kiek studentu yra grupeje? (iveskite 0, jei norite ivesti neribota kieki)\n");
        cin >> n;
        if (n == 0) {
            ivedimasNoSize(grupeVector);
        }
        else {
            ivedimas(grupeVector, n);
        }
        isvedimas(grupeVector, laikasSkaitymas, laikasSkaiciavimas, laikasRusiavimas);
        break;
    case 2:
        ivedimasCaseTwo(grupeVector);
        printf("Pazymiai sugeneruoti\n");

        isvedimas(grupeVector, laikasSkaitymas, laikasSkaiciavimas, laikasRusiavimas);
        break;
    case 3:

        printf("Kiek studentu yra grupeje?\n");
        cin >> n;
        for (int z = 0; z < n; z++) {
            studentasV stud = studentasV();
            generateRandomNames(stud);
            generateRandomGrades(stud);
            grupeVector.push_back(stud);
        }
        isvedimas(grupeVector, laikasSkaitymas, laikasSkaiciavimas, laikasRusiavimas);
        break;
    case 4:
        printf("Iveskite failo pavadinima\n");
        cin >> failas;
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        fileReading(grupeVector, failas, laikasSkaitymas, fakePazymiai, laikasSkaiciavimas);

        isvedimas(grupeVector, laikasSkaitymas, laikasSkaiciavimas, laikasRusiavimas);
        break;

    case 5:
        printf("Sekmingai baigete darba!!!\n");
        break;
    default:
        printf("Neteisingai ivesti duomenys\n");
    }

    printf("--------------------------------------------------\n");
    if (pasirinkimas == 5) {
        break;
    }
    for (int i = 0; i < grupeVector.size(); i++) {
        grupeVector[i].pazymiai.clear();
    }
    grupeVector.clear();

}while (pasirinkimas != 5);

    return 0;
}
