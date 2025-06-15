#include "User.h"

User::User(const MyString& name, const MyString& surname, const MyString& username, const MyString& password)
	: name(name), surname(surname), username(username), password(password), isBanned(false) {}

void User::printMailBox() const
{
	int mailboxSize = mailbox.getSize();
	if (mailboxSize == 0)
	{
		std::cout << "Mailbox is empty." << std::endl;
		return;
	}
	for (int i = 0; i < mailboxSize; i++)
	{
		std::cout << mailbox.getAt(i) << std::endl;
	}
}
void User::addMessage(const MyString& newMessage)
{
	mailbox.pushBack(newMessage);
}

const MyString& User::getName() const
{
	return name;
}
const MyString& User::getSurname() const
{
	return surname;
}
const MyString& User::getUsername() const
{
	return username;
}
bool User::isPasswordCorrect(const MyString& checkPassword) const
{
	return checkPassword == password;
}
bool User::getIsBanned() const
{
	return isBanned;
}
void User::setIsBanned(bool ban)
{
	isBanned = ban;
}

void User::print(const MyVector<Quiz>& allQuizes) const
{
}
void User::printShort(const MyVector<Quiz>& allQuizes) const
{
}
void User::printFinishedChallenges() const
{
}
bool User::isQuizLiked(int quizId) const
{
	return false;
}
bool User::isQuizFavorite(int quizId) const
{
	return false;
}
void User::likeQuiz(int quizId)
{
}
void User::unlikeQuiz(int quizId)
{
}
void User::addToFavsQuiz(int quizId)
{
}
void User::removeFromFavsQuiz(int quizId)
{
}
void User::addCreatedQuiz(int quizId)
{
}
void User::printReports() const
{
}
void User::testModeDone()
{
}
void User::normalModeDone()
{
}
void User::createQuizDone()
{
}
void User::printChallenges()
{
}

void User::writeToBinaryFile(std::ofstream& ofs) const
{
	name.writeToBinaryFile(ofs);
	surname.writeToBinaryFile(ofs);
	username.writeToBinaryFile(ofs);
	password.writeToBinaryFile(ofs);
	mailbox.writeToBinaryFile(ofs);
	ofs.write((const char*)&isBanned, sizeof(isBanned));
}
void User::readFromBinaryFile(std::ifstream& ifs) 
{
	name.readFromBinaryFile(ifs);
	surname.readFromBinaryFile(ifs);
	username.readFromBinaryFile(ifs);
	password.readFromBinaryFile(ifs);
	mailbox.readFromBinaryFile(ifs);
	ifs.read((char*)&isBanned, sizeof(isBanned));
}