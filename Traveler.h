#ifndef TRAVELER_H
#define TRAVELER_H

#include "User.h"

// Derived class: Traveler (inherits from User)
// INHERITANCE DEMONSTRATION: Child class extends parent with specialized attributes
// Represents a traveler who writes reviews and accumulates loyalty points
class Traveler : public User {
private:
    char membershipLevel[20];    // Membership tier: Silver, Gold, Platinum
    int loyaltyPoints;           // Accumulated loyalty/reward points
    Review reviewsAuthored[50];  // COMPOSITION: Array of Review objects authored by traveler
    int reviewCount;             // Count of reviews authored

public:
    // Constructor
    Traveler();
    
    // Setter method - initializes traveler with all data
    void setTravelerData(const char* id, const char* name, const char* st, 
                        const char* e, const char* membership, int points);
    
    // COMPOSITION: Add a review authored by this traveler
    void addReview(const Review& newReview);
    
    // Getter methods
    const char* getMembershipLevel() const;
    int getLoyaltyPoints() const;
    int getReviewCount() const;
    Review getReviewAt(int index) const;
    
    // Calculate average rating of reviews authored by this traveler
    double getAverageRating() const;
    
    // Add loyalty points to this traveler's account
    void addLoyaltyPoints(int points);
    
    // Display traveler information (overrides parent method)
    void displayUser() const override;
    
    // Display all reviews authored by this traveler
    void displayAllReviews() const;
    
    // OPERATOR OVERLOADING: Compare travelers by loyalty points
    bool operator>(const Traveler& other) const;  // Greater than
    bool operator<(const Traveler& other) const;  // Less than
    bool operator==(const Traveler& other) const; // Equal to
};

#endif
