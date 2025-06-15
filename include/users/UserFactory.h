#pragma once
#include <iostream>
#include "Utils.h"
#include "User.h"
#include "Administrator.h"
#include "Player.h"

using namespace Utils;

class UserFactory
{
public:
	static User* create(UserType type);
};

