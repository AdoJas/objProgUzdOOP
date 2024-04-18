//
// Created by Adomas on 15/04/2024.
//
#include "studentas.h"
#include <fstream>
double mediana(std::vector<double>){

}

void studentasVector::readStudent(std::istream& is) {
    std::string laikinasPaz;
    if (!(is >> vardas)) {
        std::cerr << "Nepavyko nuskaityti duomenų iš failo!" << std::endl;
        return;
    }
    is >> pavarde >> egzaminas;
    while (is >> laikinasPaz) {
        try {
            int pazymys = std::stoi(laikinasPaz);
            if (pazymys >= 0 && pazymys <= 10) {
                pazymiai.push_back(pazymys);
            }
        }
        catch (const std::exception& e) {
        }
    }
    egzaminas = pazymiai.back();
    pazymiai.pop_back();
}
