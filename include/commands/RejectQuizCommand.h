#pragma once
#include <iostream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Context.h"
#include "Command.h"

using namespace Utils;

class RejectQuizCommand : public Command
{
public:
	RejectQuizCommand(const MyString& input, Context& ctx);

	void execute() override;

private:
	int quizId;
	MyString reason;
	Context& ctx;
};

