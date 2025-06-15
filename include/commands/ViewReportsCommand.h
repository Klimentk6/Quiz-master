#pragma once
#include <iostream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Context.h"
#include "Command.h"

using namespace Utils;

class ViewReportsCommand : public Command
{
public:
	ViewReportsCommand(const MyString& input, Context& ctx);

	void execute() override;

private:
	Context& ctx;
};

