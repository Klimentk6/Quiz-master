#include "SingleChoiceQuestion.h"

SingleChoiceQuestion::SingleChoiceQuestion(const MyString& description, int points, const MyString* answers, char correctAnswer)
	: Question(description, points)
{
	for (int i = 0; i < 4; i++)
	{
		this->answers[i] = answers[i];
	}
	this->correctAnswer = correctAnswer;
}

Question* SingleChoiceQuestion::clone() const
{
	return new SingleChoiceQuestion(*this);
}
QuestionType SingleChoiceQuestion::getType() const
{
	return QuestionType::SingleChoice;
}
void SingleChoiceQuestion::print() const
{
	std::cout << description << " (" << points << " points)" << std::endl;
	std::cout << "A) " << answers[0] << std::endl;
	std::cout << "B) " << answers[1] << std::endl;
	std::cout << "C) " << answers[2] << std::endl;
	std::cout << "D) " << answers[3] << std::endl;
}
double SingleChoiceQuestion::playQuestion() const
{
	print();
	char answer;
	while (true)
	{
		answer = readChar("Enter your choice here: ");
		if (answer >= 'A' && answer <= 'D')
		{
			break;
		}
		std::cout << "Invalid charecter!" << std::endl;
	}
	if (answer == correctAnswer)
	{
		return points;
	}
	else
	{
		return 0;
	}
}
void SingleChoiceQuestion::playTestQuestion() const
{
	print();
	char answer;
	while (true)
	{
		answer = readChar("Enter your choice here: ");
		if (answer >= 'A' && answer <= 'D')
		{
			break;
		}
		std::cout << "Invalid charecter!" << std::endl;
	}
	std::cout << "Correct answer: " << correctAnswer;
}
void SingleChoiceQuestion::writeToBinaryFile(std::ofstream& ofs) const
{
	Question::writeToBinaryFile(ofs);
	for (int i = 0; i < 4; i++)
	{
		answers[i].writeToBinaryFile(ofs);
	}
	ofs.write((const char*)&correctAnswer, sizeof(correctAnswer));
}
void SingleChoiceQuestion::readFromBinaryFile(std::ifstream& ifs)
{
	Question::readFromBinaryFile(ifs);
	for (int i = 0; i < 4; i++)
	{
		answers[i].readFromBinaryFile(ifs);
	}
	ifs.read((char*)&correctAnswer, sizeof(correctAnswer));
}

void SingleChoiceQuestion::saveToFile(std::ofstream& ofs) const
{
	ofs << description << "\n"
		<< "   A)" << answers[0] << "\n"
		<< "   B)" << answers[1] << "\n"
		<< "   C)" << answers[2] << "\n"
		<< "   D)" << answers[3] << "\n";
}

