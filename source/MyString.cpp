#include "MyString.h"

MyString::MyString()
{
    size = 0;
    capacity = MIN_CAPACITY;
    data = new char[capacity];
    data[0] = '\0';
}
MyString::MyString(const char* str)
{
    if (!str)
    {
        size = 0;
        capacity = 16;
        data = new char[capacity];
        data[0] = '\0';
        return;
    }
    size = strlen(str);
    capacity = calculateCapacity(size + 1, MIN_CAPACITY);
    data = new char[capacity];
    strcpy(data, str);
}
MyString::MyString(const MyString& other)
{
    copyFrom(other);
}
MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
MyString::~MyString()
{
    free();
}

void MyString::copyFrom(const MyString& other)
{
    size = other.size;
    capacity = other.capacity;
    data = new char[capacity];
    strcpy(data, other.data);
}
void MyString::free()
{
    delete[] data;
}

void MyString::resize(unsigned newCapacity)
{
    if (newCapacity <= capacity)
    {
        return;
    }
    char* newData = new char[newCapacity];
    strcpy(newData, data);
    delete[] data;
    data = newData;
    capacity = newCapacity;
}
unsigned MyString::calculateCapacity(unsigned size, unsigned minCapacity)
{
    if (size == 0)
    {
        return minCapacity;
    }
    while (size < minCapacity)
    {
        size *= RESIZE_COEFF;
    }
    return ++size;
}

const char& MyString::operator[](unsigned index) const
{
    if (index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}
char& MyString::operator[](unsigned index)
{
    if (index >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

unsigned MyString::getSize() const
{
    return size;
}
bool MyString::isEmpty() const
{
    return size == 0;
}
bool MyString::isInt() const 
{
    if (isEmpty()) return false;

    size_t i = 0;
    if ((*this)[0] == '-' || (*this)[0] == '+') 
    {
        if (getSize() == 1) return false;
        i = 1;
    }

    for (; i < getSize(); ++i) {
        if ((*this)[i] < '0' || (*this)[i] > '9') {
            return false;
        }
    }
    return true;
}
int MyString::toInt() const
{
    int result = 0;
    int sign = 1;
    size_t i = 0;
    if (data[0] == '-')
    {
        sign = -1;
        i = 1;
    }
    for (; i < size; ++i)
    {
        if (data[i] < '0' || data[i] > '9')
        {
            throw std::invalid_argument("MyString::toInt: Invalid character in string");
        }
        result = result * 10 + (data[i] - '0');
    }
    return sign * result;
}

void MyString::pushBack(char c)
{
    if (size + 1 >= capacity)
    {
        resize(capacity * RESIZE_COEFF);
    }
    data[size] = c;
    size++;
    data[size] = '\0';
}
void MyString::popBack()
{
    if (isEmpty())
        throw std::out_of_range("Cannot pop from empty string");
    size--;
    data[size] = '\0';
}
void MyString::readLine(std::istream& is)
{
    char buffer[1024];
    is.getline(buffer, sizeof(buffer));
    *this = MyString(buffer);
}

MyString MyString::substring(int start, int length) const
{
    if (start < 0 || start > size || length < 0)
    {
        throw std::out_of_range("Invalid substring range.");
    }
    if (start + length > size)
    {
        length = size - start;
    }
    char* buffer = new char[length + 1];
    for (int i = 0; i < length; ++i)
    {
        buffer[i] = data[start + i];
    }
    buffer[length] = '\0';
    MyString result(buffer);
    delete[] buffer;
    return result;
}

void MyString::trim()
{
    if (isEmpty())
    {
        return;
    }
    int start = 0;
    while (data[start] == ' ' || data[start] == '\t' || data[start] == '\n' || data[start] == '\r')
    {
        start++;
    }
    int end = size - 1;
    while (end >= start && (data[end] == ' ' || data[end] == '\t' || data[end] == '\n' || data[end] == '\r'))
    {
        end--;
    }
    int newLength = end - start + 1;
    if (newLength <= 0)
    {
        clear();
        return;
    }
    char* newData = new char[newLength + 1];
    for (int i = 0; i < newLength; i++)
    {
        newData[i] = data[start + i];
    }
    newData[newLength] = '\0';
    delete[] data;
    data = newData;
    size = newLength;
    capacity = calculateCapacity(size + 1, MIN_CAPACITY);
}

MyVector<MyString> MyString::split(char delimiter) const
{
    MyVector<MyString> result;
    int start = 0;
    for (int i = 0; i < size; i++)
    {
        if (data[i] == delimiter)
        {
            result.pushBack(substring(start, i - start));
            start = i + 1;
        }
    }
    if (start <= size)
    {
        result.pushBack(substring(start, size - start));
    }
    return result;
}
MyVector<MyString> MyString::split(const MyString& delimiter) const
{
    MyVector<MyString> result;
    int delimLen = delimiter.getSize();
    int start = 0;
    bool found = false;
    for (int i = 0; i <= size - delimLen; ++i)
    {
        bool match = true;
        for (int j = 0; j < delimLen; ++j)
        {
            if (data[i + j] != delimiter[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            result.pushBack(substring(start, i - start));
            i += delimLen - 1;
            start = i + 1;
            found = true;
        }
    }
    if (found)
    {
        if (start <= size)
        {
            result.pushBack(substring(start, size - start));
        }
    }
    return result;
}

void MyString::clear()
{
    size = 0;
    if (data)
        data[0] = '\0';
}
const char* MyString::getCharArr() const
{
    return data;
}

bool MyString::operator==(const MyString& other) const
{
    if (this == &other)
        return true;

    if (!data || !other.data)
        return false; 

    if (size != other.size)
        return false;

    for (unsigned i = 0; i < size; ++i)
        if (data[i] != other.data[i])
            return false;

    return true;
}
bool MyString::operator!=(const MyString& other) const
{
    return !(*this == other);
}
MyString MyString::operator+(const MyString& other) const
{
    MyString result;
    result.capacity = size + other.size + 1;
    result.data = new char[result.capacity];
    result.data[0] = '\0'; 
    strcpy(result.data, data);
    strcat(result.data, other.data);
    result.size = strlen(result.data);
    return result;
}
MyString& MyString::operator+=(const MyString& other)
{
    unsigned newSize = size + other.size;
    if (newSize + 1 > capacity)
    {
        resize(newSize + 1);
    }
    strcat(data, other.data);
    size = newSize;
    return *this;
}
MyString& MyString::operator+=(char c)
{
    pushBack(c);
    return *this;
}
std::ostream& operator<<(std::ostream& out, const MyString& str)
{
    out << str.getCharArr();
    return out;
}
std::istream& operator>>(std::istream& in, MyString& str)
{
    char buffer[1024];
    in >> buffer;
    str = MyString(buffer);
    return in;
}

void MyString::writeToBinaryFile(std::ofstream& ofs) const 
{
    unsigned length = getSize();
    ofs.write((const char*)(&length), sizeof(length));
    ofs.write((const char*)data, length);
}
void MyString::readFromBinaryFile(std::ifstream& ifs) 
{
    unsigned length;
    ifs.read((char*)(&length), sizeof(length));
    char* buffer = new char[length + 1];
    ifs.read((char*)buffer, length * sizeof(char));
    buffer[length] = '\0';
    *this = MyString(buffer);
    delete[] buffer;
}
