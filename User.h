#ifndef USER_H
#define USER_H

#include <iostream>
#include <cstring>
#include "Review.h"
using namespace std;

// Parent class: User (base class for all users)
class User {
protected:
    int userID;
    char userName[100];
    char email[100];
    char city[50];

public:
    // Constructor
    User();
    
    // Setter method
    void setUserData(int id, const char* name, const char* e, const char* c);
    
    // Getter methods
    int getUserID() const;
    const char* getUserName() const;
    const char* getEmail() const;
    const char* getCity() const;
    
    // Display user information
    virtual void displayUser() const;
};

#endif