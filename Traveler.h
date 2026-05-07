#ifndef TRAVELER_H
#define TRAVELER_H

#include "User.h"

// Derived class: Traveler (inherits from User)
// INHERITANCE DEMONSTRATION: Child class extends parent with specialized attributes
class Traveler : public User {
private:
    int loyaltyPoints;           // Specialized attribute for travelers
    char membershipLevel[20];    // Another specialized attribute
    Review reviewsAuthored[50];  // COMPOSITION: Array of Review objects
    int reviewCount;             // Count of reviews authored

public:
    // Constructor
    Traveler();
    
    // Setter method
    void setTravelerData(int id, const char* name, const char* e, const char* c, 
                        int points, const char* membership);
    
    // COMPOSITION: Add a review authored by this traveler
    void addReview(const Review& newReview);
    
    // Getter methods
    int getLoyaltyPoints() const;
    const char* getMembershipLevel() const;
    int getReviewCount() const;
    Review getReviewAt(int index) const;
    
    // Calculate average rating of reviews authored by this traveler
    double getAverageRating() const;
    
    // Add loyalty points
    void addLoyaltyPoints(int points);
    
    // Display traveler information
    void displayUser() const override;
    
    // Display all reviews authored by this traveler
    void displayAllReviews() const;
    
    // OPERATOR OVERLOADING: Compare travelers by loyalty points
    bool operator>(const Traveler& other) const;
    bool operator<(const Traveler& other) const;
    bool operator==(const Traveler& other) const;
};

#endif