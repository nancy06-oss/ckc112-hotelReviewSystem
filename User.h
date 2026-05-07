#ifndef USER_H
#define USER_H

#include <iostream>
#include <cstring>
#include "Review.h"
using namespace std;

// Parent class: User (base class for all system users)
// Encapsulates common user attributes
class User {
protected:
    char userID[10];             // User ID (e.g., U001)
    char userName[100];          // User's full name
    char state[50];              // User's state/location
    char email[100];             // User's email address

public:
    // Constructor
    User();
    
    // Setter method - sets basic user data
    void setUserData(const char* id, const char* name, const char* st, const char* e);
    
    // Getter methods
    const char* getUserID() const;
    const char* getUserName() const;
    const char* getState() const;
    const char* getEmail() const;
    
    // Display user information (can be overridden in derived classes)
    virtual void displayUser() const;
};

#endif
