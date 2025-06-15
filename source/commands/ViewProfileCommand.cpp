#include "ViewProfileCommand.h"

ViewProfileCommand::ViewProfileCommand(const MyString& input, Context& ctx)
	:ctx(ctx) {}

void ViewProfileCommand::execute()
{
	ctx.loggedUser->print(ctx.allQuizzes);
}
