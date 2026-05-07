#include "User.h"

// Constructor - initializes user with default values
User::User() {
    userID = 0;
    strcpy(userName, "");
    strcpy(email, "");
    strcpy(city, "");
}

// Set user data
void User::setUserData(int id, const char* name, const char* e, const char* c) {
    userID = id;
    strcpy(userName, name);
    strcpy(email, e);
    strcpy(city, c);
}

// Getter: User ID
int User::getUserID() const {
    return userID;
}

// Getter: Username
const char* User::getUserName() const {
    return userName;
}

// Getter: Email
const char* User::getEmail() const {
    return email;
}

// Getter: City
const char* User::getCity() const {
    return city;
}

// Virtual display method (can be overridden)
void User::displayUser() const {
    cout << "User ID: " << userID << " | Name: " << userName 
         << " | Email: " << email << " | City: " << city << "\n";
}