#include "CreateQuizCommand.h"

CreateQuizCommand::CreateQuizCommand(const MyString& input, Context& ctx)
	:ctx(ctx) {}

QuestionType CreateQuizCommand::getTypeFromInput(unsigned questionNumber)
{
	MyString typeStr;
	while (true)
	{
		std::cout << "Enter question " << questionNumber << " type (T/F, SC, MC, ShA, MP): ";
		typeStr.readLine(std::cin);
		if (typeStr == "T/F")
		{
			return QuestionType::TrueOrFalse;
		}
		else if (typeStr == "SC")
		{
			return QuestionType::SingleChoice;
		}
		else if (typeStr == "MC")
		{
			return QuestionType::MultipleChoice;
		}
		else if (typeStr == "ShA")
		{
			return QuestionType::ShortAnswer;
		}
		else if (typeStr == "MP")
		{
			return QuestionType::MatchingPairs;
		}
		else
		{
			std::cout << "Invalid question type!" << std::endl;
		}
	}
}

void CreateQuizCommand::execute()
{
	QuestionContainer questions;
	MyString title = readMyString("Enter quiz title: ");
	int questionsSize = readPositiveInt("Enter number of questions: ");
	int id = 100;
	if (ctx.allQuizzes.getSize() > 0)
	{
		id = ctx.allQuizzes.getAt(ctx.allQuizzes.getSize() - 1).getId() + 1;
	}
	for (int i = 0; i < questionsSize; i++)
	{
		unsigned questionNumber = i + 1;
		QuestionType type = getTypeFromInput(questionNumber);;
		Question* newQuestion = QuestionFactory::createFromInput(type);
		questions.addQuestion(newQuestion);
	}
	Quiz newQuiz(id, title, ctx.loggedUser->getUsername(), questions);
	ctx.allQuizzes.pushBack(newQuiz);
	ctx.loggedUser->addCreatedQuiz(newQuiz.getId());
	ctx.loggedUser->createQuizDone();
	std::cout << "Quiz \"" << title << "\" with ID " << id << " sent for admin approval!" << std::endl;
}
