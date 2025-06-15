#pragma once
#include <iostream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Context.h"
#include "Command.h"

using namespace Utils;

class BanUserCommand : public Command
{
public:
	BanUserCommand(const MyString& input, Context& ctx);

	void execute() override;

private:
	MyString username;
	Context& ctx;
};

