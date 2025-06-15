#include "UserContainer.h"

UserContainer::UserContainer()
{
	size = 0;
	capacity = MIN_CAPACITY;
	arr = new User * [capacity];
	addDefaultAdministrators();
}
UserContainer::UserContainer(const char* fileName)
{
	try
	{
		readFromBinaryFile(fileName);
	}
	catch (std::exception)
	{
		size = 0;
		capacity = MIN_CAPACITY;
		arr = new User * [capacity];
		addDefaultAdministrators();
	}
}
UserContainer::UserContainer(const UserContainer& other) 
{
	copyFrom(other);
}
UserContainer& UserContainer::operator=(const UserContainer& other) 
{
	if (this != &other) 
	{
		free();
		copyFrom(other);
	}
	return *this;
}
UserContainer::~UserContainer() 
{
	free();
}

void UserContainer::copyFrom(const UserContainer& other) 
{
	size = other.size;
	capacity = other.capacity;
	arr = new User * [capacity];
	for (int i = 0; i < size; i++) 
	{
		arr[i] = other.arr[i]->clone();
	}
}
void UserContainer::free() 
{
	for (int i = 0; i < size; i++) 
	{
		delete arr[i];
	}
	delete[] arr;
}

void UserContainer::resize(int newCapacity) 
{
	capacity = newCapacity;
	User** temp = new User * [capacity];
	for (int i = 0; i < size; i++) 
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}

unsigned UserContainer::calculateCapacity(unsigned size, unsigned minCapacity)
{
	unsigned capacity = minCapacity;
	while (capacity < size)
	{
		capacity *= RESIZE_COEFF;
	}
	return capacity;
}

User* UserContainer::getUserPointer(const MyString& username)
{
	User* result = nullptr;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == nullptr)
		{
			continue;
		}
		if (username == arr[i]->getUsername())
		{
			result = arr[i];
			break;
		}
	}
	return result;
}
void UserContainer::addUser(const User& newUser)
{
	if (size == capacity) 
	{
		resize(capacity * 2);
	}
	arr[size++] = newUser.clone();
}
void UserContainer::addDefaultAdministrators()
{
	arr[size++] = new Administrator("Admin", "One", "admin1", "0000");
	arr[size++] = new Administrator("Admin", "Two", "admin2", "0000");
	arr[size++] = new Administrator("Admin", "Three", "admin3", "0000");
	arr[size++] = new Administrator("Admin", "Four", "admin4", "0000");
	arr[size++] = new Administrator("Admin", "Five", "admin5", "0000");
}
bool UserContainer::doesUsernameExist(const MyString& username) const
{
	for (int i = 0; i < size; i++)
	{
		if(arr[i] == nullptr)
		{
			continue;
		}
		if (arr[i]->getUsername() == username)
		{
			return true;
		}
	}
	return false;
}
void UserContainer::banUser(const MyString& username) 
{
	for (int i = 0; i < size; i++) 
	{
		if (arr[i]->getUsername() == username)
		{ 
			arr[i]->setIsBanned(true);
			break;
		}
	}
}

void UserContainer::writeToBinaryFile(const char* fileName) 
{
	std::ofstream ofs(fileName, std::ios::binary);
	if (!ofs.is_open()) 
	{ 
		return throw std::runtime_error("Cannot open file for writing");
	}
	ofs.write((const char*)&size, sizeof(size));
	for (int i = 0; i < size; i++)
	{
		bool isNullptr = (arr[i] == nullptr);
		ofs.write((const char*)&isNullptr, sizeof(isNullptr));
		if (!isNullptr)
		{
			UserType type = arr[i]->getType();
			ofs.write((const char*)&type, sizeof(type));
			arr[i]->writeToBinaryFile(ofs);
		}
	}
}
void UserContainer::readFromBinaryFile(const char* fileName) 
{
	std::ifstream ifs(fileName, std::ios::binary);
	if (!ifs.is_open())
	{
		throw std::runtime_error("Cannot open file for reading");
	}
	free();
	ifs.read((char*)&size, sizeof(size));
	capacity = calculateCapacity(size, MIN_CAPACITY);
	arr = new User * [capacity];
	for (int i = 0; i < size; i++)
	{
		bool isNullptr;
		ifs.read((char*)&isNullptr, sizeof(isNullptr));
		if (isNullptr)
		{
			arr[i] = nullptr;
		}
		else
		{
			UserType type;
			ifs.read((char*)&type, sizeof(type));
			arr[i] = UserFactory::create(type);
			if (arr[i] != nullptr)
			{
				arr[i]->readFromBinaryFile(ifs);
			}
		}
	}

}

unsigned UserContainer::getSize() const
{
	return size;
}

