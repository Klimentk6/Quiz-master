#include "RemoveFromFavsCommand.h"

RemoveFromFavsCommand::RemoveFromFavsCommand(const MyString& input, Context& ctx) : ctx(ctx)
{
	MyVector<MyString> parts = input.split(' ');
	quizId = parts[1].toInt();
}

void RemoveFromFavsCommand::execute()
{
	
	if (ctx.loggedUser->isQuizFavorite(quizId))
	{
		ctx.loggedUser->removeFromFavsQuiz(quizId);
		std::cout << "You removed the quiz from favorites successfully!" << std::endl;
	}
	else
	{
		std::cout << "Invalid id" << std::endl;
	}
}
