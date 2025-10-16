#include "MyVector.hpp"
#include <iostream>

// Constructor
MyVector::MyVector(int capacity) : size(0) {
    this->capacity = capacity;
    elements = new int[capacity];
}

// Destructor
MyVector::~MyVector() {
    delete [] elements;
}

// Copy constructor
MyVector::MyVector(const MyVector& other) {
    size = other.size;
    capacity = other.capacity;
    elements = new int[capacity];

    //copy elements
    for(int i = 0; i < size; i++) {
        elements[i] = other.elements[i];
    }
}

void MyVector::push_back(int value) {
    if (size >= capacity) {
        allocate_memory(capacity * 2);
    }
    elements[size] = value;
    size++;
}

int MyVector::pop_back(void) {
    if (size > 0) {
        if (size - 1 < capacity / 2) {
            allocate_memory(capacity / 2);
        }
        return elements[--size];
    }
    else {
        // Throw an exception
        throw "The vector is empty!";
    }
}


void MyVector::print() const {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) {
        std::cout << elements[i] << ' ';
    }
    std::cout << "]\n"; 
}


void MyVector::allocate_memory(int memory_size) {
    capacity = memory_size;
    int *old = elements;
    // Allocate a new memory (bigger or smaller)
    elements = new int[memory_size];
    for (int i = 0; i < size; i++) {
        elements[i] = old[i];
    }
    // Deallocate the old memory
    delete [] old;
}


int& MyVector::at(int index) {

}
