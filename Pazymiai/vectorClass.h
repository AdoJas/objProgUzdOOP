//
// Created by adoma on 5/13/2024.
//

#ifndef OOPUZD_VECTORCLASS_H
#define OOPUZD_VECTORCLASS_H

#include <cstddef>

/**
 * @brief Šabloninė Vector klasė
 *
 * @tparam T Elementų tipas
 */
template<typename T>
class Vector{
private:
    int size;  ///< Elementų skaičius vektoriuje
    int capacity; ///< Vietos kiekis atmintyje
    T* elements; ///< Masyvas, kuriame saugomi elementai

public:
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef std::ptrdiff_t difference_type;
    typedef size_t size_type;

    /**
     * @brief Konstruktorius be parametrų
     */
    Vector();

    /**
     * @brief Konstruktorius su n elementų
     *
     * @param n Elementų skaičius
     * @param value Pradinė elementų reikšmė
     */
    Vector(size_type n, const const_reference value);

    /**
     * @brief Kopijavimo konstruktorius
     *
     * @param rhs Vector objektas, kurį kopijuojame
     */
    Vector(const Vector &rhs);

    /**
     * @brief Destruktorius
     */
    ~Vector();

    /**
     * @brief Grąžina elementų skaičių
     *
     * @return size_type Elementų skaičius
     */
    typename Vector<T>::size_type Size();

    /**
     * @brief Grąžina kiek atminties vietos yra išskirta šiam vektoriui
     *
     * @return size_type Atminties vietos kiekis
     */
    typename Vector<T>::size_type Capacity();

    /**
     * @brief Patikrina ar vektorius yra tuščias
     *
     * @return true Jei vektorius yra tuščias
     * @return false Jei vektorius nėra tuščias
     */
    bool isEmpty();

    /**
     * @brief Įdeda elementą į vektoriaus galą
     *
     * @param object Elementas, kurį dedame
     */
    void PushBack(reference object);

    /**
     * @brief Ištrina paskutinį vektoriaus elementą
     */
    void PopBack();

    /**
     * @brief Ištrina visus elementus iš vektoriaus
     */
    void Clear();

    /**
     * @brief Pakeičia vektoriaus dydį (size) į n
     *
     * @param n Naujas vektoriaus dydis
     */
    void Resize(size_type n);

    /**
     * @brief Alokuoja atminties vietos vektoriaus elementams
     *
     * @param n Kiek atminties vietos norime išskirti
     */
    void Reserve(size_type n);

    /**
     * @brief Sukeičia vektoriaus elementus su kitu vektoriumi
     *
     * @param rhs Vector objektas, su kuriuo keičiame elementus
     */
    void Swap(Vector &rhs);

    /**
     * @brief Sumažina atminties vietos kiekį (capacity) iki vektoriaus dydžio (size)
     */
    void ShrinkToFit();

    /**
     * @brief Ištrina elementą iš vektoriaus pagal indeksą (index)
     *
     * @param index Elemento indeksas
     */
    void Erase(size_type index);

    /**
     * @brief Įterpia elementą į vektoriaus vietą pagal indeksą (index)
     *
     * @param index Indeksas, į kurį įterpiame elementą
     * @param object Elementas, kurį įterpiame
     */
    void Insert(size_type index, reference object);

    /**
     * @brief Pakeičia vektoriaus elementus į n elementų su reikšme (value)
     *
     * @param n Elementų skaičius
     * @param value Elementų reikšmė
     */
    void Assign(size_type n, const_reference value);

    /**
     * @brief Priskyrimo operatoriaus perkrova
     *
     * @param rhs Vector objektas, kurį priskiriame
     */
    void operator=(const Vector &rhs);

    /**
     * @brief Grąžina elementą pagal indeksą (index)
     *
     * @param index Elemento indeksas
     * @return reference Elementas pagal indeksą
     */
    typename Vector<T>::reference At(size_type index);

    /**
     * @brief Grąžina pirmąjį vektoriaus elementą
     *
     * @return reference Pirmasis elementas
     */
    typename Vector<T>::reference Front();

    /**
     * @brief Grąžina paskutinį vektoriaus elementą
     *
     * @return reference Paskutinis elementas
     */
    typename Vector<T>::reference Back();

    /**
     * @brief Grąžina rodyklę į vektoriaus pradžią
     *
     * @return iterator Rodyklė į vektoriaus pradžią
     */
    typename Vector<T>::iterator Begin();

    /**
     * @brief Grąžina rodyklę į vektoriaus galą
     *
     * @return iterator Rodyklė į vektoriaus galą
     */
    typename Vector<T>::iterator End();

    /**
     * @brief Grąžina rodyklę į vektoriaus pradžią iš galo
     *
     * @return iterator Rodyklė į vektoriaus pradžią iš galo
     */
    typename Vector<T>::iterator RBegin();
};

#endif //OOPUZD_VECTORCLASS_H