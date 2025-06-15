#include "QuestionFactory.h"

Question* QuestionFactory::create(QuestionType type)
{
    switch (type)
    {
    case QuestionType::TrueOrFalse:
        return new TrueOrFalseQuestion();

    case QuestionType::SingleChoice:
        return new SingleChoiceQuestion();

    case QuestionType::MultipleChoice:
        return new MultipleChoiceQuestion();

    case QuestionType::ShortAnswer:
        return new ShortAnswerQuestion();

    case QuestionType::MatchingPairs:
        return new MatchingPairsQuestion();

    default:
        return nullptr;
    }
}
Question* QuestionFactory::createFromInput(QuestionType type)
{
    switch (type)
    {
    case QuestionType::TrueOrFalse:
        return createTrueOrFalseQuestionFromInput();

    case QuestionType::SingleChoice:
        return createSingleChoiceQuestionFromInput();

    case QuestionType::MultipleChoice:
        return createMultipleChoiceQuestionFromInput();

    case QuestionType::ShortAnswer:
        return createShortAnswerQuestionFromInput();

    case QuestionType::MatchingPairs:
        return createMatchingPairsQuestionFromInput();

    default:
        return nullptr;
    }
}

Question* QuestionFactory::createTrueOrFalseQuestionFromInput()
{
    MyString description = readMyString("Enter description: ");
    bool correctAnswer = readBool("Enter correct answer: ");
    int points = readPositiveInt("Enter points: ");
    return new TrueOrFalseQuestion(description, points, correctAnswer);
}
Question* QuestionFactory::createSingleChoiceQuestionFromInput()
{
    MyString description = readMyString("Enter description: ");
    MyString answers[4];
    answers[0] = readMyString("Enter answer A: ");
    answers[1] = readMyString("Enter answer B: ");
    answers[2] = readMyString("Enter answer C: ");
    answers[3] = readMyString("Enter answer D: ");
    char correctAnswer;
    while (true)
    {
        correctAnswer = readChar("Enter correct answer : ");
        if (correctAnswer >= 'A' && correctAnswer <= 'D')
        {
            break;
        }
        else
        {
            std::cout << "Invalid charecter" << std::endl;
        }
    }
    int points = readPositiveInt("Enter points: ");
    return new SingleChoiceQuestion(description, points, answers, correctAnswer);
}
Question* QuestionFactory::createMultipleChoiceQuestionFromInput()
{
    MyString description = readMyString("Enter description: ");

    int answersCount;
    while (true)
    {
        answersCount = readPositiveInt("Enter possible answers count: ");
        if (answersCount >= 4 && answersCount <= 26)
        {
            break;
        }
        std::cout << "Please enter a number between 4 and 26" << std::endl;
    }

    MyVector<MyString> answers;
    for (int i = 0; i < answersCount; i++)
    {
        MyString prompt("Enter answer ");
        prompt += (char)('A' + i);
        prompt += ": ";
        MyString answer = readMyString(prompt.getCharArr());
        answers.pushBack(answer);
    }

    MyVector<char> correctAnswers;
    while (true)
    {
        correctAnswers.clear();
        MyString prompt("Enter correct answers (e.g. A,B,C): ");
        MyString correctAnswersStr = readMyString(prompt.getCharArr());
        MyVector<MyString> parts = correctAnswersStr.split(',');
        bool allValid = true;
        for (int i = 0; i < parts.getSize(); i++)
        {
            MyString part = parts[i];
            part.trim();
            if (part.getSize() != 1)
            {
                allValid = false;
                break;
            }
            char c = toupper(part[0]);
            if (c < 'A' || c >= 'A' + answersCount)
            {
                allValid = false;
                break;
            }
            bool alreadyAdded = false;
            for (int j = 0; j < correctAnswers.getSize(); j++)
            {
                if (correctAnswers[j] == c)
                {
                    alreadyAdded = true;
                    break;
                }
            }
            if (alreadyAdded)
            {
                allValid = false;
                break;
            }
            correctAnswers.pushBack(c);
        }
        if (allValid && correctAnswers.getSize() > 0)
        {
            break;
        }
        std::cout << "Invalid input! Please enter unique capital or lowercase letters from A to "
            << (char)('A' + answersCount - 1) << " separated by ','" << std::endl;
    }
    int points = readPositiveInt("Enter points: ");
    return new MultipleChoiceQuestion(description, points, answers, correctAnswers);
}
Question* QuestionFactory::createShortAnswerQuestionFromInput()
{
    MyString description = readMyString("Enter description: ");
    MyString correctAnswer = readMyString("Enter correct answer: ");
    int points = readPositiveInt("Enter points: ");
    return new ShortAnswerQuestion(description, points, correctAnswer);
}
Question* QuestionFactory::createMatchingPairsQuestionFromInput()
{
    MyString description = readMyString("Enter description: ");
    int leftColumnSize;
    while (true)
    {
        leftColumnSize = readPositiveInt("Enter left column values count: ");
        if (leftColumnSize > 0 && leftColumnSize <= 26)
            break;

        std::cout << "Please enter a number between 1 and 26" << std::endl;
    }
    MyVector<MyString> leftColumn;
    for (int i = 0; i < leftColumnSize; i++)
    {
        MyString prompt("Enter value ");
        prompt += (char)('A' + i);
        prompt += ": ";
        leftColumn.pushBack(readMyString(prompt.getCharArr()));
    }
    int rightColumnSize;
    while (true)
    {
        rightColumnSize = readPositiveInt("Enter right column values count: ");
        if (rightColumnSize > 0 && rightColumnSize <= 26)
            break;

        std::cout << "Please enter a number between 1 and 26" << std::endl;
    }

    MyVector<MyString> rightColumn;
    for (int i = 0; i < rightColumnSize; i++)
    {
        MyString prompt("Enter value ");
        prompt += (char)('a' + i);
        prompt += ": ";
        rightColumn.pushBack(readMyString(prompt.getCharArr()));
    }
    MyVector<CharPair> correctMatches;
    while (true)
    {
        correctMatches.clear();
        MyString input = readMyString("Enter correct matches (e.g. (A,a), (B,b)): ");
        input.trim();
        bool allValid = true;
        unsigned i = 0;
        while (i < input.getSize())
        {
            while (i < input.getSize() && (input[i] == ' ' || input[i] == ','))
                i++;
            if (i + 4 >= input.getSize() || input[i] != '(' || input[i + 2] != ',' || input[i + 4] != ')')
            {
                allValid = false;
                break;
            }
            char left = input[i + 1];
            char right = input[i + 3];
            if (left < 'A' || left >= 'A' + leftColumnSize || right < 'a' || right >= 'a' + rightColumnSize)
            {
                allValid = false;
                break;
            }
            bool duplicate = false;
            for (size_t j = 0; j < correctMatches.getSize(); j++)
            {
                if (correctMatches[j].left == left)
                {
                    duplicate = true;
                    break;
                }
            }
            if (duplicate)
            {
                allValid = false;
                break;
            }

            correctMatches.pushBack(CharPair(left, right));
            i += 5;
        }

        if (allValid && correctMatches.getSize() > 0)
            break;

        std::cout << "Invalid input! Please enter pairs in the format (A,a), (B,b) with no extra characters." << std::endl;
    }

    int points = readPositiveInt("Enter points: ");
    return new MatchingPairsQuestion(description, points, leftColumn, rightColumn, correctMatches);
}





