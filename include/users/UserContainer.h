#pragma once
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "User.h"
#include "UserFactory.h"

using namespace Utils;

class UserContainer
{
public:
	UserContainer();
	UserContainer(const char* fileName);
	UserContainer(const UserContainer& other);
	UserContainer& operator=(const UserContainer& other);
	~UserContainer();

	User* getUserPointer(const MyString& username);
	void addUser(const User& newUser);
	bool doesUsernameExist(const MyString& username) const;
	void banUser(const MyString& username);

	void writeToBinaryFile(const char* fileName);
	void readFromBinaryFile(const char* fileName);

	unsigned getSize() const;

private:
	void copyFrom(const UserContainer& other);
	void free();

	void resize(int newCapacity);
	static unsigned calculateCapacity(unsigned size, unsigned minCapacity);
	static constexpr unsigned MIN_CAPACITY = 16;
	static constexpr unsigned RESIZE_COEFF = 2;

	void addDefaultAdministrators();

	User** arr;
	unsigned size;
	unsigned capacity;
};

