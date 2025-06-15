#pragma once
#include <iostream>
#include <fstream>
#include "MyVector.hpp"
#pragma warning(disable : 4996)

class MyString
{
public:
    MyString();
    MyString(const char* cstr);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    ~MyString();

    const char& operator[](unsigned index) const;
    char& operator[](unsigned index);

    const char* getCharArr() const;
    unsigned getSize() const;
    bool isEmpty() const;
    bool isInt() const;
    int toInt() const;

    void clear();
    void pushBack(char c);
    void popBack();
    void readLine(std::istream& is);
    MyString substring(int start, int length) const;
    void trim();
    MyVector<MyString> split(char delimiter) const;
    MyVector<MyString> split(const MyString& delimiter) const;

    void writeToBinaryFile(std::ofstream& ofs) const;
    void readFromBinaryFile(std::ifstream& ifs);

    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;

    MyString operator+(const MyString& other) const;
    MyString& operator+=(const MyString& other);
    MyString& operator+=(char c);

    friend std::ostream& operator<<(std::ostream& out, const MyString& str);
    friend std::istream& operator>>(std::istream& in, MyString& str);

private:
    void copyFrom(const MyString& other);
    void free();

    void resize(unsigned newCapacity);
    static unsigned calculateCapacity(unsigned size, unsigned minCapacity);
    static constexpr unsigned MIN_CAPACITY = 16;
    static constexpr unsigned RESIZE_COEFF = 2;

    char* data;
    unsigned size;
    unsigned capacity;
};

