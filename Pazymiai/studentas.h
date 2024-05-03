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
class Zmogus {
public:
    virtual void setVardas(std::string vardas) = 0;
    virtual std::string getVardas() const = 0;
    virtual void setPavarde(std::string pavarde) = 0;
    virtual std::string getPavarde() const = 0;
    virtual ~Zmogus() = default;
};

class studentasV : public Zmogus {
private:
    std::string vardas = " ";
    std::string pavarde = " ";
    float vidurkis = 0.0;
    float mediana = 0.0;
    std::vector<int> pazymiai;
    double egzaminas{};
public:

    studentasV() : egzaminas(0.0) {}

    void setVardas(std::string vardas) override;
    std::string getVardas() const override;

    void setPavarde(std::string pavarde) override;
    std::string getPavarde() const override;

    void setPazymiaiVector(std::vector<int> pazVector);
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

//    //Rule of Five headers
    studentasV(const studentasV &kita); //Kopijavimo konstruktorius
    studentasV &operator=(const studentasV &kita); //Priskyrimo konstruktorius
    studentasV(studentasV &&kita) noexcept; //Perkelimo konstruktorius
    studentasV &operator=(studentasV &&kita) noexcept; //Perkelimo priskyrimo konstruktorius
    ~studentasV(); //Destruktorius

    friend std::ostream &operator<<(std::ostream &os, const studentasV &studentas);
    friend std::istream &operator>>(std::istream &is, studentasV &studentas);
};

#endif //OOPUZD_STUDENTAS_H
