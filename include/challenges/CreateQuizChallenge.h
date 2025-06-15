#pragma once
#include <iostream>
#include <fstream>

class CreateQuizChallenge
{
public:
	CreateQuizChallenge();
	unsigned createQuizDone();
	void print() const;
	void readFromBinaryFile(std::ifstream& ifs);
	void writeToBinaryFile(std::ofstream& ofs) const;
	unsigned getCount() const;

private:
	unsigned count;
	unsigned target;
};

