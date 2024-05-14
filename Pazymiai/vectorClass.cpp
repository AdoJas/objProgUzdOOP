//
// Created by adoma on 5/13/2024.
//
#include "vectorClass.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

template<typename T>
Vector<T>::Vector() {
    size = 0;
    capacity = 0;
    elements = nullptr;
}

void throwOutOfRange() {
    throw std::out_of_range("Out of range");
}

template<typename T>
Vector<T>::Vector(size_type n, const_reference value) {
    size = n;
    capacity = n;
    elements = new value_type[capacity];
    for (size_type i = 0; i < size; i++) {
        elements[i] = value;
    }
}

template<typename T>
Vector<T>::Vector(const Vector &rhs) {
    size = rhs.size;
    capacity = rhs.capacity;
    elements = new value_type[capacity];
    for (size_type i = 0; i < size; i++) {
        elements[i] = rhs.elements[i];
    }
}

template<typename T>
Vector<T>::~Vector() {
    delete[] elements;
}

template<typename T>
typename Vector<T>::size_type Vector<T>::Size() {
    return size;
}

template<typename T>
typename Vector<T>::size_type Vector<T>::Capacity() {
    return capacity;
}

template<typename T>
bool Vector<T>::isEmpty() {
    return size == 0;
}

template<typename T>
void Vector<T>::PushBack(reference object) {
    if (size == capacity) {
        Reserve(capacity + 1);
    }
    elements[size] = object;
    size++;
}

template<typename T>
void Vector<T>::PopBack() {
    if (size == 0) {
        throwOutOfRange();
    }
    size--;
}

template<typename T>
void Vector<T>::Clear() {
    size = 0;
}

template<typename T>
void Vector<T>::Resize(size_type n) {
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

template<typename T>
void Vector<T>::Reserve(size_type n) {
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

template<typename T>
void Vector<T>::Swap(Vector &rhs) {
    std::swap(size, rhs.size);
    std::swap(capacity, rhs.capacity);
    std::swap(elements, rhs.elements);
}

template<typename T>
void Vector<T>::ShrinkToFit() {
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

template<typename T>
void Vector<T>::Erase(size_type index) {
    if (index < 0 || index >= size) {
        throwOutOfRange();
    }
    for (size_type i = index; i < size - 1; i++) {
        elements[i] = elements[i + 1];
    }
    size--;
}

template<typename T>
void Vector<T>::Insert(size_type index, reference object) {
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

template<typename T>
void Vector<T>::Assign(size_type n, const_reference value) {
    if (n > capacity) {
        Reserve(n);
    }
    for (size_type i = 0; i < n; i++) {
        elements[i] = value;
    }
    size = n;
}

template<typename T>
void Vector<T>::operator=(const Vector &rhs) {
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

template<typename T>
typename Vector<T>::reference Vector<T>::At(size_type index) {
    if (index < 0 || index >= size) {
        throwOutOfRange();
    }
    return elements[index];
}

template<typename T>
typename Vector<T>::reference Vector<T>::Front() {
    if (size == 0) {
        throwOutOfRange();
    }
    return elements[0];
}

template<typename T>
typename Vector<T>::reference Vector<T>::Back() {
    if (size == 0) {
        throwOutOfRange();
    }
    return elements[size - 1];
}

template<typename T>
typename Vector<T>::iterator Vector<T>::begin() {
    if (size == 0) {
        throwOutOfRange();
    }
    return elements;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end() {
    if (size == 0) {
        throwOutOfRange();
    }
    return elements + size;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::RBegin() {
    if (size == 0) {
        throwOutOfRange();
    }
    return elements + size - 1;
}

template<typename T>
void Vector<T>::EmplaceBack(T&& object) {
    if (size == capacity) {
        Reserve(capacity + 1);
    }
    elements[size] = std::forward<T>(object);
    size++;
}