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
    std::vector<int> pazymiai;
    double egzaminas{};
public:

    studentasV() : egzaminas(0.0) {}

    void setVardas(std::string vardas);
    std::string getVardas() const;

    void setPavarde(std::string pavarde);
    std::string getPavarde() const;

    void setPazymiaiVector(const std::vector<int> &pazVector);
    void setPazymiai(int paz);
    std::vector<int> getPazymiai() const;
    void resizePazymiai(int n);
    void setEgzaminas(int egzaminas);
    int getEgzaminas() const;

    void setVidurkis();
    void setMediana();
    float getVidurkis() const;
    float getMediana() const;
    void setAtsitiktiniaiPazymiai();
    void setAtsitiktiniaiDuomenys();

    //Rule of Five headers
    studentasV(const studentasV &kita); //Kopijavimo konstruktorius
    studentasV &operator=(const studentasV &kita); //Priskyrimo konstruktorius
    studentasV(studentasV &&kita) noexcept; //Perkelimo konstruktorius
    studentasV &operator=(studentasV &&kita) noexcept; //Perkelimo priskyrimo konstruktorius
    ~studentasV(); //Destruktorius
    std::string vardas;
};

#endif //OOPUZD_STUDENTAS_H
