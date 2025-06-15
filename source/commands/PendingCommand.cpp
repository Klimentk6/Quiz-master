#include "PendingCommand.h"

PendingCommand::PendingCommand(const MyString& input, Context& ctx)
	:ctx(ctx) {}

void PendingCommand::execute()
{
	bool foundQuiz = false;
	int allQuizzesSize = ctx.allQuizzes.getSize();
	for (int i = 0; i < allQuizzesSize; i++)
	{
		Quiz& currentQuiz = ctx.allQuizzes.getAt(i);
		if (currentQuiz.getStatus() == QuizStatus::Pending)
		{
			foundQuiz = true;
			currentQuiz.printInfo();
		}
	}
	if (!foundQuiz)
	{
		std::cout << "No pending quizzes." << std::endl;
	}
}
