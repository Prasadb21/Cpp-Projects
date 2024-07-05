#include "User.h"
#include <functional>

// Constructor implementation
User::User(int userId, const string& username, const string& passwordHash)
    : userId(userId), username(username), passwordHash(passwordHash) {}

// Getter methods implementation for userId , Username , passwordHash
int User::getUserId() const
{
    return userId;
}

string User::getUsername() const
{
    return username;
}

string User::getPasswordHash() const
{
    return passwordHash;
}

// static function to hash a password

string User::hashPassword(const string& password)
{
    hash<string> hasher;
    return to_string(hasher(password));
}





