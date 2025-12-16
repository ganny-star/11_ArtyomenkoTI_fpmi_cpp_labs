#include "vector.h"

Vector::Vector() : elements(nullptr), currentSize(0), currentCapacity(0) {}

Vector::Vector(size_t size) : currentSize(size < 0 ? 0 : size), currentCapacity(currentSize) {
    elements = new int[currentCapacity];
    for(size_t i = 0; i < size; i++)
    {
        elements[i] = 0;
    }
}

Vector::Vector(std::initializer_list<int> initList) : currentSize(initList.size()), currentCapacity(initList.size()) {
    elements = new int[currentCapacity];
    std::copy(initList.begin(), initList.end(), elements);
}

Vector::Vector(const Vector& other) : currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
    elements = new int[currentCapacity];
    std::copy(other.elements, other.elements + currentSize, elements);
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        Vector temp(other);
        Swap(temp);
    }
    return *this;
}

Vector::~Vector() {
    delete[] elements;
}

void Vector::Swap(Vector& other) {
    std::swap(elements, other.elements);
    std::swap(currentSize, other.currentSize);
    std::swap(currentCapacity, other.currentCapacity);
}

int& Vector::operator[](size_t index) {
    return elements[index];
}

const int& Vector::operator[](size_t index) const {
    return elements[index];
}

int& Vector::At(size_t index) {
    if (index >= currentSize || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

const int& Vector::At(size_t index) const {
    if (index >= currentSize || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

size_t Vector::Size() const {
    return currentSize;
}

size_t Vector::Capacity() const {
    return currentCapacity;
}

void Vector::PushBack(int value) {
    if (currentSize == currentCapacity) {
        size_t newCapacity = (currentCapacity == 0) ? 1 : currentCapacity * 2;
        Reserve(newCapacity);
    }
    elements[currentSize++] = value;
}

void Vector::PopBack() {
    if (currentSize > 0) {
        --currentSize;
    }
}

void Vector::Clear() {
    currentSize = 0;
}

void Vector::Reserve(size_t newCapacity) {
    if (newCapacity > currentCapacity) {
        int* newElements = new int[newCapacity];
        std::copy(elements, elements + currentSize, newElements);
        delete[] elements;
        elements = newElements;
        currentCapacity = newCapacity;
    }
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "[";
    for (size_t i = 0; i < vec.Size(); ++i) {
        os << vec[i];
        if (i != vec.Size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
