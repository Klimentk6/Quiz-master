#include "ApproveQuizCommand.h"

ApproveQuizCommand::ApproveQuizCommand(const MyString& input, Context& ctx) : ctx(ctx)
{
    MyVector<MyString> parts = input.split(' ');
    quizId = std::atoi(parts[1].getCharArr());
}

void ApproveQuizCommand::execute()
{
    int allQuizzesSize = ctx.allQuizzes.getSize();
    for (int i = 0; i < allQuizzesSize; i++)
    {
        Quiz& currentQuiz = ctx.allQuizzes.getAt(i);
        if (currentQuiz.getId() == quizId)
        {
            if (currentQuiz.getStatus() == QuizStatus::Pending)
            {
                currentQuiz.setStatus(QuizStatus::Approved);
                std::cout << "Quiz approved successfully!" << std::endl;
            }
            else if (currentQuiz.getStatus() == QuizStatus::Rejected)
            {
                std::cout << "This quiz is rejected." << std::endl;
            }
            else if (currentQuiz.getStatus() == QuizStatus::Deleted)
            {
                std::cout << "This quiz is deleted." << std::endl;
            }
            else
            {
                std::cout << "This quiz is already approved." << std::endl;
            }
            return;
        }
    }
    std::cout << "Invalid id!" << std::endl;
}