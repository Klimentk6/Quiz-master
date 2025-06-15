#include "StartQuizCommand.h"

StartQuizCommand::StartQuizCommand(const MyString& input, Context& ctx)
	: ctx(ctx)
{
	MyVector<MyString> parts = input.split(' ');
	quizId = parts[1].toInt();
	if (parts[2] == "test")
	{
		isInTestMode = true;
	}
	else
	{
		isInTestMode = false;
	}
	if (parts.getSize() == 3)
	{
		isShuffleOn = false;
	}
	else
	{
		isShuffleOn = true;
	}
}

void StartQuizCommand::execute()
{
	unsigned allQuizzesSize = ctx.allQuizzes.getSize();
	for (int i = 0; i < allQuizzesSize; i++)
	{
		Quiz& quiz = ctx.allQuizzes.getAt(i);
		if (quizId == quiz.getId() && quiz.getStatus() == QuizStatus::Approved)
		{
			quiz.startQuiz(isInTestMode, isShuffleOn);
			if (isInTestMode)
			{
				ctx.loggedUser->testModeDone();
			}
			else
			{
				ctx.loggedUser->normalModeDone();
			}
			return;
		}
	}
	std::cout << "Invalid quiz id" << std::endl;
}
