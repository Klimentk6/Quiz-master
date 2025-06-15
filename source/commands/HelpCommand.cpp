#include "HelpCommand.h"

HelpCommand::HelpCommand(const MyString& input, Context& ctx)
	:ctx(ctx) {}

void HelpCommand::execute()
{
	if (ctx.loggedUser == nullptr)
	{
		std::cout << "signup <name> <surname> <username> <password1> <password2>: creates a new player account" << std::endl;
		std::cout << "login <username> <password>: logs in an existing user" << std::endl;
		std::cout << "quit: exits the program" << std::endl;
	}
	else if (ctx.loggedUser->getType() == UserType::Administrator)
	{
		std::cout << "pending: shows all quizzes awaiting admin approval" << std::endl;
		std::cout << "approve-quiz <quiz-id>: approves a quiz with the given ID" << std::endl;
		std::cout << "reject-quiz <quiz-id> <reason>: rejects a quiz with a reason sent to its author" << std::endl;
		std::cout << "view-reports: displays all submitted reports" << std::endl;
		std::cout << "remove-quiz <quiz-id> <reason>: removes an existing quiz with a reason sent to its author" << std::endl;
		std::cout << "ban <username>: bans a user by username; their created quizzes remain" << std::endl;
		std::cout << "logout: logs out the currently logged-in user" << std::endl;
		std::cout << "quit: exits the program" << std::endl;
	}
	else
	{
		std::cout << "view-profile: displays all user profile data" << std::endl;
		std::cout << "edit-profile: opens an interface to edit user profile data" << std::endl;
		std::cout << "view-challenges: shows all unfinished challenges and their progress" << std::endl;
		std::cout << "view-finished-challenges: shows all completed challenges" << std::endl;
		std::cout << "view <nickname>: displays all profile data of the user with the given nickname" << std::endl;
		std::cout << "messages: displays all received messages from the system and administrators" << std::endl;
		std::cout << "create-quiz: opens an interface for quiz creation. The quiz is sent for review and approval." << std::endl;
		std::cout << "quizzes: displays all quizzes on the platform with id, title, author, number of questions and likes" << std::endl;
		std::cout << "quizzes <username>: displays all quizzes created by the specified user" << std::endl;
		std::cout << "like-quiz <quiz-id>: likes the quiz with the given id" << std::endl;
		std::cout << "unlike-quiz <quiz-id>: removes like from the quiz with the given id" << std::endl;
		std::cout << "add-to-favs <quiz-id>: adds the quiz to your favorites" << std::endl;
		std::cout << "remove-from-favs <quiz-id>: removes the quiz from your favorites" << std::endl;
		std::cout << "start-quiz <quiz-id> test|normal (shuffle): starts a quiz in the specified mode. Optionally enables question shuffling." << std::endl;
		std::cout << "save-quiz <quiz-id> <filepath>: saves the questions from the quiz to a text file" << std::endl;
		std::cout << "report-quiz <quiz-id> <reason>: reports the quiz to the administrators. Include reason and date." << std::endl;
		std::cout << "logout: logs out the currently logged-in user" << std::endl;
		std::cout << "quit: exits the program" << std::endl;
	}
}
