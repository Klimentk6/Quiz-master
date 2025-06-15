#pragma once
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "QuestionContainer.h"

using namespace Utils;

class Quiz
{
public:
	Quiz() = default;
	Quiz(int id, const MyString& title, const MyString& creatorUsername, const QuestionContainer& questions);

	void shuffleQuestions();
	void printInfo() const;
	void printData() const;
	void newLike();
	void startQuiz(bool isInTestMode, bool isShuffleOn);
	void saveToFile(const MyString& filepath);

	void writeToBinaryFile(std::ofstream& ofs) const;
	void readFromBinaryFile(std::ifstream& ifs);

	int getId() const;
	const char* getTitle() const;
	const MyString& getCreatorUsername() const;
	bool getIsInTestMode() const;
	QuizStatus getStatus() const;

	void setStatus(QuizStatus newStatus);

private:
	int id;
	MyString title;
	MyString creatorUsername;
	QuestionContainer questions;
	QuizStatus status;
	bool isInTestMode;
	int numberOfPlays;
	int likes;
};

