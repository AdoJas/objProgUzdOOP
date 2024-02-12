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

void ivedimas(int n, int x, studentas grupe[]);

int main()
{
    int n = 0; //studentu skaicius
    int x = 0; //pazymiu skaicius

    cout << "Kiek studentu yra grupeje?" << endl;
    cin >> n;
    studentas* grupe = new studentas[n];

    cout << "Kiek namu darbu pazymiu turi kiekvienas mokinys?" << endl;
    cin >> x;

    ivedimas(n, x, grupe);
}
void ivedimas(int n, int x, studentas grupe[]) {

    for (int i = 0; i < n; i++) {
        cout << "Iveskite " << i + 1 << " mokinio varda: ";
        cin >> grupe[i].vardas;
        cout << "Iveskite " << i + 1 << " mokinio pavarde: ";
        cin >> grupe[i].pavarde;
        grupe[i].pazymiai = new float[x];
        cout << "Iveskite mokinio pazymius: ";
        float suma = 0.0;
        for (int j = 0; j < x; j++) {
            cin >> grupe[i].pazymiai[j];
            suma += grupe[i].pazymiai[j];
        }

        cout << "Iveskite " << i + 1 << " mokinio egzamino rezultata: ";
        cin >> grupe[i].egzaminas;
        grupe[i].pazVid = ((suma / x) * 0.4) + (grupe[i].egzaminas * 0.6);
    }
      
}

