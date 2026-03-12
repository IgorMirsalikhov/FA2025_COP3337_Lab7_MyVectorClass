#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

class MyVector {
public:
    MyVector(int capacity = 10);
    // Copy constructor
    MyVector(const MyVector& other);

    // Destructor
    ~MyVector();

    void print() const;
    void push_back(int val);    // Add the new element at the end
    int pop_back();             // Removes the last element and returns its value
    
    bool empty() const;
    int getCapacity() const;
    int& at(int index) const;

private:
    int* elements;      // An array of integers
    int size;           // The current number of elements
    int capacity;       // The max number of elements in the array

    bool full() const;

    void allocateMemory(int memory_size);
};

#endif
