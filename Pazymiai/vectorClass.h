//
// Created by adoma on 5/13/2024.
//

#ifndef OOPUZD_VECTORCLASS_H
#define OOPUZD_VECTORCLASS_H

#include <cstddef>
#include <stdexcept>
#include <algorithm> // for std::move and std::move_backward

/**
 * @brief Šabloninė Vector klasė
 *
 * @tparam T Elementų tipas
 */
template<typename T>
/**
 * @brief Vector klasė
 *
 * Ši klasė realizuoja vektorių, kuris yra dinaminis masyvas.
 */
class Vector{
private:
    int size;  ///< Elementų skaičius vektoriuje
    int capacity; ///< Vietos kiekis atmintyje
    T* elements; ///< Masyvas, kuriame saugomi elementai

public:

    typedef T value_type; /**< Elemento tipas */
    typedef T& reference; /**< Elemento referencija */
    typedef const T& const_reference; /**< Konstantine elemento referencija */
    typedef T* iterator; /**< Iteratorius */
    typedef const T* const_iterator; /**< Konstantinis iteratorius */
    typedef std::ptrdiff_t difference_type; /**< Skirtumas tarp dvieju iteratoriu */
    typedef size_t size_type; /**< Elementu skaicius */

    /**
     * @brief Default konstruktorius
     */
    Vector() : size(0), capacity(10), elements(new value_type[capacity]) {}

    /**
     * @brief Konstruktorius su parametrais
     *
     * @param n Elementų skaičius
     * @param value Pradinė reikšmė
     */
    Vector(size_type n, const_reference value) : size(n), capacity(n), elements(new value_type[capacity]) {
        std::fill(elements, elements + size, value);
    }

    /**
     * @brief Kopijavimo konstruktorius
     *
     * @param rhs Kopijuojamas vektorius
     */
    Vector(const Vector &rhs) : size(rhs.size), capacity(rhs.capacity), elements(new value_type[capacity]) {
        std::copy(rhs.elements, rhs.elements + size, elements);
    }

    /**
     * @brief Destruktorius
     */
    ~Vector() {
        delete[] elements;
    }

    /**
     * @brief Grąžina elementų skaičių
     *
     * @return Elementų skaičius
     */
    [[nodiscard]] size_type Size() const {
        return size;
    }

    /**
     * @brief Grąžina vietos kiekį atmintyje
     *
     * @return Vietos kiekis atmintyje
     */
    [[nodiscard]] size_type Capacity() const {
        return capacity;
    }

    /**
     * @brief Konstruktorius su perkeliamaisiais parametrais
     *
     * @param other Perkeliamas vektorius
     */
    Vector(Vector&& other) noexcept : size(other.size), capacity(other.capacity), elements(other.elements) {
        other.size = 0;
        other.capacity = 0;
        other.elements = nullptr;
    }

    /**
     * @brief Priskyrimo operatorius su perkeliamaisiais parametrais
     *
     * @param other Perkeliamas vektorius
     * @return Šis vektorius
     */
    Vector& operator=(Vector other) noexcept {
        Swap(other);
        return *this;
    }

    /**
     * @brief Patikrina ar vektorius yra tuščias
     *
     * @return Ar tuščias
     */
    [[nodiscard]] bool isEmpty() const {
        return size == 0;
    }

    /**
     * @brief Prideda elementą į vektorių
     *
     * @param object Pridedamas elementas
     */
    void PushBack(const_reference object) {
        if (size == capacity) {
            Reserve(capacity == 0 ? 1 : capacity * 2);
        }
        elements[size++] = object;
    }

    /**
     * @brief Išmeta paskutinį elementą iš vektoriaus
     */
    void PopBack() {
        if (size == 0) {
            throw std::out_of_range("Out of range");
        }
        --size;
    }

    /**
     * @brief Išvalo vektorių
     */
    void Clear() {
        size = 0;
    }

    /**
     * @brief Keičia vektoriaus dydį
     *
     * @param n Naujasis dydis
     */
    void Resize(size_type n) {
        if (n < size) {
            size = n;
        } else {
            Reserve(n);
            std::fill(elements + size, elements + n, value_type());
            size = n;
        }
    }

    /**
     * @brief Rezervuoja vietos atmintyje
     *
     * @param n Vietos kiekis
     */
    void Reserve(size_type n) {
        if (n > capacity) {
            T* newElements = new value_type[n];
            std::move(elements, elements + size, newElements);
            delete[] elements;
            elements = newElements;
            capacity = n;
        }
    }

    /**
     * @brief Apkeičia vektorius
     *
     * @param rhs Apkeičiamas vektorius
     */
    void Swap(Vector &rhs) noexcept {
        std::swap(size, rhs.size);
        std::swap(capacity, rhs.capacity);
        std::swap(elements, rhs.elements);
    }

    /**
     * @brief Sumažina vektoriaus vietos atmintyje kiekį iki elemento skaičiaus
     */
    void ShrinkToFit() {
        if (size < capacity) {
            T* newElements = new value_type[size];
            std::move(elements, elements + size, newElements);
            delete[] elements;
            elements = newElements;
            capacity = size;
        }
    }

    /**
     * @brief Ištrina elementą pagal indeksą
     *
     * @param index Indeksas
     */
    void Erase(size_type index) {
        if (index >= size) {
            throw std::out_of_range("Out of range");
        }
        std::move(elements + index + 1, elements + size, elements + index);
        --size;
    }

    /**
     * @brief Ištrina elementus intervalo viduje
     *
     * @param position Pradžios iteratorius
     * @param last Pabaigos iteratorius
     */
    void Erase(iterator position, iterator last) {
        if (position < begin() || last > end() || position > last) {
            throw std::out_of_range("Out of range");
        }
        size_t numElements = last - position;
        std::move(last, end(), position);
        size -= numElements;
    }

    /**
     * @brief Įterpia elementą į vektorių
     *
     * @param index Įterpimo vieta
     * @param object Įterpiamas elementas
     */
    void Insert(size_type index, const_reference object) {
        if (index > size) {
            throw std::out_of_range("Out of range");
        }
        if (size == capacity) {
            Reserve(capacity == 0 ? 1 : capacity * 2);
        }
        std::move_backward(elements + index, elements + size, elements + size + 1);
        elements[index] = object;
        ++size;
    }

    /**
     * @brief Įterpia elementus į vektorių
     *
     * @param pos Įterpimo vieta
     * @param first Pradžios iteratorius
     * @param last Pabaigos iteratorius
     */
    void Insert(iterator pos, const_iterator first, const_iterator last) {
        size_t index = pos - begin();
        size_t numNewElements = last - first;

        if (size + numNewElements > capacity) {
            Reserve((size + numNewElements) * 2);
        }

        std::move_backward(elements + index, elements + size, elements + size + numNewElements);
        std::copy(first, last, elements + index);
        size += numNewElements;
    }

    /**
     * @brief Grąžina elementą pagal indeksą
     *
     * @param index Indeksas
     * @return Elementas
     */
    reference operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    /**
     * @brief Grąžina elementą pagal indeksą
     *
     * @param index Indeksas
     * @return Elementas
     */
    const_reference operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    /**
     * @brief Grąžina elementą pagal indeksą
     *
     * @param index Indeksas
     * @return Elementas
     */
    reference At(size_type index) {
        if (index >= size) {
            throw std::out_of_range("Out of range");
        }
        return elements[index];
    }

    /**
     * @brief Grąžina pirmą elementą
     *
     * @return Pirmas elementas
     */
    reference Front() {
        if (size == 0) {
            throw std::out_of_range("Out of range");
        }
        return elements[0];
    }

    /**
     * @brief Grąžina paskutinį elementą
     *
     * @return Paskutinis elementas
     */
    reference Back() {
        if (size == 0) {
            throw std::out_of_range("Out of range");
        }
        return elements[size - 1];
    }

    /**
     * @brief Grąžina iteratorių į pirmą elementą
     *
     * @return Iteratorius į pirmą elementą
     */
    iterator begin() {
        return elements;
    }

    /**
     * @brief Grąžina iteratorių į pirmą elementą
     *
     * @return Iteratorius į pirmą elementą
     */
    const_iterator begin() const {
        return elements;
    }

    /**
     * @brief Grąžina iteratorių į paskutinį elementą
     *
     * @return Iteratorius į paskutinį elementą
     */
    iterator end() {
        return elements + size;
    }

    /**
     * @brief Grąžina iteratorių į paskutinį elementą
     *
     * @return Iteratorius į paskutinį elementą
     */
    const_iterator end() const {
        return elements + size;
    }

    /**
     * @brief Prideda elementą į vektorių
     *
     * @param object Pridedamas elementas
     */
    void EmplaceBack(T&& object) {
        if (size == capacity) {
            Reserve(capacity == 0 ? 1 : capacity * 2);
        }
        elements[size++] = std::forward<T>(object);
    }
};

#endif //OOPUZD_VECTORCLASS_H
