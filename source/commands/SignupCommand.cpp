#include "SignupCommand.h"

SignupCommand::SignupCommand(const MyString& input, Context& ctx) : ctx(ctx)
{
    MyVector<MyString> parts = input.split(' ');
    name = parts[1];
    surname = parts[2];
    username = parts[3];
    password1 = parts[4];
    password2 = parts[5];
}

void SignupCommand::execute()
{
    if (password1 != password2)
    {
        std::cout << "Invalid password" << std::endl;
    }
    else if (ctx.allUsers.doesUsernameExist(username)) 
    {
        std::cout << "Username already exists" << std::endl;
    }
    else
    {
        Player newPlayer(name, surname, username, password1);
        ctx.allUsers.addUser(newPlayer);
        std::cout << "Signup successful!" << std::endl;
    }
}
