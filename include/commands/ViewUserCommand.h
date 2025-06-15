#pragma once
#include <iostream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Context.h"
#include "Command.h"

using namespace Utils;

class ViewUserCommand : public Command
{
public:
	ViewUserCommand(const MyString& input, Context& ctx);

	void execute() override;

private:
	MyString username;
	Context& ctx;
};

