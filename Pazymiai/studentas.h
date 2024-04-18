//
// Created by Adomas on 15/04/2024.
//

#ifndef OOPUZD_STUDENTAS_H
#define OOPUZD_STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>

class studentasBase {
public:
    std::string vardas;
    std::string pavarde;

};

class studentasVector : public studentasBase {
public:
    std::vector<double> pazymiai;
    double egzaminas{};
    studentasVector() : egzaminas(0.0) {}

    void setVardas(std::string &vardas);
    const std::string getVardas();

    void setPavarde(std::string &pavarde);
    const std::string getPavarde();

    void setNamuDarbai(std::vector<int> &nd);
    const std::vector<int> getNamuDarbai();

    void setEgzaminas(int &egzaminas);
    const int getEgzaminas();

    const float getVidurkis();
    const float getMediana();
    const float galutinisVidurkis(int pasirinkimas);
    void setAtsitiktiniaiPazymiai();
    void setAtsitiktiniaiDuomenys();

    ~studentasVector();
};

#endif //OOPUZD_STUDENTAS_H
