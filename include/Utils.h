#pragma once
#include <iostream>
#include "MyString.h"

namespace Utils
{
	enum class QuestionType
	{
		TrueOrFalse,
		SingleChoice,
		MultipleChoice,
		ShortAnswer,
		MatchingPairs
	};
	enum class UserType
	{
		Administrator,
		Player
	};
	enum class QuizStatus
	{
		Pending,
		Approved,
		Rejected,
		Deleted
	};

	constexpr unsigned MAX_BUFFER_SIZE = 1024;

	extern const char* USERS_FILE_NAME;
	extern const char* QUIZZES_FILE_NAME;
	extern const char* REPORTS_FILE_NAME;

	int readPositiveInt(const char* prompt);
	bool readBool(const char* prompt); 
	char readChar(const char* prompt);
	MyString readMyString(const char* prompt);

	MyString convertIntToMyString(int number);
	bool areStringsEqualCaseInsensitive(const MyString& str1, const MyString& str2);
	MyString convertIntToMyStringWithLeadingZero(unsigned number);
}