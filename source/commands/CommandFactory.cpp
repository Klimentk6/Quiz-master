#include "CommandFactory.h"

bool isValidLoginInput(const MyString& input)
{
	MyVector<MyString> parts = input.split(' ');
	return parts.getSize() == 3 && parts[0] == "login";
}
bool isValidLogoutInput(const MyString& input)
{
	return input == "logout";
}
bool isValidHelpInput(const MyString& input)
{
	return input == "help";
}
bool isValidQuitInput(const MyString& input)
{
	return input == "quit";	
}
bool isValidPendingInput(const MyString& input)
{
	return input == "pending";
}
bool isValidApproveQuizInput(const MyString& input)
{
	MyVector<MyString> parts = input.split(' ');
	return parts.getSize() == 2 && parts[0] == "approve-quiz" && parts[1].isInt();
}
bool isValidRejectQuizInput(const MyString& input)
{
	MyVector<MyString> parts = input.split(' ');
	return parts.getSize() >= 3 && parts[0] == "reject-quiz" && parts[1].isInt();
}
bool isValidSignupInput(const MyString& input)
{
	MyVector<MyString> parts = input.split(' ');
	return parts.getSize() == 6 && parts[0] == "signup";
}
bool isValidCreateQuizInput(const MyString& input)
{
	return input == "create-quiz";
}
bool isValidViewProfileInput(const MyString& input)
{
	return input == "view-profile";
}
bool isValidQuizzesInput(const MyString& input)
{
	return input == "quizzes";
}
bool isValidQuizzesByUserInput(const MyString& input)
{
	MyVector<MyString> parts = input.split(' ');
	return parts.getSize() == 2 && parts[0] == "quizzes";
}
bool isValidLikeQuizInput(const MyString& input)
{
	MyVector<MyString> parts = input.split(' ');
	return parts.getSize() == 2 && parts[0] == "like-quiz" && parts[1].isInt();
}
bool isValidUnlikeQuizInput(const MyString& input)
{
	MyVector<MyString> parts = input.split(' ');
	return parts.getSize() == 2 && parts[0] == "unlike-quiz" && parts[1].isInt();
}
bool isValidBanUserInput(const MyString& input)
{
	MyVector<MyString> parts = input.split(' ');
	return parts.getSize() == 2 && parts[0] == "ban";
}
bool isValidMessagesInput(const MyString& input)
{
	return input == "messages";
}
bool isValidViewReportsInput(const MyString& input)
{
	return input == "view-reports";
}
bool isValidStartQuizInput(const MyString& input)
{
	MyVector<MyString> parts = input.split(' ');
	if (parts.getSize() != 4 && parts.getSize() != 3)
	{
		return false;
	}
	if (parts[0] != "start-quiz" || !parts[1].isInt())
	{
		return false;
	}
	if (parts[2] != "test" && parts[2] != "normal")
	{
		return false;
	}
	if (parts.getSize() == 3)
	{
		return true;
	}
	return parts[3] == "shuffle";
}
bool isValidRemoveQuizInput(const MyString& input)
{
	MyVector<MyString> parts = input.split(' ');
	return parts.getSize() >= 3 && parts[0] == "remove-quiz" && parts[1].isInt();
}
bool isValidSaveQuizInput(const MyString& input)
{
	MyVector<MyString> parts = input.split(' ');
	return parts.getSize() == 3 && parts[0] == "save-quiz" && parts[1].isInt();
}

bool isValidReportQuizInput(const MyString& input)
{
	MyVector<MyString> parts = input.split(' ');
	return parts.getSize() >= 3 && parts[0] == "report-quiz" && parts[1].isInt();
}
bool isValidAddToFavsInput(const MyString& input)
{
	MyVector<MyString> parts = input.split(' ');
	return parts.getSize() == 2 && parts[0] == "add-to-favs" && parts[1].isInt();
}
bool isValidRemoveFromFavsInput(const MyString& input)
{
	MyVector<MyString> parts = input.split(' ');
	return parts.getSize() == 2 && parts[0] == "remove-from-favs" && parts[1].isInt();
}
bool isValidChallengesInput(const MyString& input)
{
	return input == "challenges";
}

bool isValidViewUserInput(const MyString& input)
{
	MyVector<MyString> parts = input.split(' ');
	return parts.getSize() == 2 && parts[0] == "view";
}

bool isValidViewFinishedChallenges(const MyString& input)
{
	return input == "view-finished-challenges";
}

Command* createCommand(const MyString& input, Context& ctx)
{
	if (ctx.loggedUser == nullptr)
	{
		if (isValidLoginInput(input))
		{
			return new LoginCommand(input, ctx);
		}
		else if (isValidHelpInput(input))
		{
			return new HelpCommand(input, ctx);
		}
		else if (isValidSignupInput(input))
		{
			return new SignupCommand(input, ctx);
		}
		else
		{
			std::cout << "Invalid command!" << std::endl;
			return nullptr;
		}
	}
	else if (ctx.loggedUser->getType() == UserType::Administrator)
	{
		if (isValidLogoutInput(input))
		{
			return new LogoutCommand(input, ctx);
		}
		else if (isValidHelpInput(input))
		{
			return new HelpCommand(input, ctx);
		}
		else if (isValidPendingInput(input))
		{
			return new PendingCommand(input, ctx);
		}
		else if (isValidApproveQuizInput(input))
		{
			return new ApproveQuizCommand(input, ctx);
		}
		else if (isValidRejectQuizInput(input))
		{
			return new RejectQuizCommand(input, ctx);
		}
		else if (isValidBanUserInput(input))
		{
			return new BanUserCommand(input, ctx);
		}
		else if (isValidViewReportsInput(input))
		{
			return new ViewReportsCommand(input, ctx);
		}
		else if (isValidRemoveQuizInput(input))
		{
			return new RemoveQuizCommand(input, ctx);
		}
		else
		{
			std::cout << "Invalid command!" << std::endl;
			return nullptr;
		}
	}
	else
	{
		if (isValidLogoutInput(input))
		{
			return new LogoutCommand(input, ctx);
		}
		else if (isValidHelpInput(input))
		{
			return new HelpCommand(input, ctx);
		}
		else if (isValidCreateQuizInput(input))
		{
			return new CreateQuizCommand(input, ctx);
		}
		else if (isValidViewProfileInput(input))
		{
			return new ViewProfileCommand(input, ctx);
		}
		else if (isValidQuizzesInput(input)) 
		{
			return new QuizzesCommand(input, ctx);
		}
		else if (isValidQuizzesByUserInput(input))
		{
			return new QuizzesByUserCommand(input, ctx);
		}
		else if (isValidLikeQuizInput(input))
		{
			return new LikeQuizCommand(input, ctx);
		}
		else if (isValidUnlikeQuizInput(input))
		{
			return new UnlikeQuizCommand(input, ctx);
		}
		else if (isValidMessagesInput(input))
		{
			return new MessagesCommand(input, ctx);
		}
		else if (isValidStartQuizInput(input))
		{
			return new StartQuizCommand(input, ctx);
		}
		else if (isValidSaveQuizInput(input))
		{
			return new SaveQuizCommand(input, ctx);
		}
		else if (isValidReportQuizInput(input))
		{
			return new ReportQuizCommand(input, ctx);
		}
		else if (isValidAddToFavsInput(input))
		{
			return new AddToFavsCommand(input, ctx);
		}
		else if (isValidRemoveFromFavsInput(input))
		{
			return new RemoveFromFavsCommand(input, ctx);
		}
		else if (isValidChallengesInput(input))
		{
			return new ViewChallengesCommand(input, ctx);
		}
		else if (isValidViewUserInput(input))
		{
			return new ViewUserCommand(input, ctx);
		}
		else if (isValidViewFinishedChallenges(input))
		{
			return new ViewFinishedChallengesCommand(input, ctx);
		}
		else
		{
			std::cout << "Invalid command!" << std::endl;
			return nullptr;
		}
	}
}