#include "CreateQuizChallenge.h"

CreateQuizChallenge::CreateQuizChallenge()
{
    count = 0;
    target = 5;
}
unsigned CreateQuizChallenge::createQuizDone()
{
    count++;
    if (count == target)
    {
        target += 5;
        return (count * 10) / 2;
    }
    return 0;
}
void CreateQuizChallenge::print() const
{
    std::cout << "Create " << target << " quizzes (" << count << "/" << target << ")" << std::endl;
}
void CreateQuizChallenge::readFromBinaryFile(std::ifstream& ifs)
{
    ifs.read((char*)&count, sizeof(count));
    ifs.read((char*)&target, sizeof(target));
}
void CreateQuizChallenge::writeToBinaryFile(std::ofstream& ofs) const
{
    ofs.write((const char*)&count, sizeof(count));
    ofs.write((const char*)&target, sizeof(count));
}
unsigned CreateQuizChallenge::getCount() const
{
    return count;
}
