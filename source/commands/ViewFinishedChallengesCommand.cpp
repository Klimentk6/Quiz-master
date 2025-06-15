#include "ViewFinishedChallengesCommand.h"

ViewFinishedChallengesCommand::ViewFinishedChallengesCommand(const MyString& input, Context& ctx)
	: ctx(ctx) {}

void ViewFinishedChallengesCommand::execute()
{
	ctx.loggedUser->printFinishedChallenges();
}
