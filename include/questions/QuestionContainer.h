#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>  
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Question.h"
#include "QuestionFactory.h"

using namespace Utils;

class QuestionContainer
{
public:
	QuestionContainer();
	QuestionContainer(const QuestionContainer& other);
	QuestionContainer& operator=(const QuestionContainer& other);
	~QuestionContainer();

	void shuffle();
	void addQuestion(const Question* newQuestion);
	void writeToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs);
	void saveToFIle(std::ofstream& ofs);

	int getSize() const;
	Question* getAt(unsigned index);

private:
	void copyFrom(const QuestionContainer& other);
	void free();

	void resize(int newCapacity);
	static unsigned calculateCapacity(unsigned size, unsigned minCapacity);
	static constexpr unsigned MIN_CAPACITY = 16;
	static constexpr unsigned RESIZE_COEFF = 2;

	Question** arr;
	int size;
	int capacity;
};

