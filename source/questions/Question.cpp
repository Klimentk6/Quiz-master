#include "Question.h"

Question::Question(const MyString& description, int points)
{
	this->description = description;
	this->points = points;
}

void Question::writeToBinaryFile(std::ofstream& ofs) const
{
    description.writeToBinaryFile(ofs);
    ofs.write((const char*)&points, sizeof(points));
}
void Question::readFromBinaryFile(std::ifstream& ifs)
{
    description.readFromBinaryFile(ifs);
    ifs.read((char*)&points, sizeof(points));
}

int Question::getPoints() const
{
	return points;
}
MyString Question::getDescription() const
{
    return description;
}

