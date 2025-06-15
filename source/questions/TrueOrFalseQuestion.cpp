#include "TrueOrFalseQuestion.h"

TrueOrFalseQuestion::TrueOrFalseQuestion(const MyString& description, int points, bool correctAnswer)
    : Question(description, points), correctAnswer(correctAnswer) {}

Question* TrueOrFalseQuestion::clone() const
{
    return new TrueOrFalseQuestion(*this);
}
QuestionType TrueOrFalseQuestion::getType() const
{
    return QuestionType::TrueOrFalse;
}
void TrueOrFalseQuestion::print() const
{
    std::cout << description << " (" << points << " points)" << std::endl;
}
double TrueOrFalseQuestion::playQuestion() const
{
    print();
    bool answer = readBool("Enter your answer here: ");
    if (answer == correctAnswer)
    {
        return points;
    }
    else
    {
        return 0;
    }
}
void TrueOrFalseQuestion::playTestQuestion() const
{
    print();
    bool answer = readBool("Enter your answer here: ");
    std::cout << "Correct answer: " << std::boolalpha << correctAnswer << std::endl;
}
void TrueOrFalseQuestion::writeToBinaryFile(std::ofstream& ofs) const
{
    Question::writeToBinaryFile(ofs);
    ofs.write((const char*)&correctAnswer, sizeof(correctAnswer));
}
void TrueOrFalseQuestion::readFromBinaryFile(std::ifstream& ifs)
{
    Question::readFromBinaryFile(ifs);
    ifs.read((char*)&correctAnswer, sizeof(correctAnswer));
}
void TrueOrFalseQuestion::saveToFile(std::ofstream& ofs) const
{
    ofs << description << "\n   True/False\n";
}

