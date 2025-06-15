#pragma once
#include <iostream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Context.h"
#include "Command.h"

using namespace Utils;

class AddToFavsCommand : public Command
{
public:
	AddToFavsCommand(const MyString& input, Context& ctx);

	void execute() override;

private:
	int quizId;
	Context& ctx;
};

