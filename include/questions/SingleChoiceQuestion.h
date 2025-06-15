#pragma once
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Question.h"

using namespace Utils;

class SingleChoiceQuestion : public Question
{
public:
	SingleChoiceQuestion() = default;
	SingleChoiceQuestion(const MyString& description, int points, const MyString* answers, char correctAnswer);

	Question* clone() const override;
	QuestionType getType() const override;
	void print() const override;
	double playQuestion() const override;
	void playTestQuestion() const override;
	void writeToBinaryFile(std::ofstream& ofs) const override;
	void readFromBinaryFile(std::ifstream& ifs) override;
	void saveToFile(std::ofstream& ofs) const override;

private:
	MyString answers[4];
	char correctAnswer;
};

