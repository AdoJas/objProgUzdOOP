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
void medianaSkaiciavimas(int n, int x, studentas grupe[]);
void isvedimas(int n, int x, studentas grupe[]);
void swap(float* var1, float* var2);
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
    medianaSkaiciavimas(n, x, grupe);
    isvedimas(n, x, grupe);

    for (int i = 0; i < n; i++) {
        delete[] grupe[i].pazymiai;
    }
    delete[] grupe;
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
void medianaSkaiciavimas(int n, int x, studentas grupe[]) {
    int i, j;
    int laikinas = round(x * 1.0 / 2);
    for (int z = 0; z < n; z++) {

        for (i = 0; i < x - 1; i++) {
            for (j = 0; j < x - i - 1; j++) {
                if (grupe[z].pazymiai[j] > grupe[z].pazymiai[j + 1]) {
                    swap(&grupe[z].pazymiai[j], &grupe[z].pazymiai[j + 1]);
                }
            }
        }
        if (x % 2 == 0) {
            grupe[z].mediana = (grupe[z].pazymiai[laikinas] + grupe[z].pazymiai[laikinas - 1]) / 2;
        }
        else {
            grupe[z].mediana = grupe[z].pazymiai[laikinas - 1];
        }
    }
}
void isvedimas(int n, int x, studentas grupe[]) {
    string vidMed;
    cout << "Jei norite vidurkio, rasykite 1, jei norite medianos, rasykite 2" << endl;
    cin >> vidMed;
    if (vidMed == "1") {
        cout << "Vardas" << setw(10) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << endl;
        cout << "--------------------------------------" << endl;

        for (int i = 0; i < n; i++) {
            cout << grupe[i].vardas << setw(10) << grupe[i].pavarde << setw(15) << setprecision(3) << grupe[i].mediana << endl;
        }

    }

    else if (vidMed == "2") {
        cout << "Vardas" << setw(10) << "Pavarde" << setw(20) << "Galutinis (Med.)" << endl;
        cout << "--------------------------------------" << endl;

        for (int i = 0; i < n; i++) {
            cout << grupe[i].vardas << setw(10) << grupe[i].pavarde << setw(15) << setprecision(3) << grupe[i].mediana << endl;
        }
    }
}
void swap(float* var1, float* var2)
{
    float temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}

