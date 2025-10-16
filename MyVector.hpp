#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

class MyVector {
public:
    MyVector(int capacity = 1);
    ~MyVector();
    MyVector(const MyVector& other);
    int getCapacity() const { return capacity; }
    void push_back(int value); 
    int pop_back(void); 
    void print() const;
    int& at(int index);

private:
    void allocate_memory(int memory_size);

    int *elements;
    int size;
    int capacity;
};


#endif
