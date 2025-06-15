#include "AddToFavsCommand.h"

AddToFavsCommand::AddToFavsCommand(const MyString& input, Context& ctx) : ctx(ctx)
{
	MyVector<MyString> parts = input.split(' ');
	quizId = parts[1].toInt();
}

void AddToFavsCommand::execute()
{
	if (ctx.loggedUser->isQuizFavorite(quizId))
	{
		std::cout << "You have already added this quiz to favorite." << std::endl;
		return;
	}
	int quizzesSize = ctx.allQuizzes.getSize();
	for (int i = 0; i < quizzesSize; i++)
	{
		Quiz& currentQuiz = ctx.allQuizzes.getAt(i);
		if (currentQuiz.getStatus() == QuizStatus::Approved && currentQuiz.getId() == quizId)
		{
			ctx.loggedUser->addToFavsQuiz(quizId);
			std::cout << "You added the quiz to favorites successfully" << std::endl;
			return;
		}
	}
	std::cout << "Invalid quiz id!" << std::endl;
}
