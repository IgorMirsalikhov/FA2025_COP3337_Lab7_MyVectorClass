#include "MyVector.hpp"
#include <iostream>

MyVector::MyVector(int capacity) {
    this->capacity = capacity;
    size = 0;
    elements = new int[capacity];
}

// Copy constructor
MyVector::MyVector(const MyVector& other) {
    capacity = other.capacity;
    size = other.size;
    elements = new int[capacity];
    for(int i = 0; i < size; i++) {
        elements[i] = other.elements[i];
    }
}

MyVector::~MyVector() {
    delete [] elements;
}

void MyVector::print() const {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) {
        std::cout << elements[i] << ' ';
    }
    std::cout << "]\n";
}

void MyVector::push_back(int val) {
    if (full()) {
        allocateMemory(capacity * 2);
    }
    elements[size] = val;
    size++;
}

bool MyVector::empty() const {
    return size == 0;
}

bool MyVector::full() const {
    return size == capacity;
}

void MyVector::allocateMemory(int memory_size) {
    capacity = memory_size;
    // Save the old address of the array
    int* old_array = elements;
    // Allocate new memory
    elements = new int[capacity];

    // Copy the elements
    for (int i = 0; i < size; i++) {
        elements[i] = old_array[i];
    }
    delete [] old_array;
}

int MyVector::pop_back() {
    if (!empty()) {
        if (size < capacity / 2) {
            allocateMemory(capacity / 2);
        }
        return elements[--size];
    }
    else {
        throw "Empty vector";
    }
}

int MyVector::getCapacity() const {
    return capacity;
}

int& MyVector::at(int index) const {
    if (index < 0 || index >= size) {
        throw "At: out of boundaries\n";
    }
    else {
        return elements[index];
    }
}
