#include "Administrator.h"
MyVector<Report> Administrator::allReports;

Administrator::Administrator(const MyString& name, const MyString& surname, const MyString& username, const MyString& password)
    : User(name, surname, username, password){}

User* Administrator::clone() const
{
    return new Administrator(*this);
}
UserType Administrator::getType() const
{
    return UserType::Administrator;
}
void Administrator::print(const MyVector<Quiz>& allQuizes) const
{
    return;
}
void Administrator::writeToBinaryFile(std::ofstream& ofs) const
{
    User::writeToBinaryFile(ofs);
}
void Administrator::readFromBinaryFile(std::ifstream& ifs)
{
    User::readFromBinaryFile(ifs);
}

void Administrator::printReports() const
{
    int allReportsSize = allReports.getSize();
    if (allReportsSize == 0)
    {
        std::cout << "No reports." << std::endl;
        return;
    }
    for (int i = 0; i < allReportsSize; i++)
    {
        allReports[i].printReport();
    }
}
void Administrator::addReport(const Report& newReport) 
{
    allReports.pushBack(newReport);
}
void Administrator::writeReportsToFile(const char* filename)
{
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs)
        return;

    int count = allReports.getSize();
    ofs.write((const char*)&count, sizeof(count));

    for (int i = 0; i < count; ++i)
    {
        allReports[i].writeToBinaryFile(ofs);
    }
    ofs.close();
}
void Administrator::readReportsFromFile(const char* filename)
{
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs.is_open())
    {
        return;
    }
    allReports.clear();
    int count = 0;
    ifs.read((char*)&count, sizeof(count));
    for (int i = 0; i < count; ++i)
    {
        Report r;
        r.readFromBinaryFile(ifs);
        allReports.pushBack(r);
    }
    ifs.close();
}


