#pragma once
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Question.h"

using namespace Utils;

class MultipleChoiceQuestion : public Question
{
public:
	MultipleChoiceQuestion() = default;
	MultipleChoiceQuestion(const MyString& description, int points, const MyVector<MyString>& answers, const MyVector<char>& correctAnswers);

	Question* clone() const override;
	QuestionType getType() const override;
	void print() const override;
	double playQuestion() const override;
	void playTestQuestion() const override;
	void writeToBinaryFile(std::ofstream& ofs) const override;	
	void readFromBinaryFile(std::ifstream& ifs) override;
	void saveToFile(std::ofstream& ofs) const override;

private:
	MyVector<MyString> answers;
	MyVector<char> correctAnswers;
};

