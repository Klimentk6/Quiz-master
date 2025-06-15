#include "ViewReportsCommand.h"

ViewReportsCommand::ViewReportsCommand(const MyString& input, Context& ctx)
	: ctx(ctx) {}

void ViewReportsCommand::execute()
{
	ctx.loggedUser->printReports();
}
