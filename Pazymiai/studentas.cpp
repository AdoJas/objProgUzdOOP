//
// Created by Adomas on 15/04/2024.
//
#include "studentas.h"
#include <fstream>



void studentasV::setVardas(std::string vardas) {
    this-> vardas = vardas;
}
std::string studentasV::getVardas() const{
    return vardas;
}
void studentasV::setPavarde(std::string pavarde) {
    this -> pavarde = pavarde;
}
std::string studentasV::getPavarde() const{
    return pavarde;
}
void studentasV::setPazymiai(int pazRinkinys, const std::vector<double> &pazVector) {
    if (pazRinkinys == -1) {

        pazymiai = pazVector;
    } else {
        pazymiai.clear();
        pazymiai.push_back(pazRinkinys);
    }
}
void studentasV::resizePazymiai(int n) {
    pazymiai.resize(n);
}
std::vector<double> studentasV::getPazymiai() const {
    return pazymiai;
}

void studentasV::setEgzaminas(int egzaminas) {
    this -> egzaminas = egzaminas;
}
int studentasV::getEgzaminas() const{
    return egzaminas;
}
void studentasV::setVidurkis(){
    if (pazymiai.empty()) {
        vidurkis = egzaminas * 0.6;
    } else {
        double suma = std::accumulate(pazymiai.begin(), pazymiai.end(), 0.0);
        vidurkis = suma / pazymiai.size() * 0.4 + egzaminas * 0.6;
    }
}
void studentasV::setMediana() {
    std::sort(pazymiai.begin(), pazymiai.end());

    size_t size = pazymiai.size();
    if (size == 0) {
        mediana = -1;
    } else if (size % 2 == 0) {
        mediana = (pazymiai[size / 2 - 1] + pazymiai[size / 2]) / 2.0 * 0.4 + egzaminas * 0.6;
    } else {
        mediana = pazymiai[size / 2] * 0.4 + egzaminas * 0.6;
    }
}
float studentasV::getVidurkis() const{
    return vidurkis;
}
float studentasV::getMediana() const{
    return mediana;
}
void studentasV::setAtsitiktiniaiPazymiai() {
    pazymiai.resize(rand() % 10 + 1);
    for (double & paz : pazymiai) {
        paz = rand() % 10 + 1;
    }
    egzaminas = rand() % 10 + 1;
}
void studentasV::setAtsitiktiniaiDuomenys() {
    setAtsitiktiniaiPazymiai(); // Assuming this function sets pazymiai

    const std::vector<std::string> vardai = { "Bronius", "Juozas", "Rimas", "Tomas", "Matas", "Markas", "Ignas", "Kristupas", "Joris", "Arnas" };
    const std::vector<std::string> pavardes = { "Broniauskas", "Juozevicius", "Rimauskas", "Tomavicius", "Matkevicius", "Markevicius", "Igniauskas", "Kristevicius", "Jorevicius", "Arniavicius" };

    int vardasIndex = rand() % vardai.size();
    int pavardeIndex = rand() % pavardes.size();

    this->vardas = vardai[vardasIndex];
    this->pavarde = pavardes[pavardeIndex];
}
studentasV::~studentasV(){
    pazymiai.clear();
};