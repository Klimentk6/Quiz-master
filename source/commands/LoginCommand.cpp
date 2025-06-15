#include "LoginCommand.h"

LoginCommand::LoginCommand(const MyString& input, Context& ctx) : ctx(ctx)
{
    MyVector<MyString> parts = input.split(' ');
    username = parts[1];
    password = parts[2];
}

void LoginCommand::execute()
{
    if (ctx.allUsers.doesUsernameExist(username))
    {
        User* userCheck = ctx.allUsers.getUserPointer(username);
        if (userCheck->isPasswordCorrect(password))
        {
            if (userCheck->getIsBanned())
            {
                std::cout << "This user is banned!" << std::endl;
            }
            else
            {
                ctx.loggedUser = userCheck;
                std::cout << "Welcome " << ctx.loggedUser->getName() << " " << ctx.loggedUser->getSurname() << "!" << std::endl;
            } 
        }
        else
        {
            std::cout << "Invalid password!" << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid username!" << std::endl;
    }
}
