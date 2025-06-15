#include "ShortAnswerQuestion.h"

ShortAnswerQuestion::ShortAnswerQuestion(const MyString& description, int points, const MyString& correctAnswer)
    : Question(description, points)
{
    this->correctAnswer = correctAnswer;
}

Question* ShortAnswerQuestion::clone() const
{
    return new ShortAnswerQuestion(*this);
}
QuestionType ShortAnswerQuestion::getType() const
{
    return QuestionType::ShortAnswer;
}
void ShortAnswerQuestion::print() const
{
    std::cout << description << " (" << points << " points)" << std::endl;
}
double ShortAnswerQuestion::playQuestion() const
{
    print();
    MyString answer = readMyString("Enter your answer here: ");
    if (areStringsEqualCaseInsensitive(answer, correctAnswer))
    {
        return points;
    }
    else
    {
        return 0;
    }
}
void ShortAnswerQuestion::playTestQuestion() const
{
    print();
    MyString answer = readMyString("Enter your answer here: ");
    std::cout << "Correct answer: " << correctAnswer;
}
void ShortAnswerQuestion::writeToBinaryFile(std::ofstream& ofs) const
{
    Question::writeToBinaryFile(ofs);
    correctAnswer.writeToBinaryFile(ofs);
}
void ShortAnswerQuestion::readFromBinaryFile(std::ifstream& ifs)
{
    Question::readFromBinaryFile(ifs);
    correctAnswer.readFromBinaryFile(ifs);
}
void ShortAnswerQuestion::saveToFile(std::ofstream& ofs) const
{
    ofs << description << "\n   Enter your answer here:\n";
}

