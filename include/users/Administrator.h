#pragma once
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "User.h"
#include "Quiz.h"
#include "Report.h"

using namespace Utils;

class Administrator : public User
{
public:
	Administrator() = default;
	Administrator(const MyString& name, const MyString& surname, const MyString& username, const MyString& password);

	User* clone() const override;
	UserType getType() const override;
	void print(const MyVector<Quiz>& allQuizes) const override;
	void writeToBinaryFile(std::ofstream& ofs) const override;
	void readFromBinaryFile(std::ifstream& ifs) override;

	void printReports() const override;
	static void addReport(const Report& newReport);

    static void writeReportsToFile(const char* filename);
	static void readReportsFromFile(const char* filename);

private:
	static MyVector<Report> allReports;
};

