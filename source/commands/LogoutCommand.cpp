#include "LogoutCommand.h"

LogoutCommand::LogoutCommand(const MyString& input, Context& ctx)
	:ctx(ctx) {}

void LogoutCommand::execute()
{
	ctx.loggedUser = nullptr;
	std::cout << "Logout succesful!" << std::endl;
}