#include "Traveler.h"

// Constructor - initializes traveler with default values
Traveler::Traveler() : User() {
    loyaltyPoints = 0;
    strcpy(membershipLevel, "Bronze");
    reviewCount = 0;
}

// Set traveler-specific data
void Traveler::setTravelerData(int id, const char* name, const char* e, 
                               const char* c, int points, const char* membership) {
    setUserData(id, name, e, c);  // Call parent class method
    loyaltyPoints = points;
    strcpy(membershipLevel, membership);
    reviewCount = 0;
}

// COMPOSITION: Add a review to traveler's authored reviews
void Traveler::addReview(const Review& newReview) {
    if (reviewCount < 50) {
        reviewsAuthored[reviewCount] = newReview;
        reviewCount++;
    }
}

// Getter: Loyalty Points
int Traveler::getLoyaltyPoints() const {
    return loyaltyPoints;
}

// Getter: Membership Level
const char* Traveler::getMembershipLevel() const {
    return membershipLevel;
}

// Getter: Review Count
int Traveler::getReviewCount() const {
    return reviewCount;
}

// Getter: Review at index
Review Traveler::getReviewAt(int index) const {
    if (index >= 0 && index < reviewCount) {
        return reviewsAuthored[index];
    }
    return Review();
}

// Calculate average rating of all reviews authored by this traveler
double Traveler::getAverageRating() const {
    if (reviewCount == 0) return 0.0;
    
    int totalRating = 0;
    for (int i = 0; i < reviewCount; i++) {
        totalRating += reviewsAuthored[i].getRating();
    }
    return (double)totalRating / reviewCount;
}

// Add loyalty points
void Traveler::addLoyaltyPoints(int points) {
    loyaltyPoints += points;
}

// Override parent's display method
void Traveler::displayUser() const {
    cout << "=== TRAVELER PROFILE ===\n";
    cout << "User ID: " << userID << " | Name: " << userName 
         << " | Email: " << email << " | City: " << city << "\n";
    cout << "Loyalty Points: " << loyaltyPoints << " | Membership: " << membershipLevel << "\n";
    cout << "Reviews Authored: " << reviewCount << "\n";
}

// Display all reviews authored by this traveler
void Traveler::displayAllReviews() const {
    cout << "\n--- Reviews Authored by " << userName << " ---\n";
    if (reviewCount == 0) {
        cout << "No reviews authored yet.\n";
        return;
    }
    for (int i = 0; i < reviewCount; i++) {
        reviewsAuthored[i].displayReview();
    }
}

// OPERATOR OVERLOADING: Compare by loyalty points (>)
bool Traveler::operator>(const Traveler& other) const {
    return loyaltyPoints > other.loyaltyPoints;
}

// OPERATOR OVERLOADING: Compare by loyalty points (<)
bool Traveler::operator<(const Traveler& other) const {
    return loyaltyPoints < other.loyaltyPoints;
}

// OPERATOR OVERLOADING: Compare equality
bool Traveler::operator==(const Traveler& other) const {
    return userID == other.userID;
}