#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include "PazymiaiVectors.h"
#include <fstream>
#include <sstream>
#include "chrono"

using namespace std;
float studentasV::getMediana() {
    if (pazymiai.size() < 2) return -1;
    int laikinas = round(pazymiai.size() * 1.0 / 2);
    float med;
    sort(pazymiai.begin(), pazymiai.end());
    if (pazymiai.size() % 2 == 0) {
        med = (pazymiai[laikinas] + pazymiai[laikinas - 1]) * 1.0 / 2;
    }
    else {
        med = pazymiai[laikinas - 1];
    }
    return med * 0.4 + egzaminas * 0.6;
}
float studentasV::getVidurkis() {
    if (pazymiai.empty()) return egzaminas * 0.6;
    return accumulate(pazymiai.begin(), pazymiai.end(), 0) * 1.0 / pazymiai.size() * 0.4 + egzaminas * 0.6;
}


chrono::milliseconds trukmesSkaiciavimas(chrono::high_resolution_clock::time_point pradzia, chrono::high_resolution_clock::time_point pabaiga) {
    auto trukme = chrono::duration_cast<chrono::milliseconds>(pabaiga - pradzia);
    return trukme;
}
//Duomenu ivedimo/nuskaitymo funkcijos
void ivedimasV(vector<studentasV>& grupeVector, studentasV& stud, int studentoNr, int pazymiuKiekis) {
    string s;
    cout << "Iveskite " << studentoNr + 1 << " mokinio varda: ";
    cin >> stud.vardas;
    cout << "Iveskite " << studentoNr + 1 << " mokinio pavarde: ";
    cin >> stud.pavarde;
    cout << "Iveskite mokinio pazymius: ";
    readNumbersV(stud, pazymiuKiekis);
    cout << "Iveskite " << studentoNr + 1 << " mokinio egzamino rezultata: ";
    do {
        cin >> s;
    } while (stoi(s) == true);
        stud.egzaminas = stoi(s);
    grupeVector.push_back(stud);
    cout << grupeVector.size() << " ";
    //stud.pazymiai.clear();
}
void ivedimas(vector<studentasV>& grupeVector, int n) {
    int x = 0;
    cout << "Kiek namu darbu pazymiu turi kiekvienas mokinys?" << endl;
    cin >> x;
    studentasV laikinasV;
    for (int i = 0; i < n; i++) {
        ivedimasV(grupeVector, laikinasV, i, x);
    }
}
void ivedimasNoSize(vector<studentasV>& grupeVector) {
    char testi = 't';
    do {
        studentasV laikinasV;
        ivedimasV(grupeVector, laikinasV, grupeVector.size(), 0);
        cout << "Jei norite testi, iveskite t, jei nenorite testi, iveskite n ";
        cin >> testi;
    } while (testi == 't' || testi == 'T');
}
void ivedimasCaseTwo(vector<studentasV>& grupeVector) {
    char testi = 't';
    studentasV laikinasV;
    do {
        cout << "Iveskite " << grupeVector.size() + 1 << " mokinio varda: ";
        cin >> laikinasV.vardas;
        cout << "Iveskite " << grupeVector.size() + 1 << " mokinio pavarde: ";
        cin >> laikinasV.pavarde;
        generateRandomGrades(laikinasV);
        grupeVector.push_back(laikinasV);
        while(testi != 't' && testi != 'T'){
            cout << "Jei norite testi, iveskite t, jei nenorite testi, iveskite n" << endl;
            cin >> testi;
        }
    } while (testi == 't');

}
void fileReading(vector<studentasV>& grupeVector, const string& failas, double & laikasSkaitymas, int& fakePazymiai){

    ifstream fin;
    fin.open(failas);
    auto start = std::chrono::high_resolution_clock::now();
    if(!fin.is_open()){
        cerr << "Error: nepavyko atidaryti failo" << endl;
        std::exit(EXIT_FAILURE);
    }else{
        cout << "---------------------------------------------------------" << endl;
       
        string line;
        istringstream iss;
        string grade = "";
        getline(fin, line); // nereikalingas line'as pasalinamas

        while(getline(fin,line)){
            iss.str(line);
            studentasV laikinasV;
            iss >> laikinasV.vardas >> laikinasV.pavarde;
            
            while (iss >> grade) {
                try {
                    laikinasV.pazymiai.push_back(std::stoi(grade));
                }
                catch (std::exception& e) {
                    fakePazymiai++;
                }
                
            }
            
            laikinasV.egzaminas = laikinasV.pazymiai.back();
            laikinasV.pazymiai.pop_back();
            grupeVector.push_back(laikinasV);
            iss.clear();
        }
    }
    fin.close();
    auto end = std::chrono::high_resolution_clock::now();
    // Calculate the duration
    std::chrono::duration<double> duration = end - start;
    laikasSkaitymas = duration.count();
    generalVidurkisCalculate(grupeVector);
    generalMedianaCalculate(grupeVector);
    cout << laikasSkaitymas << endl;
}

//Random duomenu generavimo funkcijos
void generateRandomNames(studentasV &stud) {
    const char* vardas[] = { "Bronius", "Juozas", "Rimas", "Tomas", "Matas", "Markas", "Ignas", "Kristupas", "Joris", "Arnas" };
    const char* pavarde[] = { "Broniauskas", "Juozevicius", "Rimauskas", "Tomavicius", "Matkevicius", "Markevicius", "Igniauskas", "Kristevicius", "Jorevicius", "Arniavicius" };
    int vardasIndex = rand() % 10;
    int pavardeIndex = rand() % 10;
    stud.vardas = vardas[vardasIndex];
    stud.pavarde = pavarde[pavardeIndex];
}
void generateRandomGrades(studentasV &stud) {
    stud.pazymiai.resize(rand() % 10 + 1);
    for (int& paz : stud.pazymiai) {
        paz = rand() % 10 + 1;
    }
    stud.egzaminas = rand() % 10 + 1;
}

//General vidurkio/medianos skaiciavimas pasirinkus
void generalVidurkisCalculate(vector<studentasV>& grupeVector) {
    for (auto& student : grupeVector) {
        if (student.pazymiai.empty()) {
            student.pazVid = student.egzaminas * 0.6;
        } else {
            double suma = std::accumulate(student.pazymiai.begin(), student.pazymiai.end(), 0.0);
            student.pazVid = suma / student.pazymiai.size() * 0.4 + student.egzaminas * 0.6;
        }
    }
    cout << "vidurkis apskaiciuotas" << endl;
}
void generalMedianaCalculate(std::vector<studentasV>& grupeVector) {
    
    for (auto& studentas : grupeVector) {
        std::sort(studentas.pazymiai.begin(), studentas.pazymiai.end());

        size_t size = studentas.pazymiai.size();
        if (size % 2 == 0) {
            // For an even number of grades, the median is the average of the two middle grades
            studentas.mediana = (studentas.pazymiai[size / 2 - 1] + studentas.pazymiai[size / 2]) / 2.0 * 0.4 + studentas.egzaminas * 0.6;
        }
        else {
            studentas.mediana = studentas.pazymiai[size / 2] * 0.4 + studentas.egzaminas * 0.6;
        }
    }
}

//Isvedimo funkcija
void isvedimoPasirinkimas(string& pasirinkimasConsole){
    do {
        cout << "Jei norite isvedimo i konsole, rasykite 1, jei norite isvedimo i faila, rasykite 2" << endl;
        cin >> pasirinkimasConsole;
    } while (pasirinkimasConsole != "1" && pasirinkimasConsole != "2");
}
void pasirinkimasVidMed(string& vidMed){
    do {
        cout << "Jei norite isvedimo vidurkio pavidalu, rasykite 1, jei norite isvedimo medianos pavidalu, rasykite 2" << endl;
        cin >> vidMed;
    } while (vidMed != "1" && vidMed != "2");
}
void isvedimas(vector<studentasV> grupeVector, double laikasSkaitymas) {
    int choice = 0;
    string pasirinkimasConsole;
    string vidMed;

    ofstream fout("kursiokai.txt");

    pasirinkimasVidMed(vidMed);
    sortInput(choice, grupeVector, laikasSkaitymas);
    isvedimoPasirinkimas(pasirinkimasConsole);

    if(pasirinkimasConsole == "1"){
        if (vidMed == "1") {
            cout << "Is viso sugaistas laikas nuskaitant duomenis is failo ir juos rusiuojant: " << laikasSkaitymas << "sek. \n";
            cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Vid.)" << endl;
            cout << "--------------------------------------------------" << endl;

            for (auto& student : grupeVector) {
                cout << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.pazVid << endl;
            }
        }
        else if (vidMed == "2") {
            fout << "Is viso sugaistas laikas nuskaitant duomenis is failo ir juos rusiuojant: " << laikasSkaitymas << "sek. \n";
            cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Med.)" << endl;
            cout << "--------------------------------------------------" << endl;

            for (auto& student : grupeVector) {
                cout << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.mediana << endl;
            }
        }
    }else{
        if (vidMed == "1") {
            fout << "Is viso sugaistas laikas nuskaitant duomenis is failo ir juos rusiuojant: " << laikasSkaitymas << "sek. \n";
            fout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Vid.)" << endl;
            fout << "--------------------------------------------------" << endl;

            for (auto& student : grupeVector) {
                fout << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.pazVid << endl;
            }

        }
        else if (vidMed == "2") {
            fout << "Is viso sugaistas laikas nuskaitant duomenis is failo ir juos rusiuojant: " << laikasSkaitymas << "sek. \n";
            fout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Med.)" << endl;
            fout << "--------------------------------------------------" << endl;

            for (auto& student : grupeVector) {
                fout << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.mediana << endl;
            }
        }
    }
    fout.close();
}

//Comparinimo bool funkcijos
bool compareByName(const studentasV& a, const studentasV& b) {
    if (a.vardas.find("Vardas") == 0 && b.vardas.find("Vardas") == 0) {
        int num1 = stoi(a.vardas.substr(6));
        int num2 = stoi(b.vardas.substr(6));
        return num1 > num2;
    }else return a.vardas > b.vardas;
}
bool compareBySurname(const studentasV& a, const studentasV& b) {
    if (a.pavarde.find("Pavarde") == 0 && b.pavarde.find("Pavarde") == 0) {
        int num1 = stoi(a.pavarde.substr(6));
        int num2 = stoi(b.pavarde.substr(6));
        return num1 > num2;
    }else return a.pavarde > b.pavarde;
}
bool compareByAverage(const studentasV& a, const studentasV& b){
    return a.pazVid > b.pazVid;
}
bool compareByMediana(const studentasV& a, const studentasV& b){
    return a.mediana > b.mediana;
}

//Dinaminis pazymiu ivedimas
void readNumbersV(studentasV &stud, int maxItems = 0) {
    string s;
    bool testi = true;
    int notNumbers = 0;
    int badValues = 0;
    if (maxItems > 0) {
        cout << "Iveskite " << maxItems << " pazymius. Noredami baigti ivedima spauskite 0." << endl;
        cout << "---------------------------------------------------------" << endl;
    }
    else {
        cout << "Iveskite pazymius. Noredami baigti ivedima spauskite 0." << endl;
        cout << "---------------------------------------------------------" << endl;
    }
    while (testi) {
        while (s != "0") {
            cin >> s;
            try {
                int value = std::stoi(s);
                badValues += value >= 0 && value <= 10 ? 0 : 1;
                if ((stud.pazymiai.size() < maxItems || maxItems == 0) && value > 0 && value < 11) {
                    stud.pazymiai.push_back(stoi(s));
                }
            }
            catch (...) {
                notNumbers++;
            }
        }
        testi = maxItems > 0 && stud.pazymiai.size() < maxItems;
        if (testi) {
            if (notNumbers > 0)
                cout << "Ivestu neteisingu pazymiu skaicius: " << notNumbers << endl;
            if (badValues)
                cout << "Ivestu pazymiu, kurie nera intervale [1,10], skaicius: " << badValues << endl;
            cout << "Trukstamu pazymiu skaicius: " << maxItems - stud.pazymiai.size() << ". Teskite ivedima" << endl;
            s = "";
            notNumbers = badValues = 0;
        }
    }
}
//Sortinimo funkcija
void sortInput(int& choice, vector<studentasV>& grupeVector, double& laikasSkaitymas){
    auto start = std::chrono::high_resolution_clock::now();
    do{
        printf("Pasirinkite norima rusiavimo buda:\n");
        printf("1- Rusiuoti pagal varda\n ");
        printf("2- Rusiuoti pagal pavarde\n ");
        printf("3- Rusiuoti pagal vidurki\n ");
        printf("4- Rusiuoti pagal mediana\n ");
        cin >> choice;
    }while(choice > 4 || choice < 1);
    switch(choice){
        case 1:
            sort(grupeVector.begin(),grupeVector.end(), compareByName);
            break;
        case 2:
            sort(grupeVector.begin(),grupeVector.end(), compareBySurname);
            break;
        case 3:
            sort(grupeVector.begin(),grupeVector.end(), compareByAverage);
            break;
        case 4:
            sort(grupeVector.begin(),grupeVector.end(), compareByMediana);
            break;
        default:
            cerr << "Error: nepavyko surusiuoti failu!\n";
        }
    auto end = std::chrono::high_resolution_clock::now();
    // Calculate the duration
    std::chrono::duration<double> duration = end - start;
    laikasSkaitymas += duration.count();
}