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
public:
    studentasBase() : vardas(" "), pavarde(" "), vidurkis(0.0), mediana(0.0){};

};

class studentasV : public studentasBase {
private:
    std::vector<double> pazymiai;
    double egzaminas{};
public:
    studentasV() : egzaminas(0.0) {}

    void setVardas(std::string vardas);
    std::string getVardas() const;

    void setPavarde(std::string pavarde);
    std::string getPavarde() const;

    void setPazymiai(int pazRinkinys, const std::vector<double> &pazVector);
    std::vector<double> getPazymiai() const;
    void resizePazymiai(int n);
    void setEgzaminas(int egzaminas);
    int getEgzaminas() const;

    void setVidurkis();
    void setMediana();
    float getVidurkis() const;
    float getMediana() const;
    void setAtsitiktiniaiPazymiai();
    void setAtsitiktiniaiDuomenys();

    ~studentasV();
};

#endif //OOPUZD_STUDENTAS_H
