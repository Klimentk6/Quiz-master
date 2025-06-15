#pragma once
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Question.h"

using namespace Utils;

class TrueOrFalseQuestion : public Question
{
public:
	TrueOrFalseQuestion() = default;
	TrueOrFalseQuestion(const MyString& description, int points, bool correctAnswer);

	Question* clone() const override;
	QuestionType getType() const override;
	void print() const override;
	double playQuestion() const override;
	void playTestQuestion() const override;
	void writeToBinaryFile(std::ofstream& ofs) const override;
	void readFromBinaryFile(std::ifstream& ifs) override;
	void saveToFile(std::ofstream& ofs) const override;

private:
	bool correctAnswer;
};

