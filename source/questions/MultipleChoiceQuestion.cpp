#include "MultipleChoiceQuestion.h"

MultipleChoiceQuestion::MultipleChoiceQuestion(const MyString& description, int points, const MyVector<MyString>& answers, const MyVector<char>& correctAnswers)
    :Question(description, points)
{
    this->answers = answers;
    this->correctAnswers = correctAnswers;
}

Question* MultipleChoiceQuestion::clone() const
{
	return new MultipleChoiceQuestion(*this);
}
QuestionType MultipleChoiceQuestion::getType() const
{
	return QuestionType::MultipleChoice;
}
void MultipleChoiceQuestion::print() const
{
	std::cout << description << " (" << points << " points)" << std::endl;
	int answersCount = answers.getSize();
	for (int i = 0; i < answersCount; i++)
	{
		std::cout << (char)('A' + i) << ") " << answers[i] << std::endl;
	}
}
double MultipleChoiceQuestion::playQuestion() const
{
    print();
    MyVector<char> userAnswers;
    while (true)
    {
        MyString answerStr = readMyString("Enter your answers here: ");
        MyVector<MyString> parts = answerStr.split(',');
        bool allValid = true;
        userAnswers.clear();
        for (int i = 0; i < parts.getSize(); i++)
        {
            parts[i].trim();

            if (parts[i].getSize() != 1)
            {
                allValid = false;
                break;
            }

            char c = parts[i][0];
            if (c < 'A' || c >= 'A' + answers.getSize())
            {
                allValid = false;
                break;
            }

            bool alreadyAdded = false;
            for (int j = 0; j < userAnswers.getSize(); j++)
            {
                if (userAnswers[j] == c)
                {
                    alreadyAdded = true;
                    break;
                }
            }

            if (alreadyAdded)
            {
                allValid = false;
                break;
            }

            userAnswers.pushBack(c);
        }
        if (allValid && userAnswers.getSize() > 0)
        {
            break;
        }
        std::cout << "Invalid input! Please enter letters from A to "
            << (char)('A' + answers.getSize() - 1)
            << " separated by ', '" << std::endl;
    }
    int correctCount = 0;
    for (int i = 0; i < userAnswers.getSize(); i++)
    {
        for (int j = 0; j < correctAnswers.getSize(); j++)
        {
            if (userAnswers[i] == correctAnswers[j])
            {
                correctCount++;
                break;
            }
        }
    }
    if (correctCount == correctAnswers.getSize() && userAnswers.getSize() == correctAnswers.getSize())
    {
        return points;
    }
    else if (correctCount >= correctAnswers.getSize() / 2)
    {
        return points / 2; 
    }
    else
    {
        return 0;
    }
}
void MultipleChoiceQuestion::playTestQuestion() const
{
    print();
    MyVector<char> userAnswers;
    while (true)
    {
        MyString answerStr = readMyString("Enter your answers here: ");
        MyVector<MyString> parts = answerStr.split(','); 

        bool allValid = true;
        userAnswers.clear();

        for (int i = 0; i < parts.getSize(); i++)
        {
            parts[i].trim();

            if (parts[i].getSize() != 1)
            {
                allValid = false;
                break;
            }

            char c = parts[i][0];
            if (c < 'A' || c >= 'A' + answers.getSize())
            {
                allValid = false;
                break;
            }

            bool alreadyAdded = false;
            for (int j = 0; j < userAnswers.getSize(); j++)
            {
                if (userAnswers[j] == c)
                {
                    alreadyAdded = true;
                    break;
                }
            }

            if (alreadyAdded)
            {
                allValid = false;
                break;
            }

            userAnswers.pushBack(c);
        }

        if (allValid && userAnswers.getSize() > 0)
        {
            break;
        }

        std::cout << "Invalid input! Please enter letters from A to "
            << (char)('A' + answers.getSize() - 1)
            << " separated by ', '" << std::endl;
    }

    std::cout << "Correct answer: ";
    for (int i = 0; i < correctAnswers.getSize(); i++)
    {
        std::cout << correctAnswers[i];
        if (i + 1 != correctAnswers.getSize())
        {
            std::cout << ", ";
        }
        else
        {
            std::cout << std::endl;
        }
    }
}

void MultipleChoiceQuestion::writeToBinaryFile(std::ofstream& ofs) const
{
    Question::writeToBinaryFile(ofs);
    int answersCount = answers.getSize();
    ofs.write((const char*)&answersCount, sizeof(answersCount));
    for (int i = 0; i < answersCount; i++)
    {
        answers[i].writeToBinaryFile(ofs);
    }
    int correctAnswersCount = correctAnswers.getSize();
    ofs.write((const char*)&correctAnswersCount, sizeof(correctAnswersCount));
    for (int i = 0; i < correctAnswersCount; i++)
    {
        ofs.write((const char*)&correctAnswers[i], sizeof(correctAnswers[i]));
    }
}
void MultipleChoiceQuestion::readFromBinaryFile(std::ifstream& ifs)
{
    Question::readFromBinaryFile(ifs);
    int answersCount = 0;
    ifs.read((char*)&answersCount, sizeof(answersCount));
    answers.clear();
    for (int i = 0; i < answersCount; i++)
    {
        MyString temp;
        temp.readFromBinaryFile(ifs);
        answers.pushBack(temp);
    }
    int correctAnswersCount = 0;
    ifs.read((char*)&correctAnswersCount, sizeof(correctAnswersCount));
    correctAnswers.clear();
    for (int i = 0; i < correctAnswersCount; i++)
    {
        char c;
        ifs.read((char*)&c, sizeof(c));
        correctAnswers.pushBack(c);
    }
}

void MultipleChoiceQuestion::saveToFile(std::ofstream& ofs) const
{
    ofs << description << "\n";
    for (int i = 0; i < answers.getSize(); i++)
    {
        ofs << "   " << (char)('A' + i) << ") " << answers[i] << "\n";
    }
}


