#include "Context.h"

Context::Context()
	: allUsers(), allQuizzes(), loggedUser(nullptr)
{
	readFromBinaryFile();
}
Context::~Context()
{
	writeToBinaryFile();
}

void Context::readFromBinaryFile()
{
	try
	{
		allUsers.readFromBinaryFile(USERS_FILE_NAME);
		allQuizzes.readFromBinaryFile(QUIZZES_FILE_NAME);
		Administrator::readReportsFromFile(REPORTS_FILE_NAME);
	}
	catch (const std::runtime_error&) 
	{

	}
}
void Context::writeToBinaryFile()
{
	allUsers.writeToBinaryFile(USERS_FILE_NAME);
	allQuizzes.writeToBinaryFile(QUIZZES_FILE_NAME);
	Administrator::writeReportsToFile(REPORTS_FILE_NAME);
}
