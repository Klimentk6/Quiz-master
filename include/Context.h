#pragma once
#include <iostream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "UserContainer.h"
#include "Quiz.h"
#include "Administrator.h"

using namespace Utils;

class Context
{
public:
	Context();
	~Context();

	void readFromBinaryFile();
	void writeToBinaryFile();

	UserContainer allUsers;
	MyVector<Quiz> allQuizzes;
	User* loggedUser;
};

