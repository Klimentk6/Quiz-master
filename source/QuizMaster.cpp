#include <iostream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Context.h"
#include "Command.h"
#include "CommandFactory.h"

using namespace Utils;

int main()
{
    Context ctx;
    while (true)
    {
        std::cout << "> ";
        MyString input;
        input.readLine(std::cin);
        if (isValidQuitInput(input)) break;
        Command* command = createCommand(input, ctx);
        if (command)
        {
            command->execute();
            delete command;
        }
    }
    return 0;
}