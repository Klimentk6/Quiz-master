#include "UserFactory.h"

User* UserFactory::create(UserType type)
{
    switch (type)
    {
    case UserType::Administrator:
        return new Administrator();

    case UserType::Player:
        return new Player();

    default:
        return nullptr;
    }
}