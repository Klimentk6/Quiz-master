#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "Utils.h"
#include "Quiz.h"

using namespace Utils;

class Report 
{
public:
    Report() = default;
    Report(const MyString& senderUsername, const Quiz& quiz, const MyString& reason);

    void readFromBinaryFile(std::ifstream& ifs);
    void writeToBinaryFile(std::ofstream& ofs) const;
    void printReport() const;

private:
    MyString senderUsername;
    Quiz quiz;
    MyString reason;
    std::time_t timeSent;
};

