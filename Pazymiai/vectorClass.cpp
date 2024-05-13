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
Vector<T>::Vector(int n, const T &value) {
    size = n;
    capacity = n;
    elements = new T[capacity];
    for (int i = 0; i < size; i++) {
        elements[i] = value;
    }
}
template<typename T>
Vector<T>::Vector(const Vector &rhs) {
    size = rhs.size;
    capacity = rhs.capacity;
    elements = new T[capacity];
    for (int i = 0; i < size; i++) {
        elements[i] = rhs.elements[i];
    }
}
template<typename T>
Vector<T>::~Vector() {
    delete[] elements;
}
template<typename T>
int Vector<T>::Size() {
    return size;
}
template<typename T>
int Vector<T>::Capacity() {
    return capacity;
}
template<typename T>
bool Vector<T>::isEmpty() {
    return size == 0;
}
template<typename T>
void Vector<T>::PushBack(T &object) {
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
void Vector<T>::Resize(int n) {
    if (n < size) {
        size = n;
    } else {
        Reserve(n);
        for (int i = size; i < n; i++) {
            elements[i] = T();
        }
        size = n;
    }
}
template<typename T>
void Vector<T>::Reserve(int n) {
    if (n > capacity) {
        T* newElements = new T[n];
        for (int i = 0; i < size; i++) {
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
        T* newElements = new T[size];
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        capacity = size;
    }
}
template<typename T>
void Vector<T>::Erase(int index) {
    if (index < 0 || index >= size) {
        throwOutOfRange();
    }
    for (int i = index; i < size - 1; i++) {
        elements[i] = elements[i + 1];
    }
    size--;
}
template<typename T>
void Vector<T>::Insert(int index, T &object) {
    if (index < 0 || index > size) {
        throwOutOfRange();
    }
    if (size == capacity) {
        Reserve(capacity + 1);
    }
    for (int i = size; i > index; i--) {
        elements[i] = elements[i - 1];
    }
    elements[index] = object;
    size++;
}
template<typename T>
void Vector<T>::Assign(int n, const T &value) {
    if (n > capacity) {
        Reserve(n);
    }
    for (int i = 0; i < n; i++) {
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
        elements = new T[capacity];
        for (int i = 0; i < size; i++) {
            elements[i] = rhs.elements[i];
        }
    }
}
template<typename T>
T& Vector<T>::At(int index) {
    if (index < 0 || index >= size) {
        throwOutOfRange();
    }
    return elements[index];
}
template<typename T>
T& Vector<T>::Front() {
    if (size == 0) {
        throwOutOfRange();
    }
    return elements[0];
}
template<typename T>
T& Vector<T>::Back() {
    if (size == 0) {
        throwOutOfRange();
    }
    return elements[size - 1];
}
template<typename T>
T* Vector<T>::Begin() {
    if (size == 0) {
        throwOutOfRange();
    }
    return elements;
}
template<typename T>
T* Vector<T>::End() {
    if (size == 0) {
        throwOutOfRange();
    }
    return elements + size;
}
template<typename T>
T* Vector<T>::RBegin() {
    if (size == 0) {
        throwOutOfRange();
    }
    return elements + size - 1;
}
