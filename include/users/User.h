#pragma once
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Quiz.h"

using namespace Utils;

class User 
{
public:
    User() = default;
    User(const MyString& name, const MyString& surname, const MyString& username, const MyString& password);
    virtual ~User() = default;

    virtual User* clone() const = 0;
    virtual UserType getType() const = 0;
    virtual void writeToBinaryFile(std::ofstream& ofs) const = 0;
    virtual void readFromBinaryFile(std::ifstream& ifs) = 0;

    virtual void print(const MyVector<Quiz>& allQuizes) const;
    virtual void printShort(const MyVector<Quiz>& allQuizes) const;
    virtual void printFinishedChallenges() const;
    virtual bool isQuizLiked(int quizId) const;
    virtual bool isQuizFavorite(int quizId) const;
    virtual void likeQuiz(int quizId);
    virtual void unlikeQuiz(int quizId);
    virtual void addToFavsQuiz(int quizId);
    virtual void removeFromFavsQuiz(int quizId);
    virtual void addCreatedQuiz(int quizId);
    virtual void printReports() const;
    virtual void testModeDone();
    virtual void normalModeDone();
    virtual void createQuizDone();
    virtual void printChallenges();

    void printMailBox() const;
    void addMessage(const MyString& newMessage);
    const MyString& getName() const;
    const MyString& getSurname() const;
    const MyString& getUsername() const;
    bool isPasswordCorrect(const MyString& checkPassword) const;
    bool getIsBanned() const;
    void setIsBanned(bool ban);

protected:
    MyString name;
    MyString surname;
    MyString username;
    MyString password;
    MyVector<MyString> mailbox;
    bool isBanned;
};

