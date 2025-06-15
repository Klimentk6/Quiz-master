#include "RemoveQuizCommand.h"

RemoveQuizCommand::RemoveQuizCommand(const MyString& input, Context& ctx) : ctx(ctx)
{
    MyVector<MyString> parts = input.split(' ');
    quizId = parts[1].toInt();
    reason = "";
    for (int i = 2; i < parts.getSize(); i++)
    {
        reason += parts[i];
        if (i < parts.getSize() - 1)
        {
            reason += " ";
        }
    }
}

void RemoveQuizCommand::execute()
{
    int allQuizzesSize = ctx.allQuizzes.getSize();
    for (int i = 0; i < allQuizzesSize; i++)
    {
        Quiz& currentQuiz = ctx.allQuizzes.getAt(i);
        if (currentQuiz.getId() == quizId)
        {
            if (currentQuiz.getStatus() == QuizStatus::Deleted)
            {
                std::cout << "This quiz is already deleted." << std::endl;
            }
            else
            {
                currentQuiz.setStatus(QuizStatus::Deleted);
                MyString message = "Quiz ";
                message += convertIntToMyString(currentQuiz.getId());
                message += " \"";
                message += currentQuiz.getTitle();
                message += "\" was removed. Reason: ";
                message += reason;
                ctx.allUsers.getUserPointer(currentQuiz.getCreatorUsername())->addMessage(message);
                std::cout << "Quiz removed successfully!" << std::endl;
            }
            return;
        }
    }
    std::cout << "Invalid id!" << std::endl;
}
