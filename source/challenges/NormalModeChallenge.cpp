#include "NormalModeChallenge.h"

NormalModeChallenge::NormalModeChallenge()
{
    count = 0; 
    target = 10;
}
unsigned NormalModeChallenge::normalModeDone()
{
    count++;
    if (count == target)
    {
        target += 10;
        return 2 * ((count * 10) / 3);
    }
    return 0;
}
void NormalModeChallenge::print() const
{
    std::cout << "Complete " << target << " quizzes in normal mode (" << count << "/" << target << ")" << std::endl;
}
void NormalModeChallenge::readFromBinaryFile(std::ifstream& ifs)
{
    ifs.read((char*)&count, sizeof(count));
    ifs.read((char*)&target, sizeof(target));
}
void NormalModeChallenge::writeToBinaryFile(std::ofstream& ofs) const
{
    ofs.write((const char*)&count, sizeof(count));
    ofs.write((const char*)&target, sizeof(count));
}
unsigned NormalModeChallenge::getCount() const
{
    return count;
}
