#include "Report.h"

Report::Report(const MyString& senderUsername, const Quiz& quiz, const MyString& reason)
	: senderUsername(senderUsername), quiz(quiz), reason(reason) 
{
	timeSent = std::time(nullptr);
}

void Report::readFromBinaryFile(std::ifstream& ifs)
{
	senderUsername.readFromBinaryFile(ifs);
	quiz.readFromBinaryFile(ifs);
	reason.readFromBinaryFile(ifs);
	ifs.read((char*)&timeSent, sizeof(timeSent));
}

void Report::writeToBinaryFile(std::ofstream& ofs) const
{
	senderUsername.writeToBinaryFile(ofs);
	quiz.writeToBinaryFile(ofs);
	reason.writeToBinaryFile(ofs);
	ofs.write((const char*)&timeSent, sizeof(timeSent));
}

void Report::printReport() const
{
	std::tm* timeInfo = std::localtime(&timeSent);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "%d.%m.%Y", timeInfo);
	std::cout << buffer << " | sent by " << senderUsername << " | quiz id " << quiz.getId() << " by " << quiz.getCreatorUsername() << " | reason" << std::endl;
	std::cout << reason << std::endl;
}
