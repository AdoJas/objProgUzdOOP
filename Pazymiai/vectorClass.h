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

    Vector() {
        size = 0;
        capacity = 0;
        elements = nullptr;
    }

    void throwOutOfRange() const {
        throw std::out_of_range("Out of range");
    }

    Vector(size_type n, const_reference value) {
        size = n;
        capacity = n;
        elements = new value_type[capacity];
        for (size_type i = 0; i < size; i++) {
            elements[i] = value;
        }
    }

    Vector(const Vector &rhs) {
        size = rhs.size;
        capacity = rhs.capacity;
        elements = new value_type[capacity];
        for (size_type i = 0; i < size; i++) {
            elements[i] = rhs.elements[i];
        }
    }

    ~Vector() {
        delete[] elements;
    }

    size_type Size() const {
        return size;
    }

    size_type Capacity() const{
        return capacity;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void PushBack(reference object) {
        if (size == capacity) {
            Reserve(capacity + 1);
        }
        elements[size] = object;
        size++;
    }

    void PopBack() {
        if (size == 0) {
            throwOutOfRange();
        }
        size--;
    }

    void Clear() {
        size = 0;
    }

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

    void Reserve(size_type n) {
        if (n > capacity) {
            iterator newElements = new value_type[n];
            for (size_type i = 0; i < size; i++) {
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
            capacity = n;
        }
    }

    void Swap(Vector &rhs) {
        std::swap(size, rhs.size);
        std::swap(capacity, rhs.capacity);
        std::swap(elements, rhs.elements);
    }

    void ShrinkToFit() {
        if (size < capacity) {
            iterator newElements = new value_type[size];
            for (size_type i = 0; i < size; i++) {
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
            capacity = size;
        }
    }

    void Erase(size_type index) {
        if (index < 0 || index >= size) {
            throwOutOfRange();
        }
        for (size_type i = index; i < size - 1; i++) {
            elements[i] = elements[i + 1];
        }
        size--;
    }

    void Erase(iterator position, iterator last) {
        size_t offset = position - begin();
        size_t numElements = last - position;

        for (size_t i = offset; i < size - numElements; ++i) {
            elements[i] = std::move(elements[i + numElements]);
        }

        size -= numElements;
    }

    void Insert(size_type index, reference object) {
        if (index < 0 || index > size) {
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

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }
    void Assign(size_type n, const_reference value) {
        if (n > capacity) {
            Reserve(n);
        }
        for (size_type i = 0; i < n; i++) {
            elements[i] = value;
        }
        size = n;
    }

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

    reference At(size_type index) {
        if (index < 0 || index >= size) {
            throwOutOfRange();
        }
        return elements[index];
    }

    reference Front() {
        if (size == 0) {
            throwOutOfRange();
        }
        return elements[0];
    }

    reference Back() {
        if (size == 0) {
            throwOutOfRange();
        }
        return elements[size - 1];
    }

    iterator begin() const {
        if (size == 0) {
            throwOutOfRange();
        }
        return elements;
    }

    iterator end() const {
        if (size == 0) {
            throwOutOfRange();
        }
        return elements + size;
    }

    iterator RBegin() {
        if (size == 0) {
            throwOutOfRange();
        }
        return elements + size - 1;
    }

    void EmplaceBack(T&& object) {
        if (size == capacity) {
            Reserve(capacity + 1);
        }
        elements[size] = std::forward<T>(object);
        size++;
    }
};

#endif //OOPUZD_VECTORCLASS_H