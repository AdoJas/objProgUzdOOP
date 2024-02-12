#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>

using namespace std;

struct studentas {
    string vardas;
    string pavarde;
    float* pazymiai;
    float pazVid = 0;
    float egzaminas = 0;
    float mediana = 0;
}; 

int main()
{
    int n = 0; //studentu skaicius
    int x = 0; //pazymiu skaicius

    cout << "Kiek studentu yra grupeje?" << endl;
    cin >> n;
    studentas* grupe = new studentas[n];

    cout << "Kiek namu darbu pazymiu turi kiekvienas mokinys?" << endl;
    cin >> x;

}


