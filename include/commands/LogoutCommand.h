#pragma once
#include <iostream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Context.h"
#include "Command.h"

using namespace Utils;

class LogoutCommand : public Command
{
public:
	LogoutCommand(const MyString& input, Context& ctx);

	void execute() override;

private:
	Context& ctx;
};

