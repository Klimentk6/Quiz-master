#pragma once
#include <iostream>
#include <fstream>

class TestModeChallenge
{
public:
	TestModeChallenge();
	unsigned testModeDone();
	void print() const;
	void readFromBinaryFile(std::ifstream& ifs);
	void writeToBinaryFile(std::ofstream& ofs) const;
	unsigned getCount() const;

private:
	unsigned count;
	unsigned target;
};

