#include "SaveQuizCommand.h"

SaveQuizCommand::SaveQuizCommand(const MyString& input, Context& ctx) : ctx(ctx)
{
	MyVector<MyString> parts = input.split(' ');
	quizId = std::atoi(parts[1].getCharArr());
	filepath = parts[2];
}

void SaveQuizCommand::execute()
{
    int allQuizzesSize = ctx.allQuizzes.getSize();
    for (int i = 0; i < allQuizzesSize; i++)
    {
        Quiz& currentQuiz = ctx.allQuizzes.getAt(i);
        if (currentQuiz.getId() == quizId)
        {
            if (currentQuiz.getStatus() == QuizStatus::Approved)
            {
                ctx.allQuizzes[i].saveToFile(filepath);
                std::cout << "Quiz saved successfully!" << std::endl;
                return;
            }
        }
    }
    std::cout << "Invalid id!" << std::endl;
}
