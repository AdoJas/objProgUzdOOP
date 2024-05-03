#include <iostream>
#include <string>
#include <ctime>
#include "PazymiaiVectors.h"
#include "Common.h"
#include <stdlib.h>
#include "studentas.h"
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
    vector<Zmogus> grupeZmogus;
    grupeZmogus[0].setVardas("adomas");
    cout << grupeZmogus[0].getVardas() << endl;

do{
    meniu(pasirinkimas);
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
        } while (failoGeneravimoPasirinkimas != "1" && failoGeneravimoPasirinkimas != "2");

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

        if (failoGeneravimoPasirinkimas == "1"){
            pazymiuFailoGeneravimas();
        }

        cout << "Vector konteineris" << endl;
        vektoriaiMain(vidMed, choice, grupeVector, grupeBad, grupeGood, ivedimasKonteineris);
        ivedimasKonteineris.clear();
        break;

    }
    case 7:{
        try{
            studentasV pirminis;
            vector<int> nd = {10, 2};
            pirminis.setPazymiai(8);
            pirminis.setPazymiaiVector(nd);
            pirminis.setEgzaminas(10);

            // Kopijavimo konstruktorius
            studentasV copy(pirminis);
            cout << "Copy Constructor: " << copy << endl;
            cout << "Original Object: " << pirminis << endl;

            // Kopijavimo priskyrimo
            studentasV kopPrisk;
            kopPrisk = pirminis;
            cout << "Copy Assignment: " << kopPrisk << endl;
            cout << "Original Object: " << pirminis << endl;

            // Perkelimo konstruktorius
            studentasV perkelimas(std::move(pirminis));
            cout << "Move konstruktorius: " << perkelimas << endl;
            cout << "Pradinis objektas po perkelimo: " << pirminis << endl;

            // Perkelimo priskyrimo
            studentasV perkeltas;
            perkeltas = std::move(perkelimas);
            cout << "perkelimas priskyrimas: " << perkeltas << endl;
            cout << "pradinis objektas po perkelimo: " << perkelimas << endl;

            cout << "ROF testai pereiti sekmingai!" << endl;
        }catch(...){
            cerr << "ROF testai nepereiti" << endl;
        }
        break;
    }
    case 8:{
        printf("Sekmingai baigete darba!!!\n");
        return 0;
        break;
    }
    default:{
        printf("Neteisingai ivesti duomenys\n");
        return 0;
        break;
    }

    }
    printf("--------------------------------------------------\n");
    if (stoi(pasirinkimas) == 8) {
        break;
    }

    grupeVector.clear();

}while (stoi(pasirinkimas) != 8);

    return 0;
}
