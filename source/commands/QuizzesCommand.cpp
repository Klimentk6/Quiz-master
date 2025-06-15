#include "QuizzesCommand.h"

QuizzesCommand::QuizzesCommand(const MyString& input, Context& ctx)
	:ctx(ctx) {}

void QuizzesCommand::execute()
{
	bool foundQuiz = false;
	int quizzesCount = ctx.allQuizzes.getSize();
	for (int i = 0; i < quizzesCount; i++)
	{
		Quiz& currentQuiz = ctx.allQuizzes.getAt(i);
		if (currentQuiz.getStatus() == QuizStatus::Approved)
		{
			foundQuiz = true;
			currentQuiz.printData();
		}
	}
	if (!foundQuiz)
	{
		std::cout << "No quizzes created." << std::endl;
	}
}
