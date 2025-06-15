#pragma once
#include <iostream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Context.h"
#include "Command.h"
#include "Player.h"

using namespace Utils;

class SignupCommand : public Command
{
public:
	SignupCommand(const MyString& input, Context& ctx);

	void execute() override;

private:
	MyString name;
	MyString surname;
	MyString username;
	MyString password1;
	MyString password2;
	Context& ctx;
};

