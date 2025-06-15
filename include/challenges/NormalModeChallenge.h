#pragma once
#include <iostream>
#include <fstream>

class NormalModeChallenge
{
public:
	NormalModeChallenge();
	unsigned normalModeDone();
	void print() const;
	void readFromBinaryFile(std::ifstream& ifs);
	void writeToBinaryFile(std::ofstream& ofs) const;
	unsigned getCount() const;

private:
	unsigned count;
	unsigned target;
};

