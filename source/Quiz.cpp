#include "Quiz.h"

Quiz::Quiz(int id, const MyString& title, const MyString& creatorUsername, const QuestionContainer& questions)
    :id(id), title(title), creatorUsername(creatorUsername), questions(questions) 
{
    status = QuizStatus::Pending;
    isInTestMode = false;
    numberOfPlays = 0;
    likes = 0;
}

void Quiz::shuffleQuestions()
{
    questions.shuffle();
}
void Quiz::printInfo() const
{

    std::cout << "[id " << id << "] " << title << " by " << creatorUsername << std::endl;
}
void Quiz::printData() const
{
    std::cout << id << " | " << title << " | " << creatorUsername << " | " << questions.getSize() << " Questions | " << likes << " Likes" << std::endl;
}
void Quiz::newLike()
{
    likes++;
}
void Quiz::startQuiz(bool isInTestMode, bool isShuffleOn)
{
    Quiz copy(*this);
    if (isShuffleOn)
    {
        shuffleQuestions();
    }
    if (!isInTestMode)
    {
        unsigned points = 0;;
        unsigned totalPoints = 0;
        for (int i = 0; i < questions.getSize(); i++)
        {
            Question* question = questions.getAt(i);
            std::cout << i + 1 << ") ";
            points += question->playQuestion();
            totalPoints += question->getPoints();
        }
        std::cout << "Your score is " << points << "/" << totalPoints << std::endl;
    }
    else
    {
        for (int i = 0; i < questions.getSize(); i++)
        {
            Question* question = questions.getAt(i);
            std::cout << i + 1 << ") ";
            question->playTestQuestion();
        }
    }
    numberOfPlays++;
    *this = copy;
}
void Quiz::saveToFile(const MyString& filepath)
{
    std::ofstream ofs(filepath.getCharArr());
    if (!ofs.is_open())
    {
        std::cout << "Cannot open file for writing!" << std::endl;
    }
    ofs << title << " - " << questions.getSize() << " Questions\n"
        << "   By @" << creatorUsername << "\n\n";
    questions.saveToFIle(ofs);
}

void Quiz::writeToBinaryFile(std::ofstream& ofs) const
{
    ofs.write((const char*)&id, sizeof(id));
    title.writeToBinaryFile(ofs);
    creatorUsername.writeToBinaryFile(ofs);
    questions.writeToBinaryFile(ofs);
    ofs.write((const char*)&status, sizeof(status));
    ofs.write((const char*)&isInTestMode, sizeof(isInTestMode));
    ofs.write((const char*)&numberOfPlays, sizeof(numberOfPlays));
    ofs.write((const char*)&likes, sizeof(likes));
}
void Quiz::readFromBinaryFile(std::ifstream& ifs)
{
    ifs.read((char*)&id, sizeof(id));
    title.readFromBinaryFile(ifs);
    creatorUsername.readFromBinaryFile(ifs);
    questions.readFromBinaryFile(ifs);
    ifs.read((char*)&status, sizeof(status));
    ifs.read((char*)&isInTestMode, sizeof(isInTestMode));
    ifs.read((char*)&numberOfPlays, sizeof(numberOfPlays));
    ifs.read((char*)&likes, sizeof(likes));
}

int Quiz::getId() const
{
    return id;
}
const char* Quiz::getTitle() const
{
    return title.getCharArr();
}
const MyString& Quiz::getCreatorUsername() const
{
    return creatorUsername;
}
bool Quiz::getIsInTestMode() const
{
    return isInTestMode;
}
QuizStatus Quiz::getStatus() const
{
    return status;
}
void Quiz::setStatus(QuizStatus newStatus)
{
    status = newStatus;
}