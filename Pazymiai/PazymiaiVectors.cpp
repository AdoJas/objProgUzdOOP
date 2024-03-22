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
#include "common.h"

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

double laikasSkaitymas = 0.0;
double laikasSkaiciavimas = 0.0;
double laikasRusiavimas = 0.0;
int fakePazymiai = 0;

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
    do{
        stud.egzaminas = stoi(s);
    }while(stoi(s) > 10);
    grupeVector.push_back(stud);
    cout << grupeVector.size() << " ";
}
void ivedimas(vector<studentasV>& grupeVector, int n) {
    int x = 0;
    do {
        cout << "Kiek namu darbu pazymiu turi kiekvienas mokinys?(Bent 1 paz.)" << endl;
        cin >> x;
    }while(x < 1);
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
void fileReading(vector<studentasV>& grupeVector, string failas, double & laikasSkaitymas, int& fakePazymiai, double& laikasSkaiciavimas){
    ifstream fin;
    do{
        fin.open(failas);
        if (!fin.is_open()) {
            cerr << "Error: nepavyko atidaryti failo!!!\nIveskite failo pavadinima is naujo!!!\n" << endl;
            cin >> failas;
        }
    } while (!fin.is_open());
    auto start = std::chrono::high_resolution_clock::now();
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
                    if(stoi(grade) >= 0 && stoi(grade) <= 10) {
                        laikinasV.pazymiai.push_back(std::stoi(grade));
                    }
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
    fin.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    laikasSkaitymas = duration.count();

    auto skStart = std::chrono::high_resolution_clock::now();

    generalVidurkisCalculate(grupeVector);
    generalMedianaCalculate(grupeVector);

    auto skEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> skDuration = skEnd - skStart;
    laikasSkaiciavimas = skDuration.count();
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
}
void generalMedianaCalculate(std::vector<studentasV>& grupeVector) {
    
    for (auto& studentas : grupeVector) {
        std::sort(studentas.pazymiai.begin(), studentas.pazymiai.end());

        size_t size = studentas.pazymiai.size();
        if (size < 2) studentas.mediana = -1;
        if (size % 2 == 0) {
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

void isvedimas(vector<studentasV> grupeVector, double laikasSkaitymas, double laikasSkaiciavimas, double laikasRusiavimas, int fakePazymiai, int iteracija) {
    string choice = " ";
    string pasirinkimasConsole;
    string vidMed;
    string custom = " ";
    ofstream fout("KursiokaiNesugeneruotas" + to_string(iteracija+1) + ".txt");

    pasirinkimasVidMed(vidMed);
    cout << "--------------------------------------------------" << endl;
    sortInput(choice, grupeVector, laikasSkaitymas);
    cout << "--------------------------------------------------" << endl;
    isvedimoPasirinkimas(pasirinkimasConsole);
    cout << "--------------------------------------------------" << endl;

    if(pasirinkimasConsole == "1"){
        if (vidMed == "1") {
            laikoIsvedimas(laikasSkaitymas, laikasSkaiciavimas, laikasRusiavimas);
            cout << "--------------------------------------------------" << endl;
            cout << "Rasta blogu duomenu " << fakePazymiai << "\n";
            cout << "--------------------------------------------------" << endl;
            cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Vid.)" << endl;
            cout << "--------------------------------------------------" << endl;

            for (auto& student : grupeVector) {
                cout << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.pazVid << endl;
            }
        }
        else if (vidMed == "2") {
            laikoIsvedimas(laikasSkaitymas, laikasSkaiciavimas, laikasRusiavimas);
            cout << "--------------------------------------------------" << endl;
            cout << "Rasta blogu duomenu " << fakePazymiai << "\n";
            cout << "--------------------------------------------------" << endl;
            cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Med.)" << endl;
            cout << "--------------------------------------------------" << endl;

            for (auto& student : grupeVector) {
                cout << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.mediana << endl;
            }
        }
    }else{
        if (vidMed == "1") {
            fout << "Is viso sugaistas laikas nuskaitant duomenis is failo: " << laikasSkaitymas << "sek. \n";
            fout << "Is viso sugaistas laikas  atliekant skaiciavimus: " << laikasSkaitymas << "sek. \n";
            fout << "Is viso sugaistas laikas rusiuojant duomenis: " << laikasSkaiciavimas << "sek. \n";
            fout << "Viso sugaista laiko: " << laikasSkaitymas + laikasSkaitymas + laikasSkaiciavimas << "sek. \n";
            fout << "--------------------------------------------------" << endl;
            fout << "Rasta blogu duomenu " << fakePazymiai << "\n";
            fout << "--------------------------------------------------" << endl;
            fout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Vid.)" << endl;
            fout << "--------------------------------------------------" << endl;

            for (auto& student : grupeVector) {
                fout << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.pazVid << endl;
            }

        }
        else if (vidMed == "2") {
            fout << "Is viso sugaistas laikas nuskaitant duomenis is failo: " << laikasSkaitymas << "sek. \n";
            fout << "Is viso sugaistas laikas  atliekant skaiciavimus: " << laikasSkaitymas << "sek. \n";
            fout << "Is viso sugaistas laikas rusiuojant duomenis: " << laikasSkaiciavimas << "sek. \n";
            fout << "Viso sugaista laiko: " << laikasSkaitymas + laikasSkaitymas + laikasSkaiciavimas << "sek. \n";
            fout << "--------------------------------------------------" << endl;
            fout << "Rasta blogu duomenu " << fakePazymiai << "\n";
            fout << "--------------------------------------------------" << endl;
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
    }else return a.vardas < b.vardas;
}
bool compareBySurname(const studentasV& a, const studentasV& b) {
    if (a.pavarde.find("Pavarde") == 0 && b.pavarde.find("Pavarde") == 0) {
        int num1 = stoi(a.pavarde.substr(7));
        int num2 = stoi(b.pavarde.substr(7));
        return num1 > num2;
    }else return a.pavarde < b.pavarde;
}
bool compareByAverage(const studentasV& a, const studentasV& b){
    return a.pazVid < b.pazVid;
}
bool compareByMediana(const studentasV& a, const studentasV& b){
    return a.mediana < b.mediana;
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
void sortInput(string& choice, vector<studentasV>& grupeVector, double& laikasRusiavimas){
    auto start = std::chrono::high_resolution_clock::now();
    switch(stoi(choice)){
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
            cerr << "Klaida: nepavyko surusiuoti failu!\n";
        }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    laikasRusiavimas = duration.count();
}

void laikoIsvedimas(double laikasSkaitymas, double laikasSkaiciavimas, double laikasRusiavimas) {
        cout << "Is viso sugaistas laikas nuskaitant duomenis is failo: " << laikasSkaitymas << "sek. \n";
        cout << "Is viso sugaistas laikas  atliekant skaiciavimus: " << laikasSkaitymas << "sek. \n";
        cout << "Is viso sugaistas laikas rusiuojant duomenis: " << laikasSkaiciavimas << "sek. \n";
        cout << "Viso sugaista laiko: " << laikasSkaitymas + laikasSkaitymas + laikasSkaiciavimas << "sek. \n";
}
void studentuGeneravimas(vector<studentasV>& grupeVector, studentasV& stud, int kiekis) {
    for (int i = 1; i <= kiekis; i++) {
        stud.vardas = "Vardas" + to_string(i);
        stud.pavarde = "Pavarde" + to_string(i);
        stud.pazymiai.resize(rand() % 10 + 1);
        for (int& paz : stud.pazymiai) {
            paz = rand() % 10 + 1;
        }
        stud.egzaminas = rand() % 10 + 1;
        grupeVector.push_back(stud);
    }
    
}
void pazymiuFailoGeneravimas() {
    for (int i = 0; i < 5; i++) {
        //studentasV stud = studentasV();
        failoGeneravimasIsvedimas(i);
        cout << "Duomenys isvesti i faila!!!!" << endl;
        cout << "--------------------------------------------------" << endl;
    }
}
void failoNuskaitymasRusiavimas(vector<studentasV>& grupeVector, vector<studentasV>& grupeBad, vector<studentasV>& grupeGood, double& laikasSkaitymas, double& laikasSkaiciavimas, int i, string vidMed) {
    fileReading(grupeVector, "KursiokaiGen" + to_string(i + 1) + ".txt", laikasSkaitymas, fakePazymiai, laikasSkaiciavimas);

    auto start = std::chrono::high_resolution_clock::now();

    if (vidMed == "1") {
        auto it = std::partition(grupeVector.begin(), grupeVector.end(), [](const studentasV& student) {
            return student.pazVid >= 5;
            });

        grupeGood.insert(grupeGood.end(), grupeVector.begin(), it);
        grupeBad.insert(grupeBad.end(), it, grupeVector.end());
    }
    else {
        auto it = std::partition(grupeVector.begin(), grupeVector.end(), [](const studentasV& student) {
            return student.mediana >= 5;
            });

        grupeGood.insert(grupeGood.end(), grupeVector.begin(), it);
        grupeBad.insert(grupeBad.end(), it, grupeVector.end());
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Studentu nuskaitymas is failo  " << laikasSkaitymas << " sek." << std::endl;
    std::cout << "Studentu duomenu apskaiciavimas truko:  " << laikasSkaiciavimas << " sek." << std::endl;
    std::cout << "Studentu rusiavimas i du konteinerius truko:  " << duration.count() << " sek." << std::endl;
}
void isvedimasFailai(vector<studentasV> grupeVector, vector<studentasV> grupeBad,int i, string& vidMed, string& choice) {

        ofstream fout("KursiokaiGood" + to_string(i + 1) + ".txt");
        ofstream foutB("KursiokaiBad" + to_string(i + 1) + ".txt");

        stringstream bufferis;
        stringstream bufferisB;
        auto start = std::chrono::high_resolution_clock::now();
        sortInput(choice, grupeVector, laikasSkaitymas);
        sortInput(choice, grupeBad, laikasSkaitymas);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        cout << "Abieju studentu konteineriu rusiavimas pagal pasirinkima :  " << duration.count() << " sek." << endl;
        auto start1 = std::chrono::high_resolution_clock::now();
        if (vidMed == "1") {
            bufferis << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Vid.)" << endl;
            bufferis << "--------------------------------------------------" << endl;

            for (auto& student : grupeVector) {
                bufferis << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.pazVid << endl;
            }
            fout << bufferis.str();
            bufferis.str(""); 
            bufferis.clear(); 
        }
        else if (vidMed == "2") {
            bufferis << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Med.)" << endl;
            bufferis << "--------------------------------------------------" << endl;

            for (auto& student : grupeVector) {
                bufferis << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.mediana << endl;
            }
            fout << bufferis.str();
            bufferis.str("");
            bufferis.clear();
        }

        if (vidMed == "1") {
            bufferisB << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Vid.)" << endl;
            bufferisB << "--------------------------------------------------" << endl;

            for (auto& student : grupeBad) {
                bufferisB << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.pazVid << endl;
            }
            foutB << bufferisB.str();
            bufferisB.str("");
            bufferisB.clear();

        }
        else if (vidMed == "2") {
            bufferisB << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(20) << "Galutinis (Med.)" << endl;
            bufferisB << "--------------------------------------------------" << endl;

            for (auto& student : grupeBad) {
                bufferisB << left << setw(20) << student.vardas << left << setw(20) << student.pavarde << left << setw(20) << setprecision(3) << student.mediana << endl;
            }
            foutB << bufferisB.str();
            bufferisB.str("");
            bufferisB.clear();
        }
        fout.close();
        foutB.close();
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration1 = end1 - start1;
        cout << "Abieju studentu konteineriu isvedimas truko:  " << duration1.count() << " sek." << endl;
}
void vektoriaiMain(string vidMed, string choice, vector<studentasV>& grupeVector, vector<studentasV>& grupeBad, vector<studentasV>& grupeGood) {

    pasirinkimasVidMed(vidMed);
    sortChoice(choice);
    pazymiuFailoGeneravimas();
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 5; i++) {
        failoNuskaitymasRusiavimas(grupeVector, grupeBad, grupeGood, laikasSkaitymas, laikasSkaiciavimas, i, vidMed);
        isvedimasFailai(grupeGood, grupeBad, i, vidMed, choice);

        for (int i = 0; i < grupeVector.size(); i++) {
            grupeVector[i].pazymiai.clear();
        }
        grupeVector.clear();

        for (int i = 0; i < grupeBad.size(); i++) {
            grupeBad[i].pazymiai.clear();
        }
        grupeBad.clear();

        for (int i = 0; i < grupeGood.size(); i++) {
            grupeGood[i].pazymiai.clear();
        }
        grupeGood.clear();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << "VIsos programos veikimo trukme:  " << duration.count() << " sek." << endl;
}