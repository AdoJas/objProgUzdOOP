#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <ctime>
#include "PazymiaiVectors.h"
#include "PazymiaiArrays.h"
#include "PazymiaiList.h"
#include "PazymiaiDeque.h"
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
    int fakePazymiai;
    int ivedimasList = 0;
    int arrVect = 0;
    int laikinas = 0;

    double laikasSkaitymas = 0.0;
    double laikasSkaiciavimas = 0.0;
    double laikasRusiavimas = 0.0;

    string pasirinkimas = " ";
    string containerPasirinkimas = " ";
    string failas = " ";
    string vidMed;
    string choice = " ";
    string ivedimasKonteineris = " ";
    string failoGeneravimoPasirinkimas = " ";

    vector<studentasV> grupeVector;
    vector<studentasV> grupeBad;
    vector<studentasV> grupeGood;

    list<studentasL> grupeList;
    list<studentasL> grupeListBad;
    list<studentasL> grupeListGood;

    deque<studentasD> grupeDeque;
    deque<studentasD> grupeDequeGood;
    deque<studentasD> grupeDequeBad;

do{
    meniu(pasirinkimas);
    //pasirinkimas = 0;
    switch (stoi(pasirinkimas)) {
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
        do {
            cout << "Ar norite generuoti failus?" << endl;
            cout << "1 - taip" << endl;
            cout << "2 - ne" << endl;
            cin >> failoGeneravimoPasirinkimas;
        } while (failoGeneravimoPasirinkimas != "1" || failoGeneravimoPasirinkimas != "2");

        if (failoGeneravimoPasirinkimas == "1")
            pazymiuFailoGeneravimas();

        vektoriaiMain(vidMed, choice, grupeVector, grupeBad, grupeGood, ivedimasKonteineris);
        break;
    }
    case 6: {
        do {
            cout << "Ar norite generuoti failus?" << endl;
            cout << "1 - taip" << endl;
            cout << "2 - ne" << endl;
            cin >> failoGeneravimoPasirinkimas;
        } while (failoGeneravimoPasirinkimas != "1" && failoGeneravimoPasirinkimas != "2");

        if (failoGeneravimoPasirinkimas == "1")
            pazymiuFailoGeneravimas();


        meniuKonteineriai(containerPasirinkimas);
        switch (stoi(containerPasirinkimas)) {
        case 1: {
            cout << "Vector konteineris" << endl;
            vektoriaiMain(vidMed, choice, grupeVector, grupeBad, grupeGood, ivedimasKonteineris);
            ivedimasKonteineris.clear();
            break;
        }
        case 2: {
            cout << "List konteineris" << endl;

            listMain(vidMed, choice, grupeList, grupeListBad, grupeListGood, ivedimasKonteineris);
            ivedimasKonteineris.clear();
            break;
        }
        case 3: {
            cout << "Deque konteineris" << endl;
            dequeMain(vidMed, choice, grupeDeque, grupeDequeBad, grupeDequeGood, ivedimasKonteineris);
            ivedimasKonteineris.clear();
            break;
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
    //printf("--------------------------------------------------\n");
    if (stoi(pasirinkimas) == 7) {
        break;
    }
    for (int i = 0; i < grupeVector.size(); i++) {
        grupeVector[i].pazymiai.clear();
    }
    grupeVector.clear();

}while (stoi(pasirinkimas) != 7);

    return 0;
}
