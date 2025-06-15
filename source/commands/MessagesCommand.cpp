#include "MessagesCommand.h"

MessagesCommand::MessagesCommand(const MyString& input, Context& ctx)
	:ctx(ctx) {}

void MessagesCommand::execute()
{
	ctx.loggedUser->printMailBox();
}

