#include "Utils.h"

namespace Utils
{
    const char* USERS_FILE_NAME = "usersData.bin";
    const char* QUIZZES_FILE_NAME = "quizzesData.bin";
    const char* REPORTS_FILE_NAME = "reportsData.bin";

    int readPositiveInt(const char* prompt)
    {
        MyString input;
        while (true)
        {
            std::cout << prompt;
            input.readLine(std::cin);
            if (input.isInt())
            {
                int value = input.toInt();
                if (value > 0)
                    return value;
            }
            std::cout << "Invalid number!" << std::endl;
        }
    }
    bool readBool(const char* prompt)
    {
        MyString input;
        while (true)
        {
            std::cout << prompt;
            input.readLine(std::cin);
            input.trim();

            for (unsigned i = 0; i < input.getSize(); ++i)
                input[i] = tolower(input[i]);

            if (input == "true")
                return true;
            else if (input == "false")
                return false;

            std::cout << "Invalid input!" << std::endl;
        }
    }
    char readChar(const char* prompt)
    {
        MyString input;
        while (true)
        {
            std::cout << prompt;
            input.readLine(std::cin);
            input.trim();
            if (input.getSize() == 1)
            {
                return input[0];
            }
            std::cout << "Invalid character!" << std::endl;
        }
    }
    MyString readMyString(const char* prompt)
    {
        MyString input;
        while (true)
        {
            std::cout << prompt;
            input.readLine(std::cin);
            input.trim();
            if (input.getSize() > 0)
            {
                return input;
            }
            std::cout << "Input cannot be empty!" << std::endl;
        }
    }

    MyString convertIntToMyString(int number)
    {
        char buffer[12];
        int index = 0;
        if (number == 0)
        {
            buffer[index++] = '0';
        }
        else
        {
            bool isNegative = number < 0;
            unsigned int absNumber = isNegative ? -number : number;
            while (absNumber > 0)
            {
                buffer[index++] = '0' + (absNumber % 10);
                absNumber /= 10;
            }
            if (isNegative)
            {
                buffer[index++] = '-';
            }
            for (int i = 0; i < index / 2; ++i)
            {
                char temp = buffer[i];
                buffer[i] = buffer[index - i - 1];
                buffer[index - i - 1] = temp;
            }
        }
        buffer[index] = '\0';
        return MyString(buffer);
    }
    bool areStringsEqualCaseInsensitive(const MyString& str1, const MyString& str2) 
    {
        if (str1.getSize() != str2.getSize())
        {
            return false;
        }
        for (unsigned i = 0; i < str1.getSize(); i++) 
        {
            char c1 = std::tolower(str1[i]);
            char c2 = std::tolower(str2[i]);
            if (c1 != c2)
            {
                return false;
            }
        }
        return true;
    }
    MyString convertIntToMyStringWithLeadingZero(unsigned number)
    {
        MyString result;
        if (number < 10)
            result += "0";
        result += convertIntToMyString(number);
        return result;
    }


}