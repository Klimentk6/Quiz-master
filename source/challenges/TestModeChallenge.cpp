#include "TestModeChallenge.h"

TestModeChallenge::TestModeChallenge()
{
    count = 0;
    target = 10;
}
unsigned TestModeChallenge::testModeDone()
{
    count++;
    if (count == target)
    {
        target += 10;
        return (count * 10) / 3;
    }
    return 0;
}
void TestModeChallenge::print() const
{
    std::cout << "Complete " << target << " quizzes in test mode (" << count << "/" << target << ")" << std::endl;
}
void TestModeChallenge::readFromBinaryFile(std::ifstream& ifs)
{
    ifs.read((char*)&count, sizeof(count));
    ifs.read((char*)&target, sizeof(target));
}
void TestModeChallenge::writeToBinaryFile(std::ofstream& ofs) const
{
    ofs.write((const char*)&count, sizeof(count));
    ofs.write((const char*)&target, sizeof(count));
}
unsigned TestModeChallenge::getCount() const
{
    return count;
}
