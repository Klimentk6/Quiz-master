#include "ReportQuizCommand.h"

ReportQuizCommand::ReportQuizCommand(const MyString& input, Context& ctx) : ctx(ctx)
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

void ReportQuizCommand::execute()
{
    int allQuizzesSize = ctx.allQuizzes.getSize();
    for (int i = 0; i < allQuizzesSize; i++)
    {
        Quiz& currentQuiz = ctx.allQuizzes.getAt(i);
        if (currentQuiz.getId() == quizId)
        {
            if (currentQuiz.getStatus() == QuizStatus::Approved)
            {
                Report newReport(ctx.loggedUser->getUsername(), currentQuiz, reason);
                Administrator::addReport(newReport);
                std::cout << "Report sent successfully!" << std::endl;
            }
            return;
        }
    }
    std::cout << "Invalid id!" << std::endl;
}
