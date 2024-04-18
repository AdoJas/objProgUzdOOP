//
// Created by Adomas on 15/04/2024.
//

#ifndef OOPUZD_STUDENTAS_H
#define OOPUZD_STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include "numeric"
#include <algorithm>
class studentasBase {
protected:
    std::string vardas;
    std::string pavarde;
    float vidurkis;
    float mediana;
    float galutinisVidurkis;
public:
    studentasBase() : vardas(" "), pavarde(" "), vidurkis(0.0), mediana(0.0){};

};

class studentasV : public studentasBase {
public:
    std::vector<double> pazymiai;
    double egzaminas{};
    studentasV() : egzaminas(0.0) {}

    void setVardas(std::string &vardas);
    const std::string getVardas();

    void setPavarde(std::string &pavarde);
    const std::string getPavarde();

    void setNamuDarbai(std::vector<double> &pazRinkinys);
    const std::vector<double> getNamuDarbai();

    void setEgzaminas(int &egzaminas);
    const int getEgzaminas();

    const float setVidurkis();
    const float setMediana();
    const float getVidurkis();
    const float getMediana();
    void setAtsitiktiniaiPazymiai();
    void setAtsitiktiniaiDuomenys();

    ~studentasV();
};

#endif //OOPUZD_STUDENTAS_H
