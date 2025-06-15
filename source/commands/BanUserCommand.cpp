#include "BanUserCommand.h"

BanUserCommand::BanUserCommand(const MyString& input, Context& ctx) : ctx(ctx)
{
	MyVector<MyString> parts = input.split(' ');
	username = parts[1];
}

void BanUserCommand::execute()
{
	if (ctx.allUsers.doesUsernameExist(username))
	{
		if (ctx.allUsers.getUserPointer(username)->getType() == UserType::Administrator)
		{
			std::cout << "Cannot ban an administrator." << std::endl;
		}
		else 
		{
			if (ctx.allUsers.getUserPointer(username)->getIsBanned())
			{
				std::cout << "This user is already banned." << std::endl;
			}
			else
			{
				ctx.allUsers.getUserPointer(username)->setIsBanned(true);
				std::cout << "User banned succesfuly!" << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Invalid username!" << std::endl;
	}
}
