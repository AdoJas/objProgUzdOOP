#include <iostream>
#include <string>
#include <ctime>
#include "PazymiaiVectors.h"
#include "Common.h"
#include <stdlib.h>
#include "studentas.h"
#include "vectorClass.h"
#include "math.h"
#include <chrono>
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

    Vector<studentasV> grupeVector;
    Vector<studentasV> grupeBad;
    Vector<studentasV> grupeGood;

    //Atkomentavus gauname errora, Zmogus yra abstrakti klase
    //Zmogus grupeZmogus;

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
            grupeVector.PushBack(stud);
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
        int alokacijaSTD = 0, alokacijaVector = 0;
        for(int x = 0; x < 5; x++){
            auto start = std::chrono::high_resolution_clock::now();
                unsigned int sz = pow(10, 3+x);
                std::vector<int> v1;
                for (int i = 1; i <= sz; ++i){
                    v1.push_back(i);
                    if(v1.size() == v1.capacity()){
                        ++alokacijaSTD;
                }
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end-start;
            cout << "std::vector<int> " << sz << " elementu: " << diff.count() << " s\n";
            cout << "Alokacijos std::vector<int>: " << alokacijaSTD << endl;
            alokacijaSTD = 0;
        }
        cout<< "--------------------------------" << endl;
        for(int x = 0; x < 5; x++){
            auto start = std::chrono::high_resolution_clock::now();
            unsigned int sz = pow(10, 3+x);
            Vector<int> v1;
            for (int i = 1; i <= sz; ++i){
                v1.PushBack(i);
                if(v1.Size() == v1.Capacity()){
                    alokacijaVector++;
                }
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end-start;
            cout << "Vector<int> " << sz << " elementu: " << diff.count() << " s\n";
            cout << "Alokacijos Vector<int>: " << alokacijaVector << endl;
            alokacijaVector = 0;
        }

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

    grupeVector.Clear();

}while (stoi(pasirinkimas) != 8);

    return 0;
}
