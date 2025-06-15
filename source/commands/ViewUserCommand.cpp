#include "ViewUserCommand.h"

ViewUserCommand::ViewUserCommand(const MyString& input, Context& ctx) : ctx(ctx)
{
	MyVector<MyString> parts = input.split(' ');
	username = parts[1];
}

void ViewUserCommand::execute()
{
	User* user = ctx.allUsers.getUserPointer(username);
	if (user == nullptr || user->getType() != UserType::Player)
	{
		std::cout << "Invalid input!" << std::endl;
	}
	else
	{
		user->printShort(ctx.allQuizzes);
	}
}
