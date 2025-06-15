#include "UnlikeQuizCommand.h"

UnlikeQuizCommand::UnlikeQuizCommand(const MyString& input, Context& ctx) :ctx(ctx)
{
	MyVector<MyString> parts = input.split(' ');
	quizId = parts[1].toInt();
}

void UnlikeQuizCommand::execute()
{
	if (ctx.loggedUser->isQuizLiked(quizId))
	{
		ctx.loggedUser->unlikeQuiz(quizId);
		std::cout << "You unliked the quiz successfully!" << std::endl;
	}
	else 
	{
		std::cout << "Invalid id" << std::endl;
	}
}
