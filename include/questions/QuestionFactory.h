#pragma once
#include <iostream>
#include "Utils.h"
#include "Question.h"
#include "TrueOrFalseQuestion.h"
#include "SingleChoiceQuestion.h"
#include "MultipleChoiceQuestion.h"
#include "ShortAnswerQuestion.h"
#include "MatchingPairsQuestion.h"

using namespace Utils;

class QuestionFactory
{
public:
	static Question* create(QuestionType type);
	static Question* createFromInput(QuestionType type);

private:
	static Question* createTrueOrFalseQuestionFromInput();
	static Question* createSingleChoiceQuestionFromInput();
	static Question* createMultipleChoiceQuestionFromInput();
	static Question* createShortAnswerQuestionFromInput();
	static Question* createMatchingPairsQuestionFromInput();
};

