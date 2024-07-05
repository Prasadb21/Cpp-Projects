#ifndef USER_H
#define USER_H

#include<iostream>
#include<string>

using namespace std;



// Class representing a user in the system
class User {

    private:
        int userId; // User ID
        string username; // Username
        string passwordHash; // Hashed password

    public:
        // Constructor to initialize a user
        User(int userId, const string& username, const string& passwordHash);

        // Getter for user ID
        int getUserId() const;

        // Getter for username
        string getUsername() const;

        // Getter for password hash
        string getPasswordHash() const;

        // Static function to hash a password
        static string hashPassword(const string& password);
};

#endif // USER_H