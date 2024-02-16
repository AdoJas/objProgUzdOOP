#include "common.h"
#include "PazymiaiArrays.h"

void swap(int* var1, int* var2)
{
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}

void addToArray(int*& arr, int& size, int value) {
    size++;
    int* tmp = new int[size];
    for (int i = 0; i < size - 1; i++) {
        tmp[i] = arr[i];
    }
    tmp[size - 1] = value;
    delete[] arr;
    arr = tmp;
}

void addToArray(studentasA*& arr, int& size, studentasA value) {
    size++;
    studentasA* tmp = new studentasA[size];
    for (int i = 0; i < size - 1; i++) {
        tmp[i] = arr[i];
    }
    tmp[size - 1] = value;
    delete[] arr;
    arr = tmp;
}
void meniu(int& pasirinkimas){
        std::cout << "Meniu:\n"
            << "1 - Studentu duomenu ivedimas ranka\n"
            << "2 - Ivestiems studentams generuojami pazymiai\n"
            << "3 - Generuojami pazymiai ir vardai/pavardes ivedus studentu skaiciu\n"
            << "4 - Baigti darba\n"
            <<("--------------------------------------------------\n")
            << "Pasirinkite norima opcija: ";
        std::cin >> pasirinkimas;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        printf("--------------------------------------------------\n");
}
void arraysVectorsPasirinkimas(char& arrVect) {
    std::cout << "Pasirinkite, su kokia duomenu struktura norite dirbti:\n"
        << "1 - Arrays\n"
        << "2 - Vectors\n";
    std::cin >> arrVect;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');



}