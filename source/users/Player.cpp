#include "Player.h"

Player::Player(const MyString& name, const MyString& surname, const MyString& username, const MyString& password)
	:User(name, surname, username, password), createdQuizzes(), likedQuizzes(), favoriteQuizzes()
{
	points = 0;
	level = 1;
}

User* Player::clone() const
{
	return new Player(*this);
}
UserType Player::getType() const
{
	return UserType::Player;
}
void Player::writeToBinaryFile(std::ofstream& ofs) const
{
	name.writeToBinaryFile(ofs);
	surname.writeToBinaryFile(ofs);
	username.writeToBinaryFile(ofs);
	password.writeToBinaryFile(ofs);
	ofs.write((const char*)&isBanned, sizeof(isBanned));
	ofs.write((const char*)&points, sizeof(points));
	ofs.write((const char*)&level, sizeof(level));
	int createdSize = createdQuizzes.getSize();
	ofs.write((const char*)&createdSize, sizeof(createdSize));
	for (unsigned i = 0; i < createdSize; i++)
	{
		ofs.write((const char*)&createdQuizzes[i], sizeof(int));
	}
	int favoriteSize = favoriteQuizzes.getSize();
	ofs.write((const char*)&favoriteSize, sizeof(favoriteSize));
	for (unsigned i = 0; i < favoriteSize; ++i)
	{
		ofs.write((const char*)&favoriteQuizzes[i], sizeof(int));
	}
	int likedSize = likedQuizzes.getSize();
	ofs.write((const char*)&likedSize, sizeof(likedSize));
	for (unsigned i = 0; i < likedSize; ++i)
	{
		ofs.write((const char*)&likedQuizzes[i], sizeof(int));
	}
	testModeChallenge.writeToBinaryFile(ofs);
	normalModeChallenge.writeToBinaryFile(ofs);
	createQuizchallenge.writeToBinaryFile(ofs);
	challengeMailbox.writeToBinaryFile(ofs);
}
void Player::readFromBinaryFile(std::ifstream& ifs)
{
	name.readFromBinaryFile(ifs);
	surname.readFromBinaryFile(ifs);
	username.readFromBinaryFile(ifs);
	password.readFromBinaryFile(ifs);
	ifs.read((char*)&isBanned, sizeof(isBanned));
	ifs.read((char*)&points, sizeof(points));
	ifs.read((char*)&level, sizeof(level));
	int createdSize = 0;
	ifs.read((char*)&createdSize, sizeof(createdSize));
	createdQuizzes.clear();
	for (int i = 0; i < createdSize; i++) 
	{
		int id = 0;
		ifs.read((char*)&id, sizeof(id));
		createdQuizzes.pushBack(id);
	}
	int favoriteSize = 0;
	ifs.read((char*)&favoriteSize, sizeof(favoriteSize));
	favoriteQuizzes.clear();
	for (int i = 0; i < favoriteSize; i++) 
	{
		int id = 0;
		ifs.read((char*)&id, sizeof(id));
		favoriteQuizzes.pushBack(id);
	}
	int likedSize = 0;
	ifs.read((char*)&likedSize, sizeof(likedSize));
	likedQuizzes.clear();
	for (int i = 0; i < likedSize; i++)
	{
		int id = 0;
		ifs.read((char*)&id, sizeof(id));
		likedQuizzes.pushBack(id);
	}
	testModeChallenge.readFromBinaryFile(ifs);
	normalModeChallenge.readFromBinaryFile(ifs);
	createQuizchallenge.readFromBinaryFile(ifs);
	challengeMailbox.readFromBinaryFile(ifs);
}

void Player::addNewPoints(unsigned newPoints)
{
	unsigned nextLevelPoints = getNextLevelPoints();
	points += newPoints;
	if (points >= nextLevelPoints)
	{
		level++;
		MyString message = "Level ";
		message += convertIntToMyString(level);
		message += " reached!";
		addMessage(message);
	}
}

int Player::getNextLevelPoints() const
{
	return ((points / 1000) + 1) * 1000;
}
void Player::print(const MyVector<Quiz>& allQuizzes) const
{
	printInfo();
	printCreatedQuizzes(allQuizzes);
	printLikedQuizzes(allQuizzes);
	printFavoriteQuizzes(allQuizzes);
}
void Player::printShort(const MyVector<Quiz>& allQuizzes) const
{
	printInfo();
	printCreatedQuizzes(allQuizzes);
}
void Player::printFinishedChallenges() const
{
	for (int i = 0; i < challengeMailbox.getSize(); i++)
	{
		std::cout << challengeMailbox[i] << std::endl;
	}
}
bool Player::isQuizLiked(int quizId) const
{
	int likedQuizzesSize = likedQuizzes.getSize();
	for (int i = 0; i < likedQuizzesSize; i++)
	{
		if (quizId == likedQuizzes.getAt(i))
		{
			return true;
		}
	}
	return false;
}
bool Player::isQuizFavorite(int quizId) const
{
	int favoriteQuizzesSize = favoriteQuizzes.getSize();
	for (int i = 0; i < favoriteQuizzesSize; i++)
	{
		if (quizId == favoriteQuizzes.getAt(i))
		{
			return true;
		}
	}
	return false;
}
void Player::likeQuiz(int quizId) 
{
	likedQuizzes.pushBack(quizId);
}
void Player::unlikeQuiz(int quizId)
{
	int likedQuizzesSize = likedQuizzes.getSize();
	for (int i = 0; i < likedQuizzesSize; i++)
	{
		if (likedQuizzes.getAt(i) == quizId)
		{
			likedQuizzes.removeAt(i);
			return;
		}
	}
}
void Player::addToFavsQuiz(int quizId)
{
	favoriteQuizzes.pushBack(quizId);
}
void Player::removeFromFavsQuiz(int quizId)
{
	int favQuizzesSize = favoriteQuizzes.getSize();
	for (int i = 0; i < favQuizzesSize; i++)
	{
		if (favoriteQuizzes.getAt(i) == quizId)
		{
			favoriteQuizzes.removeAt(i);
			return;
		}
	}
}
void Player::addCreatedQuiz(int quizId)
{
	createdQuizzes.pushBack(quizId);
}
void Player::testModeDone()
{
	unsigned newPoints = testModeChallenge.testModeDone();
	if (newPoints != 0)
	{
		MyString message = "New challenge completed! You solved ";
		message += convertIntToMyString(testModeChallenge.getCount());
		message += " quizzes in test mode!\n";
		message += convertIntToMyString(newPoints);
		message += " points added.";
		addMessage(message);
		addNewPoints(newPoints);

		std::time_t now = std::time(nullptr);
		std::tm localTime = *std::localtime(&now);
		unsigned currentDay = localTime.tm_mday;
		unsigned currentMonth = localTime.tm_mon + 1;
		unsigned currentYear = localTime.tm_year + 1900;
		MyString message2;
		message2 += convertIntToMyStringWithLeadingZero(currentDay);
		message2 += ".";
		message2 += convertIntToMyStringWithLeadingZero(currentMonth);
		message2 += ".";
		message2 += convertIntToMyString(currentYear);
		message2 += " | Complete ";
		message2 += convertIntToMyString(testModeChallenge.getCount());
		message2 += " quizzes in test mode\n";
		challengeMailbox.pushBack(message2);
	}
}
void Player::normalModeDone()
{
	unsigned newPoints = normalModeChallenge.normalModeDone();
	if (newPoints != 0)
	{
		MyString message = "New challenge completed! You solved ";
		message += convertIntToMyString(normalModeChallenge.getCount());
		message += " quizzes in normal mode!\n";
		message += convertIntToMyString(newPoints);
		message += " points added.";
		addMessage(message);
		addNewPoints(newPoints);

		std::time_t now = std::time(nullptr);
		std::tm localTime = *std::localtime(&now);
		unsigned currentDay = localTime.tm_mday;
		unsigned currentMonth = localTime.tm_mon + 1;
		unsigned currentYear = localTime.tm_year + 1900;
		MyString message2;
		message2 += convertIntToMyStringWithLeadingZero(currentDay);
		message2 += ".";
		message2 += convertIntToMyStringWithLeadingZero(currentMonth);
		message2 += ".";
		message2 += convertIntToMyString(currentYear);
		message2 += " | Complete ";
		message2 += convertIntToMyString(normalModeChallenge.getCount());
		message2 += " quizzes in normal mode\n";
		challengeMailbox.pushBack(message2);
	}
}
void Player::createQuizDone()
{
	unsigned newPoints = createQuizchallenge.createQuizDone();
	if (newPoints != 0)
	{
		MyString message = "New challenge completed! You created ";
		message += convertIntToMyString(createQuizchallenge.getCount());
		message += " quizzes!\n";
		message += convertIntToMyString(newPoints);
		message += " points added.";
		addMessage(message);
		addNewPoints(newPoints);

		std::time_t now = std::time(nullptr);
		std::tm localTime = *std::localtime(&now);
		unsigned currentDay = localTime.tm_mday;
		unsigned currentMonth = localTime.tm_mon + 1;
		unsigned currentYear = localTime.tm_year + 1900;
		MyString message2;
		message2 += convertIntToMyStringWithLeadingZero(currentDay);
		message2 += ".";
		message2 += convertIntToMyStringWithLeadingZero(currentMonth);
		message2 += ".";
		message2 += convertIntToMyString(currentYear);
		message2 += " | Create ";
		message2 += convertIntToMyString(createQuizchallenge.getCount());
		message2 += " quizzes\n";
		challengeMailbox.pushBack(message2);
	}
}
void Player::printChallenges()
{
	testModeChallenge.print();
	normalModeChallenge.print();
	createQuizchallenge.print();
}
void Player::printInfo() const
{
	std::cout << name << " " << surname << " @" << username << std::endl;
	std::cout << "Level: " << level << std::endl;
	std::cout << points << "/" << getNextLevelPoints() << " Points to next level" << std::endl;
	std::cout << std::endl;
}
void Player::printCreatedQuizzes(const MyVector<Quiz>& allQuizzes) const
{
	std::cout << "Created quizzes:" << std::endl;
	bool foundCreatedQuiz = false;
	int createdQuizzesSize = createdQuizzes.getSize();
	for (int i = 0; i < createdQuizzesSize; i++)
	{
		int quizId = createdQuizzes[i];
		int allQuizzesSize = allQuizzes.getSize();
		for (int j = 0; j < allQuizzesSize; j++)
		{
			const Quiz& quiz = allQuizzes[j];
			if (quiz.getId() == quizId && quiz.getStatus() != QuizStatus::Deleted)
			{
				std::cout << "[" << quizId << "] " << quiz.getTitle() << std::endl;
				foundCreatedQuiz = true;
				break;
			}
		}
	}
	if (!foundCreatedQuiz)
	{
		std::cout << "You have no created quizzes" << std::endl;
	}
	std::cout << std::endl;
}
void Player::printLikedQuizzes(const MyVector<Quiz>& allQuizzes) const
{
	std::cout << "Liked quizzes: ";
	bool foundLikedQuiz = false;
	int likedQuizzesSize = likedQuizzes.getSize();
	for (int i = 0; i < likedQuizzesSize; i++)
	{
		int quizId = likedQuizzes[i];
		int allQuizzesSize = allQuizzes.getSize();
		for (int j = 0; j < allQuizzesSize; j++)
		{
			const Quiz& quiz = allQuizzes[j];
			if (quiz.getId() == quizId && quiz.getStatus() != QuizStatus::Deleted)
			{
				std::cout << " [" << quizId << "]";;
				foundLikedQuiz = true;
				break;
			}
		}
	}
	if (!foundLikedQuiz)
	{
		std::cout << "You have no liked quizzes" << std::endl;
	}
	std::cout << std::endl;
}
void Player::printFavoriteQuizzes(const MyVector<Quiz>& allQuizzes) const
{
	std::cout << "Favorite quizzes: ";
	bool foundFavoriteQuiz = false;
	int favoriteQuizzesSize = favoriteQuizzes.getSize();
	for (int i = 0; i < favoriteQuizzesSize; i++)
	{
		int quizId = favoriteQuizzes[i];
		int allQuizzesSize = allQuizzes.getSize();
		for (int j = 0; j < allQuizzesSize; j++)
		{
			const Quiz& quiz = allQuizzes[j];
			if (quiz.getId() == quizId && quiz.getStatus() != QuizStatus::Deleted)
			{
				std::cout << " [" << quizId << "]";
				foundFavoriteQuiz = true;
				break;
			}
		}
	}
	if (foundFavoriteQuiz == false)
	{
		std::cout << "You have no favorite quizzes" << std::endl;
	}
	std::cout << std::endl;
}

