#pragma once
#include <iostream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Context.h"
#include "Command.h"

using namespace Utils;

class StartQuizCommand : public Command
{
public:
	StartQuizCommand(const MyString& input, Context& ctx);

	void execute() override;

private:
	int quizId;
	bool isInTestMode;
	bool isShuffleOn;
	Context& ctx;
};

