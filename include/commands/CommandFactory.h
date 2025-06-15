#pragma once
#include <iostream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "Context.h"
#include "Command.h"
#include "LoginCommand.h"
#include "LogoutCommand.h"
#include "HelpCommand.h"
#include "QuitCommand.h"
#include "PendingCommand.h"
#include "ApproveQuizCommand.h"
#include "RejectQuizCommand.h"
#include "SignupCommand.h"
#include "CreateQuizCommand.h"
#include "ViewProfileCommand.h"
#include "QuizzesCommand.h"
#include "QuizzesByUserCommand.h"
#include "LikeQuizCommand.h"
#include "UnlikeQuizCommand.h"
#include "BanUserCommand.h"
#include "MessagesCommand.h"
#include "ViewReportsCommand.h"
#include "StartQuizCommand.h"
#include "RemoveQuizCommand.h"
#include "SaveQuizCommand.h"
#include "ReportQuizCommand.h"
#include "AddToFavsCommand.h"
#include "RemoveFromFavsCommand.h"
#include "ViewChallengesCommand.h"
#include "ViewUserCommand.h"
#include "ViewFinishedChallengesCommand.h"

using namespace Utils;

bool isValidLoginInput(const MyString& input);
bool isValidLogoutInput(const MyString& input);
bool isValidHelpInput(const MyString& input);
bool isValidQuitInput(const MyString& input);
bool isValidPendingInput(const MyString& input);
bool isValidApproveQuizInput(const MyString& input);
bool isValidRejectQuizInput(const MyString& input);
bool isValidSignupInput(const MyString& input);
bool isValidCreateQuizInput(const MyString& input);
bool isValidViewProfileInput(const MyString& input);
bool isValidQuizzesInput(const MyString& input);
bool isValidQuizzesByUserInput(const MyString& input);
bool isValidLikeQuizInput(const MyString& input);
bool isValidUnlikeQuizInput(const MyString& input);
bool isValidBanUserInput(const MyString& input);
bool isValidMessagesInput(const MyString& input);
bool isValidViewReportsInput(const MyString& input);
bool isValidStartQuizInput(const MyString& input);
bool isValidRemoveQuizInput(const MyString& input);
bool isValidSaveQuizInput(const MyString& input);
bool isValidReportQuizInput(const MyString& input);
bool isValidAddToFavsInput(const MyString& input);
bool isValidRemoveFromFavsInput(const MyString& input);
bool isValidChallengesInput(const MyString& input);
bool isValidViewUserInput(const MyString& input);
bool isValidViewFinishedChallenges(const MyString& input);

Command* createCommand(const MyString& input, Context& ctx);
