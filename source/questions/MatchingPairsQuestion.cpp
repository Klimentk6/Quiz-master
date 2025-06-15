#include "MatchingPairsQuestion.h"

MatchingPairsQuestion::MatchingPairsQuestion(const MyString& description, int points, const MyVector<MyString>& leftColumn, const MyVector<MyString>& rightColumn, const MyVector<CharPair>& correctMatches)
    : Question(description, points)
{
    this->leftColumn = leftColumn;
    this->rightColumn = rightColumn;
    this->correctMatches = correctMatches;
}

Question* MatchingPairsQuestion::clone() const
{
    return new MatchingPairsQuestion(*this);
}
QuestionType MatchingPairsQuestion::getType() const 
{
    return QuestionType::MatchingPairs;
}
void MatchingPairsQuestion::print() const
{
    std::cout << description << " (" << points << " points)" << std::endl;
    int leftSize = leftColumn.getSize();
    int rightSize = rightColumn.getSize();
    int maxRows = leftSize > rightSize ? leftSize : rightSize;
    for (int i = 0; i < maxRows; ++i)
    {
        if (i < leftSize)
        {
            std::cout << (char)('A' + i) << ") " << leftColumn[i];
        }
        else
        {
            std::cout << "      ";
        }
        std::cout << "    ";
        if (i < rightSize)
        {
            std::cout << (char)('a' + i) << ") " << rightColumn[i];
        }

        std::cout << std::endl;
    }
}
double MatchingPairsQuestion::playQuestion() const
{
    print();
    MyVector<CharPair> userMatches;
    while (true)
    {
        userMatches.clear();
        MyString input = readMyString("Enter your matches (e.g. (A,a), (B,b)): ");
        MyVector<MyString> pairs = input.split(", ");
        bool allValid = true;
        for (int i = 0; i < pairs.getSize(); ++i)
        {
            pairs[i].trim();
            if (pairs[i].getSize() != 5 || pairs[i][0] != '(' || pairs[i][2] != ',' || pairs[i][4] != ')')
            {
                allValid = false;
                break;
            }

            char left = pairs[i][1];
            char right = pairs[i][3];

            if (left < 'A' || left >= 'A' + leftColumn.getSize() ||
                right < 'a' || right >= 'a' + rightColumn.getSize())
            {
                allValid = false;
                break;
            }

            bool duplicate = false;
            for (int j = 0; j < userMatches.getSize(); ++j)
            {
                if (userMatches[j].left == left || userMatches[j].right == right)
                {
                    duplicate = true;
                    break;
                }
            }
            if (duplicate)
            {
                allValid = false;
                break;
            }
            userMatches.pushBack(CharPair(left, right));
        }
        if (allValid)
        {
            break;
        }
        std::cout << "Invalid input! Please enter valid unique pairs like (A,a), (B,b) using only listed letters.\n";
    }
    int correctCount = 0;
    for (int i = 0; i < userMatches.getSize(); ++i)
    {
        for (int j = 0; j < correctMatches.getSize(); ++j)
        {
            if (userMatches[i].left == correctMatches[j].left &&
                userMatches[i].right == correctMatches[j].right)
            {
                ++correctCount;
                break;
            }
        }
    }

    if (correctCount == correctMatches.getSize() && userMatches.getSize() == correctMatches.getSize())
    {
        return points;
    }
    else if (correctCount >= (correctMatches.getSize() + 1) / 2)
    {
        return points / 2.0;
    }
    else
    {
        return 0.0;
    }
}
void MatchingPairsQuestion::playTestQuestion() const
{
    print();
    MyVector<CharPair> userMatches;
    while (true)
    {
        userMatches.clear();
        MyString input = readMyString("Enter your matches (e.g. (A,a), (B,b)): ");
        MyVector<MyString> pairs = input.split(", ");
        bool allValid = true;
        for (int i = 0; i < pairs.getSize(); ++i)
        {
            pairs[i].trim();
            if (pairs[i].getSize() != 5 || pairs[i][0] != '(' || pairs[i][2] != ',' || pairs[i][4] != ')')
            {
                allValid = false;
                break;
            }

            char left = pairs[i][1];
            char right = pairs[i][3];

            if (left < 'A' || left >= 'A' + leftColumn.getSize() ||
                right < 'a' || right >= 'a' + rightColumn.getSize())
            {
                allValid = false;
                break;
            }

            bool duplicate = false;
            for (int j = 0; j < userMatches.getSize(); ++j)
            {
                if (userMatches[j].left == left || userMatches[j].right == right)
                {
                    duplicate = true;
                    break;
                }
            }
            if (duplicate)
            {
                allValid = false;
                break;
            }
            userMatches.pushBack(CharPair(left, right));
        }
        if (allValid)
        {
            break;
        }
        std::cout << "Invalid input! Please enter valid unique pairs like (A,a), (B,b) using only listed letters.\n";
    }
    std::cout << "Correct answer: ";
    for (int i = 0; i < correctMatches.getSize(); i++)
    {
        std::cout << "(" << correctMatches[i].left << "," << correctMatches[i].right << ")";
        if (i + 1 != correctMatches.getSize())
        {
            std::cout << ", ";
        }
        else
        {
            std::cout << std::endl;
        }
    }
}
void MatchingPairsQuestion::writeToBinaryFile(std::ofstream& ofs) const
{
    Question::writeToBinaryFile(ofs);

    int leftSize = leftColumn.getSize();
    ofs.write((const char*)&leftSize, sizeof(leftSize));
    for (int i = 0; i < leftSize; i++)
        leftColumn[i].writeToBinaryFile(ofs);

    int rightSize = rightColumn.getSize();
    ofs.write((const char*)&rightSize, sizeof(rightSize));
    for (int i = 0; i < rightSize; i++)
        rightColumn[i].writeToBinaryFile(ofs);

    int matchSize = correctMatches.getSize();
    ofs.write((const char*)&matchSize, sizeof(matchSize));
    for (int i = 0; i < matchSize; ++i)
    {
        ofs.write((const char*)&correctMatches[i].left, sizeof(char));
        ofs.write((const char*)&correctMatches[i].right, sizeof(char));
    }
}
void MatchingPairsQuestion::readFromBinaryFile(std::ifstream& ifs)
{
    Question::readFromBinaryFile(ifs);

    int leftSize = 0;
    ifs.read((char*)&leftSize, sizeof(leftSize));
    leftColumn.clear();
    for (int i = 0; i < leftSize; ++i)
    {
        MyString str;
        str.readFromBinaryFile(ifs);
        leftColumn.pushBack(str);
    }

    int rightSize = 0;
    ifs.read((char*)&rightSize, sizeof(rightSize));
    rightColumn.clear();
    for (int i = 0; i < rightSize; ++i)
    {
        MyString str;
        str.readFromBinaryFile(ifs);
        rightColumn.pushBack(str);
    }

    correctMatches.clear();
    int matchSize = 0;
    ifs.read((char*)&matchSize, sizeof(matchSize));
    for (int i = 0; i < matchSize; i++)
    {
        char left, right;
        ifs.read((char*)&left, sizeof(char));
        ifs.read((char*)&right, sizeof(char));
        correctMatches.pushBack(CharPair(left, right));
    }
}
void MatchingPairsQuestion::saveToFile(std::ofstream& ofs) const
{
    ofs << description << "\n";
    int leftSize = leftColumn.getSize();
    int rightSize = rightColumn.getSize();
    int maxRows = leftSize > rightSize ? leftSize : rightSize;
    for (int i = 0; i < maxRows; ++i)
    {
        if (i < leftSize)
        {
            ofs << "   " << (char)('A' + i) << ") " << leftColumn[i];
        }
        else
        {
            ofs << "      ";
        }
        ofs << "    ";
        if (i < rightSize)
        {
            ofs << "   " << (char)('a' + i) << ") " << rightColumn[i];
        }
        ofs << std::endl;
    }
}


