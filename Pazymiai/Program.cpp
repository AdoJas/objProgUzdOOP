#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include "PazymiaiVectors.h"
#include "PazymiaiArrays.h"


using namespace std;

int main()
{
    int n = 0; //studentu skaicius
    int x = 0; //pazymiu skaicius

    cout << "Kiek studentu yra grupeje?" << endl;
    cin >> n;
    studentasA* grupe = new studentasA[n];

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