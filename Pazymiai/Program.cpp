#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include "PazymiaiVectors.h"
#include "PazymiaiArrays.h"
#include "Common.h"


using namespace std;

int main()
{
    
    int n = 0; //studentu skaicius
    int x = 0; //pazymiu skaicius

    cout << "Kiek studentu yra grupeje? (iveskite 0, jei norite ivesti neribota kieki)" << endl;
    cin >> n;
    studentasA* grupe = new studentasA[n];
    if (n == 0) {
        ivedimas(grupe, n);
        vidurkis(n, grupe);
        medianaSkaiciavimas(n, grupe);
    }
    else {
        cout << "Kiek namu darbu pazymiu turi kiekvienas mokinys?" << endl;
        cin >> x;

        ivedimas(n, x, grupe);
        medianaSkaiciavimas(n, x, grupe);
    }

    isvedimas(n, grupe);

    for (int i = 0; i < n; i++) {
        delete[] grupe[i].pazymiai;
    }
    delete[] grupe;
}