#pragma once
#include <iostream>
#include <initializer_list>
#include <stdexcept>

class Vector {
private:
    int* elements;
    size_t currentSize;
    size_t currentCapacity;

public:
    Vector();

    Vector(size_t size);

    Vector(std::initializer_list<int> initList);

    Vector(const Vector& other);

    Vector& operator=(const Vector& other);

    ~Vector();

    void Swap(Vector& other);

    int& operator[](size_t index);
    const int& operator[](size_t index) const;

    int& At(size_t index);
    const int& At(size_t index) const;

    size_t Size() const;

    size_t Capacity() const;

    void PushBack(int value);

    void PopBack();

    void Clear();

    void Reserve(size_t newCapacity);

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
};
