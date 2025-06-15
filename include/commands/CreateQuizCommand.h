#pragma once
#include <iostream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Context.h"
#include "Command.h"
#include "QuestionFactory.h"

using namespace Utils;

class CreateQuizCommand : public Command
{
public:
	CreateQuizCommand(const MyString& input, Context& ctx);

	void execute() override;

private:
	QuestionType getTypeFromInput(unsigned questionNumber);

	Context& ctx;
};

