#pragma once
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Question.h"

using namespace Utils;

struct CharPair
{
	CharPair() = default;
	CharPair(char l, char r) : left(l), right(r) {}

	char left;  
	char right;
};

class MatchingPairsQuestion : public Question
{
public:
	MatchingPairsQuestion() = default;
	MatchingPairsQuestion(const MyString& description, int points, const MyVector<MyString>& leftColumn, const MyVector<MyString>& rightColumn, const MyVector<CharPair>& correctMatches);

	Question* clone() const override;
	QuestionType getType() const override;
	void print() const override;
	double playQuestion() const override;
	void playTestQuestion() const override;
	void writeToBinaryFile(std::ofstream& ofs) const override;
	void readFromBinaryFile(std::ifstream& ifs) override;
	void saveToFile(std::ofstream& ofs) const override;

private:
	MyVector<MyString> leftColumn;
	MyVector<MyString> rightColumn;
	MyVector<CharPair> correctMatches;
};
