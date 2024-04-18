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
    double egzaminas;

};
class studentasVector : public studentasBase{
    std::vector<double> pazymiai;
    studentasVector() : egzaminas(0) { }
    studentasVector(std::istream& is);
    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
    double galBalas(double (*) (std::vector<double>)) const;
    void readStudent(std::istream&);

};

#endif //OOPUZD_STUDENTAS_H
