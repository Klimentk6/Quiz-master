#include "LikeQuizCommand.h"

LikeQuizCommand::LikeQuizCommand(const MyString& input, Context& ctx)
	:ctx(ctx)
{
	MyVector<MyString> parts = input.split(' ');
	quizId = parts[1].toInt();
}

void LikeQuizCommand::execute()
{
	if (ctx.loggedUser->isQuizLiked(quizId))
	{
		std::cout << "You have already liked this quiz." << std::endl;
		return;
	}
	int quizzesSize = ctx.allQuizzes.getSize();
	for (int i = 0; i < quizzesSize; i++)
	{
		Quiz& currentQuiz = ctx.allQuizzes.getAt(i);
		if (currentQuiz.getStatus() == QuizStatus::Approved && currentQuiz.getId() == quizId)
		{
			ctx.loggedUser->likeQuiz(quizId);
			currentQuiz.newLike();
			std::cout << "You liked the quiz successfully" << std::endl;
			return;
		}
	}
	std::cout << "Invalid quiz id!" << std::endl;
}

