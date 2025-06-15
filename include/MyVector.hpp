#pragma once
#include <iostream>
#include <fstream>

template <typename T>
class MyVector
{
public:
    MyVector();
    MyVector(const char* fileName);
    MyVector(unsigned size, const T* arr);
    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& other);
    ~MyVector();

    const T& operator[](unsigned index) const;
    T& operator[](unsigned index);

    const T& getAt(unsigned index) const;
    T& getAt(unsigned index);

    void removeAt(unsigned index);
    void insertAt(unsigned index, const T& value);
    void swap(MyVector& other);
    void pushBack(const T& value);
    void popBack();
    void shrinkToFit();
    void clear();
    bool isEmpty() const;

    void writeToBinaryFile(const char* filename) const;
    void readFromBinaryFile(const char* filename);
    void writeToBinaryFile(std::ofstream& ofs) const;
    void readFromBinaryFile(std::ifstream& ifs);

    const T* getArr() const;
    unsigned getSize() const;
    unsigned getCapacity() const;

private:
    void copyFrom(const MyVector& other);
    void free();

    void resize(unsigned newCapacity);
    static unsigned calculateCapacity(unsigned size, unsigned minCapacity);
    static constexpr unsigned MIN_CAPACITY = 16;
    static constexpr unsigned RESIZE_COEFF = 2;

    T* arr;
    unsigned size;
    unsigned capacity;
};

template <typename T>
MyVector<T>::MyVector() 
{
    size = 0;
    capacity = MIN_CAPACITY;
    arr = new T[capacity];
}
template<typename T>
MyVector<T>::MyVector(const char* fileName)
{
    try
    {
        readFromBinaryFile(fileName);
    }
    catch (std::exception)
    {
        size = 0;
        capacity = MIN_CAPACITY;
        arr = new T[capacity];
    }
}
template <typename T>
MyVector<T>::MyVector(unsigned size, const T* arr)
{
    this->size = size;
    this->capacity = calculateCapacity(size, MIN_CAPACITY);
    this->arr = new T[this->capacity];
    for (int i = 0; i < size; i++)
    {
        this->arr[i] = arr[i];
    }
}
template <typename T>
MyVector<T>::MyVector(const MyVector& other) 
{
    copyFrom(other);
}
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) 
{
    if (this != &other) 
    {
        free();
        copyFrom(other);
    }
    return *this;
}
template <typename T>
MyVector<T>::~MyVector() 
{
    free();
}

template <typename T>
void MyVector<T>::copyFrom(const MyVector& other) 
{
    size = other.size;
    capacity = other.capacity;
    arr = new T[capacity];
    for (unsigned i = 0; i < size; i++)
    {
        arr[i] = other.arr[i];
    }
}
template <typename T>
void MyVector<T>::free()
{
    delete[] arr;
}

template <typename T>
void MyVector<T>::resize(unsigned newCapacity)
{
    if (newCapacity <= capacity)
    {
        return;
    }
    T* newArr = new T[newCapacity];
    for (unsigned i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}
template <typename T>
unsigned MyVector<T>::calculateCapacity(unsigned size, unsigned minCapacity)
{
    if (size == 0)
    {
        return minCapacity;
    }
    while (size < minCapacity)
    {
        size *= RESIZE_COEFF;
    }
    return size;
}

template <typename T>
const T& MyVector<T>::operator[](unsigned index) const
{
    if (index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}
template <typename T>
T& MyVector<T>::operator[](unsigned index)
{
    if (index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

template <typename T>
const T& MyVector<T>::getAt(unsigned index) const 
{
    if (index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}
template <typename T>
T& MyVector<T>::getAt(unsigned index) 
{
    if (index >= size) 
    { 
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

template <typename T>
void MyVector<T>::pushBack(const T& value) 
{
    if (size == capacity)
    {
        resize(capacity * 2);
    }
    arr[size++] = value;
}
template <typename T>
void MyVector<T>::popBack() 
{
    if (isEmpty())
    {
        throw std::out_of_range("Cannot pop from empty vector");
    }
    size--;
}
template <typename T>
void MyVector<T>::removeAt(unsigned index) 
{
    if (index >= size)
    { 
        throw std::out_of_range("Index out of range"); 
    }
    for (unsigned i = index; i < size - 1; i++) 
    {
        arr[i] = arr[i + 1];
    }
    size--;
}
template <typename T>
void MyVector<T>::insertAt(unsigned index, const T& value) 
{
    if (index > size) 
    { 
        throw std::out_of_range("Index out of range"); 
    }
    if (size == capacity)
    {
        resize(capacity * 2);
    }
    for (unsigned i = size; i > index; i--) 
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    size++;
}
template <typename T>
void MyVector<T>::swap(MyVector& other) 
{
    if (this == &other)
    {
        return;
    }
    std::swap(arr, other.arr);
    std::swap(size, other.size);
    std::swap(capacity, other.capacity);
}
template <typename T>
void MyVector<T>::shrinkToFit() 
{
    if (size == capacity) return;
    T* newArr = new T[size];
    for (unsigned i = 0; i < size; i++) 
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = size;
}
template <typename T>
void MyVector<T>::clear() 
{
    size = 0;
}
template <typename T>
bool MyVector<T>::isEmpty() const
{
    return size == 0;
}
template<typename T>
void MyVector<T>::writeToBinaryFile(const char* filename) const 
{
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs.is_open()) 
    {
        throw std::runtime_error("Cannot open file for writing");
    }
    writeToBinaryFile(ofs); 
}
template<typename T>
void MyVector<T>::readFromBinaryFile(const char* filename) 
{
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs.is_open()) 
    {
        throw std::runtime_error("Cannot open file for reading");
    }
    readFromBinaryFile(ifs);
}
template<typename T>
void MyVector<T>::writeToBinaryFile(std::ofstream& ofs) const 
{
    ofs.write((const char*)(&size), sizeof(size));
    for (int i = 0; i < size; i++) 
    {
        arr[i].writeToBinaryFile(ofs);
    }
}
template<typename T>
void MyVector<T>::readFromBinaryFile(std::ifstream& ifs) 
{
    delete[] arr;
    ifs.read((char*)&size, sizeof(size));
    capacity = calculateCapacity(size, MIN_CAPACITY);
    arr = new T[capacity];
    for (int i = 0; i < size; i++) 
    {
        arr[i].readFromBinaryFile(ifs);
    }
}

template <typename T>
const T* MyVector<T>::getArr() const 
{
    return arr;
}
template <typename T>
unsigned MyVector<T>::getSize() const 
{
    return size;
}
template <typename T>
unsigned MyVector<T>::getCapacity() const 
{
    return capacity;
}