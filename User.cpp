#include "User.h"

// Constructor - initializes user with default/empty values
User::User() {
    strcpy(userID, "");
    strcpy(userName, "");
    strcpy(state, "");
    strcpy(email, "");
}

// Set user data with provided values
// Parameters: id = user ID, name = user's name, st = state, e = email
void User::setUserData(const char* id, const char* name, const char* st, const char* e) {
    strcpy(userID, id);
    strcpy(userName, name);
    strcpy(state, st);
    strcpy(email, e);
}

// Getter: User ID
const char* User::getUserID() const {
    return userID;
}

// Getter: Username
const char* User::getUserName() const {
    return userName;
}

// Getter: State
const char* User::getState() const {
    return state;
}

// Getter: Email
const char* User::getEmail() const {
    return email;
}

// Virtual display method (overridden in Traveler class)
void User::displayUser() const {
    cout << "User ID: " << userID << " | Name: " << userName 
         << " | State: " << state << " | Email: " << email << "\n";
}
