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
    Vector() {
        size = 0;
        capacity = 10;
        elements = new value_type[capacity];
    }
    /**
     * @brief Ismeta exception jei indeksas yra uz vektoriaus ribu
     */
    void throwOutOfRange() const {
        throw std::out_of_range("Out of range");
    }
    /**
     * @brief Konstruktorius su parametrais
     *
     * @param n Elementų skaičius
     * @param value Pradinė reikšmė
     */
    Vector(size_type n, const_reference value) {
        size = n;
        capacity = n;
        elements = new value_type[capacity];
        for (size_type i = 0; i < size; i++) {
            elements[i] = value;
        }
    }
    /**
     * @brief Kopijavimo konstruktorius
     *
     * @param rhs Kopijuojamas vektorius
     */
    Vector(const Vector &rhs) {
        size = rhs.size;
        capacity = rhs.capacity;
        elements = new value_type[capacity];
        for (size_type i = 0; i < size; i++) {
            elements[i] = rhs.elements[i];
        }
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
    [[nodiscard]] size_type Capacity() const{
        return capacity;
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
    void PushBack(reference object) {
        if (size == capacity) {
            Reserve(capacity == 0 ? 1 : capacity * 2);
        }
        elements[size] = object;
        size++;
    }
    /**
     * @brief Išmeta paskutinį elementą iš vektoriaus
     */
    void PopBack() {
        if (size == 0) {
            throwOutOfRange();
        }
        size--;
    }
    /**
     * @brief Išvalo vektorių
     */
    void Clear() {
        size = 0;
    }
    /**
     * @brief Prideda elementą į vektorių
     *
     * @param object Pridedamas elementas
     */
    void Resize(size_type n) {
        if (n < size) {
            size = n;
        } else {
            Reserve(n);
            for (size_type i = size; i < n; i++) {
                elements[i] = value_type();
            }
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
            auto newElements = new value_type[n];
//            for (size_type i = 0; i < size; i++) {
//                newElements[i] = elements[i];
//            }
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
    void Swap(Vector &rhs) {
        std::swap(size, rhs.size);
        std::swap(capacity, rhs.capacity);
        std::swap(elements, rhs.elements);
    }
    /**
     * @brief Sumažina vektoriaus vietos atmintyje kiekį iki elemento skaičiaus
     */
    void ShrinkToFit() {
        if (size < capacity) {
            auto newElements = new value_type[size];
            for (size_type i = 0; i < size; i++) {
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
            capacity = size;
        }
    }
    /**
     * @brief Prideda elementą į vektorių
     *
     * @param object Pridedamas elementas
     */
    void Erase(size_type index) {
        if (index >= size) {
            throwOutOfRange();
        }
        for (size_type i = index; i < size - 1; i++) {
            elements[i] = elements[i + 1];
        }
        size--;
    }
    /**
     * @brief Prideda elementą į vektorių
     *
     * @param object Pridedamas elementas
     */
    void Erase(iterator position, iterator last) {
        size_t offset = position - begin();
        size_t numElements = last - position;

        for (size_t i = offset; i < size - numElements; ++i) {
            elements[i] = std::move(elements[i + numElements]);
        }

        size -= numElements;
    }
    /**
     * @brief Įterpia elementą į vektorių
     *
     * @param index Įterpimo vieta
     * @param object Įterpiamas elementas
     */
    void Insert(size_type index, reference object) {
        if (index > size) {
            throwOutOfRange();
        }
        if (size == capacity) {
            Reserve(capacity + 1);
        }
        for (size_type i = size; i > index; i--) {
            elements[i] = elements[i - 1];
        }
        elements[index] = object;
        size++;
    }
    /**
     * @brief Įterpia elementą į vektorių
     *
     * @param pos Įterpimo vieta
     * @param first Pradžios iteratorius
     * @param last Pabaigos iteratorius
     */
    void Insert(iterator pos, iterator first, iterator last) {
        size_t index = std::distance(elements, pos);
        size_t numNewElements = std::distance(first, last);

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
    T& operator[](size_t index) {
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
    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }
    /**
     * @brief Priskiria elementus iš kitos vektoriaus
     *
     * @param rhs Kitas vektorius
     * @return Šis vektorius
     */
    void Assign(size_type n, const_reference value) {
        if (n > capacity) {
            Reserve(n);
        }
        for (size_type i = 0; i < n; i++) {
            elements[i] = value;
        }
        size = n;
    }
    /**
     * @brief Priskiria elementus iš kitos vektoriaus
     *
     * @param rhs Kitas vektorius
     * @return Šis vektorius
     */
    void operator=(const Vector &rhs) {
        if (this != &rhs) {
            delete[] elements;
            size = rhs.size;
            capacity = rhs.capacity;
            elements = new value_type[capacity];
            for (size_type i = 0; i < size; i++) {
                elements[i] = rhs.elements[i];
            }
        }
    }
    /**
     * @brief Grąžina elementą pagal indeksą
     *
     * @param index Indeksas
     * @return Elementas
     */
    reference At(size_type index) {
        if (index >= size) {
            throwOutOfRange();
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
            throwOutOfRange();
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
            throwOutOfRange();
        }
        return elements[size - 1];
    }
//pakeitimai begin() funkcijai nebecrashina programos, panaikintas throwOutOfRange()
    /**
     * @brief Grąžina iteratorių į pirmą elementą
     *
     * @return Iteratorius į pirmą elementą
     */
    iterator begin() const {
        return elements;
    }
//pakeitimai end() funkcijai nebecrashina programos, panaikintas throwOutOfRange()
    /**
     * @brief Grąžina iteratorių į paskutinį elementą
     *
     * @return Iteratorius į paskutinį elementą
     */
    iterator end() const {
//        if (size == 0) {
//            throwOutOfRange();
//        }
        return elements + size;
    }
    /**
     * @brief Grąžina iteratorių į paskutinį elementą
     *
     * @return Iteratorius į paskutinį elementą
     */
    iterator RBegin() {
        if (size == 0) {
            throwOutOfRange();
        }
        return elements + size - 1;
    }
    /**
     * @brief Grąžina iteratorių į paskutinį elementą
     *
     * @return Iteratorius į paskutinį elementą
     */
    void EmplaceBack(T&& object) {
        if (size == capacity) {
            Reserve(capacity + 1);
        }
        elements[size] = std::forward<T>(object);
        size++;
    }
};

#endif //OOPUZD_VECTORCLASS_H