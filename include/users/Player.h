#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Quiz.h"
#include "User.h"
#include "TestModeChallenge.h"
#include "NormalModeChallenge.h"
#include "CreateQuizChallenge.h"

using namespace Utils;

class Player : public User
{
public:
	Player() = default;
	Player(const MyString& name, const MyString& surname, const MyString& username, const MyString& password);

	User* clone() const override;
	UserType getType() const override;
	void writeToBinaryFile(std::ofstream& ofs) const override;
	void readFromBinaryFile(std::ifstream& ifs) override;

	void print(const MyVector<Quiz>& allQuizes) const override;
	void printShort(const MyVector<Quiz>& allQuizes) const override;
	void printFinishedChallenges() const override;
	bool isQuizLiked(int quizId) const override;
	bool isQuizFavorite(int quizId) const override;
	void likeQuiz(int quizId) override;
	void unlikeQuiz(int quizId) override;
	void addToFavsQuiz(int quizId) override;
	void removeFromFavsQuiz(int quizId) override;
	void addCreatedQuiz(int quizId) override;
	void testModeDone() override;
	void normalModeDone() override;
	void createQuizDone() override;
	void printChallenges() override;

private:
	void addNewPoints(unsigned newPoints);
	int getNextLevelPoints() const;
	void printInfo() const;
	void printCreatedQuizzes(const MyVector<Quiz>& allQuizes) const;
	void printLikedQuizzes(const MyVector<Quiz>& allQuizes) const;
	void printFavoriteQuizzes(const MyVector<Quiz>& allQuizes) const;

	int points;
	int level;
	MyVector<int> createdQuizzes;
	MyVector<int> favoriteQuizzes;
	MyVector<int> likedQuizzes;
	TestModeChallenge testModeChallenge;
	NormalModeChallenge normalModeChallenge;
	CreateQuizChallenge createQuizchallenge;
	MyVector<MyString> challengeMailbox;
};

