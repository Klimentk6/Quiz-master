#include "QuizzesByUserCommand.h"

QuizzesByUserCommand::QuizzesByUserCommand(const MyString& input, Context& ctx) : ctx(ctx)
{
	MyVector<MyString> parts = input.split(' ');
	username = parts[1];
}

void QuizzesByUserCommand::execute()
{
	if (!ctx.allUsers.doesUsernameExist(username))
	{
		std::cout << "Invalid username!" << std::endl;
		return;
	}
	bool foundQuiz = false;
	int quizzesCount = ctx.allQuizzes.getSize();
	for (int i = 0; i < quizzesCount; i++)
	{
		Quiz& currentQuiz = ctx.allQuizzes.getAt(i);
		if (currentQuiz.getStatus() == QuizStatus::Approved && currentQuiz.getCreatorUsername() == username)
		{
			foundQuiz = true;
			currentQuiz.printData();
		}
	}
	if (!foundQuiz)
	{
		std::cout << "No quizzes created by that user." << std::endl;
	}
}
