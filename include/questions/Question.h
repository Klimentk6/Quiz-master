#pragma once
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"

using namespace Utils;

class Question
{
public:
	Question() = default;
	Question(const MyString& description, int points);
	virtual ~Question() = default;

	virtual Question* clone() const = 0;
	virtual QuestionType getType() const = 0;
	virtual void print() const = 0;
	virtual double playQuestion() const = 0;
	virtual void playTestQuestion() const = 0;
	virtual void writeToBinaryFile(std::ofstream& ofs) const = 0;
	virtual void readFromBinaryFile(std::ifstream& ifs) = 0;
	virtual void saveToFile(std::ofstream& ofs) const = 0;

	int getPoints() const;
	MyString getDescription() const;

protected:
	MyString description;
	int points;
};

