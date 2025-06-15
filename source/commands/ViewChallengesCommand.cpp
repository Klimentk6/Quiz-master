#include "ViewChallengesCommand.h"

ViewChallengesCommand::ViewChallengesCommand(const MyString& input, Context& ctx)
	:ctx(ctx) {}

void ViewChallengesCommand::execute()
{
	ctx.loggedUser->printChallenges();
}
