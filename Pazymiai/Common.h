#pragma once
#include "PazymiaiVectors.h"

/**
 * @brief Programos meniu funkcija
 * @param pasirinkimas ka norite kad programa darytu pasirinkimo kintamasis
 */
void meniu(string& pasirinkimas);

/**
 * @brief rusiavimo funkcijos meniu
 * @param choice sortinimo pasirinkimo kintamasis
 */
void sortChoice(string& choice);

/**
 * @brief vidurkio arba medianos pasirinkimo meniu
 * @param vidMed vidurkio medianos pasirinkimo kintamasis
 */
void pasirinkimasVidMed(string& vidMed);

/**
 * @brief pasirinkimo i kelis konteineriu norima rusiuoti funkcija
 * @param ivedimas ivedimo kintamasis
 */
void pasirinkimasIvedimas(string& ivedimas);

/**
 * @brief funkcija, kuri isveda sugeneruota
 * @param iteracija su kuriais failais reikes dirbti
 */
void failoGeneravimasIsvedimas(int iteracija);

/**
 * @brief pagalbine funkcija isvedant pazymiu failus
 */
void pazymiuFailoGeneravimas();