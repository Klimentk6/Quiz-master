#pragma once
#include <iostream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Context.h"
#include "Command.h"

using namespace Utils;

class LikeQuizCommand : public Command
{
public:
	LikeQuizCommand(const MyString& input, Context& ctx);

	void execute() override;

private:
	int quizId;
	Context& ctx;
};

